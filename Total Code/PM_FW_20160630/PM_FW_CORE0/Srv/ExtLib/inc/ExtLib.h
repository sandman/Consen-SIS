﻿/*
*********************************************************************************************************************** 
*                  Copyright(c) 北京康吉森技术有限公司 2015
*           Beijing Consen Technologies Co.,Ltd. All rights reserved.
*
*
*  项目名称    : 安全控制系统
*
*  模块名称    : 算法库模块
*
*  文件名称    : ExtLib.c
*
*  功能简介    : 外部库（TON，TOF等）
*
*  作者            : 李琦
*
*  创建日期    : 2016-05-03
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

#ifndef EXT_LIB_H_
#define EXT_LIB_H_

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
#define MAX_FUNC_NAME_LEN           28


/*
***********************************************************************************************************************
*                                数据结构定义
***********************************************************************************************************************
*/

typedef double_t (*fp)(double_t x);

typedef struct ExtLibMathTableTag
{
    char_t cName[MAX_FUNC_NAME_LEN];
    fp pFunc;
}ExtLibMathTable;

/*
***********************************************************************************************************************
*                                全局函数声明
***********************************************************************************************************************
*/




#endif /* EXT_LIB_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/

