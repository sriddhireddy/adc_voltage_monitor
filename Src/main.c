#include "adc_driver.h"
#include "uart_driver.h"
#include "systick_driver.h"

int main(void)
{
	UART_Init();

    UART_WriteString("Voltage Monitor Started\r\n");

    while(1){

    }
}
