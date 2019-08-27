/*
***********************************************************************************************************************
*                  Copyright(c) 北京康吉森技术有限公司 2015
*           Beijing Consen Technologies Co.,Ltd. All rights reserved.
*
*
*  项目名称    : 安全控制系统
*
*  模块名称    : 系统资源管理模块
*
*  文件名称    : SysStateMngt.c
*
*  功能简介    : 系统资源管理模块中的状态管理模块，供其他状态管理功能相关模块调用
*
*  作者            : 刘阳
*
*  创建日期    : 2016-04-04
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
#include "../inc/SysStateMngt.h"

/*
***********************************************************************************************************************
*                                局部变量声明
***********************************************************************************************************************
*/
static SysAjustSyncTime_t s_stSysAjustSyncTime[NUM_OF_PM];

static PMController_t s_emWaitPMId = INVALID_PM_ID;

SysPMStateInfo_t s_stPMStateInfo[NUM_OF_PM];

static sys_state_t s_emSysState = SYS_STABLE_STATE;

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
* 函数名称: SysStateMngtInit
*
* 功能描述: 初始化函数。
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
void SysStateMngtInit(void)
{
    memset(&s_stSysAjustSyncTime[0], 0x00, sizeof(SysAjustSyncTime_t)*NUM_OF_PM);
    memset(&s_stPMStateInfo[0], 0x00, sizeof(SysPMStateInfo_t)*NUM_OF_PM);
    s_emWaitPMId = INVALID_PM_ID;
    s_emSysState = SYS_STABLE_STATE;
}
/*
***********************************************************************************************************************
* 函数名称: SysSetAjustTimerEn
*
* 功能描述: 设置是否使能校时。
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
void SysSetAjustTimerEn(PMController_t emPMId, ajust_status_t emAjustEn)
{
    SysPMStateInfo_t* pstPMState = NULL;
    pstPMState = SysGetPMStateInfo(emPMId);
    if(pstPMState != NULL)
    {
        pstPMState->stAjustSyncTime.emAjustEn = emAjustEn;
    }

    return;
}

/*
***********************************************************************************************************************
* 函数名称: SysGetAjustTimerEn
*
* 功能描述: 获取是否使能校时。
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
ajust_status_t SysGetAjustTimerEn(PMController_t emPMId )
{
    ajust_status_t emAjustEn = AJUST_DISEN;
    SysPMStateInfo_t* pstPMState = NULL;
    pstPMState = SysGetPMStateInfo(emPMId);
    if(pstPMState != NULL)
    {
        emAjustEn = pstPMState->stAjustSyncTime.emAjustEn;
    }

    return emAjustEn;
}


/*
***********************************************************************************************************************
* 函数名称: SysGetWaitPMId
*
* 功能描述: 获取等待控制器ID。
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
PMController_t SysGetWaitPMId(void)
{
    PMController_t emRetPMId = INVALID_PM_ID;

    emRetPMId = s_emWaitPMId;

    return emRetPMId;
}
/*
***********************************************************************************************************************
* 函数名称: SysSetWaitPMId
*
* 功能描述: 设置等待控制器ID。
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
void SysSetWaitPMId(PMController_t emPMId)
{
    s_emWaitPMId = emPMId;

    return;
}

/*
***********************************************************************************************************************
* 函数名称: SysGetPMState
*
* 功能描述: 获取指定PM的状态信息。
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
SysPMStateInfo_t* SysGetPMStateInfo(PMController_t emPMId)
{
    SysPMStateInfo_t* pPMState = NULL;
    
    if(emPMId < NUM_OF_PM)
    {
        pPMState = (SysPMStateInfo_t*)&s_stPMStateInfo[emPMId];
    }

    return pPMState;
}
/*
***********************************************************************************************************************
* 函数名称: SysGetPrjInfo
*
* 功能描述: 获取指定PM当前使用的工程信息。
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
PrjInfo_t* SysGetPrjInfo(PMController_t emPMId)
{
    PrjInfo_t* pPrjInfo = NULL;
    
    if(emPMId < NUM_OF_PM)
    {
        pPrjInfo = (PrjInfo_t*)&s_stPMStateInfo[emPMId].stPrjInfo;
    }

    return pPrjInfo;
}
/*
***********************************************************************************************************************
* 函数名称: SysGetDownLoadPrjInfo
*
* 功能描述: 获取指定PM当前下装的工程（未生效）信息。
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
PrjInfo_t* SysGetDownLoadPrjInfo(PMController_t emPMId)
{
    PrjInfo_t* pPrjInfo = NULL;
    
    if(emPMId < NUM_OF_PM)
    {
        pPrjInfo = (PrjInfo_t*)&s_stPMStateInfo[emPMId].stDLPrjInfo;
    }

    return pPrjInfo;
}


/*
***********************************************************************************************************************
* 函数名称: SysSetState
*
* 功能描述: 设置系统状态。
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
void SysSetState(sys_state_t emSysState)
{
    if((SYS_STABLE_STATE == emSysState) || (SYS_UNSTABLE_STATE == emSysState))
    {
        s_emSysState = emSysState;
    }
    
    return;
}
/*
***********************************************************************************************************************
* 函数名称: SysGetState
*
* 功能描述: 获取系统状态。
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
sys_state_t SysGetState(void)
{
    return s_emSysState;
}
/*
***********************************************************************************************************************
* 函数名称: SysGetPrjFileExist
*
* 功能描述: 获取系统状态。
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
uint32_t SysGetPrjFileExist(void)
{
    uint32_t uiPrjFileExistFlg = PRG_FILE_EXIST;
    
    return uiPrjFileExistFlg;
}

/*
***********************************************************************************************************************
* 函数名称: SysGetConfigStatus
*
* 功能描述: 获取工程是否进行过配置，是否存在配置信息状态。
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
uint32_t SysGetConfigStatus(PMController_t emPMId)
{
    uint8_t ucConfigStatus = 0U;
    
    if(emPMId < NUM_OF_PM)
    {
        ucConfigStatus = s_stPMStateInfo[emPMId].stPrjInfo.ucIsConfigured;
    }
    
    return ucConfigStatus;
}

/*
***********************************************************************************************************************
* 函数名称: SysSetConfigStatus
*
* 功能描述: 设置工程是否进行过配置，是否存在配置信息状态。
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
void SysSetConfigStatus(PMController_t emPMId, uint8_t ucConfigStatus)
{
    
    if((emPMId < NUM_OF_PM) && \
       ((NOT_HAS_BE_CONFIGURED == ucConfigStatus) || (HAS_BE_CONFIGURED == ucConfigStatus)))
    {
        s_stPMStateInfo[emPMId].stPrjInfo.ucIsConfigured = ucConfigStatus;
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
