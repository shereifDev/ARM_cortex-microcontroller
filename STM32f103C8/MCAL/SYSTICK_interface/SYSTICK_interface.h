/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @date    :  9Sep25                   ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  SYSTICK_interface.h      ****************/
/****************************************************************************/



#ifndef   SYSTICK_INTERFACE_H_
#define   SYSTICK_INTERFACE_H_

/**
 *  @brief  include used header files 
 *
 */

#include  "BIT_MATH.h"
#include "STD_TYPES.h"












/**
 *  @brief  SYSTICK timer function prototypes 
 *
 */

STD_Return_Type MCAL_SYSTICK_init(void);
STD_Return_Type MCAL_SYSTICK_xinit(uint32 copy_loadVal);
void MCAL_SYSTICK_startCounting(void);
void MCAL_SYSTICK_stopCounting(void);
void MCAL_SYSTICK_reset(void);
uint32 MCAL_SYSTICK_getRemainingCounts(void);
void SysTick_Handler(void);





#endif  /*< SYSTICK_INTERFACE_H_*/