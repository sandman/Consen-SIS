﻿/*
*********************************************************************************************************************** 
*                  Copyright(c) 北京康吉森技术有限公司 2015
*           Beijing Consen Technologies Co.,Ltd. All rights reserved.
*
*
*  项目名称    : 安全控制系统
*
*  模块名称    : 共享内存
*
*  文件名称    : SharedMem.h
*
*  功能简介    : core0与core1间的共享内存
*
*  作者            : 李琦
*
*  创建日期    : 2016-04-15
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

#ifndef SHARED_MEM_H_
#define SHARED_MEM_H_

/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/
#include "inc/DataType.h"
#include "inc/Hardware.h"
#include "SharedComm.h"
#include "SharedConfig.h"
#include "SharedRtData.h"
#include "SharedPRG.h"
#include "LED.h"

/*
***********************************************************************************************************************
*                                宏定义
***********************************************************************************************************************
*/
#define get_cpu_no() (*(volatile unsigned int *)(0xffe40090))

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
* 函数名称: SharedMemInit
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
void SharedMemInit(void);

#endif /* SHARED_MEM_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/
