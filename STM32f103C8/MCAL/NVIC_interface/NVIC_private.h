/****************************************************************************/
/******************* AUTHOR     :  sherif osama abdelkareem *****************/
/******************* DATE       :  29Aug25                  *****************/
/******************* VERSION    :  0X01                     *****************/
/******************* FILE NAME  :  NVIC_private.h           *****************/
/****************************************************************************/



#include "NVIC_config.h"


#ifndef   NVIC_private_H_
#define   NVIC_private_H_







/**
 * @brief NVIC ISER Registers.
 * 
 * 
 */

#define         NVIC_BASE_ADDRESS       0xE000E100

#define         NVIC_ISER0     (*((volatile uint32 *)(NVIC_BASE_ADDRESS+0x100)))
#define         NVIC_ISER1     (*((volatile uint32 *)(NVIC_BASE_ADDRESS+0x104))) 
#define         NVIC_ISER2     (*((volatile uint32 *)(NVIC_BASE_ADDRESS+0x108))) 


/**
 * @brief NVIC ICER Registers.
 * 
 * 
 */

#define         NVIC_ICER0     (*((volatile uint32 *)(NVIC_BASE_ADDRESS+0x180))) 
#define         NVIC_ICER1     (*((volatile uint32 *)(NVIC_BASE_ADDRESS+0x184))) 
#define         NVIC_ICER2     (*((volatile uint32 *)(NVIC_BASE_ADDRESS+0x188))) 


/**
 * @brief NVIC ISPR Registers.
 * 
 * 
 */

#define         NVIC_ISPR0     (*((volatile uint32 *)(NVIC_BASE_ADDRESS+0x200))) 
#define         NVIC_ISPR1     (*((volatile uint32 *)(NVIC_BASE_ADDRESS+0x204))) 
#define         NVIC_ISPR2     (*((volatile uint32 *)(NVIC_BASE_ADDRESS+0x208))) 



/**
 * @brief NVIC ICPR Registers.
 * 
 * 
 */

#define         NVIC_ICPR0     (*((volatile uint32 *)(NVIC_BASE_ADDRESS+0x280))) 
#define         NVIC_ICPR1     (*((volatile uint32 *)(NVIC_BASE_ADDRESS+0x284))) 
#define         NVIC_ICPR2     (*((volatile uint32 *)(NVIC_BASE_ADDRESS+0x288))) 


/**
 * @brief NVIC IABR Registers.
 * 
 * 
 */

#define         NVIC_IABR0     (*((volatile uint32 *)(NVIC_BASE_ADDRESS+0x300)))
#define         NVIC_IABR1     (*((volatile uint32 *)(NVIC_BASE_ADDRESS+0x304))) 
#define         NVIC_IABR2     (*((volatile uint32 *)(NVIC_BASE_ADDRESS+0x308))) 




/**
 * @brief   NVIC IPR Registers.
 * 
 * @note    1) define this register as pointer to char to move 8 bit in one step 
 *             cause each 8 bit in this register control IRQ ...  
 *            
 *          2) we can define this register as pointer to int and move 32 bit(4byte)
 *             in one step .. BUT u should detect in which reg this IRQ ? IPR0,IPR1,...
 *             and in which part? part1 , part2 , part3 , part4 ?? 
 * 
 *             - to calc the IRQ drop in which reg we use this eq -> (IRQn / 4) 
 *             - to calc the IRQ drop in which part we use this eq -> (IRQn % 4)
 * 
 *  for example IRQ no 7 drop in (7/4 ~= 1) IPR1 and part number (7%4 = 3) 3   
 * 
 * @example to control IRQ no : 2  we do that --> NVIC_IPR_BASE_ADDRESS[2] = xxxx << 4 ;
 */

#define         NVIC_IPR_BASE_ADDRESS           ((volatile uint8*)0xE000E100) 




//////////////_______________________________________________________*_*////



/**
 * @brief NVIC ICPR Registers.
 */



#define           SCB_AIRCR          (*(volatile uint32 *)0xE000ED0C)




//////////////_______________________________________________________*_*////



/**
 * @brief NVIC priority grouping 
 * 
 */

 

#define           _16_GROUPS_0_SUB         0x05FA0300 
#define           _8_GROUPS_2_SUB          0x05FA0400 
#define           _4_GROUPS_4_SUB          0x05FA0500 
#define           _2_GROUPS_8_SUB          0x05FA0600 
#define           _0_GROUPS_16_SUB         0x05FA0700 




//////////////_______________________________________________________*_*////


/**
 * @brief 
 * 
 * 
 * 
 */


#define        MAX_NUMBER_OF_IRQ            67

#if  PRIORITY_GROUPING   ==  _16_GROUPS_0_SUB  
#define        MAX_NUMBER_OF_PRIORITY       0
#define        MAX_NUMBER_OF_GROUBS         16

#elif  PRIORITY_GROUPING   ==  _4_GROUPS_4_SUB  
#define        MAX_NUMBER_OF_PRIORITY       4
#define        MAX_NUMBER_OF_GROUBS         4


#elif  PRIORITY_GROUPING   ==  _2_GROUPS_8_SUB  
#define        MAX_NUMBER_OF_PRIORITY       8
#define        MAX_NUMBER_OF_GROUBS         2

#elif  PRIORITY_GROUPING   ==  _8_GROUPS_2_SUB  
#define        MAX_NUMBER_OF_PRIORITY       2
#define        MAX_NUMBER_OF_GROUBS         8


#elif  PRIORITY_GROUPING   ==  _0_GROUPS_16_SUB  
#define        MAX_NUMBER_OF_PRIORITY       16
#define        MAX_NUMBER_OF_GROUBS         0



#endif /**<_PRIORITY_GROUPING_*/





#endif  /**<NVIC_private_H_*/