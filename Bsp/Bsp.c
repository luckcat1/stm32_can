
/************************************************************************
*@文件: Bsp.h
*@作者:
*@版本:
*@日期:
*@描述:
************************************************************************/
#include "includes.h"


#if 1
#pragma import(__use_no_semihosting)             
                 
struct __FILE 
{ 
	int handle; 
	/* Whatever you require here. If the only file you are using is */ 
	/* standard output using printf() for debugging, no file handling */ 
	/* is required. */ 
}; 
/* FILE is typedef’ d in stdio.h. */ 
FILE __stdout;         
int _sys_exit(int x) 
{ 
	x = x; 
	return 0;
} 

int fputc(int ch, FILE *f)
{   

  while((PC_USART->SR&0x40) == 0);
  PC_USART->DR = (u8)ch;      
  return ch;
}
#endif


/************************************************************************
  * @描述:  串口配置
  * @参数:  Baud:串口波特率
  * @返回值: None
  **********************************************************************/
void PC_USART_Config(u32 Baud)
{
  u8 data;
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure;
  if (PC_USARTAPB == APB1)
  {
    RCC_APB2PeriphClockCmd(RCC_APBxPeriph_PC_USART_IO | RCC_APB2Periph_AFIO,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APBxPeriph_PC_USART,ENABLE);
  }
  else
  {
	RCC_APB2PeriphClockCmd(RCC_APBxPeriph_PC_USART_IO | RCC_APBxPeriph_PC_USART | RCC_APB2Periph_AFIO,ENABLE);
  }
  if (PC_PinRemap == ENABLE)
  {  				 
    GPIO_PinRemapConfig(GPIO_Remap_USART2,ENABLE);
  }
  GPIO_InitStructure.GPIO_Pin = PC_USART_TXD;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(PC_USART_IO,&GPIO_InitStructure);
    
  GPIO_InitStructure.GPIO_Pin = PC_USART_RXD;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(PC_USART_IO,&GPIO_InitStructure);

  USART_InitStructure.USART_BaudRate = Baud;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None ;
  USART_InitStructure.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;
  USART_Init(PC_USART,&USART_InitStructure);
  data = data;
  data = PC_USART->DR;
  data = PC_USART->SR;
  USART_ITConfig(PC_USART,USART_IT_RXNE,ENABLE);
  USART_Cmd(PC_USART,ENABLE);
}
/************************************************************************
  * @描述:  中断配置
  * @参数:  None
  * @返回值: None
  **********************************************************************/
void NVIC_Config(void)
{
  NVIC_InitTypeDef  NVIC_InitStructure;

  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
   
  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  NVIC_InitStructure.NVIC_IRQChannel = USB_LP_CAN1_RX0_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}

/************************************************************************
  * @描述:  LED配置
  * @参数:  None
  * @返回值: None
  **********************************************************************/
void LED_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APBxPeriph_LED_IO,ENABLE);

  GPIO_InitStructure.GPIO_Pin = LED_D2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(LED_IO,&GPIO_InitStructure);
  GPIO_WriteBit(LED_IO, LED_D2, Bit_SET);
}

/************************************************************************
  * @描述:  LED开关
  * @参数:  sw 
  * @返回值: None
  **********************************************************************/
void LED_ONOFF(SwitchType sw)
{
  if (sw == ON)
  {
    GPIO_WriteBit(LED_IO, LED_D2, Bit_RESET);
  }
  else
  {
    GPIO_WriteBit(LED_IO, LED_D2, Bit_SET);
  }
}
/************************************************************************
  * @描述:   CAN所用IO引脚配置
  * @参数:   None
  * @返回值: None
  **********************************************************************/
void CAN_GPIOConfig(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APBxPeriph_CAN_IO | RCC_APB2Periph_AFIO,ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1,ENABLE);
  GPIO_InitStructure.GPIO_Pin = CAN_RXD;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(CAN_IO, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = CAN_TXD;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(CAN_IO, &GPIO_InitStructure);
  if (CAN_PinRemap == ENABLE)
  { 
    GPIO_PinRemapConfig(GPIO_Remap1_CAN1,ENABLE);
  }
}
/************************************************************************
  * @描述:  CAN速率配置
  * @参数:  velocity 速率分频值
  * @返回值: None
  **********************************************************************/
void CAN_Config(u8 velocity)
{
  CAN_InitTypeDef  CAN_InitStructure;

  CAN_GPIOConfig();
  CAN_DeInit(CAN1);
  CAN_StructInit(&CAN_InitStructure);
    
  CAN_InitStructure.CAN_TTCM = DISABLE;
  CAN_InitStructure.CAN_ABOM = DISABLE;
  CAN_InitStructure.CAN_AWUM = DISABLE;
  CAN_InitStructure.CAN_NART = DISABLE;
  CAN_InitStructure.CAN_RFLM = DISABLE;
  CAN_InitStructure.CAN_TXFP = DISABLE;
  CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;
  CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;
  CAN_InitStructure.CAN_BS1 = CAN_BS1_11tq;
  CAN_InitStructure.CAN_BS2 = CAN_BS2_6tq;
  CAN_InitStructure.CAN_Prescaler = velocity;
  CAN_Init(CAN1, &CAN_InitStructure);
}
/************************************************************************
  * @描述:  CAN扩展帧滤波器设置
  * @参数:  id1,id2 效验码   mid1,mid2 屏蔽码
  * @返回值: None
  **********************************************************************/
void CAN1_Config32BitFilter(u32 id1, u32 id2, u32 mid1, u32 mid2)
{
  CAN_FilterInitTypeDef  CAN_FilterInitStructure;
  CAN_FilterInitStructure.CAN_FilterNumber = 0;
  CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;
  CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;  
  CAN_FilterInitStructure.CAN_FilterIdHigh = id1>>13;
  CAN_FilterInitStructure.CAN_FilterIdLow = (id1<<3)|4;
  CAN_FilterInitStructure.CAN_FilterMaskIdHigh = mid1>>13;
  CAN_FilterInitStructure.CAN_FilterMaskIdLow = (mid1<<3)|4;
  CAN_FilterInitStructure.CAN_FilterFIFOAssignment = 0;
  CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
  CAN_FilterInit(&CAN_FilterInitStructure);
  CAN_FilterInitStructure.CAN_FilterNumber = 1;
  CAN_FilterInitStructure.CAN_FilterIdHigh = id2>>13;
  CAN_FilterInitStructure.CAN_FilterIdLow = (id2<<3)|4;
  CAN_FilterInitStructure.CAN_FilterMaskIdHigh = mid2>>13;
  CAN_FilterInitStructure.CAN_FilterMaskIdLow = (mid2<<3)|4;
  CAN_FilterInit(&CAN_FilterInitStructure);
  CAN_ITConfig(CAN1, CAN_IT_FMP0, ENABLE);
}
/************************************************************************
  * @描述:  CAN标准帧滤波器设置
  * @参数:  id1,id2 效验码   mid1,mid2 屏蔽码
  * @返回值: None
  **********************************************************************/
void CAN1_Config16BitFilter(u16 id1, u16 id2, u16 mid1, u16 mid2)                                                                             
{                                                                                                                         
    CAN_FilterInitTypeDef  CAN_FilterInitStructure;                                                                       
                                                                                                                          
    CAN_FilterInitStructure.CAN_FilterNumber=1;                                                                           
    CAN_FilterInitStructure.CAN_FilterMode=CAN_FilterMode_IdMask;                                                         
    CAN_FilterInitStructure.CAN_FilterScale=CAN_FilterScale_16bit;                                                        
    CAN_FilterInitStructure.CAN_FilterIdHigh=id1<<5;                                                                      
    CAN_FilterInitStructure.CAN_FilterIdLow=id2<<5;                                                                       
    CAN_FilterInitStructure.CAN_FilterMaskIdHigh=mid1<<5;                                                                  
    CAN_FilterInitStructure.CAN_FilterMaskIdLow=mid2<<5;                                                                   
    CAN_FilterInitStructure.CAN_FilterFIFOAssignment=CAN_FIFO0;                                                           
    CAN_FilterInitStructure.CAN_FilterActivation=ENABLE;                                                                  
                                                                                                                          
    CAN_FilterInit(&CAN_FilterInitStructure);
	CAN_ITConfig(CAN1, CAN_IT_FMP0, ENABLE);                                                                             
}

/************************************************************************
  * @描述:  发送一帧CAN数据(基于汽车诊断)
  * @参数:  
  * @返回值: None
  **********************************************************************/
__IO ErrorStatus RxFlay;
__IO u8 RxRAM[100];
u8* Send_CANFrame(CanTxMsg* TxMessage,ErrorStatus* err)
{
  u8 TransmitMailbox;
  u32 i;
  RxFlay = ERROR;

  TransmitMailbox = CAN_Transmit(CAN1, TxMessage);
  while(CAN_TransmitStatus(CAN1,TransmitMailbox) != CANTXOK);
  for (i = 0;i < 10000000/3;i++)	//大概等待1.5秒
  {
    if (RxFlay == SUCCESS) break;
  }
  *err = RxFlay;
  return (u8*)&RxRAM[0];
}





