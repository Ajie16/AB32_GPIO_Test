#include "key_board.h"

//调用包
#include <stdlib.h>
uint8_t key1,key2,key3,key4,key5,key6;
uint8_t key_pres;
void key_board_init(void)
{
    key1= rt_pin_get("PA.7");
    key2= rt_pin_get("PA.6");
    key3= rt_pin_get("PA.5");
    key4= rt_pin_get("PF.0");
    key5= rt_pin_get("PA.1");
    key6= rt_pin_get("PA.0");
    // 下拉输入
    rt_pin_mode(key1, PIN_MODE_INPUT_PULLDOWN );
    rt_pin_mode(key2, PIN_MODE_INPUT_PULLDOWN );
    rt_pin_mode(key3, PIN_MODE_INPUT_PULLDOWN );
    rt_pin_mode(key4, PIN_MODE_INPUT_PULLDOWN );
    rt_pin_mode(key5, PIN_MODE_INPUT_PULLDOWN );
    rt_pin_mode(key6, PIN_MODE_INPUT_PULLDOWN );
}
uint8_t key_scan(void)
{
    if(key_pres==0)
    {
        key_pres=1;
        if(rt_pin_read(key1)==1)
        {
            rt_thread_mdelay(30);//消抖
            if(rt_pin_read(key1)==1)
            {
                   return 1;
            }
        }
        if(rt_pin_read(key2)==1)
        {
            rt_thread_mdelay(30);
            if(rt_pin_read(key2)==1)
            {
                   return 2;
            }
        }
        if(rt_pin_read(key3)==1)
        {
            rt_thread_mdelay(30);
            if(rt_pin_read(key3)==1)
            {
                   return 3;
            }
        }
        if(rt_pin_read(key4)==1)
        {
            rt_thread_mdelay(30);
            if(rt_pin_read(key4)==1)
            {
                   return 4;
            }
        }
        if(rt_pin_read(key5)==1)
        {
            rt_thread_mdelay(30);
            if(rt_pin_read(key5)==1)
            {
                   return 5;
            }
        }
        if(rt_pin_read(key6)==1)
        {
            rt_thread_mdelay(30);
            if(rt_pin_read(key6)==1)
            {
                   return 6;
            }
        }
    }else {
        if(rt_pin_read(key1)|rt_pin_read(key2)|rt_pin_read(key3)|rt_pin_read(key4)|rt_pin_read(key5)|rt_pin_read(key6))
        {
            key_pres=0;
        }
    }
    return 0;
}




