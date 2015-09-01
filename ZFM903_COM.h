#ifndef _ZFM903_COM_H_
#define _ZFM903_COM_H_

// ���Ͷ���
#define   uchar                 unsigned char
#define   uint                  unsigned  int
#define   ulong                 unsigned long

typedef union 
{
	unsigned int word;
	struct double_byte
	{
		unsigned char low;
		unsigned char high;
	}byte;
}my_word;

typedef union 
{
	unsigned int word;
	struct double_word
	{
		unsigned char low1;
		unsigned char low2;
		unsigned char high1;
		unsigned char high2;
	}byte;
}DOUBLE_WORD;


typedef struct _fp_match
{
	unsigned char ack;
	unsigned short id;
	unsigned short score;
}fp_match;




// ����ֵ��������
#define   FALSE                 0x00
#define   TRUE                  0x01
#define   OVER_TIME_S		0xfe
#define   OVER_TIME_R		0xfd


// ʱ�䳣������
#define	  T_300MS		30
#define	  T_500MS		50
#define   T_1S			100
#define   T_5S			500


// ָ��ģ����س�������
//FG_STATUSָ�ƹ���״̬
#define  FG_NONE                0               // ����
#define  FG_ADD                 1               // ע��
#define  FG_SEA                 2               // ����
#define  FG_DEL                 3               // ɾ��


//��������

#define   CMD_ECHO      0x16//0x53   //����


#define   CMD_GET_IMAGE      0x01   //¼ָ��ͼ��
//#define   CMD_ENROLL		0x10		// ��ʼָ��ע��

#define   CMD_IMG2TZ		0x02		// ͼ��ת����
#define   CMD_MATCH		0x03		// �Ա�����
#define   CMD_SERACH		0x04		// ����ָ��
#define   CMD_REG_MODEL      0x05   //�����ϳ�ģ��
#define   CMD_STORE		0x06		// �洢ģ��
#define   CMD_LOAD_CHAR		0x07		// ����ģ��
#define   CMD_UP_CHAR		0x08		// �ϴ�����
#define   CMD_DOWN_CHAR		0x09		// ��������
#define   CMD_UP_IMAGE      0x0a   //�ϴ�ͼ��
#define   CMD_DOWN_IMAGE      0x0b   //����ͼ��
#define   CMD_DEL_CHAR		0x0c		// ɾ��ģ��
#define   CMD_CLEAR_ALL_TEMPLATE		0x0d		// ���ָ�ƿ�
#define   CMD_SET_SYS		0x0e		// ����ϵͳ����
#define   CMD_READ_SYS		0x0f		// ��ϵͳ����
#define   CMD_SET_PWD		0x12		// ���ÿ���
#define   CMD_VFY_PWD		0x13		//У�����
#define   CMD_GET_RANDOM		0x14		//���������
#define   CMD_SET_ADDR		0x15		//���õ�ַ

#define   CMD_WR_NOTEPAD		0x18		//д���±�
#define   CMD_RD_NOTEPAD		0x19		//�����±�


#define   CMD_GET_TEMPLATE_NUM      0x1d   //��ָ��ģ����
#define   CMD_READ_TEMPLATE_LIST      0x1f   //��ָ��ģ��������


#define CMD_UP_IMAGE_TEST    0x50     //�ϴ�ָ��ͼƬ�����ڲ���


#define   CMD_ALOGIN		0x54		// �Զ�ע��



//Ӧ��ȷ�����
#define   ERR_OK      0x00   //ָ��ִ����ϻ�OK
#define   ERR_DATA_ERR      0x01   //���ݰ����մ���
#define   ERR_NO_DETECT_FINGER      0x02   //��������û����ָ
#define   ERR_GET_IMAGE      0x03   //¼��ָ��ͼ��ʧ��

#define   ERR_IMG2TZ1      0x06   //ָ��ͼ��̫�Ҷ�����������
#define   ERR_IMG2TZ2      0x07   //ָ��ͼ��������������̫�ٶ�����������
#define   ERR_MATCH      0x08   //ָ�Ʋ�ƥ��
#define   ERR_SERACH      0x09   //û������ָ��
#define   ERR_REG_MODEL      0x0a   //�����ϲ�ʧ��
#define   ERR_GET_TEMPLATE_NUM      0x0b   //����ָ�ƿ�ʱ��ַ��ų���ָ�ƿⷶΧ��
#define   ERR_LOAD_CHAR      0x0c   //��ָ�ƿ��ģ��������Ч��
#define   ERR_UP_CHAR      0x0d   //�ϴ�����ʧ��
#define   ERR_RECV_DATA      0x0e   //ģ�鲻�ܽ��ܺ������ݰ�
#define   ERR_UP_IMAGE      0x0f   //�ϴ�ͼ��ʧ��
#define   ERR_DEL_CHAR      0x10   //ɾ��ģ��ʧ��
#define   ERR_CLEAR_ALL_TEMPLATE      0x11   //���ָ�ƿ�ʧ��
#define   ERR_VFY_PWD      0x13   //�����
#define   ERR_IMAGE      0x15   //��������û����Чԭʼͼ��������ͼ��
#define   ERR_FLASH      0x18   //��дFLASH����
#define   ERR_REG      0x1a   //��Ч�Ĵ�����
#define   ERR_ADDR      0x20   //��ַ�����
#define   ERR_INPUT_PWD      0x21   //������֤����




#define   RBUF_LEN		16		// ���ڽ��ջ��泤��
#define   FG_MAX		29		// ʹ��ָ��ģ�������

#define   FG_2X   		0		// ָ��20ϵ��ģ��
#define   FG_6X   		1		// ָ��60��70ϵ��ģ��

#define   FG_TPYE		FG_6X		// ָ��ģ��ϵ��ѡ��ֻ��ѡ��FG_2X����FG_6X
#if (FG_TPYE == FG_2X)
    #define FG_GETIMG_5S   	0x1c 		// 20ϵ�вɼ�ͼ��5�볬ʱ����(��ЧȡֵΪ1~255)
#elif (FG_TPYE == FG_6X)
    #define FG_GETIMG_5S	0x4d 		// 60��70ϵ�вɼ�ͼ��5�볬ʱ����(��ЧȡֵΪ1~255)
#endif

#define   FG_GETIMG_CNT   	2 		// �Զ�ע���ָ������ֻ������Ϊ2��3


// �����������



#endif
