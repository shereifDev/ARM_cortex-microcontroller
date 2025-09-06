/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @date    :  25Aug25                  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  RCC_interface.h          ****************/
/****************************************************************************/



#include"STD_TYPES.h"
#include "BIT_MATH.h"







#ifndef  RCC_INTERFACE_H_
#define  SRCC_INTERFACE_H_
 

/**
 * @brief
 * 
 * 
 * 
 * 
 */


#define     RCC_AHB              0
#define     RCC_APB1             1
#define     RCC_APB2             2



/**
 * @brief
 * 
 * 
 * 
 * 
 */

#define     RCC_APB1_TIM2EN      0
#define     RCC_APB1_TIM3EN      1
#define     RCC_APB1_TIM4EN      2



/**
 * @brief
 * 
 * 
 * 
 * 
 */

#define     RCC_APB2_IOPAEN      2
#define     RCC_APB2_IOPBEN      3
#define     RCC_APB2_IOPCEN      4
#define     RCC_APB2_IOPDEN      5
#define     RCC_APB2_IOPEEN      6




/**
 * @brief
 * 
 * 
 * 
 * 
 */

#define     RCC_AHB_DMA1EN       0
#define     RCC_AHB_DMA2EN       1
#define     RCC_AHB_SRAME        2





/**
 * @brief
 * 
 * 
 * 
 * 
 */


  STD_Return_Type MCAL_RCC_INITIALIZE_SYSCLK(void);
  STD_Return_Type MCAL_RCC_ENABLE_PERIPHERAL(uint8 copy_busId , uint8 copy_peripheralId);
  STD_Return_Type MCAL_RCC_DISABLE_PERIPHERAL(uint8 copy_busId , uint8 copy_peripheralId);





#endif /*RCC_INTERFACE_H_*/