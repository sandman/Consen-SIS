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
*  文件名称    : SysSync.h
*
*  功能简介    :
*
*  作者            : 刘阳
*
*  创建日期    : 2016-03-23
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

#ifndef SYS_SYNC_H_
#define SYS_SYNC_H_

/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/
#include "SysCommon.h"
#include "SysCfgFile.h"
#include "Srv/CommProtocol/inc/PMBusProtocol.h"
#include"../../../../PM_FW_COMMON/inc/DataType.h"
#include "../../../../PM_FW_COMMON/Srv/Sys/inc/CommSysSync.h"
#include "../../../../PM_FW_COMMON/Srv/Sys/inc/CommSysStateMngt.h"
#include "../../../../PM_FW_COMMON/Srv/PMBUS/inc/PMBUS.h"
#include "../../../../PM_FW_COMMON/Srv/SharedMem/inc/SharedMem.h"

/*
***********************************************************************************************************************
*                                宏定义
***********************************************************************************************************************
*/
/* sync (100us unit)*/
/* 同步服务任务数目 */
#define SYNC_SRV_TASKS_NUM              (20U)
/* 同步工程任务数目 */
#define SYNC_PRJ_TASKS_NUM              (1U)
/* 服务激活时间 */
#define SYNC_RELATIVE_ACTIVE_TIME       (5000U)
/* 服务超时时间 */
#define SYNC_RELATIVE_TIMEOUT_TIME      (1000U)
/* 动态处理时间 */
#define SYNC_DYNAMIC_TIMEOUT            (5U)
/* 看门狗余量时间 (200us) */
#define SYNC_WD_MARGIN                  (2U)
/* 任务调度启动时间 (6ms) */
#define SYNC_USER_TASK_STARTTIME        (60U)
/* 用于计算任务调度启动时间 的基础时间 */
#define SYNC_USER_TASK_BASETIME         (53U)
/* 同步任务延时节拍数 */
#define SYNC_TASK_DELAYCYCLES           (2U)
/*任务调度启动时间根据数据区实际使用大小调整，每3K加0.1ms*/
#define SYNC_DATA_BASE_LEN              (3*1024U)

/* 队列头位置初始值 */
#define SYS_QUEUE_HEAD_INIT             (0x0000U)
/* 队列尾位置初始值 */
#define SYS_QUEUE_TAIL_INIT             (0x0000U)
#define SYS_QUEUE_NULL                  (0x00000000U)
#define SYS_QUEUE_NOFULL                (0x00000000U)
#define SYS_QUEUE_FULL                  (0x00000001U)
#define SYS_QUEUE_NOEMPTY               (0x00000000U)
#define SYS_QUEUE_EMPTY                 (0x00000001U)
#define SYS_QUEUE_NOEXIST               (0x00000000U)
#define SYS_QUEUE_EXIST                 (0x00000001U)

#define SYNC_TIME_OUT                   (0xFFFFFFFFU)
#define SYNC_TIME_AJUST_OK              (0x00000001U)
#define SYNC_TIME_AJUST_NOTOK           (0x00000000U)

#define SYNC_SRV_DATA_LEN               (8000U)

/* 服务不需要处理 */
#define SRV_NOT_NEED_PROCESS            (0x00000000U)
/* 服务需要处理 */
#define SRV_NEED_PROCESS                (0x00000001U)



/* 容许同步时间校准 */
#define SYS_AJUST_SYNCTIME_READY        (0x00000001U)
/* 不容许同步时间校准 */
#define SYS_AJUST_SYNCTIME_NOREADY      (0x00000000U)
#define SYS_AJUST_DELAY_START           (0x00000000U)
#define SYS_AJUST_DELAYING              (0x00000001U)
#define SYS_AJUST_DELAY_END             (0x00000002U)

/* 判断是否有数据 */
#define CPU_HAS_IO_DATA                 (0U)            /* 判断有IO数据                 */
#define CPU_NO_IO_DATA                  (1U)            /* 判断没有IO数据               */
#define CPU_ERR_IO_DATA                 (2U)            /* IO数据有错误                 */
#define CPU_HAS_STAT_DATA               (0U)            /* 判断有状态数据               */
#define CPU_NO_STAT_DATA                (1U)            /* 判断没有状态数据             */
#define CPU_ERR_STAT_DATA               (2U)            /* 状态数据有错误               */

/*
***********************************************************************************************************************
*                                数据结构定义
***********************************************************************************************************************
*/

/* 服务数据子类型*/
typedef enum
{
    CS1131_SRV = 0x00000000U,                           /* 服务数据子类型:CS1131服务 id = 0 */
    OPC_SRV,                                            /* 服务数据子类型:OPC服务 id = 1 */
    P2P_SRV,                                            /* 服务数据子类型:P2P服务 id = 2 */
    MODBUS_SRV,                                         /* 服务数据子类型:Modbus服务 id = 3 */
    SOE_SRV,                                            /* 服务数据子类型:Modbus服务 id = 4 */
    CTRL_SRV,                                           /* 服务数据子类型:PM间服务 id = 5 */
    NUM_OF_SRVTYPE,                                     /* 服务数据子类型个数*/
    NOT_USED
}srv_srvdata_type_t;
/* 同步任务 */
typedef enum
{
    SYS_BROADCAST_CTRLDATA = 0x00000000U,               /* 同步任务:广播PM状态数据 */
    SYS_BROADCAST_CS1131SRV,                            /* 同步任务:广播CS1131服务数据 */
    SYS_BROADCAST_OPCSRV,                               /* 同步任务:广播OPC服务数据 */
    SYS_BROADCAST_P2PSRV,                               /* 同步任务:广播P2P服务数据 */
    SYS_BROADCAST_MODBUSSRV,                            /* 同步任务:广播Modbus服务数据 */
    SYS_REQUEST_ACTIVE,                                 /* 同步任务:请求激活 */
    SYS_RECV_REALDATA,                                  /* 同步任务:接收实时数据 */
    SYS_SEND_REALDATA,                                  /* 同步任务:发送实时数据 */
    SYS_RECV_FILE,                                      /* 同步任务:接收文件数据 */
    SYS_SEND_FILE,                                      /* 同步任务:发送文件数据 */
    SYS_PAUSE,                                          /* 同步任务:系统暂停，用于同步实时数据前使整个系统处于暂停状态*/
    SYS_CONTINUE,                                       /* 同步任务:系统继续，用于系统暂停之后的恢复 */
    SYS_LAST_SRV_CANCEL,                                /* 同步任务:取消上次同步服务 */
    SYS_TASK_ID_NULL
}sync_task_id_t;

/* 当前同步任务状态 */
typedef enum
{
    TASK_SEND = 0x00000000U,                            /* 任务状态: 同步任务发送 */
    TASK_FILE,                                          /* 任务状态: 同步文件 */
    TASK_INCRE_FILE,                                    /* 任务状态: 增量同步文件 */
    TASK_G_DATA,                                        /* 任务状态: 同步G区数据 */
    TASK_I_DATA,                                        /* 任务状态: 同步I区数据 */
    TASK_Q_DATA,                                        /* 任务状态: 同步Q区数据 */
    TASK_WAITACK,                                       /* 任务状态: 等待应答 */
    TASK_FILE_COMPLETE,                                 /* 任务状态: 同步文件完成，接收方存储文件（Flash），发送方停止运算等待发送实时数据*/
    TASK_COMPLETE                                       /* 任务状态: 同步完成 */
}sync_task_stat_t;

/* 同步任务延迟发送*/
typedef enum
{
    TASK_NOWAIT = 0x00000000U,                          /* 状态:立即发送 */
    TASK_WAIT                                           /* 状态:延迟发送 */
}sync_task_wait_t;

/* 同步记录状态初始化 */
typedef enum
{
    SYNC_DATA_INIT = (0x00000000U),                        /* 同步记录状态初始化 */
    SYNC_DATA_NOINIT                                       /* 同步记录状态不初始化 */
}sync_data_init_t;





typedef enum
{
    NO_JOIN_REQ_ACTIVE = 0x00000000U,                   /* NO handle active = 0 */
    JOIN_REQ_ACTIVE                                     /* need handle active = 1 */
}Join_req_status_t;


/* 校时状态 */
typedef enum
{
    TIMER_SLAVE = 0x00000000U,                            /* 状态:校时客户端 = 0 */
    TIMER_MASTER                                          /* 状态:校时服务器 = 1 */
}timer_status_t;

/* 请求激活标志 */
typedef enum
{
    AJUST_EN = 0x00000000U,                               /* ajust timer enable = 0 */
    AJUST_DISEN                                           /* ajust timer disable = 1 */
}ajust_status_t;

//typedef struct SyncTimeD32Tag
//{
//    uint32_t uiHigh32b;                                    /* the high 32 bits of sync (us) timer */
//    uint32_t uiLow32b;                                    /* the low 32 bits of sync (us) timer */
//}SyncTimeD32_t;

//typedef union SyncTime64Tag
//{
//    SyncTimeD32_t stTimeStruct;                          /* double 32 bits struct */
//    ulong64_t ullTime;                                   /* 64 bits value */
//}SyncTime64_t;
typedef struct SysSyncTaskTag
{
    /* 同步任务目的PM ID号 */
    PMController_t emPMId;
    /* 同步任务来源CM ID号*/
    CMController_t emCMId;
    /* 任务号 */
    sync_task_id_t emTaskId;
    /* 任务状态 */
    sync_task_stat_t emTaskStatus;
    /* 任务等待标识 */
    sync_task_wait_t emTaskWait;
    

}SysSyncTask_t;

typedef struct SysSyncSrvQueueTag
{
    /* 同步任务队列任务数 */
    uint32_t uiTaskNum;
    /* 队列头 */
    uint16_t usHead;
    /* 队列尾 */
    uint16_t usTail;
    /* 任务队列元素 */
    SysSyncTask_t stSysSyncTask[SYNC_SRV_TASKS_NUM];
    
}SysSyncSrvQueue_t;

typedef struct SysSyncPrjQueueTag
{
    /* 同步任务队列任务数 */
    uint32_t uiTaskNum;
    /* 队列头 */
    uint16_t usHead;
    /* 队列尾 */
    uint16_t usTail;
    /* 任务队列元素 */
    SysSyncTask_t stSysSyncTask[SYNC_PRJ_TASKS_NUM];
}SysSyncPrjQueue_t;

typedef struct SysJoinReqStatusTag
{
    /* 新PM请求加入标识 */
    Join_req_status_t emJoinReqFlag;
    /* 激活时间 */
    SyncTime64_t unActiveTime;
    /* 同步超时时间 */
    SyncTime64_t unTimeOutTime;
}SysJoinReqStatus_t;



//typedef struct SysActiveStatusTag
//{
//    /* 新PM请求加入标识 */
//    Join_req_status_t emActiveFlag;
//    /* 激活时间 */
//    SyncTime64_t unActiveTime;
//    /* 同步超时时间 */
//    SyncTime64_t unTimeOutTime;
//}SysActiveStatus_t;


/*
***********************************************************************************************************************
*                                全局函数声明
***********************************************************************************************************************
*/
/*
***********************************************************************************************************************
* 函数名称: SysGetSyncSrvQueue
*
* 功能描述: 获取同步任务队列指针。
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
SysSyncSrvQueue_t* SysGetSyncSrvQueue(void);

/*
***********************************************************************************************************************
* 函数名称: SysSyncSrvQueueExist
*
* 功能描述: 查找指定同步任务是否已在同步任务队列。。
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
uint32_t SysSyncSrvQueueExist(sync_task_id_t emTaskId);

/*
***********************************************************************************************************************
* 函数名称: SysSyncSrvQueueEmpty
*
* 功能描述: 同步任务队列是否为空。
*
* 输入参数: pstSyncSrvQueue    任务队列指针
*
* 输出参数: uiRet           若队列为空 SYS_QUEUE_EMPTY 否则 SYS_QUEUE_NOEMPTY
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
uint32_t SysSyncSrvQueueEmpty(const SysSyncSrvQueue_t* pstSyncSrvQueue);

/*
***********************************************************************************************************************
* 函数名称: SysSyncSrvQueueFind
*
* 功能描述: 查找指定同步任务是否已在同步任务队列，若存在将其填充到指定地址中。
*
* 输入参数: pstSyncTask     同步任务信息
*
* 输出参数:
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
void SysSyncSrvQueueFind(sync_task_id_t emTaskId, SysSyncTask_t* pstSyncTask);

/*
***********************************************************************************************************************
* 函数名称: SysDeSyncSrvQueue
*
* 功能描述: 队首元素出队。
*
* 输入参数: pstSyncSrvQueue    任务队列指针
*
* 输出参数: 无
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
void SysDeSyncSrvQueue(SysSyncSrvQueue_t* pstSyncSrvQueue);

/*
***********************************************************************************************************************
* 函数名称: SysSyncSrvQueueUpdate
*
* 功能描述: 更新同步任务的任务状态。
*
* 输入参数: emTaskStatus             任务状态
*
* 输出参数: 无
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
void SysSyncSrvQueueUpdate(sync_task_stat_t emTaskStatus);

/*
***********************************************************************************************************************
* 函数名称: SysSyncSrvQueueWait
*
* 功能描述: 设置同步任务等待标识。
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
void SysSyncSrvQueueWait(sync_task_wait_t emTaskWait);

/*
***********************************************************************************************************************
* 函数名称: SysSyncSrvQueueFull
*
* 功能描述: 
*
* 输入参数: pstSyncSrvQueue    任务队列指针
*
* 输出参数: 无
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
uint32_t SysSyncSrvQueueFull(const SysSyncSrvQueue_t* pstSyncQueue);
/*
***********************************************************************************************************************
* 函数名称: SysClearSyncSrvQueue
*
* 功能描述: 清空任务同步队列中目的地址为某一PM的任务。
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
void SysClearSyncSrvQueue(SysSyncSrvQueue_t* pstSyncQueue, PMController_t emPMId);


/*
***********************************************************************************************************************
* 函数名称: BspDiffSyncTime
*
* 功能描述: 计算时间差。
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
uint32_t SysDiffSyncTime(const SyncTime64_t* punSyncOldTime, const SyncTime64_t* punSyncCurTime);

/*
***********************************************************************************************************************
* 函数名称: SysGetSyncDataInit
*
* 功能描述: 获取同步记录信息是否初始化标识。
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
sync_data_init_t SysGetSyncDataInit(void);
/*
***********************************************************************************************************************
* 函数名称: SysSetSyncDataInit
*
* 功能描述: 设置同步记录信息是否初始化标识。
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
void SysSetSyncDataInit(sync_data_init_t emDataInit);
/*
***********************************************************************************************************************
* 函数名称: SysGetTimerStatus
*
* 功能描述: 获取同步时钟主从状态。
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
timer_status_t SysGetTimerStatus(PMController_t emPMId);
/*
***********************************************************************************************************************
* 函数名称: SysGetSyncTime
*
* 功能描述: 获取同步时钟值。
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
void SysGetSyncTime(SyncTime64_t* punSyncTime);
/*
***********************************************************************************************************************
* 函数名称: SysCalRelativeTime
*
* 功能描述: 计算绝对时间函数，根据当前时间及时间间隔计算出下一个绝对时间。
*
* 输入参数: punCalTime               计算结果
*        punCurTime               当前时间
*        uiIntervalTime           时间间隔
*
* 输出参数: 无
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
void SysCalRelativeTime(SyncTime64_t* punCalTime, const SyncTime64_t* punCurTime, uint32_t uiIntervalTime);
/*
***********************************************************************************************************************
* 函数名称: SysGetSrvInfo
*
* 功能描述: 获取来自某CM指定类型服务相关数据指针。
*
* 输入参数:
*
* 输出参数: pstRetSysSrvInfo         服务相关数据指针
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
SysSrvInfo_t* SysGetSrvInfo(CMController_t emCMID, srv_srvdata_type_t emSrvType);

SysJoinReqStatus_t* SysGetActiveInfo(void);


/*
***********************************************************************************************************************
* 函数名称: SysGetSyncPrjQueue
*
* 功能描述: 获取同步任务队列指针。
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

SysSyncPrjQueue_t* SysGetSyncPrjQueue(void);
/*
***********************************************************************************************************************
* 函数名称: SysSyncPrjQueueExist
*
* 功能描述: 查找指定同步任务是否已在同步任务队列。。
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
uint32_t SysSyncPrjQueueExist(sync_task_id_t emTaskId);

/*
***********************************************************************************************************************
* 函数名称: SysSyncPrjQueueEmpty
*
* 功能描述: 同步任务队列是否为空。
*
* 输入参数: pstSyncPrjQueue    任务队列指针
*
* 输出参数: uiRet           若队列为空 SYS_QUEUE_EMPTY 否则 SYS_QUEUE_NOEMPTY
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
uint32_t SysSyncPrjQueueEmpty(const SysSyncPrjQueue_t* pstSyncPrjQueue);

/*
***********************************************************************************************************************
* 函数名称: SysSyncPrjQueueFront
*
* 功能描述: 获取同步任务队列队首的同步任务信息。
*
* 输入参数: pstSyncPrjQueue    任务队列指针
*
* 输出参数: pstSyncTask     同步任务信息
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
void SysSyncPrjQueueFront(SysSyncPrjQueue_t* pstSyncPrjQueue, SysSyncTask_t* pstSyncTask);

/*
***********************************************************************************************************************
* 函数名称: SysSyncPrjQueueFind
*
* 功能描述: 查找指定同步任务是否已在同步任务队列，若存在将其填充到指定地址中。
*
* 输入参数: pstSyncTask     同步任务信息
*
* 输出参数:
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
void SysSyncPrjQueueFind(sync_task_id_t emTaskId, SysSyncTask_t* pstSyncTask);

/*
***********************************************************************************************************************
* 函数名称: SysDeSyncPrjQueue
*
* 功能描述: 队首元素出队。
*
* 输入参数: pstSyncPrjQueue    任务队列指针
*
* 输出参数: 无
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
void SysDeSyncPrjQueue(SysSyncPrjQueue_t* pstSyncPrjQueue);
/*
***********************************************************************************************************************
* 函数名称: SysSyncPrjQueueFull
*
* 功能描述: 
*
* 输入参数: pstSyncPrjQueue    PRJ队列指针
*
* 输出参数: 无
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
uint32_t SysSyncPrjQueueFull(const SysSyncPrjQueue_t* pstSyncQueue);
/*
***********************************************************************************************************************
* 函数名称: SysEnSyncPrjQueue
*
* 功能描述: 将同步任务放入同步队列。
*
* 输入参数: pstSyncPrjQueue    任务队列指针
*
* 输出参数: 无
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
void SysEnSyncPrjQueue(SysSyncPrjQueue_t* pstSyncPrjQueue, SysSyncTask_t* pstSyncTask);
/*
***********************************************************************************************************************
* 函数名称: SysSyncPrjQueueUpdate
*
* 功能描述: 更新同步任务的任务状态。
*
* 输入参数: emTaskStatus             任务状态
*
* 输出参数: 无
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
void SysSyncPrjQueueUpdate(sync_task_stat_t emTaskStatus);

/*
***********************************************************************************************************************
* 函数名称: SysSyncPrjQueueWait
*
* 功能描述: 设置同步任务等待标识。
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
void SysSyncPrjQueueWait(sync_task_wait_t emTaskWait);

/*
***********************************************************************************************************************
* 函数名称: SysClearSyncPrjQueue
*
* 功能描述: 清空工程同步队列中目的地址为某一PM的任务。
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
void SysClearSyncPrjQueue(SysSyncPrjQueue_t* pstSyncQueue, PMController_t emPMId);

#endif /* SYS_SYNC_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/

