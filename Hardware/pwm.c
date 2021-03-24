#include "pwm.h"
#include <rtthread.h>
#include "board.h"

//使用板载资源
#define LED_R "PE.1"
#define LED_G "PE.4"
#define LED_B "PA.2"

uint8_t R,G,B;   //GPIO口句柄
uint8_t a=5,b=5,c=5;    //比较值
//GPIO模拟PWM的实体
void pwm_entry(void* p)
{
    uint8_t count;
    while(1)
    {
        //设定脉宽200ms
        count++;
        count %=10;
        rt_thread_mdelay(1);
        //模拟pwm比较
        //红色的pwm输出
        if(count>a)
        {
            rt_pin_write(R, PIN_LOW);
        }
        else {
            rt_pin_write(R, PIN_HIGH);
        }
        //绿色的PWM输出
        if(count>b)
        {
            rt_pin_write(G, PIN_LOW);
        }
        else {
            rt_pin_write(G, PIN_HIGH);
        }
        //蓝色的pwm输出
        if(count>c)
        {
            rt_pin_write(B, PIN_LOW);
        }
        else
        {
            rt_pin_write(B, PIN_HIGH);
        }
    }
}

//GPIO模拟PWM的GPIO初始化
void pwm_init(void)
{
    rt_thread_t tid;
    rt_err_t ret = RT_EOK;
    //返回句柄
    R = rt_pin_get(LED_R);
    G = rt_pin_get(LED_G);
    B = rt_pin_get(LED_B);

    /* 设置PIN脚模式为输出 */
    rt_pin_mode(R, PIN_MODE_OUTPUT);
    rt_pin_mode(G, PIN_MODE_OUTPUT);
    rt_pin_mode(B, PIN_MODE_OUTPUT);

    rt_pin_write(R, PIN_HIGH);
    rt_pin_write(G, PIN_HIGH);
    rt_pin_write(B, PIN_HIGH);

    tid = rt_thread_create("pwm_rgb",
                            pwm_entry,
                            RT_NULL,
                            512,
                            10,
                            20);
    if (tid != RT_NULL)
    {
        //创建线程
        rt_thread_startup(tid);
    }
    else
    {
        ret = RT_ERROR;
    }
}







