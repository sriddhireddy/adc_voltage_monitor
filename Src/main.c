#include "adc_driver.h"
#include "uart_driver.h"
#include "systick_driver.h"

#define ADC_VREF			(3300U)
#define ADC_MAX_VALUE		(4095U)

int main(void)
{
	uint16_t analogValue;
	uint32_t millivolts;

	UART_Init();
	ADC_Init();
	SysTick_Init();

    UART_WriteString("Voltage Monitor Started\r\n");

    while(1){
    	analogValue = ADC_Read();

    	UART_WriteString("ADC Value: ");

    	UART_WriteUInt(analogValue);

    	UART_WriteString("\r\n");

    	UART_WriteString("Voltage: ");

    	millivolts = (analogValue * ADC_VREF) / ADC_MAX_VALUE;

//    	uint32_t volts = millivolts / 1000;
//    	uint32_t milli = millivolts % 1000;

    	UART_WriteUInt(millivolts);
    	UART_WriteString(" mV");

    	UART_WriteString("\r\n\r\n");
    	SysTick_DelayMs(1000);

    }

}

