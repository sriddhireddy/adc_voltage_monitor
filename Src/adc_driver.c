#include "adc_driver.h"

#define ADC1EN			(1U<<8)
#define GPIOAEN			(1U<<0)

//alr defined in CMSIS
//#define ADC_CR2_ADON	(1U<<0)

#define ADC_SQ1_CH1 	(1U) //as its a value not a bit. for ch1-> (1U) for ch5: (5U)

//alr defines these macros in CMSIS

//#define ADC_CR2_SWSTART		(1U<<30)
//#define ADC_SR_EOC		(1U<<1)


void ADC_Init(void){

	RCC->APB2ENR |= ADC1EN;
	RCC->AHB1ENR |= GPIOAEN;

	GPIOA->MODER &=~(3U<<2); //clear bits 3:2
	GPIOA->MODER |= (3U<<2); //11 to bits 3:2

	GPIOA->PUPDR &=~(3U<<2); //no pull-up, pull-down

	ADC1->CR2 |= ADC_CR2_ADON;

	ADC1->SQR3 = ADC_SQ1_CH1;

}

uint16_t ADC_Read(void){

	ADC1->CR2 |= ADC_CR2_SWSTART;

	while(!(ADC1->SR & ADC_SR_EOC)){}

	return (ADC1->DR);

}



