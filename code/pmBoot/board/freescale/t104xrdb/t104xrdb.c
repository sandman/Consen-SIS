/*
 * Copyright 2013 Freescale Semiconductor, Inc.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <command.h>
#include <netdev.h>
#include <linux/compiler.h>
#include <asm/mmu.h>
#include <asm/processor.h>
#include <asm/cache.h>
#include <asm/immap_85xx.h>
#include <asm/fsl_law.h>
#include <asm/fsl_serdes.h>
#include <asm/fsl_portals.h>
#include <asm/fsl_liodn.h>
#include <fm_eth.h>
#include <asm/mpc85xx_gpio.h>

#include "t104xrdb.h"
#include "cpld.h"

DECLARE_GLOBAL_DATA_PTR;

int checkboard(void)
{
	struct cpu_type *cpu = gd->arch.cpu;
	u8 sw;

	printf("Board: %sRDB\n", cpu->name);
	printf("Board rev: 0x%02x CPLD ver: 0x%02x, ",
	       CPLD_READ(hw_ver), CPLD_READ(sw_ver));

	sw = CPLD_READ(flash_ctl_status);
	sw = ((sw & CPLD_LBMAP_MASK) >> CPLD_LBMAP_SHIFT);

	if (sw <= 7)
		printf("vBank: %d\n", sw);
	else
		printf("Unsupported Bank=%x\n", sw);

	return 0;
}

int board_early_init_r(void)
{
#ifdef CONFIG_SYS_FLASH_BASE
	const unsigned int flashbase = CONFIG_SYS_FLASH_BASE;
	const u8 flash_esel = find_tlb_idx((void *)flashbase, 1);

	/*
	 * Remap Boot flash region to caching-inhibited
	 * so that flash can be erased properly.
	 */

	/* Flush d-cache and invalidate i-cache of any FLASH data */
	flush_dcache();
	invalidate_icache();

	/* invalidate existing TLB entry for flash */
	disable_tlb(flash_esel);

	set_tlb(1, flashbase, CONFIG_SYS_FLASH_BASE_PHYS,
		MAS3_SX|MAS3_SW|MAS3_SR, MAS2_I|MAS2_G,
		0, flash_esel, BOOKE_PAGESZ_256M, 1);
#endif
	set_liodns();
#ifdef CONFIG_SYS_DPAA_QBMAN
	setup_portals();
#endif

	return 0;
}

int misc_init_r(void)
{
	return 0;
}

void ft_board_setup(void *blob, bd_t *bd)
{
	phys_addr_t base;
	phys_size_t size;

	ft_cpu_setup(blob, bd);

	base = getenv_bootm_low();
	size = getenv_bootm_size();

	fdt_fixup_memory(blob, (u64)base, (u64)size);

#ifdef CONFIG_PCI
	pci_of_setup(blob, bd);
#endif

	fdt_fixup_liodn(blob);

#ifdef CONFIG_HAS_FSL_DR_USB
	fdt_fixup_dr_usb(blob, bd);
#endif

#ifdef CONFIG_SYS_DPAA_FMAN
	fdt_fixup_fman_ethernet(blob);
#endif
}

#ifdef CONFIG_FSL_DEEP_SLEEP
/* determine if it is a warm boot */
bool is_warm_boot(void)
{
#define DCFG_CCSR_CRSTSR_WDRFR	(1 << 3)
	struct ccsr_gur __iomem *gur = (void *)CONFIG_SYS_MPC85xx_GUTS_ADDR;

	if (in_be32(&gur->scrtsr[0]) & DCFG_CCSR_CRSTSR_WDRFR)
		return 1;

	return 0;
}

void fsl_dp_mem_setup(void)
{
	/* does not provide HW signals for power management */
	CPLD_WRITE(misc_ctl_status, (CPLD_READ(misc_ctl_status) & ~0x40));
	/* Disable MCKE isolation */
	gpio_set_value(2, 0);
	udelay(1);
}

void fsl_dp_ddr_restore(void)
{
#define DDR_BUFF_LEN	128
	volatile u64 *src, *dst;
	int i;
	struct ccsr_scfg __iomem *scfg = (void *)CONFIG_SYS_MPC85xx_SCFG;

	if (!is_warm_boot())
		return;

	/* get the address of ddr date from SPARECR3 */
	src = (u64 *)in_be32(&scfg->sparecr[2]);
	dst = (u64 *)CONFIG_SYS_SDRAM_BASE;

	for (i = 0; i < DDR_BUFF_LEN / 8; i++)
		*dst++ = *src++;

	flush_dcache();
}

int fsl_dp_resume(void)
{
	u32 start_addr;
	void (*kernel_resume)(void);
	struct ccsr_scfg __iomem *scfg = (void *)CONFIG_SYS_MPC85xx_SCFG;

	if (!is_warm_boot())
		return 0;

	fsl_dp_ddr_restore();

	l2cache_init();
#if defined(CONFIG_RAMBOOT_PBL)
	disable_cpc_sram();
#endif
	enable_cpc();

	/* Get the entry address and jump to kernel */
	start_addr = in_be32(&scfg->sparecr[1]);
	debug("Entry address is 0x%08x\n", start_addr);
	kernel_resume = (void (*)(void))start_addr;
	kernel_resume();

	return 0;
}
#endif
