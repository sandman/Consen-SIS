﻿/*
*********************************************************************************************************************** 
*                  Copyright(c) 北京康吉森技术有限公司 2015
*           Beijing Consen Technologies Co.,Ltd. All rights reserved.
*                                  
*                                  
*  项目名称    : 安全控制系统
*
*  模块名称    : CM_FW外部通信模块
*
*  文件名称    : Socket.h
*
*  功能简介    : 套接字相关接口
*
*  作者        : 王东
*
*  创建日期    : 2016-01-05
*
*  版本信息    : V1.0
*
*  修订信息    : 无
*
***********************************************************************************************************************
*/

#ifndef SOCKET_H_
#define SOCKET_H_

/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <pthread.h>
#include <net/if.h>
#include <net/route.h>
#include "Sys/inc/Sys.h"
#include "Sys/inc/DataType.h"

/*
***********************************************************************************************************************
*                                宏定义
***********************************************************************************************************************
*/

#define SOCKET_ERROR   (-1)
#define INVALID_SOCKET (-1)

#define DEBUG_OUT_SOCKET

#ifdef DEBUG_OUT_SOCKET
#define DEBUG_SOCKET(format, args...)  printf ("DB_SKT: ") ; printf(format, ##args)
#else
#define DEBUG_SOCKET(format, args...)
#endif

/*
***********************************************************************************************************************
*                                数据结构定义
***********************************************************************************************************************
*/

typedef int32_t SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct ifreq IFREQ;

/*
***********************************************************************************************************************
*                                全局函数声明
***********************************************************************************************************************
*/

/*
***********************************************************************************************************************
* 函数名称: GetErrorNo
*
* 功能描述: 获取Linux API操作产生的错误码
*
* 输入参数: 无
*
* 输出参数: 无
*
* 返 回 值: 错误码
*
* 注意事项: Linux API 返回值显示出错时，在获取此错误码，不建议手动设置此错误码。
***********************************************************************************************************************
*/

int32_t GetErrorNo( void );

/*
***********************************************************************************************************************
* 函数名称: CloseSocket
*
* 功能描述: 关闭套接字
*
* 输入参数: phSocket：指向待关闭的套接字
*
* 输出参数: phSocket：指向关闭后的套接字
*
* 返 回 值: 无
*
* 注意事项: 无
***********************************************************************************************************************
*/

void CloseSocket( SOCKET *phSocket );

/*
***********************************************************************************************************************
* 函数名称: CloseListenSocket
*
* 功能描述: 关闭监听套接字
*
* 输入参数: phSocket：指向待关闭的套接字
*
* 输出参数: phSocket：指向关闭后的套接字
*
* 返 回 值: 无
*
* 注意事项: 无
***********************************************************************************************************************
*/

void CloseListenSocket( SOCKET *phSocket );

/*
***********************************************************************************************************************
* 函数名称: CloseConnSocket
*
* 功能描述: 关闭连接套接字
*
* 输入参数: phSocket：指向关闭前的连接套接字
*
* 输出参数: phSocket：指向关闭后的连接套接字
*
* 返 回 值: true：关闭成功；false：关闭失败。
*
* 注意事项: 无
***********************************************************************************************************************
*/

void CloseConnSocket( SOCKET *phSocket );

/*
***********************************************************************************************************************
* 函数名称: CreateListenSocket
*
* 功能描述: 创建监听套接字，绑定到指定端口，并开始监听
*
* 输入参数: uiIPAddr：网口IP地址；
*          usPort：待监听端口；
*          bNonBlock：是否设置成非阻塞模式；
*          bCloExec：是否close-on-exec during a successful execve；
*          phSocket：指向创建前的监听套接字。
*
* 输出参数: phSocket：指向创建后的监听套接字
*
* 返 回 值: true：创建成功；false：创建失败。
*
* 注意事项: 无
***********************************************************************************************************************
*/

void CreateListenSocket( uint32_t uiIPAddr, uint16_t usPort, bool_t bNonBlock, bool_t bCloExec, SOCKET *phSocket );

/*
***********************************************************************************************************************
* 函数名称: CreateUDPServerSocket
*
* 功能描述: 创建UDP服务器端套接字
*
* 输入参数: uiIPAddr：网口IP地址；
*          usPort：待绑定端口；
*          bNonBlock：是否设置成非阻塞模式；
*          bCloExec：是否close-on-exec during a successful execve；
*          phSocket：指向未创建前的UDP服务器端套接字。
*
* 输出参数: phSocket：指向创建后的UDP服务器端套接字
*
* 返 回 值: 无
*
* 注意事项: 无
***********************************************************************************************************************
*/

void CreateUDPServerSocket( uint32_t uiIPAddr, uint16_t usPort, bool_t bNonBlock, bool_t bCloExec, SOCKET *phSocket );

/*
***********************************************************************************************************************
* 函数名称: Connect
*
* 功能描述: 建立连接
*
* 输入参数: uiIPAddr：目标IP地址；
*          usPort：目标端口号；
*          bNonBlock：是否设置为非阻塞模式。
*
* 输出参数: phSocket：连接套接字，INVALID_SOCKET代表创建失败
*
* 返 回 值: 连接成功标志，true代表成功
*
* 注意事项: 无
***********************************************************************************************************************
*/

bool_t Connect( uint32_t uiIPAddr, uint16_t usPort, bool_t bNonBlock, SOCKET *phSocket );

#endif /*SOCKET_H_*/

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/


