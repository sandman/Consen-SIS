﻿/*
***********************************************************************************************************************
*                  Copyright(c) 北京康吉森技术有限公司 2015
*           Beijing Consen Technologies Co.,Ltd. All rights reserved.
*
*
*  项目名称    : 安全控制系统
*
*  模块名称    : Main模块
*
*  文件名称    : UP1TaskExeEntryBin0.c
*
*  功能简介    :
*
*  作者            : 李琦
*
*  创建日期    : 2016-11-17
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
#include "inc/DataType.h"
#include <Srv/Scheduler/include/stdio.h>
#include <Srv/Scheduler/include/string.h>
#include <Srv/Scheduler/cagos.h>
#include "Srv/Sys/inc/CommSys.h"
#include "../inc/Task.h"

/*
***********************************************************************************************************************
*                                局部变量声明
***********************************************************************************************************************
*/
static uint32_t uiStartTime = 0;
static uint32_t uiEndTime = 0;
static uint32_t uiTimeWindow1 = UP1_TASK_START_TIME_OFFSET;
static uint32_t uiTimeWindow2 = UP1_TASK_START_TIME_OFFSET + TIME_TOLERANCE;

extern void powerpcIntDisable(void);
extern void powerpcIntEnable(void);
extern void ImageSwitchRTS0ToRTS1(void);

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
* 函数名称: TskUP1TaskExeEntry
*
* 功能描述: UP1周期任务入口函数
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
void TskUP1TaskExeEntry(void)
{
    /* 开中断 */
    powerpcIntEnable();

    uiStartTime = SysGetSyncTimeLow32 ();

    if(((uiStartTime%TASK_PERIOD) >= uiTimeWindow1)&&((uiStartTime%TASK_PERIOD) <= uiTimeWindow2))
    {
        //printf("Bin0UP1\n");
        TskUP1TaskExe();

        uiEndTime = SysGetSyncTimeLow32 ();

        if(uiEndTime - uiStartTime <= TIME_TOLERANCE)
        {
            udelay(1000);
        }
    }
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


