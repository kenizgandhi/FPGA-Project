#include "xparameters.h"
#include "xgpio.h"
#include "switch1_ip.h"
#include "xuartps_hw.h"
#include "stdint.h"

//====================================================
#define BUTTON_DELAY 100000000

int main (void)
{

   XGpio button;
   int i ,dip_check, button_data= 0, switch_data;
   u8 Data;

   xil_printf("-- Start of the Program --\r\n");

   //XGpio_Initialize(&dip, XPAR_SWITCH1_IP_DEVICE_ID);
   //XGpio_Initialize(&dip, XPAR_AXI_GPIO_0_DEVICE_ID);
   //XGpio_SetDataDirection(&dip, 1, 0xffffffff);
   XGpio_Initialize(&button, XPAR_AXI_GPIO_0_DEVICE_ID);
   XGpio_SetDataDirection(&button, 1, 0xffffffff);
   xil_printf("\n PRESS BUTTON 1 WHEN YOU WISH TO READ THE VALUE \n\r");
   while (1){

	   button_data = XGpio_DiscreteRead(&button, 1);
	   	   if(button_data==0b0001)
	   	   {
	   		   for (i = 0; i < BUTTON_DELAY; i++);
	   		   SWITCH1_IP_mWriteReg(XPAR_SWITCH1_IP_S_AXI_BASEADDR, 0, 8);
	   		   dip_check = SWITCH1_IP_mReadReg(XPAR_SWITCH1_IP_S_AXI_BASEADDR, 0);
	   		   xil_printf(" Value is %x\r\n", dip_check);

	   		   xil_printf(" Enter Data you wish to write to custom IP Register\n\r");
	   		   Data = XUartPs_RecvByte(XPAR_PS7_UART_1_BASEADDR);
	   		   SWITCH1_IP_mWriteReg(XPAR_SWITCH1_IP_S_AXI_BASEADDR, 0, Data);
    		   dip_check = SWITCH1_IP_mReadReg(XPAR_SWITCH1_IP_S_AXI_BASEADDR, 0);
	   		   xil_printf(" User entered Data: %c\r\n", dip_check);

	   		   //dip_check = SWITCH1_IP_mReadReg(XPAR_SWITCH1_IP_S_AXI_BASEADDR, 0);
	   		   //xil_printf(" Switch Status %x\r\n", dip_check);

	   		   //xil_printf("\n PRESS BUTTON 1 WHEN YOU WISH TO READ THE VALUE  AGAIN \n\r");
	   	   }
   }

}
