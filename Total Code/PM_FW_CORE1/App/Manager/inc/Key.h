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
*  文件名称    : Key.h
*
*  功能简介    :
*
*  作者            : 李琦
*
*  创建日期    : 2016-06-14
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

#ifndef KEY_H_
#define KEY_H_

/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/
#include "inc/DataType.h"
#include "inc/Hardware.h"
#include "App/Main/inc/Task.h"
/*
***********************************************************************************************************************
*                                宏定义
***********************************************************************************************************************
*/
#ifdef CONTROL_CYCLE_20MS
#define KEY_FILTER_TIME      (150U)
#endif

#ifdef CONTROL_CYCLE_5MS
#define KEY_FILTER_TIME      (600U)
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
* 函数名称: KeyManagerInit
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
void KeyManagerInit(void);

/*
***********************************************************************************************************************
* 函数名称: KeyManagerCycle
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
void KeyManagerCycle(void);

#endif /* KEY_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/

