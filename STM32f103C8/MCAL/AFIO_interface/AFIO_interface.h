/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @date    :  30Aug25                  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  AFIO_interface.h         ****************/
/****************************************************************************/




#ifndef    AFIO_INTERFACE_H_
#define    AFIO_INTERFACE_H_

/**
 * @brief 
 * 
 * 
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"



/**
 * @brief 
 * 
 * 
 */

#define      MAX_EXTI_LINES     16

#define      MAX_EXTI_LINE_PINS  3

/**
 * @brief 
 * 
 * 
 */

typedef enum {

AFIO_EXTI_LINE0,
AFIO_EXTI_LINE1,
AFIO_EXTI_LINE2,
AFIO_EXTI_LINE3,
AFIO_EXTI_LINE4, 
AFIO_EXTI_LINE5,
AFIO_EXTI_LINE6,
AFIO_EXTI_LINE7,
AFIO_EXTI_LINE8,
AFIO_EXTI_LINE9,
AFIO_EXTI_LINE10,
AFIO_EXTI_LINE11,
AFIO_EXTI_LINE12,
AFIO_EXTI_LINE13,
AFIO_EXTI_LINE14,
AFIO_EXTI_LINE15 

}AFIO_EXTI_LINES_t;



/**
 * @brief 
 * 
 * 
 */

typedef enum {
  
AFIO_PAx ,
AFIO_PBx ,
AFIO_PCx 

}AFIO_EXTI_PORT_MAP_t;



/**
 * @brief 
 * 
 * 
 */


STD_Return_Type  MCAL_AFIO_selectSourceOfExternalInterrupt(uint8 copy_line , uint8 copy_portMap);




#endif  /*< AFIO_INTERFACE_H_*/