﻿/*
***********************************************************************************************************************
*                  Copyright(c) 北京康吉森技术有限公司 2015
*           Beijing Consen Technologies Co.,Ltd. All rights reserved.
*
*
*  项目名称    : 安全控制系统
*
*  模块名称    : 监控模块
*
*  文件名称    : Monitor.h
*
*  功能简介    :
*
*  作者        : 李琦
*
*  创建日期    : 2016-09-07
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

#ifndef MONITOR_H_
#define MONITOR_H_

/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/
#include "Sys/inc/DataType.h"
#include "Sys/inc/Hardware.h"
#include "Sys/inc/Sys.h"

/*
***********************************************************************************************************************
*                                宏定义
***********************************************************************************************************************
*/



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
* 函数名称: MonitorInit
*
* 功能描述: 监控模块初始化
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
void MonitorInit(void);

/*
***********************************************************************************************************************
* 函数名称: MonitorCycle
*
* 功能描述: 监控模块周期运行函数
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
void MonitorCycle(void);


#endif /* MONITOR_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/
