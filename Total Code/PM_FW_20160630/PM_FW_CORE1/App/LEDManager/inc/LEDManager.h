﻿/*
*********************************************************************************************************************** 
*                  Copyright(c) 北京康吉森技术有限公司 2015
*           Beijing Consen Technologies Co.,Ltd. All rights reserved.
*
*
*  项目名称    : 安全控制系统
*
*  模块名称    : 状态灯管理模块
*
*  文件名称    : LEDManager.h
*
*  功能简介    :
*
*  作者       : 李琦
*
*  创建日期    : 2016-04-28
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

#ifndef LED_MANAGER_H_
#define LED_MANAGER_H_

/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/
#include "inc/DataType.h"


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
* 函数名称: LEDManagerInit
*
* 功能描述: 状态灯管理初始化
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
void LEDManagerInit(void);

/*
***********************************************************************************************************************
* 函数名称: LEDManagerCycle
*
* 功能描述: 状态灯管理周期运行函数
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
void LEDManagerCycle(void);



#endif /* LED_MANAGER_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/
