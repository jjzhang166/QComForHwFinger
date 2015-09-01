
#include "ZFM903_COM.h"
//#include "yoyon_types.h"
#include "Lib_Define.h"
#include <string.h>
#include <stdarg.h>


uchar CharBuffer1[512],CharBuffer2[512];
//uchar ImageBuffer[256*288];
void UartExportImag(void);

//uchar const ZFM903_BAGHEAD[6] = {0xef,0x01,0xff,0xff,0xff,0xff};      // ��ͷ�͵�ַ��
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
// ��  ��  : ZFM903_GetSum()����У���                                //
// ��  ��  : *p          �����                              //
//           len         ���㳤��                              //
// ��  ��  : sum         �ۼӺ�                                //
// ��  ע  : ��                                                //
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


//����Ӧ���
uchar ZFM903_SendACK(uchar *pbuf ,int len)
{
    my_word sum;                                               // У���
	uchar *buf=ZFM903_SendBuf;
	
    // �����жϱ�ʾ�������Ӧ�������
    buf[0] = 0xef;                          // ��ͷ����
    buf[1] = 0x01;                          // ��ͷ����
    buf[2] = 0xff;                          // ģ���ַ����
    buf[3] = 0xff;                          // ģ���ַ����
    buf[4] = 0xff;                          // ģ���ַ����
    buf[5] = 0xff;                          // ģ���ַ����
    buf[6] = 0x07;                          // Ӧ�������ʶ����

    buf[7] = ((len+2)/256);                          // ����
    buf[8] = ((len+2)%256);                          // ����

	//buf[9] == 0x55; 
    memcpy(&buf[9],pbuf,len);

	//ZFM903_GetSum(&buf[6],len+3);
	sum.word = ZFM903_GetSum((uchar*)&buf[6],len+3);					// ��������У���

	buf[len+9]=sum.byte.high; 			 // У���
	buf[len+10]=sum.byte.low;			 // У���	

    Comm_Send(buf,len+11);

}



//�������ݰ�
uchar ZFM903_SendData(uchar *pbuf ,int len)
{
    my_word sum;                                               // У���
	uchar *buf=ZFM903_SendBuf;
	
    // �����жϱ�ʾ�������Ӧ�������
    buf[0] = 0xef;                          // ��ͷ����
    buf[1] = 0x01;                          // ��ͷ����
    buf[2] = 0xff;                          // ģ���ַ����
    buf[3] = 0xff;                          // ģ���ַ����
    buf[4] = 0xff;                          // ģ���ַ����
    buf[5] = 0xff;                          // ģ���ַ����
    buf[6] = 0x02;                          // �к������ݰ�

    buf[7] = ((len+2)/256);                          // ����
    buf[8] = ((len+2)%256);                          // ����

	//buf[9] == 0x55; 
    memcpy(&buf[9],pbuf,len);

	//ZFM903_GetSum(&buf[6],len+3);
	sum.word = ZFM903_GetSum((uchar*)&buf[6],len+3);					// ��������У���

	buf[len+9]=sum.byte.high; 			 // У���
	buf[len+10]=sum.byte.low;			 // У���	

    Comm_Send(buf,len+11);

}

//���ͽ������ݰ�
uchar ZFM903_SendDataEnd(uchar *pbuf ,int len)
{
    my_word sum;                                               // У���
	uchar *buf=ZFM903_SendBuf;
	
    // �����жϱ�ʾ�������Ӧ�������
    buf[0] = 0xef;                          // ��ͷ����
    buf[1] = 0x01;                          // ��ͷ����
    buf[2] = 0xff;                          // ģ���ַ����
    buf[3] = 0xff;                          // ģ���ַ����
    buf[4] = 0xff;                          // ģ���ַ����
    buf[5] = 0xff;                          // ģ���ַ����
    buf[6] = 0x08;                          // �������ݰ�

    buf[7] = ((len+2)/256);                          // ����
    buf[8] = ((len+2)%256);                          // ����

	//buf[9] == 0x55; 
    memcpy(&buf[9],pbuf,len);

	//ZFM903_GetSum(&buf[6],len+3);
	sum.word = ZFM903_GetSum((uchar*)&buf[6],len+3);					// ��������У���

	buf[len+9]=sum.byte.high; 			 // У���
	buf[len+10]=sum.byte.low;			 // У���	

    Comm_Send(buf,len+11);

}


//�������ݰ�
uchar ZFM903_RecvData(uchar *p ,uchar *outbuf,int *len)
{
	uchar ack;
	int i;
    uint num;                                                  // ����Ӧ��������ȼ���
    my_word sum;                                               // У���


	// �����жϱ�ʾ�������Ӧ�������
    if (p[0] != 0xef) return FALSE;                          // ��ͷ����
    if (p[1] != 0x01) return FALSE;                          // ��ͷ����
    if (p[2] != 0xff) return FALSE;                          // ģ���ַ����
    if (p[3] != 0xff) return FALSE;                          // ģ���ַ����
    if (p[4] != 0xff) return FALSE;                          // ģ���ַ����
    if (p[5] != 0xff) return FALSE;                          // ģ���ַ����

	num = p[7]*256+p[8];  //������
	//if(num!=len+2)
	//	return FALSE; 
	
	// ����Ӧ�����ϣ��ж�У���
	sum.word = ZFM903_GetSum((uchar*)&p[6],num+1);					// ������յ�����У���
	
	if (sum.byte.low != p[num+7]) return FALSE; 			 // У��ʹ���
	if (sum.byte.high != p[num+8]) return FALSE;			 // У��ʹ���	

    if(p[6]==0x02) //�к�����
	{
	  memcpy(outbuf,&p[9],num-2);
	  return 1;
	}
    else if(p[6]==0x08) //�޺�����
	{
	   memcpy(outbuf,&p[9],num-2);
	   return 2;
	}
	*len=num-2;

   return 0;
   
}



//����ָ���
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



