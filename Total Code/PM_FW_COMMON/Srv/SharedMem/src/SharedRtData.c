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
*  文件名称    : SharedRtData.h
*
*  功能简介    : core0与core1间的共享实时数据
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

/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/
#include <Srv/Scheduler/include/string.h>
#include "../inc/SharedRtData.h"

/*
***********************************************************************************************************************
*                                局部变量声明
***********************************************************************************************************************
*/
SharedRTDataArea_t g_stSharedRtData;

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
* 函数名称: SharedRtDataInit
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
void SharedRtDataInit(void)
{
    /* 初始化 */
    memset((puint8_t) &g_stSharedRtData, 0 , sizeof(SharedRTDataArea_t));

    memset((puint8_t)&g_stSharedRtData.stAppend.ucModBusCtrl[0], 0x01, sizeof(uint8_t)* MAX_MODBUS_CTRL_INFO);
    memset((puint8_t)&g_stSharedRtData.stAppend.ucP2PCtrl[0], 0x01, sizeof(uint8_t)* MAX_P2P_CTRL_INFO);

    g_stSharedRtData.bLock = RTDATA_AREA_UNLOCKED;
    g_stSharedRtData.bStatus = RTDATA_AREA_WRITE_ONLY;
    return;
}

/*
***********************************************************************************************************************
* 函数名称: SysGetSharedMemRtDataStartAddr
*
* 功能描述: 获取共享内存的实时数据区首地址
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
puint8_t SysGetSharedMemRtDataStartAddr(SysRtDataType_t emDataType)
{
    puint8_t pStartAddr = NULL;

    switch(emDataType)
    {
        case RT_DATA_TYPE_G:
        {
           pStartAddr = &(g_stSharedRtData.ucG[0]);
        }
        break;

        case RT_DATA_TYPE_I:
        {
           pStartAddr = &(g_stSharedRtData.ucI[0]);
        }
        break;

        case RT_DATA_TYPE_Q:
        {
           pStartAddr = &(g_stSharedRtData.ucQ[0]);
        }
        break;

        default:
        break;
    }

    return pStartAddr;
}

/*
***********************************************************************************************************************
* 函数名称: SysGetSharedMemAppendInfoStartAddr
*
* 功能描述: 获取共享内存的附加区首地址
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
puint8_t SysGetSharedMemAppendInfoStartAddr(void)
{
    puint8_t pStartAddr = NULL;

    pStartAddr = (puint8_t)&(g_stSharedRtData.stAppend);

    return pStartAddr;
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
