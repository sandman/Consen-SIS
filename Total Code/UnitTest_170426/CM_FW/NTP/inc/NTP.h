﻿/*
*********************************************************************************************************************** 
*                  Copyright(c) 北京康吉森技术有限公司 2015
*           Beijing Consen Technologies Co.,Ltd. All rights reserved.
*                                  
*                                  
*  项目名称    : 安全控制系统
*
*  模块名称    : NTP校时模块
*
*  文件名称    : NTP.h
*
*  功能简介    : NTP校时
*
*  作者        : 王东
*
*  创建日期    : 2016-12-22
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

#ifndef NTP_H_
#define NTP_H_

/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/
#include "Sys/inc/Sys.h"
#include "Sys/inc/DataType.h"
#include "ExterComm/inc/ExterComm.h"

/*
***********************************************************************************************************************
*                                宏定义
***********************************************************************************************************************
*/

#define DEBUG_DBNTP

#define DEBUG_OUT_NTP

#ifdef DEBUG_OUT_NTP
#define DEBUG_NTP(format, args...)  printf ("DB_NTP: ") ; printf(format, ##args)
#else
#define DEBUG_NTP(format, args...)
#endif

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
* 函数名称: NTPInit
*
* 功能描述: 模块初始化函数
*
* 输入参数: 无
*
* 输出参数: 无
*
* 返 回 值: 无
*
* 注意事项: 无
***********************************************************************************************************************
*/

void NTPInit( void );

/*
***********************************************************************************************************************
* 函数名称: NTPCycle
*
* 功能描述: 模块周期运行函数
*
* 输入参数: 无
*
* 输出参数: 无
*
* 返 回 值: 无
*
* 注意事项: 无
***********************************************************************************************************************
*/

void NTPCycle( void );

#endif /*NTP_H_*/

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/


