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
*  文件名称    : Manager.c
*
*  功能简介    : 
*
*  作者          : 李琦
*
*  创建日期    : 2016-04-13
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
#include "../inc/Manager.h"
#include "../inc/Key.h"
#include "../inc/Watchdog.h"
#include "App/LEDManager/inc/LEDManager.h"
#include "App/ProjectConfig/inc/Config.h"
#include "App/SysStateManager/inc/StateMngt.h"
#include "App/Sync/inc/Sync.h"
/*
***********************************************************************************************************************
*                                局部变量声明
***********************************************************************************************************************
*/


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
* 函数名称: ManagerInit
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
void ManagerInit(void)
{
    StateMngtInit();
    KeyManagerInit();
    LEDManagerInit();
    ConfigInit();
    SyncInit();
    WatchdogManagerInit();
}

/*
***********************************************************************************************************************
* 函数名称: ManagerCycle
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
void ManagerCycle(void)
{
    SysStateMngt();
    KeyManagerCycle();
    LEDManagerCycle();
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
