﻿/*
***********************************************************************************************************************
*                  Copyright(c) 北京康吉森技术有限公司 2015
*           Beijing Consen Technologies Co.,Ltd. All rights reserved.
*
*
*  项目名称    : 安全控制系统
*
*  模块名称    :
*
*  文件名称    : RamTest.h
*
*  功能简介    :
*
*  作者            : 李琦
*
*  创建日期    : 2016-11-18
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

#ifndef _RAM_TEST_H
#define _RAM_TEST_H
/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/
#include "SysTest.h"
#include "DiagCommon.h"


/*
***********************************************************************************************************************
*                                宏定义
***********************************************************************************************************************
*/

#define    DBS_LEN                  (6U)                    /*内存自检数据背景*/
#define    RAM_ZONE_NUM             (3U)                    /*自检内存段总数*/
#define    RAM_TEST_MINLEN          (0x100U)                /*在一个原子时间内自检字节个数*/
#define    RAM_TEST_TOTALSIZE       (4U*CFG_DATA_SIZE)        /*每次内存自检总字节数*/

/*
***********************************************************************************************************************
*                                数据结构定义
***********************************************************************************************************************
*/
typedef enum
{
    TESTORDER_UP = 1U,                                   /*升序内存自检*/
    TESTORDER_DOWN                                      /*降序内存自检*/
}TestOrder;

typedef struct RamSectionTag
{
    puint32_t        puiStartAddr;                      /*内存段起始地址*/
    uint32_t         uiAddrScope;                       /*内存段字节大小*/
}RamSection_t;

typedef struct RamTestTableTag
{
    RamSection_t     stDiagAddrScope[RAM_ZONE_NUM];     /*内存段*/
    uint32_t         uiTotalSize;                        /*总内存自检字节数*/
}RamTestTable_t;


typedef enum
{
    RAM_DIAG_FINISHED = 1U,                              /*内存自检完成*/
    RAM_DIAG_WAITSTART,                                 /*内存自检等待开始*/
    RAM_DIAG_UNDERWAY                                   /*内存自检进行中*/
}RamDiagStatus;

typedef enum
{  /*March测试方法序列 w0/ (r0,w1,r1,w0,r0,w1)/ (r1,w0,w1)/ (r1,w0,w1,w0)/ (r0,w1,w0)*/
    W0,
    R0W1R1W0R0W1,
    R1W0W1,
    R1W0W1W0,
    R0W1W0,
    MAX_DBs
}RamDiagSn;
typedef struct RamDiagnosisInfoTag
{
    excute_id       emCurUsedZone;                      /*当前系统地址空间*/
    RamDiagStatus   emCurStatus;                        /*当前自检状态*/
    uint32_t        uiCurRamSn;                         /*当前内存自检地址*/
    uint32_t        uiDBsSn;                            /*当前使用的内存自检数据背景*/
    uint32_t        uiAddrStep;                         /*内存自检步进距离*/
    RamDiagSn       emDiagSn;                           /*当前使用的March算法序号*/
}RamDiagInfo_t;

/*
***********************************************************************************************************************
*                                全局函数声明
***********************************************************************************************************************
*/

/*
***********************************************************************************************************************
* 函数名称: RamTestInit
*
* 功能描述: RAM自检初始化函数。
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
void RamTestInit(void);

/*
***********************************************************************************************************************
* 函数名称: RamTestCycle
*
* 功能描述: RAM自检调度函数，根据当前状态决定是否执行RAM自检算法或是更新状态数据
*
* 输入参数: 无
*
* 输出参数: puiVectorTest:   错误记录变量
*
* 返 回 值  :
*       uiResult:        RAM自检完成标志TEST_FINISHED_FALSE为RAM自检未完成，
*                                           TEST_FINISHED_TRUE为完成
*
* 注意事项: 无
***********************************************************************************************************************
*/
uint32_t RamTestCycle(puint32_t puiVectorTest);


#endif /* CPUTest_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/

