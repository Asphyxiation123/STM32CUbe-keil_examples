#include "key_led.h"

KEYS Scankey(uint32_t timeout)
{ //扫描按键按下情况
    KEYS key = KEY_NONE;
    uint32_t tickstart = HAL_GetTick();
    const uint32_t delaytime = 20; //延时20ms
    GPIO_PinState key_state;
    while ((1))
    {

        key_state = HAL_GPIO_ReadPin(key0_GPIO_Port, key0_Pin);
        if (key_state == GPIO_PIN_RESET)
        {
            
            HAL_Delay(delaytime);
            key_state = HAL_GPIO_ReadPin(key0_GPIO_Port, key0_Pin);
            if (key_state == GPIO_PIN_RESET)
            {
                return key0;
            }
        }
        key_state = HAL_GPIO_ReadPin(key1_GPIO_Port, key1_Pin);
        if (key_state == GPIO_PIN_RESET)
        {
            HAL_Delay(delaytime);
            key_state = HAL_GPIO_ReadPin(key1_GPIO_Port, key1_Pin);
            if (key_state == GPIO_PIN_RESET)
            {
                return key1;
            }
        }

        if (timeout != 0)
        {
            if ((HAL_GetTick() - tickstart) > timeout)
            {

                break;
            }
        }
    }
    return key;
}

void key2led(uint32_t timeout)
{

    switch (Scankey(timeout))
    {
    case key0:
        led0_on();
        led1_off();
        break;
    case key1:
        led1_on();
        led0_off();
        break;

    default:
        break;
    }
    HAL_Delay(300);
}
