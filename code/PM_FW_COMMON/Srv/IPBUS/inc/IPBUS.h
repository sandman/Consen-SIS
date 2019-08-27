﻿/*
***********************************************************************************************************************
*                  Copyright(c) 北京康吉森技术有限公司 2015
*           Beijing Consen Technologies Co.,Ltd. All rights reserved.
*
*
*  项目名称    :
*
*  模块名称    :
*
*  文件名称    : IPBUS.h
*
*  功能简介    : IPBUS协议相关处理
*
*  作者        : 朱耿华
*
*  创建日期    : 2016-06-10
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/
#ifndef IPBUS_H_
#define IPBUS_H_

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
/* IPBUS初始化 */
#define IPBUS_INIT_VALUE              (1U)      /* IPBUS初始化值 */
#define IPBUS_RESET_MASTER_VALUE      (0U)      /* IPBUS主卡复位值 */
/* slave模块槽位范围 */
#define IPBUS_MAX_SLAVE_NO            (239U)
#define IPBUS_MIN_SLAVE_NO            (4U)
#define IPBUS_SLAVE_MAX_NUM           (236)    /* IO模块的最大个数 */
#define IPBUS_MODULE_MAX_NUM          (240)     /* IPBUS模块的最大个数。0-2：PM；3：CM；4-239；IO*/
/* 数据区或邮箱权限 */
#define IPBUS_RIGHTS_FREE             (0U)
#define IPBUS_RIGHTS_BUSY             (1U)
/* 公共返回值 */
#define IPBUS_RET_OK                  (0U)       /* 公共返回值OK */
#define IPBUS_RET_NORIGHT             (1U)       /* 公共返回值无权限 */
#define IPBUS_RET_NOTOK               (2U)       /* 公共返回值NOT OK */
/* 寄存器长度，单位字节 */
#define IPBUS_REG_SIZE                (2U)
/* IPBUS主卡地址 */
#define IPBUS_MASTER_ADDR             (240U)
/* IPBUS周期轮询时间 */
#define IPBUS_POLLING_INTERVAL        (50U)
/*从站使能标志长度，单位字节*/
#define IPBUS_SLAVE_ENABLE_BUFSIZE    (32U)
/*从站使能标志BUF号*/
#define IPBUS_SLAVE_ENABLE_BUF0       (0U)
#define IPBUS_SLAVE_ENABLE_BUF1       (1U)
/*从站在线状态*/
#define IPBUS_SLAVE_OFFLINE           (0U)      /* 该从站离线 */
#define IPBUS_SLAVE_ONLINE            (1U)      /* 该从站在线 */
/*从站数据有效状态*/
#define IPBUS_SLAVE_INVALID           (0U)      /* 该从站数据无效 */
#define IPBUS_SLAVE_VALID             (1U)      /* 该从站数据有效 */
/*从站数据有效状态*/
#define IPBUS_SLAVE_NOCONFIG          (0U)      /* 该从站未配置 */
#define IPBUS_SLAVE_CONFIG            (1U)      /* 该从站已配置 */
/*应用层是否完成配置状态*/
#define IPBUS_APP_NOCONFIG_DEVICE     (0U)      /* 应用层未完成设备层配置 */
#define IPBUS_APP_CONFIG_DEVICE       (1U)      /* 应用层完成设备层配置 */
/*应用层离线在线状态*/
#define IPBUS_APP_OFFLINE             (0U)      /* 应用层离线 */
#define IPBUS_APP_ONLINE              (1U)      /* 应用层在线 */
/*设备层是否完成配置状态*/
#define IPBUS_DEVICE_NOCONFIG_SLAVE   (0U)      /* 设备层未完成从站配置 */
#define IPBUS_DEVICE_CONFIG_SLAVE     (1U)      /* 设备层完成从站配置 */
/*设备层离线在线状态*/
#define IPBUS_DEVICE_OFFLINE          (0U)      /* 设备层离线 */
#define IPBUS_DEVICE_ONLINE           (1U)      /* 设备层在线 */

/* 应用层状态 */
#define APP_STATE_OFFLINE           0x0000      /* 应用层离线 */
#define APP_STATE_STOP              0x0001      /* 应用层停止状态 */
#define APP_STATE_CONFIG            0x0010      /* 应用层配置状态 */
#define APP_STATE_RUN               0x0100      /* 应用层运行状态 */
/* 设备层状态 */
#define DEVICE_STATE_OFFLINE        0x0000      /* 设备层离线 */
#define DEVICE_STATE_STOP           0x0001      /* 设备层停止状态 */
#define DEVICE_STATE_CONFIG         0x0010      /* 设备层配置状态 */
#define DEVICE_STATE_RUN            0x0100      /* 设备层运行状态 */
/* 应用层标志掩码 */
#define APP_ACTIVE_MASK             0x0001      /* 应用层在线标志 */
#define APP_CONFIG_MASK             0x0002      /* 应用层完成配置标志 */
#define APP_PRMRAM_MASK             0x0020      /* 参数区选择标志 */
#define APP_RESET_MASK              0x8000      /* 复位标志 */
/* 设备层标志掩码 */
#define DEVICE_ACTIVE_MASK          0x0001      /* 设备层在线标志 */
#define DEVICE_CONFIG_MASK          0x0002      /* 设备层完成配置标志 */
/* 应用层设备层共用掩码 */
#define DATARAM_MASK                0x0004      /* 数据区权限判断标志 */
#define MAILSEND_MASK               0x0008      /* 发送邮箱权限判断标志 */
#define MAILRECEIVE_MASK            0x0010      /* 接收邮箱权限判断标志 */

/*
***********************************************************************************************************************
*                                数据结构定义
***********************************************************************************************************************
*/
#pragma pack(1)

/* 应用层邮箱协议头 */
typedef struct IPBUSAPPMailHeaderTag
{
    uint16_t usMailRX;             /* 收件人 */
    uint16_t usMailTX;             /* 发件人 */
    uint16_t usMailNR;             /* 消息号 */
    uint16_t usMailSlaveAddr;      /* 消息地址 */
    uint16_t usMailFunc;           /* 消息服务码 */
    uint16_t usMailLN;             /* 消息长度 */
    uint16_t usMailACK;            /* 消息应答请求 */
    uint16_t usMailFault;          /* 消息错误码 */
}IPBUSAPPMailHeader_t;

typedef struct IPBUSMailDataTag
{
    uint8_t ucIndex;
    uint16_t usDataLen;
    uint8_t ucData[497];

}IPBUSMailData_t;


#pragma pack ()

/*
***********************************************************************************************************************
*                                全局函数声明
***********************************************************************************************************************
*/
/*
***********************************************************************************************************************
* 函数名称: IPBUSRamInit
*
* 功能描述: IPBUS初始化，初始化需要用户初始化的寄存器
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
void IPBUSDualRamInit(void);

/*
***********************************************************************************************************************
* 函数名称: IPBUSMailSend
*
* 功能描述: 邮箱发送操作
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
uint8_t IPBUSMailSend(uint8_t ucMailSend[], IPBUSAPPMailHeader_t *pstMailHeader);

/*
***********************************************************************************************************************
* 函数名称: IPBUSMailRecv
*
* 功能描述: 邮箱接收操作
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
uint8_t IPBUSMailRecv(uint8_t ucMailRecv[], IPBUSAPPMailHeader_t *pstMailHeader);

/*
***********************************************************************************************************************
* 函数名称: IPBUSGetDataRAMRight
*
* 功能描述: 获取IPBUS主卡数据区权限状态
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
uint8_t IPBUSGetDataRAMRight(void);

/*
***********************************************************************************************************************
* 函数名称: IPBUSReleaseDataRAMRight
*
* 功能描述: 释放IPBUS主卡数据区RAM权限
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
void IPBUSReleaseDataRAMRight(void);

/*
***********************************************************************************************************************
* 函数名称: IPBUSGetSendMailRight
*
* 功能描述: 获取IPBUS主卡发送邮箱区权限状态
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
uint8_t IPBUSGetSendMailRight(void);

/*
***********************************************************************************************************************
* 函数名称: IPBUSReleaseSendMailRight
*
* 功能描述: 释放IPBUS主卡发送邮箱区权限
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
void IPBUSReleaseSendMailRight(void);

/*
***********************************************************************************************************************
* 函数名称: IPBUSGetRecieveMailRight
*
* 功能描述: 获取IPBUS主卡接收邮箱区权限状态
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
uint8_t IPBUSGetRecieveMailRight(void);

/*
***********************************************************************************************************************
* 函数名称: IPBUSReleaseRecieveMailRight
*
* 功能描述: 释放IPBUS主卡接收邮箱区权限
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
void IPBUSReleaseRecieveMailRight(void);

/*
***********************************************************************************************************************
* 函数名称: IPBUSSetMasterAddr
*
* 功能描述: 设置主站地址
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
void IPBUSSetMasterAddr(void);

/*
***********************************************************************************************************************
* 函数名称: IPBUSSetRollingInterval
*
* 功能描述: 设置周期轮询时间
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
void IPBUSSetRollingInterval(void);

/*
***********************************************************************************************************************
* 函数名称: IPBUSSetSlaveDelayMin
*
* 功能描述: 设置最小从站延迟时间
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
void IPBUSSetSlaveDelayMin(uint16_t usDelayTime);

/*
***********************************************************************************************************************
* 函数名称: IPBUSSetSlaveDelayMax
*
* 功能描述: 设置最大从站延迟时间
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
void IPBUSSetSlaveDelayMax(uint16_t usDelayTime);

/*
***********************************************************************************************************************
* 函数名称: IPBUSSetSlaveAckTimeout
*
* 功能描述: 设置从站应答超时时间
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
void IPBUSSetSlaveAckTimeout(uint16_t usTimeout);

/*
***********************************************************************************************************************
* 函数名称: IPBUSSetMasterMailTimeout
*
* 功能描述: 设置非周期轮询应答超时时间
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
void IPBUSSetMasterMailTimeout(uint16_t usTimeout);

/*
***********************************************************************************************************************
* 函数名称: IPBUSSetRetransmissionNumber
*
* 功能描述: 设置最大重传次数
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
void IPBUSSetRetransmissionNumber(uint16_t usNumber);

/*
***********************************************************************************************************************
* 函数名称: IPBUSGetFaultConter
*
* 功能描述: 读取总线故障计数器
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
uint16_t IPBUSGetFaultConter(void);

/*
***********************************************************************************************************************
* 函数名称: IPBUSSetWatchdogTimeout
*
* 功能描述: 设置看门狗超时时间
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
void IPBUSSetWatchdogTimeout(uint16_t usTimeout);

/*
***********************************************************************************************************************
* 函数名称: IPBUSMonitorMasterWatchdog
*
* 功能描述: 根据看门狗监视主卡
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
uint16_t IPBUSMonitorMasterWatchdog(void);

/*
***********************************************************************************************************************
* 函数名称: IPBUSSetAPPState
*
* 功能描述: 设置应用层状态
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
void IPBUSSetAPPState(uint16_t usState);

/*
***********************************************************************************************************************
* 函数名称: IPBUSGetAPPState
*
* 功能描述: 读取应用层状态
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
uint16_t IPBUSGetAPPState(void);

/*
***********************************************************************************************************************
* 函数名称: IPBUSGetDeviceState
*
* 功能描述: 读取设备层状态
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
uint16_t IPBUSGetDeviceState(void);

/*
***********************************************************************************************************************
* 函数名称: IPBUSResetMaster
*
* 功能描述: 复位主卡
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
void IPBUSResetMaster(void);

/*
***********************************************************************************************************************
* 函数名称: IPBUSSetPrmBufID
*
* 功能描述: 设置应用层标志bit5，即使用的参数区ID号
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
void IPBUSSetPrmBufID(uint8_t ucBufID);

/*
***********************************************************************************************************************
* 函数名称: IPBUSSetAPPConfigDeviceFlag
*
* 功能描述: 设置应用层标志bit1，即设置是否完成设备层配置
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
void IPBUSSetAPPConfigDeviceFlag(uint8_t ucConfigFlag);

/*
***********************************************************************************************************************
* 函数名称: IPBUSSetAPPOnlineFlag
*
* 功能描述: 设置应用层标志bit0，即应用层离线在线标志
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
void IPBUSSetAPPOnlineFlag(uint8_t ucOnlineFlag);

/*
***********************************************************************************************************************
* 函数名称: IPBUSGetDeviceConfigSlaveFlag
*
* 功能描述: 读取设备层标志bit1，即判断设备层是否完成从站配置
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
uint8_t IPBUSGetDeviceConfigSlaveFlag(void);

/*
***********************************************************************************************************************
* 函数名称: IPBUSGetDeviceOnlineFlag
*
* 功能描述: 读取设备层标志bit0，即判断设备层离线在线状态
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
uint8_t IPBUSGetDeviceOnlineFlag(void);

/*
***********************************************************************************************************************
* 函数名称: IPBUSAcylicWrite
*
* 功能描述: IPBUS非周期写操作
*
* 输入参数: 无
*       ucSlaveAddr: 从站号
*       ucParDataAdd:参数数据地址
*       ucParDataLen:参数数据长度
*       ucParDataLen:参数数据长度
*
* 输出参数: 无
*
* 返 回 值: 无
*
* 注意事项: 无
***********************************************************************************************************************
*/
/*邮箱具体处理待定*/
uint8_t IPBUSAcylicWrite(void);

/*
***********************************************************************************************************************
* 函数名称: IPBUSAcylicRead
*
* 功能描述: IPBUS非周期读操作
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
/*邮箱具体处理待定*/
uint8_t IPBUSAcylicRead(void);

/*
***********************************************************************************************************************
* 函数名称: IPBUSSetSlaveRollingList
*
* 功能描述: 填写从站周期轮询列表
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
void IPBUSSetSlaveRollingList(uint8_t ucData[], uint32_t uiSize);

/*
***********************************************************************************************************************
* 函数名称: IPBUSSetSlaveEnableBuf
*
* 功能描述: 填写从站使能标志
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
void IPBUSSetSlaveEnableBuf(uint8_t ucData[], uint8_t ucBufID);

/*
***********************************************************************************************************************
* 函数名称: IPBUSGetSlaveOnlineState
*
* 功能描述: 获取从站在线状态
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
uint8_t IPBUSGetSlaveOnlineState(uint8_t ucSlaveNo);

/*
***********************************************************************************************************************
* 函数名称: IPBUSGetSlaveValidState
*
* 功能描述: 获取从站数据有效无效状态
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
uint8_t IPBUSGetSlaveValidState(uint8_t ucSlaveNo);

/*
***********************************************************************************************************************
* 函数名称: IPBUSGetSlaveConfigState
*
* 功能描述: 获取从站参数配置完成标志
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
uint8_t IPBUSGetSlaveConfigState(uint8_t ucSlaveNo);

/*
***********************************************************************************************************************
* 函数名称: IPBUSSetSlavePRMChange
*
* 功能描述: 填写在线下装从站参数变化标志
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
void IPBUSSetSlavePRMChange(uint8_t ucData[]);

/*
***********************************************************************************************************************
* 函数名称: IPBUSSetSlaveInputAddr
*
* 功能描述: 设置单个从站输入区基地址
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
void IPBUSSetSlaveInputAddr(uint16_t usSlaveNo, uint16_t usInputAddr);

/*
***********************************************************************************************************************
* 函数名称: IPBUSSetSlaveInputLen
*
* 功能描述: 设置单个从站输入区长度
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
void IPBUSSetSlaveInputLen(uint16_t usSlaveNo, uint16_t usInputLen);

/*
***********************************************************************************************************************
* 函数名称: IPBUSSetSlaveOutputAddr
*
* 功能描述: 设置单个从站输出区基地址
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
void IPBUSSetSlaveOutputAddr(uint16_t usSlaveNo, uint16_t usOutputAddr);

/*
***********************************************************************************************************************
* 函数名称: IPBUSSetSlaveOutputLen
*
* 功能描述: 设置单个从站输入区长度
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
void IPBUSSetSlaveOutputLen(uint16_t usSlaveNo, uint16_t usOutputLen);

/*
***********************************************************************************************************************
* 函数名称: IPBUSSetSlavePrmAddr
*
* 功能描述: 设置单个从站参数区基地址
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
void IPBUSSetSlavePrmAddr(uint16_t usSlaveNo, uint16_t usPrmAddr, uint8_t ucBufID);

/*
***********************************************************************************************************************
* 函数名称: IPBUSSetSlavePrmLen
*
* 功能描述: 设置单个从站参数区基地址
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
void IPBUSSetSlavePrmLen(uint16_t usSlaveNo, uint16_t usPrmLen, uint8_t ucBufID);

#endif /* IPBUS_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/
