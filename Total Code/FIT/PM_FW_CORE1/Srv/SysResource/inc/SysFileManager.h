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
*  文件名称    : SysFileManager.h
*
*  功能简介    :
*
*  作者       : 李琦
*
*  创建日期    : 2016-03-31
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

#ifndef SYS_FILE_MANAGER_H_
#define SYS_FILE_MANAGER_H_

/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/
#include "inc/DataType.h"
#include "SysCommon.h"
/*
***********************************************************************************************************************
*                                宏定义
***********************************************************************************************************************
*/
#define MAX_FILE_MSG_LEN         (8000u)               /*最大请求或应答消息内容长度 (FPGA收发缓冲区为8192，预留192字节头部信息)*/
//#define MAX_FILE_NAME_LEN        (32u)                 /* 文件名最大长度 */

#define FM_MSGBOX_LOCKED       true                  /* 信箱被锁定*/
#define FM_MSGBOX_UNLOCKED     false                 /* 信箱未锁定 */

#define FM_MSGBOX_FULL         true                  /* 信箱满 */
#define FM_MSGBOX_EMPTY        false                 /* 信箱空 */

/* RTS task发送的控制字control word */
#define FM_OPEN_FILE           (0x00000001u)        /* bit0=1:打开文件，若文件不存在则创建文件 */
#define FM_WRITE_FILE          (0x00000002u)        /* bit1=1:写文件，每次将内容追加到末尾 */
#define FM_CLOSE_FILE          (0x00000004u)        /* bit2=1:关闭文件 */
#define FM_DELETE_FILE         (0x00000008u)        /* bit3=1:删除文件 */
#define FM_IS_FILE_EXIST       (0x00000010u)        /* bit4=1:判断文件是否存在 */
#define FM_RENAME_FILE         (0x00000020u)        /* bit5=1:重命名文件 */
#define FM_READ_FILE           (0x00000040u)        /* bit6=1:读文件 */

#define FM_ERASE_RTS_FLG   (0x00000100u)        /* bit8=1:擦RTS flag*/
#define FM_ERASE_FPGA_FLG   (0x00000200u)        /* bit9=1:擦FPGA flag*/
#define FM_ERASE_RTS_AREA0   (0x00000400u)        /* bit10=1:擦RTS area0*/
#define FM_ERASE_RTS_AREA1   (0x00000800u)        /* bit11=1:擦RTS area1*/
#define FM_ERASE_FPGA_AREA0   (0x00001000u)        /* bit12=1:擦FPGA area0*/
#define FM_ERASE_FPGA_AREA1   (0x00002000u)        /* bit13=1:擦FPGA area1*/


#define FM_INVALID_CWT         (0x1000000u)         /* bit=31:无效的控制命令 */

/* File manager task应答的状态字 status word */
#define FM_OPEN_FILE_ACK           (0x00000001u)        /* bit0=1:打开文件，若文件不存在则创建文件，控制命令执行成功 */
#define FM_OPEN_FILE_NACK          (~0x00000001u)       /* bit0=0:打开文件，若文件不存在则创建文件，控制命令执行失败 */
#define FM_WRITE_FILE_ACK          (0x00000002u)        /* bit1=1:写文件，每次将内容追加到末尾，控制命令执行成功*/
#define FM_WRITE_FILE_NACK         (~0x00000002u)       /* bit1=0:写文件，每次将内容追加到末尾，控制命令执行失败 */
#define FM_CLOSE_FILE_ACK          (0x00000004u)        /* bit2=1:关闭文件，控制命令执行成功 */
#define FM_CLOSE_FILE_NACK         (~0x00000004u)       /* bit2=0:关闭文件，控制命令执行失败 */
#define FM_DELETE_FILE_ACK         (0x00000008u)        /* bit3=1:删除文件，控制命令执行成功 */
#define FM_DELETE_FILE_NACK        (~0x00000008u)       /* bit3=0:删除文件，控制命令执行失败 */
#define FM_IS_FILE_EXIST_ACK       (0x00000010u)        /* bit4=1:判断文件是否存在，控制命令执行成功 */
#define FM_IS_FILE_EXIST_NACK      (~0x00000010u)       /* bit4=0:判断文件是否存在，控制命令执行失败 */
#define FM_RENAME_FILE_ACK         (0x00000020u)        /* bit5=1:重命名文件，控制命令执行成功  */
#define FM_RENAME_FILE_NACK        (~0x00000020u)       /* bit5=0:重命名文件，控制命令执行失败 */
#define FM_READ_FILE_CONTINUE_ACK  (0x00000040u)        /* bit6=1:读文件，控制命令执行成功  */
#define FM_READ_FILE_CONTINUE_NACK (~0x00000040u)       /* bit6=0:读文件，控制命令执行失败 */
#define FM_READ_FILE_END_ACK       (0x00000080u)        /* bit7=1:读文件结束，控制命令执行成功  */
#define FM_READ_FILE_END_NACK      (~0x00000080u)       /* bit7=0:读文件结束，控制命令执行失败 */

#define FM_ERASE_RTS_FLG_ACK   (0x00000100u)        /* bit8=1:擦RTS flag成功*/
#define FM_ERASE_RTS_FLG_NACK   (~0x00000100u)        /* bit8=1:擦RTS flag失败*/
#define FM_ERASE_FPGA_FLG_ACK   (0x00000200u)        /* bit9=1:擦FPGA flag成功*/
#define FM_ERASE_FPGA_FLG_NACK   (~0x00000200u)        /* bit9=1:擦FPGA flag失败*/
#define FM_ERASE_RTS_AREA0_ACK   (0x00000400u)        /* bit10=1:擦RTS area0成功*/
#define FM_ERASE_RTS_AREA0_NACK   (~0x00000400u)        /* bit10=1:擦RTS area0失败*/
#define FM_ERASE_RTS_AREA1_ACK   (0x00000800u)        /* bit11=1:擦RTS area1 成功*/
#define FM_ERASE_RTS_AREA1_NACK   (~0x00000800u)        /* bit11=1:擦RTS area1失败*/
#define FM_ERASE_FPGA_AREA0_ACK   (0x00001000u)        /* bit12=1:擦FPGA area0成功*/
#define FM_ERASE_FPGA_AREA0_NACK   (~0x00001000u)        /* bit12=1:擦FPGA area0失败*/
#define FM_ERASE_FPGA_AREA1_ACK   (0x00002000u)        /* bit13=1:擦FPGA area1成功*/
#define FM_ERASE_FPGA_AREA1_NACK   (~0x00002000u)        /* bit13=1:擦FPGA area1失败*/

#define FM_INVALIDE_CWT_ACK        (0x00000000u)        /* bit31=1:对无效控制命令的应答 */

/* File manager task应答的错误码 error code */
#define FM_OK                      (0x00000000u)        /* 正常 */

#define FM_OPEN_FILE_ERR           (0x00000001u)        /* 打开文件出错 */
#define FM_WRITE_FILE_ERR          (0x00000002u)        /* 写文件出错 */
#define FM_CLOSE_FILE_ERR          (0x00000004u)        /* 关闭文件出错 */
#define FM_DELETE_FILE_ERR         (0x00000008u)        /* 删除文件出错 */
#define FM_FILE_EXIST_TRUE         (0x00000010u)        /* 文件存在 */
#define FM_FILE_EXIST_FALSE        (0x00000020u)        /* 文件不存在 */

#define FM_CTW_ERR                 (0x00000100u)        /* 控制字无效 */
#define FM_FILE_NAME_ERR           (0x00000200u)        /* 文件名非法 */
#define FM_FILE_NAME_LEN_ERR       (0x00000400u)        /* 文件名长度非法 */
#define FM_FILE_CONTENT_LEN_ERR    (0x00000800u)        /* 写入文件内容长度超限 */

#define FM_ERASE_FAILED            (0x00001000u)        /* 擦除flash失败 */

#define FW_FM_RTS_FLG_BLK_NUM       (1U)
#define FW_FM_FPGA_FLG_BLK_NUM      (1U)
#define FW_FM_RTS_BLK_NUM           (40U)
#define FW_FM_FPGA_BLK_NUM          (40U)

#define FW_FM_RTS_FLG_START_BLK     (0U)
#define FW_FM_FPGA_FLG_START_BLK    (FW_FM_RTS_FLG_START_BLK + FW_FM_RTS_FLG_BLK_NUM)
#define FW_FM_RTS_AREA0_START_BLK   (FW_FM_FPGA_FLG_START_BLK + FW_FM_FPGA_FLG_BLK_NUM)
#define FW_FM_RTS_AREA1_START_BLK   (FW_FM_RTS_AREA0_START_BLK + FW_FM_RTS_BLK_NUM)
#define FW_FM_FPGA_AREA0_START_BLK  (FW_FM_RTS_AREA1_START_BLK + FW_FM_RTS_BLK_NUM)
#define FW_FM_FPGA_AREA1_START_BLK  (FW_FM_FPGA_AREA0_START_BLK + FW_FM_FPGA_BLK_NUM)

/*
***********************************************************************************************************************
*                                数据结构定义
***********************************************************************************************************************
*/
#pragma pack(1)
/* RTS task发送到File Manager Task的消息数据结构定义*/
typedef struct SysFMReqTag
{
    uint8_t ucFileName[MAX_FILE_NAME_LEN];      /* 文件名字符串 */
    uint32_t uiCtrlWord;                        /* 控制字 */
    int32_t iFd;                                /* 文件描述符 */
    uint16_t usLen;                             /* 写文件内容长度 */
    uint8_t ucContent[MAX_FILE_MSG_LEN];        /* 存放待写入的文件内容 */
} SysFMReq_t;

typedef struct SysFMReqMsgBoxTag
{
    bool_t bLock;                               /* 信箱是否可以被访问 */
    bool_t bStatus;                             /* 信箱的两种状态：空或满 */
    SysFMReq_t stReqMsg;                        /* 请求消息 */
} SysFMReqMsgBox_t;

/* RTS task接收来自File Manager Task的应答消息数据结构定义 */
typedef struct SysFMAckTag
{
    uint32_t uiStatusWord;                      /* 状态字*/
    uint32_t uiErrCode;                         /* 错误码 */
    int32_t iFd;                                /* 文件描述符 */
    uint16_t usLen;                             /* 读文件内容长度 */
    uint8_t ucContent[MAX_FILE_MSG_LEN];        /* 存放读出的文件内容 */
} SysFMAck_t;

typedef struct SysFMAckHeaderTag
{
    uint32_t uiStatusWord;                      /* 状态字*/
    uint32_t uiErrCode;                         /* 错误码 */
    int32_t iFd;                                /* 文件描述符 */
} SysFMAckHeader_t;

typedef struct SysFileMngtAckTag
{
    bool_t bLock;                               /* 信箱是否可以被访问 */
    bool_t bStatus;                             /* 信箱的两种状态：空或满 */
    SysFMAck_t stAckMsg;                        /* 应答消息 */
} SysFMAckMsgBox_t;

#pragma pack()
/*
***********************************************************************************************************************
*                                全局函数声明
***********************************************************************************************************************
*/
/*
***********************************************************************************************************************
* 函数名称: SysFileManagerInit
*
* 功能描述: 文件管理初始化
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
void SysFileManagerInit(void);

/*
***********************************************************************************************************************
* 函数名称: SysWriteFile
*
* 功能描述: RTS task写文件名称及内容到共享内存缓冲区
*
* 输入参数: iFd: 文件描述符
*        ucContent[]: 待写入的文件内容
*        usLen: 文件内容长度
*
* 输出参数: 无
*
* 返 回 值  : true-写入成功
*        false- 1)输入参数错误  2)不允许访问
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysWriteFile(int32_t iFd, uint8_t ucContent[], uint16_t usLen);

/*
***********************************************************************************************************************
* 函数名称: SysReadFile
*
* 功能描述: RTS task读文件内容到共享内存缓冲区
*
* 输入参数: iFd: 文件描述符
*        usLen: 文件内容长度
*
* 输出参数: 无
*
* 返 回 值  : true-写入成功
*        false- 1)输入参数错误  2)不允许访问
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysReadFile(int32_t iFd, uint16_t usLen);

/*
***********************************************************************************************************************
* 函数名称: SysSendAck
*
* 功能描述: file manager task发送ack消息到共享内存缓冲区
*
* 输入参数: pstAck: 指向ack消息
*
* 输出参数: 无
*
* 返 回 值  : 发送成功或失败
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysSendAck(SysFMAck_t *pstAck);

/*
***********************************************************************************************************************
* 函数名称: SysReadFMReqMsg
*
* 功能描述: file manager task从共享内存缓冲区中读文件名字及内容
*
* 输入参数: 无
*
* 输出参数:  ucName[]: 文件名
*         puiCTW: 控制字
*         ucContent[]: 待读出的文件内容
*         pusLen: 指向待读出的文件内容长度
*
* 返 回 值  : 读取成功或失败
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysReadFMReqMsg(SysFMReq_t *pstSysFMReq);

/*
***********************************************************************************************************************
* 函数名称: SysRecvAck
*
* 功能描述: RTS task从共享内存缓冲区中接收来自file manager task的ack
*
* 输入参数: 无
*
* 输出参数:  pstAck: 指向ack消息
*
* 返 回 值  : 读取成功或失败
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysRecvAck(SysFMAck_t *pstAck);

/*
***********************************************************************************************************************
* 函数名称: SysRecvAckHeader
*
* 功能描述: RTS task从共享内存缓冲区中接收来自file manager task的ack的头部
*
* 输入参数: 无
*
* 输出参数:  pstAckHeader: 指向ack消息头部
*
* 返 回 值  : 读取成功或失败
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysRecvAckHeader(SysFMAckHeader_t *pstAckHeader);

/*
***********************************************************************************************************************
* 函数名称: SysOpenFile
*
* 功能描述: RTS task向共享内存缓冲区中写入需要打开的文件名称（若文件不存在则创建该文件）
*
* 输入参数: ucName[]: 文件名
*
* 输出参数: 无
*
* 返 回 值  : true-打开成功
*        false- 1)输入参数错误  2)不允许访问
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysOpenFile(uint8_t ucName[]);


/*
***********************************************************************************************************************
* 函数名称: SysCloseFile
*
* 功能描述: RTS task向共享内存缓冲区中写入需要关闭的文件名称
*
* 输入参数: iFd: 文件描述符
*
* 输出参数: 无
*
* 返 回 值  : true-关闭成功
*        false- 1)输入参数错误  2)不允许访问
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysCloseFile(int32_t iFd);


/*
***********************************************************************************************************************
* 函数名称: SysDeleteFile
*
* 功能描述: RTS task向共享内存缓冲区中写入需要删除的文件名称
*
* 输入参数: ucName[]: 文件名
*
* 输出参数: 无
*
* 返 回 值  : true-删除成功
*        false- 1)输入参数错误  2)不允许访问
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysDeleteFile(uint8_t ucName[]);


/*
***********************************************************************************************************************
* 函数名称: SysSendIsFileExist
*
* 功能描述: RTS task向共享内存缓冲区中写入需要判断文件是否存在的文件名称
*
* 输入参数: ucName[]: 文件名
*
* 输出参数: 无
*
* 返 回 值  : true-输入参数正确 且允许访问
*        false- 1)输入参数错误  2)不允许访问
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysSendIsFileExist(uint8_t ucName[]);

/*
***********************************************************************************************************************
* 函数名称: SysRenameFile
*
* 功能描述: RTS task向共享内存缓冲区中写入旧文件名及新文件名
*
* 输入参数: ucOldName[]: 旧文件名
*        ucNewName[]: 新文件名
*
* 输出参数: 无
*
* 返 回 值  : true-输入参数正确 且允许访问
*        false- 1)输入参数错误  2)不允许访问
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysRenameFile(uint8_t ucOldName[], uint8_t ucNewName[]);

/*
***********************************************************************************************************************
* 函数名称: SysEraseNorflash
*
* 功能描述: 擦Norflash
*
* 输入参数: iBlockIndex: 第几块
*        iBlockNum: 块数
*
* 输出参数: 无
*
* 返 回 值  : true-输入参数正确 且擦除成功
*        false- 1)输入参数错误  2)擦除失败
*
* 注意事项: 无
***********************************************************************************************************************
*/
int32_t SysEraseNorflash(int iBlockIndex, int iBlockNum);
/*
***********************************************************************************************************************
* 函数名称: SysEraseFirmware
*
* 功能描述: 擦除flash中的firmware
*
* 输入参数: uiCwd命令
*
* 输出参数: 无
*
* 返 回 值  : true-擦除成功
*        false- 1)输入参数错误  2)不允许访问
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysEraseFirmware(uint32_t uiCwd);
#endif /* SYS_FILE_MANAGER_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/

