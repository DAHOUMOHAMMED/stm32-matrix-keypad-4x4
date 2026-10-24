
#include <stdint.h>
#include <stdio.h>

void delay()
{
	for(uint32_t i = 0 ; i<= 300000 ; i++);
}

volatile uint32_t *const pPortDOutreg      =  (volatile uint32_t*) 0x48000C14;
volatile uint32_t *const pPortDINReg       =  (volatile uint32_t*) 0x48000C10;


void checkLine0();
void checkLine1();
void checkLine2();
void checkLine3();


int main(void)
{
	   volatile uint32_t *const pClkctrlreg       =  (volatile uint32_t*) 0x4002104C;
	   volatile uint32_t *const pPortDModeReg     =  (volatile uint32_t*) 0x48000C00;
	   volatile uint32_t *const pPortpull_up      =  (volatile uint32_t*) 0x48000C0C;



   //1 Enable the clock for GPIOD peripheral in AHB2 set the 3rd bit position

	   *pClkctrlreg|= (1<<3) ; //GPIOD


   //2 GPIOD PD0 PD1 PD2 PD3 port mode register as an output 01

	   *pPortDModeReg &= ~(0xFF<<16); // clear
	   *pPortDModeReg |=  0x55; // set

   //3 GPIOD PD8 PD9 PD10 PD11 port mode register as an INPUT 00

   	   *pPortDModeReg &= ~(0xFF<<16); // clear


   //2 GPIOD PD8 PD9 PD10 PD11 PULL-UP 01 COLUMN

      *pPortpull_up &= ~(0xFF<<16); // clear
      *pPortpull_up |=  (0x55<<16); // set


   while(1)
   {
	   // read pin status of the PA0

	   checkLine0();
	   checkLine1();
	   checkLine2();
	   checkLine3();



   }

}


void checkLine0()
{
	*pPortDOutreg = 0x0E;
	uint16_t pinstatus = (uint16_t)(*pPortDINReg & (1<<8));
	if(!pinstatus)
	{
		delay();
		printf("1\n");
		return;
	}

	pinstatus = (uint16_t)(*pPortDINReg & (1<<9));
	if(!pinstatus)
	{
		delay();
		printf("2\n");
		return;

	}

	pinstatus = (uint16_t)(*pPortDINReg & (1<<10));
	if(!pinstatus)
	{
		delay();
		printf("3\n");
		return;
	}

	pinstatus = (uint16_t)(*pPortDINReg & (1<<11));
	if(!pinstatus)
	{
		delay();
		printf("A\n");
		return;
	}


}
void checkLine1()
{
	*pPortDOutreg = 0x0D;
	uint16_t pinstatus = (uint16_t)(*pPortDINReg & (1<<8));
	if(!pinstatus)
	{
		delay();
		printf("4\n");
		return;
	}

	pinstatus = (uint16_t)(*pPortDINReg & (1<<9));
	if(!pinstatus)
	{
		delay();
		printf("5\n");
		return;

	}

	pinstatus = (uint16_t)(*pPortDINReg & (1<<10));
	if(!pinstatus)
	{
		delay();
		printf("6\n");
		return;
	}

	pinstatus = (uint16_t)(*pPortDINReg & (1<<11));
	if(!pinstatus)
	{
		delay();
		printf("B\n");
		return;
	}


}
void checkLine2()
{
	*pPortDOutreg = 0x0B;
	uint16_t pinstatus = (uint16_t)(*pPortDINReg & (1<<8));
	if(!pinstatus)
	{
		delay();
		printf("7\n");
		return;
	}

	pinstatus = (uint16_t)(*pPortDINReg & (1<<9));
	if(!pinstatus)
	{
		delay();
		printf("8\n");
		return;

	}

	pinstatus = (uint16_t)(*pPortDINReg & (1<<10));
	if(!pinstatus)
	{
		delay();
		printf("9\n");
		return;
	}

	pinstatus = (uint16_t)(*pPortDINReg & (1<<11));
	if(!pinstatus)
	{
		delay();
		printf("C\n");
		return;
	}


}
void checkLine3()
{
	*pPortDOutreg = 0x07;
	uint16_t pinstatus = (uint16_t)(*pPortDINReg & (1<<8));
	if(!pinstatus)
	{
		delay();
		printf("*\n");
		return;
	}

	pinstatus = (uint16_t)(*pPortDINReg & (1<<9));
	if(!pinstatus)
	{
		delay();
		printf("0\n");
		return;

	}

	pinstatus = (uint16_t)(*pPortDINReg & (1<<10));
	if(!pinstatus)
	{
		delay();
		printf("#\n");
		return;
	}

	pinstatus = (uint16_t)(*pPortDINReg & (1<<11));
	if(!pinstatus)
	{
		delay();
		printf("D\n");
		return;
	}


}





