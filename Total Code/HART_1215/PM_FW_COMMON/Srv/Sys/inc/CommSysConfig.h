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
*  文件名称    : SysPMConfig.h
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

#ifndef COMM_SYS_PMCONFIG_H_
#define COMM_SYS_PMCONFIG_H_

/*
***********************************************************************************************************************
*                                包含头文件
***********************************************************************************************************************
*/
#include "inc/DataType.h"
#include "CommSysCMConfig.h"

/*
***********************************************************************************************************************
*                                宏定义
***********************************************************************************************************************
*/

#define MAX_DATA_AREA_NUM                      (0x03)

#define MAX_MOD_NUM                            (240U)//240
#define MAX_CHANNEL_NUM                        (32U)
#define MAX_SUBMOD_NUM                         (10U)                /*待定*/
#define MAX_INDEV_NUM                          (MAX_MOD_NUM)
#define MAX_OUTDEV_NUM                         (MAX_MOD_NUM)
#define IO_PARAM_LEN                           (200U)               /*待定*/
#define IO_MODDATA_LEN                         (200U)               /*待定*/
#define IO_HARD_PARAM_LEN                      (MAX_MOD_NUM*200)//240*200    /*待定*/









#define SECTION_CONTENT_SAME                   (0x01)
#define SECTION_CONTENT_NOTSAME                (0x00)

#define IO_MOD_NEW                             (0x00)
#define IO_MOD_SAME                            (0x01)
#define IO_MOD_CHANGE                          (0x02)

#define DRAM_INPUT_AREA_OFFSET                 (0x00000000)      /*待定*/
#define DRAM_OUTPUT_AREA_OFFSET                (0x00001000)      /*待定*/

#define MODTAG_PM                              (0x0101)
#define MODTAG_CM                              (0x0102)
#define MODTAG_BI                              (0x0103)
#define MODTAG_AI                              (0x0104)
#define MODTAG_AO                              (0x0105)
#define MODTAG_DI                              (0x0106)
#define MODTAG_DO                              (0x0107)
#define MODTAG_OSP                             (0x0108)

#define CHANNEL_TYPE_BOOL                      (0x00)
#define CHANNEL_TYPE_BYTE                      (0x01)
#define CHANNEL_TYPE_WORD                      (0x02)
#define CHANNEL_TYPE_DWORD                     (0x03)
#define CHANNEL_TYPE_REAL                      (0x04)

#define MODTYPE_INPUT                          (0x0001)
#define MODTYPE_OUTPUT                         (0x0002)
#define MODTYPE_INPUT_OUTPUT                   (0x0003)

#define MAX_SOE_VAR_NUM                        (5000U)//5000
#define MAX_SOE_VAR_SINGLE_BLOCK               (2000U)//2000
#define MAX_SOE_BLOCK_NUM                      (16U)//16
#define MAX_SOE_RECORD_NUM                     (100000U)


#define MAX_P2P_BLOCK_NUM                      (64U)//64
#define MAX_P2P_VAR_NUM                        (200U)//200            /*待定*/
#define P2P_SEND_BLOCK                         (0U)
#define P2P_RECV_BLOCK                         (1U)





#define MAX_RETAIN_NUM                         (500U)


#define UINT32_BITS                            (32U)             /* UINT32_BITS = 32 */
#define UINT16_BITS                            (16U)             /* UINT16_BITS = 16 */
#define UINT24_BITS                            (24U)             /* UINT24_BITS = 24 */
#define UINT8_BITS                             (8U)              /* UINT8_BITS = 8 */


#define UINT8_MASK                             (0xFF)            /* UINT8_MASK = 0xFF */
#define UINT16_MASK                            (0xFFFF)          /* UINT16_MASK = 0xFFFF */
#define UINT32_MASK                            (0xFFFFFFFF)      /* UINT32_MASK = 0xFFFFFFFF */

#define MAX_FUNC_NAME_LEN                      (80)
#define MAX_EXLIB_FUNC_NUM                     (100)

/*
***********************************************************************************************************************
*                                数据结构定义
***********************************************************************************************************************
*/

typedef enum
{
    SW_SOE = 0,                            /*软SOE*/
    HW_SOE,                                /*硬SOE*/
    INVALID_SOE_TYPE
}SOEType_t;

#pragma pack (1)


/* LogicConfigInfo struct  Prg信息结构体定义 */
typedef struct LogicConfigInfoTag
{
    uint32_t uiCRC;
    uint32_t uiFileVern;
    uint32_t uiDataAreaUsedSize[MAX_DATA_AREA_NUM];
    uint32_t uiMachineCodeLen;
    uint32_t uiMaxPous;
    uint32_t uiLoadAddr;
}LogicConfigInfo_t;


typedef struct ExLibFuncInfoTag
{
    uint32_t uiRelocOffset;                         /*数据区内存放函数地址的相对偏移（相对G区）*/
    char_t cFuncName[MAX_FUNC_NAME_LEN];
}ExLibFuncInfo_t;

typedef struct ExLibConfigInfoTag
{
    uint32_t uiExLibFuncNum;
    ExLibFuncInfo_t stExLibFuncInfo[MAX_EXLIB_FUNC_NUM];
}ExLibConfigInfo_t;


/*P2P信息头结构体定义*/
typedef struct P2PConfigHeadTag
{
    uint32_t uiRecvBlockNum;
    uint32_t uiSendBlockNum;
}P2PConfigHead_t;

/*P2P块信息头结构体定义*/
typedef struct P2PBlockHeadTag
{
    uint32_t uiBlockID;
    uint16_t usUpdateFlag;              /*更新标志，0：P2P块配置信息未变化；1：P2P块配置信息变化；2：P2P块配置信息为新增；*/
    uint8_t ucCMID1;                    /*配置的P2P第一个网口所属CM号，若没配置，为0*/
    uint8_t ucNetID1;                   /*1：使用NET1通讯；2：使用NET2通讯，若没配置，为0*/
    uint8_t ucCMID2;                    /*配置的P2P第二个网口所属CM号，若没配置，为0*/
    uint8_t ucNetID2;                   /*1：使用NET1通讯；2：使用NET2通讯，若没配置，为0*/
    uint16_t usCommProperty;
    uint32_t uiTargetStationID;
    uint32_t uiTargetStationIP1;
    uint32_t uiTargetStationIP2;
    uint32_t uiPeriod;
    uint32_t uiP2PVarNum;
}P2PBlockHead_t;

/*P2P变量结构体定义*/
typedef struct P2PVarTag
{
    uint8_t ucTaskID;
    uint8_t ucRefID;
    uint16_t usVarSize;
    uint32_t uiOffset;
//    uint32_t uiSafetyValue;       /*P2P变量是否有安全值*/
}P2PVar_t;

/*P2P块结构体定义*/
typedef struct P2PBlockTag
{
    ActiveFlag_t emActive;             /*是否有有效配置信息*/
    P2PBlockHead_t stP2PBlockHead;
    P2PVar_t stP2PVar[MAX_P2P_VAR_NUM];
}P2PBlock_t;

/*P2P配置信息结构体定义*/
typedef struct P2PConfigInfoTag
{
    uint32_t uiCRC;
    uint32_t uiFileVern;
    P2PConfigHead_t stP2PConfigHead;
    P2PBlock_t stP2PRecvBlockInfo[MAX_P2P_BLOCK_NUM + 1];
    P2PBlock_t stP2PSendBlockInfo[MAX_P2P_BLOCK_NUM + 1];
}P2PConfigInfo_t;

/*Retain变量结构体定义*/
typedef struct RetainVarTag
{
    uint8_t ucTaskID;
    uint8_t ucRefID;
    uint16_t usVarSize;
    uint32_t uiOffset;
}RetainVar_t;

/*Retain信息结构体定义*/
typedef struct RetainVarInfoTag
{
    uint32_t uiCRC;
    uint32_t uiFileVern;
    uint32_t uiUPVarNum[MAX_TASK_NUM];
    RetainVar_t stRetainVar[MAX_TASK_NUM][MAX_RETAIN_NUM];
}RetainVarInfo_t;


///*硬SOE块信息结构体定义*/
//typedef struct SOE_HW_BlockTag
//{
//    ActiveFlag_t emActive;
//    uint32_t uiBlockID;
//    uint16_t usBlockType;               /*SOE块的类型，取值UNASSIGNED、EXTERNAL、FIRST OUT、HISTORY、OPC等*/
//    uint8_t	ucReserved[2];
//    uint32_t uiMaxRecordCount;          /*单个SOE块保存的SOE记录条数上限*/
//}SOE_HW_Block_t;

/*软SOE点信息结构体定义*/
typedef struct SoftSOEVarTag
{
    uint8_t ucTaskID;
    uint8_t ucRefID;
    uint16_t usVarSize;
    uint32_t uiOffset;
}SoftSOEVar_t;

///*硬SOE点信息结构体定义*/
//typedef struct SOE_HW_VarTag
//{
//    uint32_t uiModID;                   /*所属块号*/
//    uint32_t uiChannelID;
//}SOE_HW_Var_t;

/*软SOE块信息结构体定义*/
typedef struct SoftSOEBlockTag
{
    ActiveFlag_t emActive;
    uint16_t usBlockType;               /* SOE块的类型，取值UNASSIGNED、EXTERNAL、FIRST OUT、HISTORY、OPC等*/
    uint8_t ucReserved[2];
    uint32_t uiMaxRecordCount;          /*单个SOE块保存的SOE记录条数上限*/
    uint32_t uiSoftSOEVarNum;
    uint32_t uiSoftSOEVarIndex;
    uint32_t uiSW_BaseAddr;
}SoftSOEBlock_t;

///*IO模块SOE信息结构体定义*/
//typedef struct ModuleSOEInfoTag
//{
//    ActiveFlag_t emActive;
//    ActiveFlag_t emSOE_HW_Var[MAX_CHANNEL_NUM];
//}ModuleSOEInfo_t;

/*SOE配置信息结构体定义*/
typedef struct SOEConfigInfoTag
{
    uint32_t uiCRC;
    uint32_t uiFileVern;
    uint8_t  ucSoftSOEBlockNum[MAX_TASK_NUM];
    uint8_t ucSoftSOEBlockTable[MAX_TASK_NUM][MAX_SOE_BLOCK_NUM];
    SoftSOEBlock_t stSoftSOEBlock[MAX_SOE_BLOCK_NUM];
    SoftSOEVar_t stSoftSOEVar[MAX_SOE_VAR_NUM];
}SOEConfigInfo_t;






///*VOTE通道信息结构体定义*/
//typedef struct VoteChannelInfoTag
//{
//    uint8_t ucVoteType;
//    uint32_t uiSafetyValue;
//}VoteFileChannelInfo_t;

/*VOTE配置信息通道信息结构体定义*/
typedef struct VoteChannelInfoTag
{
    uint8_t ucVoteType;
    uint32_t uiSafetyValue;
}VoteChannelInfo_t;


/*VOTE模块信息结构体定义*/
typedef struct VoteModInfoTag
{
    ActiveFlag_t emActive;                  /*是否有有效配置信息*/
    uint16_t usChannelCount;
    VoteChannelInfo_t stVoteChannelInfo[MAX_CHANNEL_NUM];
}VoteModInfo_t;

/*VOTE信息结构体定义*/
typedef struct VOTEConfigInfoTag
{
    uint32_t uiCRC;
    uint32_t uiFileVern;
    uint32_t uiModNum;
    uint8_t ucModAddr[MAX_MOD_NUM];
    VoteModInfo_t stVoteModInfo[MAX_MOD_NUM];
}VOTEConfigInfo_t;





typedef struct IoParamIndexTag
{

    uint8_t ucModAddr;                      /* IO模块站号 */
    uint8_t ucChangeFlag;                   /* IO变更标识：0：模块是新增的；1：模块信息和上一次成功下装的一样；2：模块信息和上一次成功下装的不一样；*/
    uint8_t ucModType;                      /* IO模块类型（输入模块、输出模块、输入输出模块） */
    uint8_t ucReserve;                      /* 预留 */
    uint16_t usInputAreaOffset;             /*输入区地址偏移*/
    uint16_t usInputAreaDataLen;            /*输入数据长度*/
    uint16_t usOutputAreaOffset;            /*输出区地址偏移*/
    uint16_t usOutputAreaDataLen;           /*输出数据长度*/
    uint16_t usParamAreaOffset;             /*参数区地址偏移*/
    uint16_t usParamAreaDataLen;            /*参数数据长度*/

}IoParamIndex_t;

/* IO parameter  struct  IO参数结构体定义 */
typedef struct SysIoParamAreaTag
{
    uint8_t ucModNum;
    uint8_t usReserve;
    uint16_t usIoParamIndex;
    IoParamIndex_t stIoParamIndex[MAX_MOD_NUM];
    uint8_t ucIoParam[IO_HARD_PARAM_LEN];
}SysIoParamArea_t;


typedef struct SysIoChannelInfoTag
{
    uint8_t ucChannelNum;                   /*通道序号*/
    uint8_t ucChannelType;                  /*通道数据类型*/
    uint8_t ucRefId;                        /*通道所占的数据区 (1=input, 2=output,)*/
    uint32_t uiBitOffset;                   /*通道在数据区的位偏移*/
}SysIoChannelInfo_t;

typedef struct SysIoSubModInfoTag
{

}SysIoSubModInfo_t;

/* device mapping table struct  设备映射表结构体定义 */
typedef struct SysIoDevInfoTag
{
    uint16_t usModTag;                                              /* IO模块类型 */
    uint16_t usDualInputSize;                                       /* 双口RAM输入区中数据长度 */
    uint32_t uiDualInputOffset;                                     /* 双口RAM输入区中偏移地址 */
    uint16_t usDualOutputSize;                                      /* 双口RAM输出去中数据长度 */
    uint32_t uiDualOutputOffset;                                    /* 双口RAM输出区中偏移地址 */
    uint32_t uiIecOffset;                                           /* 工程数据区偏移地址 */
    uint16_t usIecSize;                                             /* IEC数据区长度 */
    uint16_t usChannelNum;
    SysIoChannelInfo_t stSysIoChannelInfo[MAX_CHANNEL_NUM];
}SysIoDevInfo_t;

/* IO module mapping table struct  IO模块映射表结构体定义 */
typedef struct SysIoSlaveInfoTag
{
    uint16_t usInDevNum[MAX_TASK_NUM];                              /* 输入设备数目 */
    uint16_t usOutDevNum[MAX_TASK_NUM];                             /* 输出设备数目 */
    uint8_t ucInDevTabl[MAX_TASK_NUM][MAX_INDEV_NUM];               /* 输入设备统计表，记录输入设备的ID号*/
    uint8_t ucOutDevTabl[MAX_TASK_NUM][MAX_OUTDEV_NUM];             /* 输出设备统计表，记录输出设备的ID号*/
    SysIoDevInfo_t stDevInfo[MAX_MOD_NUM];                          /* 输入输出设备映射表 ，记录输出设备配置信息，以设备ID号为下标 */

}SysIoSlaveInfo_t;

/*PM配置信息*/
typedef struct SysPMInfoTag
{
    uint16_t usMinTsdr;
    uint16_t usMaxTsdr;
    uint16_t usCycResTime;
    uint16_t usAcyResTime;
    uint16_t usMaxRetryLimit;
    uint16_t usPPM;
    uint16_t usPPMSource;
    uint16_t usPPMPolarity;
    uint16_t usErrHandle;
    uint16_t usFirstErrRetry;
}SysPMInfo_t;

/* IO module information  struct  IO模块信息结构体定义 */
typedef struct SysIoModInfoTag
{
    uint32_t uiCRC;
    uint32_t uiFileVern;
    uint32_t uiModNum;
    SysIoParamArea_t stSysIoParamArea;      /* data of IO parameter zone IO参数区数据 */
    SysIoSlaveInfo_t stSysIoSlaveInfo;      /*IO Slave module information IO从站模块信息 */
    SysPMInfo_t stSysPMInfo;
}SysIoModInfo_t;



typedef struct SegmentUsedHeadTag
{
    uint32_t uiSegmentUsedEntryNum;         /*Segment Used Entry个数*/
    uint32_t uiReserverd;                   /*保留*/
}SegmentUsedHead_t;

typedef struct SegmentUsedTag
{
    uint32_t uiSegmentId;                   /*数据区ID，（目前，G，I，O）*/
    uint32_t uiSizeUsed;                    /*使用的大小*/
}SegmentUsed_t;

typedef struct ProgramHeadTag
{
    uint32_t uiReserved1;
    uint32_t uiReserved2;
    uint32_t uiMachineCodeLen;
    uint32_t uiMaxPous;
    uint32_t uiFunctionEntryNum;
    uint32_t uiLoadAddr;
    uint32_t uiReserved3;
    uint32_t uiReserved4;
}ProgramHead_t;

typedef struct IOModuleConfigHeadTag
{
    uint8_t ucEntryTag;                     /*入口标志‘M’*/
    uint8_t ucChangeFlag;                   /*0：模块是新增的  1：模块信息和上一次成功下装的一样；  2：模块信息和上一次成功下装的不一样；*/
    uint16_t usModuleTag;                   /*模块类型 */
    uint32_t uiNodeId;                      /*节点ID，在组态中当作地址来用*/
    uint32_t uiBitOffsetInput;              /*输入区的位偏移*/
    uint32_t uiBitSizeInput;                /*输入区的位大小*/
    uint32_t uiBitOffsetOutput;             /*输出区的位偏移*/
    uint32_t uiBitSizeOutput;               /*输出区的位大小*/
}IOModuleConfigHead_t;

typedef struct IOModuleDataTag
{
    uint32_t uiDualInputOffset;             /*模块数据在双口输入区的偏移*/
    uint32_t uiDualInputSize;               /*模块数据在双口输入区的长度*/
    uint32_t uiDualOutputOffset;            /*模块数据在双口输出区的偏移*/
    uint32_t uiDualOutputSize;              /*模块数据在双口输出区的长度*/
    uint32_t uiDualParamOffset;             /*模块数据在双口输出区的偏移*/
    uint32_t uiDualParamSize;               /*模块数据在双口输出区的长度*/
    uint8_t ucTaskID;                       /*模块所属的任务*/

}IOModuleData_t;

/*SOE文件中SOE块的信息结构*/
typedef struct SOE_Block_InfoTag
{
    uint32_t uiBlockID;                     /*SOE块号*/
    uint16_t usBlockType;                   /*SOE块的类型，取值UNASSIGNED、EXTERNAL、FIRST OUT、HISTORY、OPC等*/
    uint16_t usReserved;                 
    uint32_t uiMaxRecordCount;              /*单个SOE块保存的SOE记录条数上限*/
    uint32_t uiSOEVarNum;                   /*SOE块中变量的个数*/
}SOE_Block_Info_t;


#pragma pack ()

/*
***********************************************************************************************************************
*                                全局函数声明
***********************************************************************************************************************
*/
/*
*********************************函数描述******************************************************************************
* 函数名称: SysCheckCMSlotID
*
* 功能描述: 完成对CM Config文件的解析配置
*
* 输入参数: 无
*
* 输出参数: 无
*
* 返 回 值: 无
*
* 注意事项:
***********************************************************************************************************************
*/
uint32_t SysCheckCMSlotID(uint32_t uiCMSlotID,CMSlotIdTabl_t* pstCMSlotIdTabl);


#endif /* COMM_SYS_PMCONFIG_H_ */

/*
***********************************************************************************************************************
                                 文件结束
***********************************************************************************************************************
*/

