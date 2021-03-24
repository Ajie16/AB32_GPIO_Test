/*
 * Copyright (c) 2020-2021, Bluetrum Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020/12/10     greedyhao    The first version
 */

#include <rtthread.h>
#include "board.h"
#include "pwm.h"
#include "key_board.h"
extern uint8_t a,b,c;    //比较值
int main(void)
{
    uint8_t key;
    key_board_init();
    pwm_init();
    while(1)
    {
        key=key_scan();
        if(key==1)
            a++;
        else if(key==2)
            a--;
        else if(key==3)
            b++;
        else if(key==4)
            b--;
        else if(key==5)
            c++;
        else if(key==6)
            c--;

        if(a>9)
            a=9;
        else if(a<1)
            a=1;
        if(b>9)
            b=9;
        else if(b<1)
            b=1;
        if(c>9)
            c=9;
        else if(c<1)
            c=1;
        rt_thread_mdelay(10);
    }
    return 0;
}
