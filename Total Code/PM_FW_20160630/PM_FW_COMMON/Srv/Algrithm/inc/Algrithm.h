﻿/*
*********************************************************************************************************************** 
*                  Copyright(c) 北京康吉森技术有限公司 2015
*           Beijing Consen Technologies Co.,Ltd. All rights reserved.
*
*
*  项目名称    : 安全控制系统
*
*  模块名称    : 通用算法模块
*
*  文件名称    : Algrithm.h
*
*  功能简介    : 通用算法(CRC算法、哈希算法等)
*
*  作者            : 李琦
*
*  创建日期    : 2015-12-31
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

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
* 函数名称: SysCrc32Cal
*
* 功能描述: 计算CRC32
*
* 输入参数: uiCrc: 基值
*        pucBuf: 指向待计算的数组的起始地址
*        uiLen: 数据个数
*
* 输出参数: 无
*
* 返 回 值  : CRC32
*
* 注意事项: 无
***********************************************************************************************************************
*/
uint32_t SysCrc32Cal(uint32_t uiCrc, const puint8_t pucBuf, uint32_t uiCount);

/*
***********************************************************************************************************************
* 函数名称: SysCrc16Cal
*
* 功能描述: 计算CRC16
*
* 输入参数: pucBuf: 指向待计算的数组的起始地址
*        usCount: 数据个数
*
* 输出参数: 无
*
* 返 回 值  : CRC16
*
* 注意事项: 无
***********************************************************************************************************************
*/
uint16_t SysCrc16Cal(const puint8_t pucBuf, uint16_t usCount);

#endif /* ALGORITHM_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/

