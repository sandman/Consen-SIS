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
*  文件名称    : Log.h
*
*  功能简介    :
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

#ifndef LOG_H_
#define LOG_H_

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
#define LOG_TYPE_CORE0                                     (0)
#define LOG_TYPE_CORE1                                     (1)
#define LOG_TYPE_USER                                      (2)

#define LOG_THRESHOLD_VAL                                  (500)

#define MAX_LOG_NUM                                        (10000U)
#define MAX_LOG_NUM_RETAIN                                 (10000U)
#define LOG_INDEX_VALID                                    (1U)
#define LOG_INDEX_INVALID                                  (0U)

#define LOG_SRAM_LOCK_FLAG_START_ADDR                      (0xFF650000)
#define LOG_SRAM_QUEUE_INFO_SEC5_START_ADDR                (0xFF650004)
#define LOG_SRAM_LOG_INFO_SEC5_START_ADDR                  (0xFF650100)
#define LOG_SRAM_LOG_INFO_SEC6_START_ADDR                  (0xFF660000)

#define LOG_SRAM_LOCK_FLAG1_START_ADDR                     (0xFF670000)
#define LOG_SRAM_QUEUE_INFO_SEC7_START_ADDR                (0xFF670004)
#define LOG_SRAM_LOG_INFO_SEC7_START_ADDR                  (0xFF670100)
#define LOG_SRAM_LOG_INFO_SEC8_START_ADDR                  (0xFF680000)

#define LOG_SRAM_LOCK_FLAG2_START_ADDR                     (0xFF690000)
#define LOG_SRAM_QUEUE_INFO_SEC9_START_ADDR                (0xFF690004)
#define LOG_SRAM_LOG_INFO_SEC9_START_ADDR                  (0xFF690100)
#define LOG_SRAM_LOG_INFO_SECA_START_ADDR                  (0xFF6A0000)


#define LOG_INFO_SEC5_START_INDEX                          (0U)
#define LOG_INFO_SEC5_MAX_INDEX                            (5000U)
#define LOG_INFO_SEC6_START_INDEX                          (5001U)
#define LOG_INFO_SEC6_MAX_INDEX                            (9999U)

#define LOG_INFO_SEC7_START_INDEX                          (0U)
#define LOG_INFO_SEC7_MAX_INDEX                            (5000U)
#define LOG_INFO_SEC8_START_INDEX                          (5001U)
#define LOG_INFO_SEC8_MAX_INDEX                            (9999U)

#define LOG_INFO_SEC9_START_INDEX                          (0U)
#define LOG_INFO_SEC9_MAX_INDEX                            (5000U)
#define LOG_INFO_SECA_START_INDEX                          (5001U)
#define LOG_INFO_SECA_MAX_INDEX                            (9999U)

#define READ_LOG_FROM_BEGINNING                            (0xFFFF)

#define LOG_QUEUE_UNLOCK                                   (0u)
#define LOG_QUEUE_LOCK                                     (1u)

/* 队列空或满 */
#define LOG_QUEUE_EMPTY                                    (0U)
#define LOG_QUEUE_NOT_EMPTY_NOT_FULL                       (1U)
#define LOG_QUEUE_FULL                                     (2U)

#define LOG_MAGIC_1                                        (0x1234)
#define LOG_MAGIC_2                                        (0x5678)

/* 队列被读空 */
#define LOG_QUEUE_IS_EMPTY_NOW                             (-1)
/* 队列中最后一条LOG记录 */
#define THE_LAST_LOG_IN_QUEUE                              (-2)
/* 因传参错误导致读取LOG失败 */
#define READ_LOG_QUEUE_FAILED                              (-3)
/* 共享内存被锁定 */
#define READ_LOG_QUEUE_LOCKED                              (-4)

#define LOG_DELAY_TIME_2US                                 (2U)

/* 设置报警标志 */
#define LOG_SET_ALARM                                      (1u)
/* 清除报警标志 */
#define LOG_CLR_ALARM                                      (0u)
/* ______________________________________________________
* | S | Sector 0 start addr(0xFF600000)             |   |
* | O | SOE0 SOE1 SOE2 SOE3 SOE4 ...                |   |
* | F | ...                                         |   |
* | T | SOE6552                                     |   |
* |   |---------------------------------------------| S |
* | S | Sector 1 start addr(0xFF610000)             | R |
* | O | SOE6553 SOE6554 SOE6555 ...                 | A |
* | E | ...                                         | M |
* |   | SOE9999                                     |   |
* |___|_____________________________________________|   |
* | H | Sector 2 start addr(0xFF620000)             |   |
* | A | SOE0 SOE1 SOE2 SOE3 SOE4 ...                |   |
* | R | ...                                         |   |
* | D | SOE5461                                     |   |
* |   |---------------------------------------------|   |
* | S | Sector 3 start addr(0xFF630000)             |   |
* | O | SOE5462 SOE5463 SOE5464 ...                 |   |
* | E | ...                                         |   |
* |   | SOE9999                                     |   |
* |___|_____________________________________________|   |
* | R | Sector 4 start addr(0xFF640000)             |   |
* | E | task0 retain data                           |   |
* | T | offset = 0                                  |   |
* | A | size = 1024 (3072 reserved)                 |   |
* | I | ...                                         |   |
* | N |---------------------------------------------|   |
* |   | task1 retain data                           |   |
* |   | offset = 4096                               |   |
* | D | size = 1024 (3072 reserved)                 |   |
* | A | ...                                         |   |
* | T |                                             |   |
* | A |                                             |   |
* |___|_____________________________________________|   |
* |   | Sector 5 start addr(0xFF650000)             |   |
* | L | Queue info struct                           |   |
* | O |---------------------------------------------|   |
* | G | start addr(0xFF650100)                      |   |
* |   | LOG0 LOG1 LOG2                              |   |
* | C | ...                                         |   |
* | O | LOG6500                                     |   |
* | R |---------------------------------------------|   |
* | E | Sector 6 start addr(0xFF660000)             |   |
* | 0 | LOG6501                                     |   |
* |   | ...                                         |   |
* |   | LOG9999                                     |   |
* |___|_____________________________________________|___|
* |   | Sector 7 start addr(0xFF670000)             |   |
* | L | Queue info struct                           |   |
* | O |---------------------------------------------|   |
* | G | start addr(0xFF670100)                      |   |
* |   | LOG0 LOG1 LOG2                              |   |
* | C | ...                                         |   |
* | O | LOG6500                                     |   |
* | R |---------------------------------------------|   |
* | E | Sector 8 start addr(0xFF680000)             |   |
* | 1 | LOG6501                                     |   |
* |   | ...                                         |   |
* |   | LOG9999                                     |   |
* |___|_____________________________________________|___|
* |   | Sector 9 start addr(0xFF690000)             |   |
* | L | Queue info struct                           |   |
* | O |---------------------------------------------|   |
* | G | start addr(0xFF690100)                      |   |
* |   | LOG0 LOG1 LOG2                              |   |
* | U | ...                                         |   |
* | S | LOG6500                                     |   |
* | E |---------------------------------------------|   |
* | R | Sector A start addr(0xFF6A0000)             |   |
* |   | LOG6501                                     |   |
* |   | ...                                         |   |
* |   | LOG9999                                     |   |
* |___|_____________________________________________|___|
*/
/*
***********************************************************************************************************************
*                                数据结构定义
***********************************************************************************************************************
*/
#pragma pack (4)
/*LOG结构体定义*/
typedef struct LogInfoTag
{
    uint32_t uiSec;    /*时间戳 相对起点走过的秒 起点：1970.01.01 00:00:00 */
    uint32_t uiMicroSec; /* 时间戳 -微秒 */
    uint32_t uiLogID;  /* 不同的ID代表不同的含义*/
}LogInfo_t;
#pragma pack ()

#pragma pack (2)
/*LOG队列结构体定义*/
typedef struct LogQueueTag
{
    uint16_t usMagic1;
    uint16_t usSize;     /* 队列大小 */
    uint16_t usHeader;   /* 队头*/
    uint16_t usRetainHeader;   /* 掉电保持队头*/
    uint16_t usTail;     /* 队尾 */
    uint16_t usQueueState;/* 队列空满状态标识 */
    uint16_t usAlarm;
    int32_t iReadIndex;
    uint16_t usMagic2;
}LogQueue_t;

#pragma pack ()

/*
***********************************************************************************************************************
*                                全局函数声明
***********************************************************************************************************************
*/
/*
***********************************************************************************************************************
* 函数名称: LogInit
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
void LogInit(void);

/*
***********************************************************************************************************************
* 函数名称: LogWrite
*
* 功能描述: 将1条LOG记录写入队列
*
* 输入参数: usLogID: 日志的id
*
* 输出参数: 无
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
void LogWrite(uint32_t usLogID);

/*
***********************************************************************************************************************
* 函数名称: LogRead
*
* 功能描述: 从队列读取一条日志
*
* 输入参数: pstLogInfo: 待存放日志的指针
*        usLogicPos: 队列中的逻辑位置(READ_LOG_FROM_BEGINNING 表示从开头读)
*
* 输出参数: puiNextIndex: 下一条记录的位置
*
* 返 回 值  : -1 队列已经为空
*        -2 最后一条LOG记录
*        -3 输入输出参数错误，读取失败
*        >=0 当前被读取的LOG记录在队列中的偏移
*
* 注意事项: 无
***********************************************************************************************************************
*/
int32_t LogRead(LogInfo_t *pstLogInfo, uint16_t usLogicPos, uint32_t uiLogType, puint32_t puiNextIndex);

/*
***********************************************************************************************************************
* 函数名称: LogInitCore0
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
void LogInitCore0(void);

/*
***********************************************************************************************************************
* 函数名称: LogWriteCore0
*
* 功能描述: 将1条LOG记录写入队列
*
* 输入参数: usLogID: 日志的id
*
* 输出参数: 无
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
void LogWriteCore0(uint32_t usLogID);

/*
***********************************************************************************************************************
* 函数名称: LogReadCore0
*
* 功能描述: 从队列读取一条日志
*
* 输入参数: pstLogInfo: 待存放日志的指针
*        usLogicPos: 队列中的逻辑位置(READ_LOG_FROM_BEGINNING 表示从开头读)
*
* 输出参数: puiNextIndex: 下一条记录的位置
*
* 返 回 值  : -1 队列已经为空
*        -2 最后一条LOG记录
*        -3 输入输出参数错误，读取失败
*        >=0 当前被读取的LOG记录在队列中的偏移
*
* 注意事项: 无
***********************************************************************************************************************
*/
int32_t LogReadCore0(LogInfo_t *pstLogInfo, uint16_t usLogicPos, puint32_t puiNextIndex);

/*
***********************************************************************************************************************
* 函数名称: LogInitCore1
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
void LogInitCore1(void);

/*
***********************************************************************************************************************
* 函数名称: LogWriteCore1
*
* 功能描述: 将1条LOG记录写入队列
*
* 输入参数: usLogID: 日志的id
*
* 输出参数: 无
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
void LogWriteCore1(uint32_t usLogID);

/*
***********************************************************************************************************************
* 函数名称: LogReadCore1
*
* 功能描述: 从队列读取一条日志
*
* 输入参数: pstLogInfo: 待存放日志的指针
*        usLogicPos: 队列中的逻辑位置(READ_LOG_FROM_BEGINNING 表示从开头读)
*
* 输出参数: puiNextIndex: 下一条记录的位置
*
* 返 回 值  : -1 队列已经为空
*        -2 最后一条LOG记录
*        -3 输入输出参数错误，读取失败
*        >=0 当前被读取的LOG记录在队列中的偏移
*
* 注意事项: 无
***********************************************************************************************************************
*/
int32_t LogReadCore1(LogInfo_t *pstLogInfo, uint16_t usLogicPos, puint32_t puiNextIndex);

/*
***********************************************************************************************************************
* 函数名称: LogInitUser
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
void LogInitUser(void);

/*
***********************************************************************************************************************
* 函数名称: LogWriteUser
*
* 功能描述: 将1条LOG记录写入队列
*
* 输入参数: usLogID: 日志的id
*
* 输出参数: 无
*
* 返 回 值  : 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
void LogWriteUser(uint32_t usLogID);

/*
***********************************************************************************************************************
* 函数名称: LogReadUser
*
* 功能描述: 从队列读取一条日志
*
* 输入参数: pstLogInfo: 待存放日志的指针
*        usLogicPos: 队列中的逻辑位置(READ_LOG_FROM_BEGINNING 表示从开头读)
*
* 输出参数: puiNextIndex: 下一条记录的位置
*
* 返 回 值  : -1 队列已经为空
*        -2 最后一条LOG记录
*        -3 输入输出参数错误，读取失败
*        >=0 当前被读取的LOG记录在队列中的偏移
*
* 注意事项: 无
***********************************************************************************************************************
*/
int32_t LogReadUser(LogInfo_t *pstLogInfo, uint16_t usLogicPos, puint32_t puiNextIndex);

/*
***********************************************************************************************************************
* 函数名称: SetLogAlarm
*
* 功能描述: 设置日志报警标志
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
void SetLogAlarm(void);

/*
***********************************************************************************************************************
* 函数名称: ClearLogAlarm
*
* 功能描述: 清除日志报警标志
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
void ClearLogAlarm(void);

/*
***********************************************************************************************************************
* 函数名称: GetLogAlarm
*
* 功能描述: 获取日志报警标志
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
uint16_t GetLogAlarm(void);

#endif /* LOG_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/

