﻿/*
*********************************************************************************************************************** 
*                  Copyright(c) 北京康吉森技术有限公司 2015
*           Beijing Consen Technologies Co.,Ltd. All rights reserved.
*
*
*  项目名称    : 安全控制系统
*
*  模块名称    : 系统资源管理模块
*
*  文件名称    : SysConfig.h
*
*  功能简介    :
*
*  作者        : 李琦
*
*  创建日期    : 2015-12-31
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

#ifndef SYS_CONFIG_H_
#define SYS_CONFIG_H_

/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/
#include "DataType.h"
#include "CMconfig.h"

/*
***********************************************************************************************************************
*                                宏定义
***********************************************************************************************************************
*/
#define SYS_CLR_RECV_CONFIGINFO_DONE                (0x00)
#define SYS_RECV_CONFIGINFO_DONE                    (0x01)


/*
***********************************************************************************************************************
*                                数据结构定义
***********************************************************************************************************************
*/
typedef struct ExtCommNetConfigInfoTag
{
    ActiveFlag_t emActive;
    bool_t bUpdate;
    uint8_t ucReserve[3];
    uint32_t  uiIPAddr;             /* 端口IP地址：NET 1默认值：192.168.1.0；NET 2默认值：192.168.1.1。*/
    uint32_t  uiSubnetMask;         /* 子网掩码，默认值：255.255.255.0 */
    uint32_t  uiGateway;            /* 默认网关，默认值：0.0.0.0 典型地，此参数为网络路由器的IP地址  */
}ExtCommNetConfigInfo_t;

typedef struct OPCNetConfigInfoTag
{
    ActiveFlag_t emActive;
    bool_t bUpdate;
    bool_t bPortWriteEnable;
    uint8_t ucReserve[2];
}OPCNetConfigInfo_t;

typedef struct ExtCommModbusTCPConfigInfoTag
{
    ActiveFlag_t emActive;
    bool_t bUpdate;
    uint8_t ucProtocol;
    uint8_t ucReserve[2];
    uint32_t  uiIPAddr;
}ExtCommModbusTCPConfigInfo_t;

/*
***********************************************************************************************************************
*                                全局函数声明
***********************************************************************************************************************
*/
/*
***********************************************************************************************************************
* 函数名称: SysConfigInit
*
* 功能描述: 静态变量初始化
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
void SysConfigInit(void);


/*
***********************************************************************************************************************
* 函数名称: SysGetAccCtrlInfo
*
* 功能描述: 获取访问控制信息
*
* 输入参数: 无
*
* 输出参数: pstAccCtrlInfo: 指向访问控制信息结构体变量的指针
*
* 返 回 值  : 获取访问控制信息成功则返回TRUE
*        获取访问控制信息失败则返回FALSE
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysGetAccCtrlInfo(AccessCtrlConfigInfo_t *pstAccCtrlInfo);

/*
***********************************************************************************************************************
* 函数名称: SysGetNetworkConfigInfo
*
* 功能描述: 获取本CM的某网络通讯端口的配置信息
*
* 输入参数: emType:指定的网络通讯口
*
* 输出参数: pstNetworkParam: 指向配置信息的结构体变量
*
* 返 回 值  : 获取配置信息成功则返回TRUE
*        获取配置信息失败则返回FALSE
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysGetNetworkConfigInfo(NetworkPortType_t emType, NetConfigInfo_t *pstNetworkParam);

/*
***********************************************************************************************************************
* 函数名称: SysGetCOMConfigInfo
*
* 功能描述: 获取本CM的某串口的配置信息
*
* 输入参数: emType:指定的串口
*
* 输出参数: pstCOMConfigInfo: 指向配置信息的结构体变量
*
* 返 回 值  : 获取配置信息成功则返回TRUE
*        获取配置信息失败则返回FALSE
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysGetCOMConfigInfo(SerialPortType_t emType, COMConfigInfo_t *pstCOMConfigInfo);

/*
***********************************************************************************************************************
* 函数名称: SysGetModbusTcpConfigInfo
*
* 功能描述: 获取本CM的某网口的ModbusTCP配置信息
*
* 输入参数: emType:指定的网口
*
* 输出参数: pstModbusTcpConfigInfo: 指向配置信息的结构体变量
*
* 返 回 值  : 获取配置信息成功则返回TRUE
*        获取配置信息失败则返回FALSE
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysGetModbusTcpConfigInfo(NetworkPortType_t emType, ModbusTCPConfigInfo_t *pstModbusTcpConfigInfo);

/*
***********************************************************************************************************************
* 函数名称: SysGetNTPTCPConfigInfo
*
* 功能描述: 获取本CM的NTP/TCP的配置信息
*
* 输入参数: emType:指定的串口
*
* 输出参数: pstNTPTCPConfigInfo: 指向配置信息的结构体变量
*
* 返 回 值  : 获取配置信息成功则返回TRUE
*        获取配置信息失败则返回FALSE
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysGetNTPTCPConfigInfo(NTPTCPConfigInfo_t *pstNTPTCPConfigInfo);

/*
***********************************************************************************************************************
* 函数名称: SysExterCommGetNetworkConfigInfo
*
* 功能描述: 外部通讯模块获取本CM的某网络通讯端口的配置信息
*
* 输入参数: emType:指定的网络通讯口
*
* 输出参数: pstNetworkParam: 指向配置信息的结构体变量
*
* 返 回 值  : 获取配置信息成功则返回TRUE
*        获取配置信息失败则返回FALSE
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysExterCommGetNetworkConfigInfo(NetworkPortType_t emType, ExtCommNetConfigInfo_t *pstNetworkParam);

/*
***********************************************************************************************************************
* 函数名称: SysSetCMConfigInfo
*
* 功能描述: 存储来自PM的CM配置信息
*
* 输入参数: pucContent: 指向CM配置信息内容
*        usLen: 配置信息长度
*
* 输出参数:
*
* 返 回 值  : 设置配置信息成功则返回TRUE
*        设置配置信息失败则返回FALSE
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysSetCMConfigInfo(puint8_t pucContent, uint16_t usLen);

/*
***********************************************************************************************************************
* 函数名称: SysGetLocalStationID
*
* 功能描述: 获取本控制站ID
*
* 输入参数: 无
*
* 输出参数: 无
*
* 返 回 值  : 版本号
*
* 注意事项: 无
***********************************************************************************************************************
*/
uint32_t SysGetLocalStationID(void);

/*
***********************************************************************************************************************
* 函数名称: SysGetRTDataVersion
*
* 功能描述: 获取CRC及实时数据版本
*
* 输入参数: 无
*
* 输出参数: puiCRC: CRC32
*        puiFileVern: 版本号
*
* 返 回 值  : 版本号
*
* 注意事项: 无
***********************************************************************************************************************
*/
//bool_t SysGetRTDataVersion(puint32_t puiCRC, puint32_t puiFileVern);
bool_t SysGetRTDataVersion(RTDataVerInfo_t *pstRTDataVer);
/*
***********************************************************************************************************************
* 函数名称: SysSetRTDataVersion
*
* 功能描述: 设置实时数据版本
*
* 输入参数: pstRTDataVer 版本信息
*
* 输出参数: 无
*
* 返 回 值  : 设置成功或失败
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysSetRTDataVersion(PMController_t emPMID, RTDataVerInfo_t *pstRTDataVer);
/*
***********************************************************************************************************************
* 函数名称: SysGetRTDataTimestamp
*
* 功能描述: 实时数据时间戳
*
* 输入参数: 无
*
* 输出参数: pulTimestamp 时间
*
* 返 回 值  : 读取成功或失败
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysGetRTDataTimestamp(PMController_t emPMID, ulong64_t *pulTimestamp);

/*
***********************************************************************************************************************
* 函数名称: SysSetRTDataTimestamp
*
* 功能描述: 记录时间戳
*
* 输入参数: ulTimestamp 时间戳
*
* 输出参数: 无
*
* 返 回 值  : 设置成功或失败
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysSetRTDataTimestamp(PMController_t emPMID, puint8_t pucTimestamp);
/*
***********************************************************************************************************************
* 函数名称: SysGetOPCConfigVersion
*
* 功能描述: 获取OPC配置参数的版本
*
* 输入参数: 无
*
* 输出参数: puiCRC: 用CRC表示主版本
*        puiFileVern: 版本
*
* 返 回 值  : 获取成功则返回TRUE
*        获取失败则返回FALSE
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysGetOPCConfigVersion(puint32_t puiCRC, puint32_t puiFileVern);

/*
***********************************************************************************************************************
* 函数名称: SysGetPassword
*
* 功能描述: 获取连接密码
*
* 输入参数: 无
*
* 输出参数: 无
*
* 返 回 值  : 版本号
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysGetPassword(puint8_t pucPwd, puint8_t pucLen);

/*
***********************************************************************************************************************
* 函数名称: SysGetCMConfigInfoActiveFlag_t
*
* 功能描述: 获取CM配置信息是否更新标识
*
* 输入参数: 无
*
* 输出参数: 无
*
* 返 回 值  : 版本号
*
* 注意事项: 无
***********************************************************************************************************************
*/
ActiveFlag_t SysGetCMConfigInfoActiveFlag_t(void);

/*
***********************************************************************************************************************
* 函数名称: SysGetCMConfigVersion
*
* 功能描述: 获取CM配置信息版本
*
* 输入参数: 无
*
* 输出参数: puiCRC: CRC32
*        puiFileVern: 版本号
*
* 返 回 值  : 版本号
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysGetCMConfigVersion(puint32_t puiCRC, puint32_t puiFileVern);

/*
***********************************************************************************************************************
* 函数名称: SysGetOPCVarConfigInfo
*
* 功能描述: 获取OPC变量配置信息的首地址
*
* 输入参数: 无
*
* 输出参数: 无
*
* 返 回 值  : 返回OPC变量配置信息的首地址
*
* 注意事项: 无
***********************************************************************************************************************
*/
//OPCVarInfo_t* SysGetOPCVarConfigInfo(void);
uint32_t SysGetOPCVarConfigInfo( puint8_t pucBuff, uint32_t uiOffset, uint32_t uiLength );

/*
***********************************************************************************************************************
* 函数名称: SysOPCGetNetworkConfigInfo
*
* 功能描述: OPC模块获取本CM的指定网口的配置信息
*
* 输入参数: emType: 网口类型
*
* 输出参数: pstNetworkParam: 指向指定网口的配置信息
*
* 返 回 值  : 获取成功则返回TRUE
*        获取失败则返回FALSE
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysOPCGetNetworkConfigInfo(NetworkPortType_t emType, OPCNetConfigInfo_t *pstNetworkParam);

/*
***********************************************************************************************************************
* 函数名称: SysExterCommGetModbusTCPConfigInfo
*
* 功能描述: 外部通讯模块获取本CM的某网口的Modbus TCP配置信息
*
* 输入参数: emType: 网口类型
*
* 输出参数: pstModbusTCPConfig: 指向指定网口的Modbus TCP配置信息
*
* 返 回 值  : 获取成功则返回TRUE
*        获取失败则返回FALSE
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysExterCommGetModbusTCPConfigInfo(NetworkPortType_t emType, ExtCommModbusTCPConfigInfo_t *pstModbusTCPConfig);

/*
***********************************************************************************************************************
* 函数名称: SysGetRecvConfigInfoFlg
*
* 功能描述: 获取内部通讯接收CM配置信息是否完成标志
*
* 输入参数:
*
* 输出参数:
*
* 返 回 值  :
*
* 注意事项: 无
***********************************************************************************************************************
*/
uint8_t SysGetRecvConfigInfoFlg(void);

/*
***********************************************************************************************************************
* 函数名称: SysSetRecvConfigInfoFlg
*
* 功能描述: 设置CM配置信息是否完成标志
*
* 输入参数:
*
* 输出参数:
*
* 返 回 值  :
*
* 注意事项: 无
***********************************************************************************************************************
*/
void SysSetRecvConfigInfoFlg(uint8_t ucFlag);

#endif /* SYS_CONFIG_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/

