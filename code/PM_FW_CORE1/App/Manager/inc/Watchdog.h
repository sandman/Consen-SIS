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
*  文件名称    : Watchdog.h
*
*  功能简介    :
*
*  作者            : 李琦
*
*  创建日期    : 2016-08-05
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

#ifndef WATCHDOG_H_
#define WATCHDOG_H_

/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/
#include "inc/DataType.h"
#include "inc/Hardware.h"

/*
***********************************************************************************************************************
*                                宏定义
***********************************************************************************************************************
*/
#define WTD_LOW_LIMIT          (00U)   /* 0ms (单位：100us) */
#define WTD_HIGH_LIMIT         (6000U)   /* 600ms */
//#define WTD_HIGH_LIMIT         (200U)   /* 20ms */
//#define WTD_HIGH_LIMIT         (100U)   /* 10ms */
//#define WTD_HIGH_LIMIT         (55U)   /* 5.5ms */
/*
***********************************************************************************************************************
*                                数据结构定义
***********************************************************************************************************************
*/


/*
***********************************************************************************************************************
*                                全局函数声明
***********************************************************************************************************************
*/
/*
***********************************************************************************************************************
* 函数名称: WatchdogManagerInit
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
void WatchdogManagerInit(void);

/*
***********************************************************************************************************************
* 函数名称: WatchdogManagerEnable
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
void WatchdogManagerEnable(void);

/*
***********************************************************************************************************************
* 函数名称: WatchdogManagerCycle
*
* 功能描述: 周期运行函数
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
void WatchdogManagerCycle(void);

/*
***********************************************************************************************************************
* 函数名称: UpdateWatchdogCounter
*
* 功能描述: 更新看门狗计数器
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
void UpdateWatchdogCounter(void);

/*
***********************************************************************************************************************
* 函数名称: SetCrashFlag
*
* 功能描述: 设置程序异常标志
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
void SetCrashFlag(void);

#endif /* WATCHDOG_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/

