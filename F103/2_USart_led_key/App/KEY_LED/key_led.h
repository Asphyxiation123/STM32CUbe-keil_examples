#ifndef _KEY_LED_H
#define _KEY_LED_H
#endif

#include "main.h"
#include "gpio.h"
typedef enum{
	KEY_NONE=0,//无按键被按下
	key_Wakeup=1,//按键wakeup被按下
	key0=2,//按键key0被按下
	key1=3
}KEYS;

#ifdef led0_Pin
	#define led0_toggle() HAL_GPIO_TogglePin(led0_GPIO_Port,led0_Pin);
	#define led0_on() HAL_GPIO_WritePin(led0_GPIO_Port,led0_Pin,GPIO_PIN_RESET);
	#define led0_off() HAL_GPIO_WritePin(led0_GPIO_Port,led0_Pin,GPIO_PIN_SET);
	
#endif

#ifdef led1_Pin
	#define led1_toggle() HAL_GPIO_TogglePin(led1_GPIO_Port,led1_Pin);
	#define led1_on() HAL_GPIO_WritePin(led1_GPIO_Port,led1_Pin,GPIO_PIN_RESET);
	#define led1_off() HAL_GPIO_WritePin(led1_GPIO_Port,led1_Pin,GPIO_PIN_SET);
	
#endif
KEYS Scankey(uint32_t timeout);//扫描按键按下情况
void key2led(uint32_t timeout);//按键控制led
