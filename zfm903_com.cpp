

#include "zfm903_com.h"
//#include "yoyon_types.h"
//#include "Lib_Define.h"
#include <string.h>
#include <stdarg.h>
//#include "mainwindow.h"

uchar CharBuffer1[512],CharBuffer2[512];
//uchar ImageBuffer[256*288];
void UartExportImag(void);

//uchar const ZFM903_BAGHEAD[6] = {0xef,0x01,0xff,0xff,0xff,0xff};      // 包头和地址码
uchar ZFM903_SendBuf[1024];
uchar ZFM903_RecvBuf[1024];

uchar PWD_VERIFY_OK=0;


int Comm_Send(uchar *p,uint len)
{
    ///return uart_send(p,len);

    //ui->Com_Send((char *)p,len);


}

int Comm_Recv(uchar* data,uint len,uint timeout)
{
   ///return Com_UartGetData(data,len,timeout);
}


//=============================================================//
//                                                             //
// 功  能  : ZFM903_GetSum()计算校验和                                //
// 输  入  : *p          命令缓存                              //
//           len         计算长度                              //
// 输  出  : sum         累加和                                //
// 备  注  : 无                                                //
//                                                             //
//=============================================================//
uint ZFM903_GetSum(uchar *p,uint len)
{
    uchar i;
    uint sum;

    sum = *p;
    for (i=1; i<len; i++)
    {
        sum += p[i];
    }

    return (sum);
}


//发送应答包
uchar ZFM903_SendACK(uchar *pbuf ,int len)
{
    my_word sum;                                               // 校验和
    uchar *buf=ZFM903_SendBuf;

    // 以下判断表示不处理非应答包数据
    buf[0] = 0xef;                          // 包头错误
    buf[1] = 0x01;                          // 包头错误
    buf[2] = 0xff;                          // 模块地址错误
    buf[3] = 0xff;                          // 模块地址错误
    buf[4] = 0xff;                          // 模块地址错误
    buf[5] = 0xff;                          // 模块地址错误
    buf[6] = 0x07;                          // 应答包包标识错误

    buf[7] = ((len+2)/256);                          // 长度
    buf[8] = ((len+2)%256);                          // 长度

    //buf[9] == 0x55;
    memcpy(&buf[9],pbuf,len);

    //ZFM903_GetSum(&buf[6],len+3);
    sum.word = ZFM903_GetSum((uchar*)&buf[6],len+3);					// 计算数据校验和

    buf[len+9]=sum.byte.high; 			 // 校验和
    buf[len+10]=sum.byte.low;			 // 校验和

    Comm_Send(buf,len+11);

}



//发送数据包
uchar ZFM903_SendData(uchar *pbuf ,int len)
{
    my_word sum;                                               // 校验和
    uchar *buf=ZFM903_SendBuf;

    // 以下判断表示不处理非应答包数据
    buf[0] = 0xef;                          // 包头错误
    buf[1] = 0x01;                          // 包头错误
    buf[2] = 0xff;                          // 模块地址错误
    buf[3] = 0xff;                          // 模块地址错误
    buf[4] = 0xff;                          // 模块地址错误
    buf[5] = 0xff;                          // 模块地址错误
    buf[6] = 0x02;                          // 有后续数据包

    buf[7] = ((len+2)/256);                          // 长度
    buf[8] = ((len+2)%256);                          // 长度

    //buf[9] == 0x55;
    memcpy(&buf[9],pbuf,len);

    //ZFM903_GetSum(&buf[6],len+3);
    sum.word = ZFM903_GetSum((uchar*)&buf[6],len+3);					// 计算数据校验和

    buf[len+9]=sum.byte.high; 			 // 校验和
    buf[len+10]=sum.byte.low;			 // 校验和

    Comm_Send(buf,len+11);

}

//发送结束数据包
uchar ZFM903_SendDataEnd(uchar *pbuf ,int len)
{
    my_word sum;                                               // 校验和
    uchar *buf=ZFM903_SendBuf;

    // 以下判断表示不处理非应答包数据
    buf[0] = 0xef;                          // 包头错误
    buf[1] = 0x01;                          // 包头错误
    buf[2] = 0xff;                          // 模块地址错误
    buf[3] = 0xff;                          // 模块地址错误
    buf[4] = 0xff;                          // 模块地址错误
    buf[5] = 0xff;                          // 模块地址错误
    buf[6] = 0x08;                          // 结束数据包

    buf[7] = ((len+2)/256);                          // 长度
    buf[8] = ((len+2)%256);                          // 长度

    //buf[9] == 0x55;
    memcpy(&buf[9],pbuf,len);

    //ZFM903_GetSum(&buf[6],len+3);
    sum.word = ZFM903_GetSum((uchar*)&buf[6],len+3);					// 计算数据校验和

    buf[len+9]=sum.byte.high; 			 // 校验和
    buf[len+10]=sum.byte.low;			 // 校验和

    Comm_Send(buf,len+11);

}


//接收数据包
uchar ZFM903_RecvData(uchar *p ,uchar *outbuf,int *len)
{
    uchar ack;
    int i;
    uint num;                                                  // 接收应答包包长度计数
    my_word sum;                                               // 校验和


    // 以下判断表示不处理非应答包数据
    if (p[0] != 0xef) return FALSE;                          // 包头错误
    if (p[1] != 0x01) return FALSE;                          // 包头错误
    if (p[2] != 0xff) return FALSE;                          // 模块地址错误
    if (p[3] != 0xff) return FALSE;                          // 模块地址错误
    if (p[4] != 0xff) return FALSE;                          // 模块地址错误
    if (p[5] != 0xff) return FALSE;                          // 模块地址错误

    num = p[7]*256+p[8];  //包长度
    //if(num!=len+2)
    //	return FALSE;

    // 接收应答包完毕，判断校验和
    sum.word = ZFM903_GetSum((uchar*)&p[6],num+1);					// 计算接收的数据校验和

    if (sum.byte.low != p[num+7]) return FALSE; 			 // 校验和错误
    if (sum.byte.high != p[num+8]) return FALSE;			 // 校验和错误

    if(p[6]==0x02) //有后续包
    {
      memcpy(outbuf,&p[9],num-2);
      return 1;
    }
    else if(p[6]==0x08) //无后续包
    {
       memcpy(outbuf,&p[9],num-2);
       return 2;
    }
    *len=num-2;

   return 0;

}



//握手指令处理
uchar ECHO_Pro(void)
{
    uchar ack=0x55;

    ZFM903_SendACK(&ack,1);

}






uchar ZFM903_CmdPro(void)
{
    int len;

    ///SystemInfoLoad();
    //FLASH_TEST();

    while(1)
    {
        len=Comm_Recv(ZFM903_RecvBuf,1024,50);
        if(len)
        {
            //DEBUG_PRINT("len=%d,data[0]=%d,data[%d]=%d\r\n",len,ZFM903_RecvBuf[0],len-1,ZFM903_RecvBuf[len-1]);
            //store_all_int();
            ///ZFM903_CmdComm(ZFM903_RecvBuf,len);
            ///restore_all_int();
        }
    }

}


/////////////////////////////////////////////////////////////////////
//1）验证口令 VfyPwd
//功能说明：验证模块口令（串行通讯必须进行的握手）。
//输入参数：PassWord
//返回参数：确认码
//指令代码：0x13

//★ 应答包校验和(2 bytes)=包标识(1 byte)+包长度(2 bytes)+确认码(1 byte)；
//★ 校验和以字节相加，超过2 字节的进位忽略，传送时高字节在前；
void CMD_Send_VfyPwd(void)
{
    my_word sum;       // 校验和
    uchar *buf=ZFM903_SendBuf;

    // 以下判断表示不处理非应答包数据
    buf[0] = 0xef;                          // 包头错误
    buf[1] = 0x01;                          // 包头错误

    //★ 默认模块地址为“0xffffffff”
    buf[2] = 0xff;                          // 模块地址错误
    buf[3] = 0xff;                          // 模块地址错误
    buf[4] = 0xff;                          // 模块地址错误
    buf[5] = 0xff;                          // 模块地址错误

    buf[6] = 0x01; // 命令包标识
    buf[7] = 0x00; // 长度
    buf[8] = 0x07; // 长度
    buf[9] = 0x13; // 指令代码：0x13

    //★ 默认口令为“0x00000000”。
    buf[10] = 0x00;//四字节口令
    buf[11] = 0x00;
    buf[12] = 0x00;
    buf[13] = 0x00;

    //★ 指令包校验和(2 bytes)=包标识(1 byte)+包长度(2 bytes)+指令码(1 byte)+口令(4 bytes)；
    sum.word = ZFM903_GetSum((uchar*)&buf[6],8);// 计算数据校验和

    buf[14]=sum.byte.high; 			 // 校验和
    buf[15]=sum.byte.low;			 // 校验和

    Comm_Send(buf,16);

}


//2）设置口令 SetPwd
//功能说明：设置模块口令（参见4.6模块口令）。
//输入参数：PassWord
//返回参数：确认字
//指令代码：0x12



//3） 设置模块地址 SetAddr
//功能说明：设置模块地址（参见4.7 模块地址）。
//输入参数：模块新地址（如遗忘地址，发送一条默认地址的正确指令，即可获得新地址）
//返回参数：确认字
//指令代码：0x15


//4）设置模块系统基本参数 SetSysPara
//功能说明：基本参数设置（参见4.4 系统配置参数）。
//输入参数：参数序号 + 内容
//返回参数：确认字
//指令代码：0x0e


//5）读系统参数 ReadSysPara
//功能说明：读取模块的状态寄存器和系统基本配置参数（参见4.4系统配置参数和4.5系统状态寄存器）。
//输入参数：none
//返回参数：确认字 + 基本参数
//指令代码：0x0f


//6) 读指纹模板索引表 ReadConList
//功能说明：读取模块指纹模板索引表，且每次最多读取256个指纹模板的索引表。
//输入参数：索引页
//索引页0代表读取0～255 指纹模板索引表
//索引页1代表读取256～511 指纹模板索引表
//索引页2代表读取512～767 指纹模板索引表
//索引页3代表读取768～1024指纹模板索引表
//返回参数：确认字 + 指纹模板索引表
//指令代码：0x1f


//7）读有效模板个数 TemplateNum
//功能说明：读模块内已存储的指纹模板个数。
//输入参数：none
//返回参数：确认字 + 模板个数N
//指令代码：0x1d
void CMD_Send_Get_TemplateNum(void)
{
    my_word sum;       // 校验和
    uchar *buf=ZFM903_SendBuf;

    // 以下判断表示不处理非应答包数据
    buf[0] = 0xef;                          // 包头错误
    buf[1] = 0x01;                          // 包头错误

    //★ 默认模块地址为“0xffffffff”
    buf[2] = 0xff;                          // 模块地址错误
    buf[3] = 0xff;                          // 模块地址错误
    buf[4] = 0xff;                          // 模块地址错误
    buf[5] = 0xff;                          // 模块地址错误

    buf[6] = 0x01; // 命令包标识
    buf[7] = 0x00; // 长度
    buf[8] = 0x03; // 长度
    buf[9] = 0x1d; // 指令代码：0x1d

    //★ 指令包校验和(2 bytes)=包标识(1 byte)+包长度(2 bytes)+指令码(1 byte)
    sum.word = ZFM903_GetSum((uchar*)&buf[6],4);// 计算数据校验和

    buf[10]=sum.byte.high; 			 // 校验和
    buf[11]=sum.byte.low;			 // 校验和

    Comm_Send(buf,12);
}




