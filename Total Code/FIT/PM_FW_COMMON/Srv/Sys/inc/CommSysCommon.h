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
*  文件名称    : CommSysCMConfig.h
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

#ifndef COMMSYSCOMM_H_
#define COMMSYSCOMM_H_

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

/* 系统第一次进行状态管理 */
#define SYS_FIRST_IN                (0x00000001U)
/* 系统非第一次进行状态管理 */
#define SYS_NOFIRST_IN              (0x00000000U)

#define BITMASK(n)                  (1U<<(n))

/*
***********************************************************************************************************************
*                                数据结构定义
***********************************************************************************************************************
*/
/* PM的ID */
typedef enum SysPMControllerTag
{
    PMA = 0x00,
    PMB,
    PMC,
    NUM_OF_PM,
    INVALID_PM_ID
} PMController_t;

/* CM的ID */
typedef enum SysCMControllerTag
{
    CM1 = 0x00,
    CM2,
    CM3,
    CM4,
    NUM_OF_CM,
    INVALID_CM_ID
} CMController_t;

/* 配置文件类型 */
typedef enum SysCfgFileTypeTag
{
    CFG_CTRL_STATION = 0x00,
    CFG_PRG,
    CFG_IO_MODULAR,
    CFG_SOE,
    CFG_P2P,
    CFG_MODBUS_MASTER,
    CFG_MODBUS_SLAVE,
    CFG_VOTE,
    CFG_RETAIN,
    CFG_OPC,
    CFG_CM,
    NUM_OF_CFG_FILE_TYPE,
    INVALID_CFG_FILE_TYPE
} SysCfgFileType_t;

/* 配置文件处理顺序 */
typedef enum 
{
    PS_PRG = 0x00,
    PS_CM,
    PS_IO_MODULAR,
    PS_SOE,
    PS_P2P,
    PS_MODBUS_MASTER,
    PS_MODBUS_SLAVE,
    PS_VOTE,
    PS_RETAIN,
    PS_OPC,
    PS_CTRL_STATION,
    NUM_OF_PS_FILE
    
}SysFileProcessSeq_t;

typedef enum
{
    NOT_ACTIVE = 0x00000000,                /*配置块未使用*/
    ACTIVE = 0x00aa00bb                     /*配置块被使用*/
}ActiveFlag_t;

typedef enum
{
    FILE_CM = 0,                         /*CM 配置文件*/
    FILE_MODBUS_MASTER,                  /*Modbus主配置文件*/
    FILE_MODBUS_SLAVE,                   /*Modbus从配置文件*/
    FILE_OPC,                            /*OPC 配置文件*/
    FILE_CTRL_STATION,                   /*控制站配置文件*/
    FILE_SOE,                            /*SOE配置文件*/
    FILE_P2P,                            /*Peer To Peer 配置文件*/
    FILE_VOTE,                           /*VOTE 配置文件*/
    FILE_IO_MODULAR,                     /*IO配置文件（硬件配置文件）*/
    FILE_RETAIN,                         /*RETAIN 配置文件*/
    FILE_PRG,                            /*PRG文件*/
    MAX_FILE_NUM                         /*最大文件个数*/
}File_ID_t;

typedef enum
{
    TASK_UP1 = 0,                           /*UP1任务ID*/
    TASK_UP2,                               /*UP2任务ID*/
    MAX_TASK_NUM                            /*最大任务个数*/
}Task_ID_t;

/* PM工作状态 */
typedef enum
{
    WS_OFFLINE = 0x00000000U,                           /* 工作状态: 离线 = 0 */
    WS_STANDBY,                                         /* 工作状态: 备用 = 1 */
    WS_WORK,                                            /* 工作状态: 停止 = 2 */
    MAX_WORK_STATUS,                                    /* max work status */
    WS_INVALID_TYPE
}work_status_t;

/* PM内各任务的状态 */
typedef enum
{
    TS_INIT = 0x00000000U,                              /* 任务状态: 初始化（无此任务配置信息） = 0 */
    TS_STOP,                                            /* 任务状态: 停止 = 1 */
    TS_RUN,                                             /* 任务状态: 运行 = 2 */
    TS_PAUSE,                                           /* 任务状态: 暂停 = 3 */
    MAX_TASK_STATUS                                     /* max task status */
}task_status_t;

/* PM同步的状态 */
typedef enum
{
    SS_NOSYNC = 0x00000000U,                            /* 工程同步状态: PM没有在进行工程同步 = 0 */
    SS_SYNC,                                            /* 工程同步状态: PM在进行工程同步 = 1 */
}sync_status_t;

/* PM上电标志 */
typedef enum
{
    PM_POWERON = 0x00000000U,                            /* PM上电状态: PM上电 = 0 */
    PM_CYCLE,                                            /* PM上电状态: PM周期循环 = 1 */
}poweron_flg_t;

typedef enum
{
    KS_INIT = 0x00000000U,
    KS_PROGRAM = 0x02U,
    KS_RUN = 0x04U,
    KS_STOP = 0x06,
    KS_INVALID_TYPE = 0xFFU
    
}Key_Switch_Type_t;

/*
***********************************************************************************************************************
*                                全局函数声明
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
PMController_t SysGetLocalPMID(void);
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
PMController_t SysGetNextPMID(PMController_t emLocalPMId);
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
PMController_t SysGetPrePMID(PMController_t emLocalPMId);

/*
***********************************************************************************************************************
* 函数名称: SysGetCfgFileType
*
* 功能描述: 根据文件处理序号获取文件的ID
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
SysCfgFileType_t SysGetCfgFileType(SysFileProcessSeq_t emFileProcessSeq);
/*
***********************************************************************************************************************
* 函数名称: SysGetBin1Num
*
* 功能描述: 获取接收应答结果
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
uint32_t SysGetBin1Num(uint32_t uiValue);


#endif /* COMMSYSCOMM_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/

