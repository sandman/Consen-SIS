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
*  文件名称    : LogID.h
*
*  功能简介    :
*
*  作者            : 王东
*
*  创建日期    : 2017-02-14
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

#ifndef OPCLOGID_H_
#define OPCLOGID_H_

/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/

/*
***********************************************************************************************************************
*                                宏定义
***********************************************************************************************************************
*/

/*
*  前10位基址在该文件定义，后22位在其它.h文件中定义 (注意： 按照图中的格式对后22位进行使用)
* ______________________________________________________________________________
* |      log ID 格式规划                                                                                                                          |
* |_____________________________________________________________________________|
* |  主模块号（8bit）                |错误等级 （2bit）|文件号（6bit） |错误号 （16bit）              |
* |-----------------------------------------------------------------------------|
* | AMS:      0x00         | 0-致命   1-严重    |             |                     |
* | Client:   0x01         | 2-一般   3-提示    |             |                     |
* | CommonLib:0x02         |               |             |                     |
* | Config:   0x03         |               |             |                     |
* | CS1131:   0x04         |               |             |                     |
* | Diag:     0x05         |               |             |                     |
* | ExterComm:0x06         |               |             |                     |
* | GPS:      0x07         |               |             |                     |
* | InterComm:0x08         |               |             |                     |
* | LED:      0x09         |               |             |                     |
* | Log:      0x0A         |               |             |                     |
* | Modbus:   0x0B         |               |             |                     |
* | Monitor:  0x0C         |               |             |                     |
* | NTP:      0x0D         |               |             |                     |
* | OPC:      0x0E         |               |             |                     |
* | P2P:      0x0F         |               |             |                     |
* | SOE:      0x10         |               |             |                     |
* | Sys:      0x11         |               |             |                     |
* | Task:     0x12         |               |             |                     |
* | Version:  0x13         |               |             |                     |
* |___________________|_____________|___________|______________________________|
*/

/* ------------  L0: 致命  ----------------------------------------------------*/
/*#define LOG_ID_OPC_LEVEL0                    (0x0E000000U)*/
#define LOGID_OPC_E_SWTO                       (0x0E000000U)
#define LOGID_OPC_E_MAKE_RESP                  (0x0E000001U)
//#define LOGID_OPC_E_ACCESS                     (0x0E000002U)
//#define LOGID_OPC_E_ACCESS_DENY                (0x0E000003U)
//#define LOGID_OPC_E_ACCESS_RO                  (0x0E000004U)
//#define LOGID_OPC_E_NOTLOGIN                   (0x0E000005U)
//#define LOGID_OPC_E_CMBUS                      (0x0E000006U)
//#define LOGID_OPC_E_SW_SRCADDR                 (0x0E000007U)

#define LOGID_OPC_E_CFG_VAR_TABLE              (0x0E000010U)
#define LOGID_OPC_E_CFG_NET                    (0x0E000011U)
//#define LOGID_OPC_E_CFG_VAR_TABLE_COPYING      (0x0E000012U)

//#define LOGID_OPC_E_CMD                        (0x0E000020U)
#define LOGID_OPC_E_CMD_ACTUAL_TYPE            (0x0E000021U)
//#define LOGID_OPC_E_CMD_PASSWORD_LEN           (0x0E000022U)
//#define LOGID_OPC_E_CMD_PASSWORD_CONTENT       (0x0E000023U)

#define LOGID_OPC_E_RESP_PM_TIMEOUT            (0x0E000040U)
#define LOGID_OPC_E_RESP_EXCOMM_SEND           (0x0E000041U)

#define LOGID_OPC_E_SYS_SET_MSG                (0x0E000060U)
#define LOGID_OPC_E_SYS_GET_RTDATA_ADDR        (0x0E000061U)
#define LOGID_OPC_E_SYS_RST_LOCK               (0x0E000062U)
#define LOGID_OPC_E_SYS_SET_LOCK               (0x0E000063U)
#define LOGID_OPC_E_SYS_RST_CONN               (0x0E000064U)
#define LOGID_OPC_E_SYS_SET_CONN               (0x0E000065U)
#define LOGID_OPC_E_SYS_SET_CLR                (0x0E000066U)

//#define LOGID_OPC_E_NET_NOT_WRITEABLE          (0x0E000080U)
#define LOGID_OPC_E_COPY_OPC_VAR_TABLE         (0x0E000081U)
//#define LOGID_OPC_E_ADD_ONLINE_DATA            (0x0E000082U)



/* ------------  L1: 严重  ----------------------------------------------------*/
/*#define LOG_ID_OPC_LEVEL1                    (0x0E400000U)*/



/* ------------  L2: 一般  ----------------------------------------------------*/
/*#define LOG_ID_OPC_LEVEL2                    (0x0E800000U)*/
//#define LOGID_OPC_E_CM_NOCFG                   (0x0E800000U)


/* ------------  L3: 提示  ----------------------------------------------------*/
/*#define LOG_ID_OPC_LEVEL3                    (0x0EC00000U)*/
#define LOGID_OPC_CFG_SWITCH_ACCESS_CTRL       (0x0EC00000U)
#define LOGID_OPC_CFG_SWITCH_NET               (0x0EC00001U)
#define LOGID_OPC_CFG_SWITCH_VAR_TABLE         (0x0EC00002U)

/*
***********************************************************************************************************************
*                                数据结构定义
***********************************************************************************************************************
*/

/*
***********************************************************************************************************************
*                                全局函数声明
***********************************************************************************************************************
*/

#endif /* OPCLOGID_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/

