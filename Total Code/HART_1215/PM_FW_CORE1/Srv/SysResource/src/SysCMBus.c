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
*  文件名称    : SysCMBus.c
*
*  功能简介    : 系统资源管理模块中的公共资源，其它模块均可调用
*
*  作者        : 李琦
*
*  创建日期    : 2016-02-24
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
#include "../inc/Sys.h"

/*
***********************************************************************************************************************
*                                局部变量声明
***********************************************************************************************************************
*/

static SysMsgBox_t  s_stSysMsgBox[NUM_OF_CM][NUM_OF_MSGTYPE];



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
* 函数名称: SysCMBusInit
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
void SysCMBusInit(void)
{
    /* 初始化 */
    memset((puint8_t)&s_stSysMsgBox[0][0], 0, sizeof(SysMsgBox_t)*NUM_OF_CM*NUM_OF_MSGTYPE);
    return;
}

/*
***********************************************************************************************************************
* 函数名称: SysGetMsg
*
* 功能描述: 从系统资源模块获取消息（请求/应答）
*
* 输入参数: emCMID: CM的ID
*        emMsgType: 各种消息类型
*
* 输出参数: pucContent: 指向待读出的消息内容
*         pusLen: 指向待读出的消息内容长度
*
* 返 回 值  : true-收到消息
*        false- 1)无数据  2)不允许访问  3)输入输出参数错误
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysGetMsg (CMController_t emCMID, SysMsgType_t emMsgType, puint8_t pucContent, puint16_t pusLen)
{
    SysMsgBox_t *pstMsgBox = NULL;
    bool_t bRet = false;

    /* 输出参数有效性检查 */
    if((pucContent != NULL) && (pusLen != NULL))
    {
        /* 输入参数有效性检查 */
        if((emCMID < NUM_OF_CM) && (emCMID >= CM1) &&(emMsgType < NUM_OF_MSGTYPE))
        {
            /* 找到待读出信息的信箱 */
            pstMsgBox = &(s_stSysMsgBox[emCMID][emMsgType]);
            /* 允许访问且有数据 */
            if((MSGBOX_UNLOCKED == pstMsgBox->bLock) && (MSGBOX_FULL == pstMsgBox->bMsgBoxStatus))
            {
                /* 锁定信箱，防止其它进程访问 */
                pstMsgBox->bLock = MSGBOX_LOCKED;
                /* 获取消息内容 */
                memcpy(pucContent,(puint8_t)&(pstMsgBox->stMsg.ucContent[0]),pstMsgBox->stMsg.usLen);
                /* 获取消息长度 */
                *pusLen = pstMsgBox->stMsg.usLen;
                /* 清空消息内容 */
                pstMsgBox->bMsgBoxStatus = MSGBOX_EMPTY;
                /* 置读取成功标识 */
                bRet = true;
                /* 解除锁定 */
                pstMsgBox->bLock = MSGBOX_UNLOCKED;
            }
            else
            {
                /* 不允许访问或无数据，置待读出消息内容长度为0 */
                *pusLen = 0;
//                printf("Get %d %d %d %d\n",pstMsgBox->bLock,pstMsgBox->bMsgBoxStatus,emCMID,emMsgType);
            }
        }
        else
        {
            /* 输入参数无效，置待读出消息内容长度为0 */
            *pusLen = 0;
        }
    }
    return bRet;
}

/*
***********************************************************************************************************************
* 函数名称: SysGetMsgLen
*
* 功能描述: 从系统资源模块获取消息（请求/应答）的长度
*
* 输入参数: emCMID: CM的ID
*        emMsgType: 各种消息类型
*
* 输出参数: pusLen: 指向待读出的消息内容长度
*
* 返 回 值  : true-读取成功
*        false- 1)无数据  2)不允许访问  3)输入输出参数错误
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysGetMsgLen (CMController_t emCMID, SysMsgType_t emMsgType, puint16_t pusLen)
{
    SysMsgBox_t *pstMsgBox = NULL;
    bool_t bRet = false;

    /* 输出参数有效性检查 */
    if(pusLen != NULL)
    {
        /* 输入参数有效性检查 */
        if((emCMID < NUM_OF_CM) && (emCMID >= CM1) &&(emMsgType < NUM_OF_MSGTYPE))
        {
            /* 找到待读出信息的信箱 */
            pstMsgBox = &(s_stSysMsgBox[emCMID][emMsgType]);
            /* 允许访问且有数据 */
            if((MSGBOX_UNLOCKED == pstMsgBox->bLock) && (MSGBOX_FULL == pstMsgBox->bMsgBoxStatus))
            {
                /* 锁定信箱，防止其它进程访问 */
                pstMsgBox->bLock = MSGBOX_LOCKED;
                /* 获取消息长度 */
                *pusLen = pstMsgBox->stMsg.usLen;
                /* 置读取成功标识 */
                bRet = true;
                /* 解除锁定 */
                pstMsgBox->bLock = MSGBOX_UNLOCKED;
            }
            else
            {
                /* 不允许访问或无数据，置待读出消息内容长度为0 */
                *pusLen = 0;
            }
        }
        else
        {
            /* 输入参数无效，置待读出消息内容长度为0 */
            *pusLen = 0;
        }
    }
    return bRet;
}

/*
***********************************************************************************************************************
* 函数名称: SysSetMsg
*
* 功能描述: 将请求或应答消息写入系统资源模块
*
* 输入参数: emCMID: CM的ID
*        emMsgType: 各种消息类型
*        pucContent: 指向待写入的消息内容
*        usLen: 指向待写入的消息内容长度
*
* 输出参数: 无
*
* 返 回 值  : 写入成功或失败
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysSetMsg (CMController_t emCMID, SysMsgType_t emMsgType , puint8_t pucContent, uint16_t usLen)
{
    bool_t bRet = false;
    SysMsgBox_t *pstMsgBox = NULL;

    /* 输入参数有效性检查 */
    if((emCMID < NUM_OF_CM) && (emCMID >= CM1) &&(emMsgType < NUM_OF_MSGTYPE))
    {
        /* 找到待写入信息的信箱 */
        pstMsgBox = &(s_stSysMsgBox[emCMID][emMsgType]);

        /* 允许访问且信箱为空 */
        if((MSGBOX_UNLOCKED == pstMsgBox->bLock) && (MSGBOX_EMPTY == pstMsgBox->bMsgBoxStatus))
        {
            /* 输出参数有效性检查 */
            if((pucContent != NULL) && (usLen > 0) && (usLen < MAX_MSG_LEN))
            {
                /* 锁定信箱，防止其它进程访问 */
                pstMsgBox->bLock = MSGBOX_LOCKED;
                 /* 写入消息内容 */
                memcpy((puint8_t)&(pstMsgBox->stMsg.ucContent[0]), pucContent,usLen);
                /* 写入消息长度 */
                pstMsgBox->stMsg.usLen = usLen;
                /* 置消息内容为满标识 */
                pstMsgBox->bMsgBoxStatus = MSGBOX_FULL;
                /* 写入成功 */
                bRet = true;
                /* 解除锁定 */
                pstMsgBox->bLock = MSGBOX_UNLOCKED;
            }
        }
        else
        {
            /* 不允许访问或信箱为满，则写入失败 */
            bRet = false;
//            printf("SetMsg %d %d\n",pstMsgBox->bLock,pstMsgBox->bMsgBoxStatus);
        }
    }
    else
    {
        /* 输入参数无效，则写入失败 */
        bRet = false;
//        printf("SetMsg 1 %d %d\n",emMsgType,pstMsgBox->bMsgBoxStatus);
    }

    return bRet;
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
