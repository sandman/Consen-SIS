/*
***********************************************************************************************************************
*                  Copyright(c) 北京康吉森技术有限公司 2015
*           Beijing Consen Technologies Co.,Ltd. All rights reserved.
*
*
*  项目名称    : 安全控制系统
*
*  模块名称    :
*
*  文件名称    : CommSysComm.c
*
*  功能简介    :
*
*  作者            : 刘阳
*
*  创建日期    : 2016-04-28
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
#include "../inc/CommSysCommon.h"


/*
***********************************************************************************************************************
*                                局部变量声明
***********************************************************************************************************************
*/
work_status_t emWorkStatus[NUM_OF_PM];


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
* 函数名称: SysGetLocalPMID
*
* 功能描述: 获取本地PM的ID
*
* 输入参数: 无
*
* 输出参数: 无
*
* 返 回 值  : 本地PM的ID
*
* 注意事项: 无
***********************************************************************************************************************
*/
PMController_t SysGetLocalPMID(void)
{
    PMController_t emPMID;
    
    emPMID = SharedGetLocalPMID();

    return emPMID;
}

/*
***********************************************************************************************************************
* 函数名称: SysGetNextPMID
*
* 功能描述: 获取后一系PM ID号
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
PMController_t SysGetNextPMID(PMController_t emLocalPMId)
{
    PMController_t emPMID;

    emPMID = (PMController_t)((emLocalPMId + 1U) % NUM_OF_PM);

    return emPMID;
}
/*
***********************************************************************************************************************
* 函数名称: SysGetPrePMID
*
* 功能描述: 获取前一系PM ID号
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
PMController_t SysGetPrePMID(PMController_t emLocalPMId)
{
    PMController_t emPMID;

    emPMID = (PMController_t)((emLocalPMId + NUM_OF_PM - PMB) % NUM_OF_PM);

    return emPMID;
}
/*
***********************************************************************************************************************
* 函数名称: SysGetWorkStatus
*
* 功能描述: 获取指定PM的工作状态
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
work_status_t SysGetWorkStatus(PMController_t emPMId)
{
    work_status_t emWork_Status = WS_OFFLINE ;
    
    if(emPMId < NUM_OF_PM)
    {
        emWork_Status = emWorkStatus[emPMId];
    }
    
    return emWork_Status;
}
/*
***********************************************************************************************************************
* 函数名称: SysSetWorkStatus
*
* 功能描述: 设置指定PM的工作状态
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
void SysSetWorkStatus(PMController_t emPMId, work_status_t emWork_Status)
{
    
    if((emPMId < NUM_OF_PM)&& (emWork_Status < MAX_WORK_STATUS))
    {
        emWorkStatus[emPMId] = emWork_Status;
    }
    
    return;
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
