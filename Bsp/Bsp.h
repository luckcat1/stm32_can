
#ifndef __BSP_H
#define __BSP_H

/**************************结构类型************************************/
typedef enum {APB1 = 0, APB2} APBType;
typedef enum {OFF = 0, ON} SwitchType;
/**************************函数声明************************************/
void PC_USART_Config(u32 Baud);
void NVIC_Config(void);
void LED_Config(void);
void LED_ONOFF(SwitchType sw);
void CAN_GPIOConfig(void);
void CAN_Config(u8 velocity);
void CAN1_Config32BitFilter(u32 id1, u32 id2, u32 mid1, u32 mid2);
void CAN1_Config16BitFilter(u16 id1, u16 id2, u16 mid1, u16 mid2);
u8* Send_CANFrame(CanTxMsg* TxMessage,ErrorStatus* err);
/**************************全局变量************************************/
extern __IO ErrorStatus RxFlay;
extern __IO u8 RxRAM[100];
/**************************PC串口配置**********************************/
#define RCC_APBxPeriph_PC_USART_IO  RCC_APB2Periph_GPIOA
#define RCC_APBxPeriph_PC_USART		RCC_APB1Periph_USART2
#define PC_USART_TXD				GPIO_Pin_2
#define PC_USART_RXD				GPIO_Pin_3
#define PC_USART_IO					GPIOA
#define PC_USART	                USART2
#define PC_PinRemap					DISABLE
#define PC_USARTAPB					APB1
#define PC_USART_IRQHandler			USART2_IRQHandler
/**************************LED配置*************************************/
#define RCC_APBxPeriph_LED_IO	    RCC_APB2Periph_GPIOA
#define LED_D2						GPIO_Pin_6
#define LED_IO						GPIOA
/**************************CAN配置*************************************/
#define CAN_500K                    4
#define CAN_125K                    16
#define RCC_APBxPeriph_CAN_IO       RCC_APB2Periph_GPIOB
#define CAN_RXD					    GPIO_Pin_8
#define CAN_TXD						GPIO_Pin_9
#define CAN_IO						GPIOB
#define CAN_PinRemap				ENABLE
/**********************************************************************/
#endif
