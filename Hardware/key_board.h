#ifndef KEY_BOARD_H__
#define KEY_BOARD_H__

//RTT 操作系统头文件和设备管理
#include <rtthread.h>
#include <rtdevice.h>

void key_board_init(void);
uint8_t key_scan(void);


#endif

