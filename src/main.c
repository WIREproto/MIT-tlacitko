#include <stdbool.h>
#include <stm8s.h>
#include "main.h"
#include "milis.h"
//#include "delay.h"
//#include "uart1.h"
//#include <stdio.h>

// Discovery Board
#ifdef STM8S003
#define LED_PORT GPIOD
#define LED_PIN  GPIO_PIN_0
#define BTN_PORT GPIOB
#define BTN_PIN  GPIO_PIN_7
#endif
// Blue-Board, Dero-Board
#ifdef STM8S103
//   Dero-Board
/*#define LED_PORT GPIOD*/
/*#define LED_PIN  GPIO_PIN_4*/
//   Blue-Board
#define LED_PORT GPIOB
#define LED_PIN  GPIO_PIN_5
#endif
// Discovery Board
#ifdef STM8S105
#define LED_PORT GPIOD
#define LED_PIN  GPIO_PIN_0
#endif
// Nucleo Kit
#ifdef STM8S208
#define LED_PORT GPIOC
#define LED_PIN  GPIO_PIN_5
#define BTN_PORT GPIOE
#define BTN_PIN  GPIO_PIN_4
#endif


void init(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);      // taktovani MCU na 16MHz
    init_milis();

    GPIO_Init(LED_PORT, LED_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);

}


int main(void)
{
  
    uint32_t time = 0;
    bool tlcitkovas = PUSH(BTN);
    
    init();

    while (1) {
        if (milis() - time > 10 ) {
            
            time = milis();
            
            if(tlcitkovas == 0 && PUSH(BTN) == 1){  //tak by slo if(!tlcitkovas && PUSH(BTN))
                REVERSE(LED);
            }
            tlcitkovas = PUSH(BTN);
        }
        
    }
}

/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
