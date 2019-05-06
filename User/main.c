

#include "includes.h"


CanTxMsg DTCCmd = {0x7E0,0,CAN_ID_STD,CAN_RTR_DATA,8,0x02,0x10,0x03,0x00,0x00,0x00,0x00,0x00};

int main(void)
{
  ErrorStatus *err;
  CAN_Config(CAN_500K);
  NVIC_Config();
  CAN1_Config16BitFilter(0x700, 0x700, 0x700, 0x700);
  Send_CANFrame(&DTCCmd,err);
  while(1);
}
