
#include "ZFM903_COM.h"
//#include "yoyon_types.h"
#include "Lib_Define.h"
#include <string.h>
#include <stdarg.h>


uchar CharBuffer1[512],CharBuffer2[512];
//uchar ImageBuffer[256*288];
void UartExportImag(void);

//uchar const ZFM903_BAGHEAD[6] = {0xef,0x01,0xff,0xff,0xff,0xff};      // 包头和地址码
uchar ZFM903_SendBuf[1024];
uchar ZFM903_RecvBuf[1024];

uchar PWD_VERIFY_OK=0;


int Comm_Send(uchar *p,uint len)
{
	return uart_send(p,len);
}

int Comm_Recv(uchar* data,uint len,uint timeout)
{
   return Com_UartGetData(data,len,timeout);
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




//=============================================================//
void uart_print(const char * fmt, ...)
{
#if 1

	va_list ap;
	//char string[512];
	char string[256];

	va_start(ap,fmt);
	vsprintf(string,fmt,ap);
	//gpio_set_pin_level(GPIO_485_TXEN, 1);
	uart_send(string,strlen(string));
	//gpio_set_pin_level(GPIO_485_TXEN, 0);
	va_end(ap);
#endif
}


uchar ZFM903_CmdPro(void)
{
    int len;
	
	SystemInfoLoad();
	//FLASH_TEST();

	while(1)
	{
		len=Comm_Recv(ZFM903_RecvBuf,1024,50);
		if(len)
		{
			//DEBUG_PRINT("len=%d,data[0]=%d,data[%d]=%d\r\n",len,ZFM903_RecvBuf[0],len-1,ZFM903_RecvBuf[len-1]);
			store_all_int();
		    ZFM903_CmdComm(ZFM903_RecvBuf,len);
			restore_all_int();
		}
	}

}



