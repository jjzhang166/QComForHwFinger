#ifndef ZFM903_COM_H
#define ZFM903_COM_H


// 类型定义
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




// 返回值常数定义
#define   FALSE                 0x00
#define   TRUE                  0x01
#define   OVER_TIME_S		0xfe
#define   OVER_TIME_R		0xfd


// 时间常数定义
#define	  T_300MS		30
#define	  T_500MS		50
#define   T_1S			100
#define   T_5S			500


// 指纹模块相关常数定义
//FG_STATUS指纹工作状态
#define  FG_NONE                0               // 待机
#define  FG_ADD                 1               // 注册
#define  FG_SEA                 2               // 搜索
#define  FG_DEL                 3               // 删除


//命令代码表

#define   CMD_ECHO      0x16//0x53   //握手


#define   CMD_GET_IMAGE      0x01   //录指纹图像
//#define   CMD_ENROLL		0x10		// 开始指纹注册

#define   CMD_IMG2TZ		0x02		// 图像转特征
#define   CMD_MATCH		0x03		// 对比特征
#define   CMD_SERACH		0x04		// 搜索指纹
#define   CMD_REG_MODEL      0x05   //特征合成模板
#define   CMD_STORE		0x06		// 存储模板
#define   CMD_LOAD_CHAR		0x07		// 读出模板
#define   CMD_UP_CHAR		0x08		// 上传特征
#define   CMD_DOWN_CHAR		0x09		// 下载特征
#define   CMD_UP_IMAGE      0x0a   //上传图像
#define   CMD_DOWN_IMAGE      0x0b   //下载图像
#define   CMD_DEL_CHAR		0x0c		// 删除模板
#define   CMD_CLEAR_ALL_TEMPLATE		0x0d		// 清空指纹库
#define   CMD_SET_SYS		0x0e		// 设置系统参数
#define   CMD_READ_SYS		0x0f		// 读系统参数
#define   CMD_SET_PWD		0x12		// 设置口令
#define   CMD_VFY_PWD		0x13		//校验口令
#define   CMD_GET_RANDOM		0x14		//采样随机数
#define   CMD_SET_ADDR		0x15		//设置地址

#define   CMD_WR_NOTEPAD		0x18		//写记事本
#define   CMD_RD_NOTEPAD		0x19		//读记事本


#define   CMD_GET_TEMPLATE_NUM      0x1d   //读指纹模板数
#define   CMD_READ_TEMPLATE_LIST      0x1f   //读指纹模板索引表


#define CMD_UP_IMAGE_TEST    0x50     //上传指纹图片，用于测试


#define   CMD_ALOGIN		0x54		// 自动注册



//应答确认码表
#define   ERR_OK      0x00   //指令执行完毕或OK
#define   ERR_DATA_ERR      0x01   //数据包接收错误
#define   ERR_NO_DETECT_FINGER      0x02   //传感器上没有手指
#define   ERR_GET_IMAGE      0x03   //录入指纹图像失败

#define   ERR_IMG2TZ1      0x06   //指纹图像太乱而生不成特征
#define   ERR_IMG2TZ2      0x07   //指纹图像正常，但特征太少而生不成特征
#define   ERR_MATCH      0x08   //指纹不匹配
#define   ERR_SERACH      0x09   //没搜索到指纹
#define   ERR_REG_MODEL      0x0a   //特征合并失败
#define   ERR_GET_TEMPLATE_NUM      0x0b   //访问指纹库时地址序号超出指纹库范围。
#define   ERR_LOAD_CHAR      0x0c   //从指纹库读模板出错或无效。
#define   ERR_UP_CHAR      0x0d   //上传特征失败
#define   ERR_RECV_DATA      0x0e   //模块不能接受后续数据包
#define   ERR_UP_IMAGE      0x0f   //上传图像失败
#define   ERR_DEL_CHAR      0x10   //删除模板失败
#define   ERR_CLEAR_ALL_TEMPLATE      0x11   //清空指纹库失败
#define   ERR_VFY_PWD      0x13   //口令不对
#define   ERR_IMAGE      0x15   //缓冲区内没有有效原始图而生不成图像
#define   ERR_FLASH      0x18   //读写FLASH出错
#define   ERR_REG      0x1a   //无效寄存器号
#define   ERR_ADDR      0x20   //地址码错误
#define   ERR_INPUT_PWD      0x21   //必须验证口令




#define   RBUF_LEN		16		// 串口接收缓存长度
#define   FG_MAX		29		// 使用指纹模板最大数

#define   FG_2X   		0		// 指安20系列模块
#define   FG_6X   		1		// 指安60、70系列模块

#define   FG_TPYE		FG_6X		// 指安模块系列选择，只能选择FG_2X或者FG_6X
#if (FG_TPYE == FG_2X)
    #define FG_GETIMG_5S   	0x1c 		// 20系列采集图像5秒超时基数(有效取值为1~255)
#elif (FG_TPYE == FG_6X)
    #define FG_GETIMG_5S	0x4d 		// 60、70系列采集图像5秒超时基数(有效取值为1~255)
#endif

#define   FG_GETIMG_CNT   	2 		// 自动注册待指次数，只能设置为2或3


// 外调函数定义


#endif // ZFM903_COM_H

