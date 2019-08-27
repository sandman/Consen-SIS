/*
 * Copyright 2014 Freescale Semiconductor, Inc.
 *
 * FSL USB HOST xHCI Controller
 *
 * Author: Ramneek Mehresh<ramneek.mehresh@freescale.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _ASM_ARCH_XHCI_FSL_H_
#define _ASM_ARCH_XHCI_FSL_H_

/* Default to the FSL XHCI defines */
#define FSL_XHCI_BASE 0x3100000
#define FSL_OCP1_SCP_BASE 0x4a084c00
#define FSL_OTG_WRAPPER_BASE 0x4A020000

#define USB3_PWRCTL_CLK_CMD_MASK	0x3FE000
#define USB3_PWRCTL_CLK_FREQ_MASK	0xFFC
#define USB3_PHY_PARTIAL_RX_POWERON     (1 << 6)
#define USB3_PHY_RX_POWERON		(1 << 14)
#define USB3_PHY_TX_POWERON		(1 << 15)
#define USB3_PHY_TX_RX_POWERON	(USB3_PHY_RX_POWERON | USB3_PHY_TX_POWERON)
#define USB3_PWRCTL_CLK_CMD_SHIFT   14
#define USB3_PWRCTL_CLK_FREQ_SHIFT	22

/* USBOTGSS_WRAPPER definitions */
#define USBOTGSS_WRAPRESET	(1 << 17)
#define USBOTGSS_DMADISABLE (1 << 16)
#define USBOTGSS_STANDBYMODE_NO_STANDBY (1 << 4)
#define USBOTGSS_STANDBYMODE_SMRT		(1 << 5)
#define USBOTGSS_STANDBYMODE_SMRT_WKUP (0x3 << 4)
#define USBOTGSS_IDLEMODE_NOIDLE (1 << 2)
#define USBOTGSS_IDLEMODE_SMRT (1 << 3)
#define USBOTGSS_IDLEMODE_SMRT_WKUP (0x3 << 2)

/* USBOTGSS_IRQENABLE_SET_0 bit */
#define USBOTGSS_COREIRQ_EN	(1 << 0)

/* USBOTGSS_IRQENABLE_SET_1 bits */
#define USBOTGSS_IRQ_SET_1_IDPULLUP_FALL_EN	(1 << 0)
#define USBOTGSS_IRQ_SET_1_DISCHRGVBUS_FALL_EN	(1 << 3)
#define USBOTGSS_IRQ_SET_1_CHRGVBUS_FALL_EN	(1 << 4)
#define USBOTGSS_IRQ_SET_1_DRVVBUS_FALL_EN	(1 << 5)
#define USBOTGSS_IRQ_SET_1_IDPULLUP_RISE_EN	(1 << 8)
#define USBOTGSS_IRQ_SET_1_DISCHRGVBUS_RISE_EN	(1 << 11)
#define USBOTGSS_IRQ_SET_1_CHRGVBUS_RISE_EN	(1 << 12)
#define USBOTGSS_IRQ_SET_1_DRVVBUS_RISE_EN	(1 << 13)
#define USBOTGSS_IRQ_SET_1_OEVT_EN	(1 << 16)
#define USBOTGSS_IRQ_SET_1_DMADISABLECLR_EN	(1 << 17)

struct fsl_xhci {
	struct xhci_hccr *hcd;
	struct dwc3 *dwc3_reg;
};

#endif /* _ASM_ARCH_XHCI_FSL_H_ */
