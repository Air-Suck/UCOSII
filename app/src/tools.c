#include "tools.h"
#include "stm32f401xe.h"

// 点亮LED2，对应PA5，操作GPIO口
void LED2_Init(void)
{
    // 先设置GPIO的模式，对应GPIO的MODER寄存器
    GPIOA->MODER &= ~0x00000C00; // 先清零
    GPIOA->MODER |= 0x00000400;  // 设置为01，即输出模式
    // 设置GPIO的输出类型，对应GPIO的OTYPER寄存器
    GPIOA->OTYPER &= ~0x00000020; // 先清零,不过PUSH-PULL模式置为就是为0
    // 设置GPIO的输出速度，对应GPIO的OSPEEDR寄存器，这里我们设置为高速吧
    GPIOA->OSPEEDR &= ~0x00000C00; // 先清零
    GPIOA->OSPEEDR |= 0x00000800;  // 设置为10，即高速
    // 设置GPIO的上下拉电阻，对应GPIO的PUPDR寄存器，这里我们设置为没有上下拉
    GPIOA->PUPDR &= ~0x00000C00; // 先清零
    // 最后设置GPIO的输出值，对应GPIO的ODR寄存器，这里我们设置为高电平
    GPIOA->ODR |= 0x00000020; // 设置为1，即高电平
}

