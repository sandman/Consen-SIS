/*
***********************************************************************************************************************
*                  Copyright(c) 北京康吉森技术有限公司 2015
*           Beijing Consen Technologies Co.,Ltd. All rights reserved.
*
*
*  项目名称    : 安全控制系统
*
*  模块名称    :
*
*  文件名称    : SharedDiagCode.c
*
*  功能简介    :
*
*  作者            : 李琦
*
*  创建日期    : 2017-03-29
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/
#include <Srv/Scheduler/include/string.h>
#include <Srv/Scheduler/include/stdio.h>
#include <Srv/Scheduler/cagos.h>
#include "../inc/SharedDiagCode.h"
#include "Srv/SharedMem/inc/SharedMem.h"


/*
***********************************************************************************************************************
*                                局部变量声明
***********************************************************************************************************************
*/
/*
 *example:
04f315e0 <BPUBranchUnconBaTest>:
 4f315e0:   38 a5 00 03     addi    r5,r5,3
 4f315e4:   7f 54 42 a6     mfsprg  r26,4
 4f315e8:   7f 48 03 a6     mtlr    r26
 4f315ec:   4e 80 00 20     blr

04f315f0 <BPUBranchUnconBlaTest>:
 4f315f0:   38 a5 00 04     addi    r5,r5,4
 4f315f4:   4e 80 00 20     blr

 04f2e590 <Bpu_branch_bca_code>:
 4f2e590:   7f 54 42 a6     mfsprg  r26,4
 4f2e594:   7f 48 03 a6     mtlr    r26
 4f2e598:   4e 80 00 20     blr

04f2f558 <Bpu_branch_bcla_code>:
 4f2f558:   7f 48 02 a6     mflr    r26
 4f2f55c:   3b 5a 00 04     addi    r26,r26,4
 4f2f560:   7f 48 03 a6     mtlr    r26
 4f2f564:   4e 80 00 20     blr

*/
static uint32_t uiBaTest[4];
static uint32_t uiBlaTest[2];
static uint32_t uiBcaTest[3];
static uint32_t uiBclaTest[4];

/*
***********************************************************************************************************************
*                                局部函数声明
***********************************************************************************************************************
*/




/*
***********************************************************************************************************************
*                                全局函数实现
***********************************************************************************************************************
*/
/*
***********************************************************************************************************************
* 函数名称: SharedDiagCodeInit
*
* 功能描述: 初始化
*
* 输入参数: 无
*
* 输出参数: 无
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
void SharedDiagCodeInit(void)
{
    uiBaTest[0] = 0x38a50003;
    uiBaTest[1] = 0x7f5442a6;
    uiBaTest[2] = 0x7f4803a6;
    uiBaTest[3] = 0x4e800020;

    uiBlaTest[0] = 0x38a50004;
    uiBlaTest[1] = 0x4e800020;

    uiBcaTest[0] = 0x7f5442a6;
    uiBcaTest[1] = 0x7f4803a6;
    uiBcaTest[2] = 0x4e800020;

    uiBclaTest[0] = 0x7f4802a6;
    uiBclaTest[1] = 0x3b5a0004;
    uiBclaTest[2] = 0x7f4803a6;
    uiBclaTest[3] = 0x4e800020;

    return;
}



/*
***********************************************************************************************************************
*                                局部函数实现
***********************************************************************************************************************
*/

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/
