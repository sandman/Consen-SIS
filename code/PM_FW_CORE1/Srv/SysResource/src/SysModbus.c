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
*  文件名称    : SysModbus.c
*
*  功能简介    : 管理Modbus应用模块与内部通讯模块间的资源
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
/* 用于内部通讯的信箱 */
static SysModbusMsgQueue_t s_stSysModbusMsgQueue[NUM_OF_CM];

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
* 函数名称: SysModbusInit
*
* 功能描述: 队列初始化
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
void SysModbusInit(void)
{
    /* 消息队列初始化：队头为0，队尾为0，消息个数为0，队列存储空间全清0 */
    memset((puint8_t)&s_stSysModbusMsgQueue[0], 0, sizeof(SysModbusMsgQueue_t) * NUM_OF_CM);
    return;
}

/*
***********************************************************************************************************************
* 函数名称: SysModbusClear
*
* 功能描述: 清除队列
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
void SysModbusClear(void)
{
    s_stSysModbusMsgQueue[CM1].usHead = 0;
    s_stSysModbusMsgQueue[CM1].usTail = 0;
    s_stSysModbusMsgQueue[CM1].usNum = 0;

    s_stSysModbusMsgQueue[CM2].usHead = 0;
    s_stSysModbusMsgQueue[CM2].usTail = 0;
    s_stSysModbusMsgQueue[CM2].usNum = 0;

    s_stSysModbusMsgQueue[CM3].usHead = 0;
    s_stSysModbusMsgQueue[CM3].usTail = 0;
    s_stSysModbusMsgQueue[CM3].usNum = 0;

    s_stSysModbusMsgQueue[CM4].usHead = 0;
    s_stSysModbusMsgQueue[CM4].usTail = 0;
    s_stSysModbusMsgQueue[CM4].usNum = 0;

    return;
}

/*
***********************************************************************************************************************
* 函数名称: SysGetModbusMsgQueue
*
* 功能描述: 从系统资源模块获取消息（请求/应答）
*
* 输入参数: emCMID: CM的ID
*
* 输出参数: pucContent: 指向待读出的消息内容
*         pusLen: 指向待读出的消息内容长度
*
* 返 回 值  : true-收到消息
*        false- 1)队列空  2)输入输出参数错误
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysGetModbusMsgQueue (CMController_t emCMID, puint8_t pucContent, puint16_t pusLen)
{
    bool_t bRet = false;                    /* 函数返回值 */
    SysModbusMsg_t *pstModbusMsg = NULL;    /* 指向待读取的消息 */
    uint16_t usNum = 0;                     /* 记录队列中的消息个数 */
    uint16_t usHead = 0;                    /* 记录队头位置 */

    /* 输出参数有效性检查 */
    if((pucContent != NULL) && (pusLen != NULL))
    {
        if((emCMID < NUM_OF_CM) && (emCMID >= CM1))
        {
            /* 获取队列中消息个数及队头位置 */
            usNum = s_stSysModbusMsgQueue[emCMID].usNum;
            usHead = s_stSysModbusMsgQueue[emCMID].usHead;

            /* 输入参数有效性检查 */
            if((usNum > 0) && (usHead < MAX_MODBUS_MSG_NUM))
            {
                /* 找到待读出信息的信箱 */
                pstModbusMsg = &(s_stSysModbusMsgQueue[emCMID].stMsg[usHead]);
                /* 获取消息内容 */
                memcpy(pucContent,(puint8_t)&(pstModbusMsg->ucContent[0]),pstModbusMsg->usLen);
                /* 获取消息长度 */
                *pusLen = pstModbusMsg->usLen;
                /* 更新队列头位置及队列中的消息个数 */
                usHead = (usHead + 1) % MAX_MODBUS_MSG_NUM;
                s_stSysModbusMsgQueue[emCMID].usHead = usHead;
                s_stSysModbusMsgQueue[emCMID].usNum--;
                /* 置读取成功标识 */
                bRet = true;
            }
            else
            {
                /* 队列空，无消息 */
                *pusLen = 0;
                bRet = false;
            }
        }
        else
        {
            /* 输入参数无效 */
            *pusLen = 0;
            bRet = false;
        }
    }
    else
    {
        /* 输出参数无效 */
        bRet = false;
    }
    return bRet;
}

/*
***********************************************************************************************************************
* 函数名称: SysGetModbusMsgNum
*
* 功能描述: 从系统资源模块获取消息（请求/应答）的个数
*
* 输入参数: emCMID: CM的ID
*
* 输出参数: pusNum: 指向待读出的消息内容长度
*
* 返 回 值  : true-读取消息个数成功
*        false-输入输出参数错误
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysGetModbusMsgNum (CMController_t emCMID, puint16_t pusNum)
{
    bool_t bRet = false;                    /* 函数返回值 */

    /* 输入输出参数有效性检查 */
    if((emCMID < NUM_OF_CM) && (emCMID >= CM1) && (pusNum != NULL))
    {
        /* 获取队列中的消息个数 */
        *pusNum =  s_stSysModbusMsgQueue[emCMID].usNum;
        bRet = true;
    }
    else
    {
        /* 输入或输出参数无效 */
        bRet = false;
    }
    return bRet;
}

/*
***********************************************************************************************************************
* 函数名称: SysSetModbusMsgQueue
*
* 功能描述: 将消息写入系统资源模块
*
* 输入参数: emCMID: CM的ID
*
* 输出参数: pucContent: 指向待写入的消息内容
*        pusLen: 指向待写入的消息内容长度
*
* 返 回 值  : 写入成功或失败
*
* 注意事项: 无
***********************************************************************************************************************
*/
bool_t SysSetModbusMsgQueue(CMController_t emCMID, puint8_t pucContent, uint16_t usLen)
{
    bool_t bRet = false;                    /* 函数返回值 */
    SysModbusMsg_t *pstModbusMsg = NULL;    /* 指向队列中待写入消息的位置 */
    uint16_t usNum = 0;                     /* 记录队列中的消息个数 */
    uint16_t usTail = 0;                    /* 记录队尾位置 */

    /* 输入参数有效性检查 */
    if((emCMID < NUM_OF_CM) && (emCMID >= CM1))
    {
        /* 获取消息个数及队尾位置 */
        usNum = s_stSysModbusMsgQueue[emCMID].usNum;
        usTail = s_stSysModbusMsgQueue[emCMID].usTail;

        /* 判断队列是否已满 */
        if(usNum < MAX_MODBUS_MSG_NUM)
        {
            /* 找到待写入消息的位置*/
            pstModbusMsg = &(s_stSysModbusMsgQueue[emCMID].stMsg[usTail]);

            /* 输出参数有效性检查 */
            if((pucContent != NULL) && (usLen != 0))
            {
                 /* 写入内容 */
                memcpy((puint8_t)&(pstModbusMsg->ucContent[0]), pucContent,usLen);
                /* 写入长度 */
                pstModbusMsg->usLen = usLen;
                /* 更新列尾及队列中的消息个数 */
                usTail = (usTail + 1) % MAX_MODBUS_MSG_NUM;
                s_stSysModbusMsgQueue[emCMID].usTail = usTail;
                s_stSysModbusMsgQueue[emCMID].usNum++;
                /* 写入成功 */
                bRet = true;
            }
            else
            {
                /* 输出参数无效 */
                bRet = false;
            }
        }
        else
        {
            /* 队列满 */
            bRet = false;
        }
    }
    else
    {
        /* 输入参数无效，则写入失败 */
        bRet = false;
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
