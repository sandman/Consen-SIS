﻿/*
*********************************************************************************************************************** 
*                  Copyright(c) 北京康吉森技术有限公司 2015
*           Beijing Consen Technologies Co.,Ltd. All rights reserved.
*                                  
*                                  
*  项目名称    : 安全控制系统
*
*  模块名称    : SOE软件应用模块
*
*  文件名称    : SOE.h
*
*  功能简介    : 处理SOE软件命令和相关配置
*
*  作者        : 王东
*
*  创建日期    : 2016-02-04
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

#ifndef SOE_H_
#define SOE_H_

/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/
#include "Sys/inc/Sys.h"
#include "Sys/inc/DataType.h"
#include "ExterComm/inc/ComCommon.h"
#include "ExterComm/inc/ExterComm.h"
#include "ExterComm/inc/PCSWCommon.h"

/*
***********************************************************************************************************************
*                                宏定义
***********************************************************************************************************************
*/

#define DEBUG_SWSOE

#define DEBUG_OUT_SOE

#ifdef DEBUG_OUT_SOE
#define DEBUG_SOE(format, args...)  printf ("DB_SOE: ") ; printf(format, ##args)
#else
#define DEBUG_SOE(format, args...)
#endif

#define SOE_PM_TIMEOUT_CYCLE_CNT  (2000/8)       /* PM应答SOE命令的超时拍数：2000ms */
#define SOE_SW_TIMEOUT_CYCLE_CNT  (30*1000/8)    /* SOE软件超时拍数: 30s */

/******************** 通信服务相关开始 ********************/
/* Request Message Type Range */
#define SOE_ATYPE_MIN       (1501)  /* Minimum */
#define SOE_ATYPE_MAX       (2000)  /* Maximum */

/* Request Message Type：CM Handle */
#define SOE_LOGIN           (1501)  /* 登录服务 */
#define SOE_LOGOUT          (1502)  /* 退出登录服务 */

/* Request Message Type：PM Handle */
#define SOE_READ            (1503)  /* 读SOE数据服务 */
#define SOE_CLEAR           (1504)  /* 清除SOE数据服务*/

/******************** 通信服务相关结束 ********************/

/*
***********************************************************************************************************************
*                                数据结构定义
***********************************************************************************************************************
*/

/* SOE Info.  SOE软件信息 */
typedef struct SOEInfoTag
{
    NetworkPortType_t emNetwork;    /* Network           网口号 */
    uint32_t uiIPAddr;              /* IP Address        数据源的IP地址 */
    uint16_t usPort;                /* Port              数据源的端口号 */
    uint8_t ucAccAuth;              /* Access Authority  访问权限 */
    uint8_t ucReserve;              /* Reserve           预留 */
    LogStatus_t emLog;              /* Log Status 登录状态 */
    SelPMID_t emSelPMID;            /* Selected PM ID  已选取的PM模块的编号 */
    uint32_t uiWaitReqCycleCnt;     /* 已等待软件请求的拍数 */
}SOEInfo_t;


/*
***********************************************************************************************************************
*                                全局函数声明
***********************************************************************************************************************
*/

/*
***********************************************************************************************************************
* 函数名称: SOEInit
*
* 功能描述: 模块初始化函数
*
* 输入参数: 无
*
* 输出参数: 无
*
* 返 回 值: 无
*
* 注意事项: 无
***********************************************************************************************************************
*/

void SOEInit( void );

/*
***********************************************************************************************************************
* 函数名称: SOECycle
*
* 功能描述: 模块周期运行函数
*
* 输入参数: 无
*
* 输出参数: 无
*
* 返 回 值: 无
*
* 注意事项: 无
***********************************************************************************************************************
*/

void SOECycle( void );

#endif /*SOE_H_*/

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/


