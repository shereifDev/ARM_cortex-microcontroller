/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @date    :  29Aug25                  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  EXTI_interface.h         ****************/
/****************************************************************************/




#ifndef   EXTI_INTERFACE_H_
#define   EXTI_INTERFACE_H_

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

/**
 * @brief 
 * 
 * 
 */

typedef enum {

EXTI_LINE0,
EXTI_LINE1,
EXTI_LINE2,
EXTI_LINE3,
EXTI_LINE4, 
EXTI_LINE5,
EXTI_LINE6,
EXTI_LINE7,
EXTI_LINE8,
EXTI_LINE9,
EXTI_LINE10,
EXTI_LINE11,
EXTI_LINE12,
EXTI_LINE13,
EXTI_LINE14,
EXTI_LINE15 

}EXTI_LINES_t;

/**
 * @brief 
 * 
 * 
 */

typedef enum{

EXTI_RISING_TRIGGER,
EXTI_FALLING_TRIGGER,
EXTI_ON_CHANGE_TRIGGER

}EXTI_TRIGGER_MODE_t;

typedef enum{

  EXTI_GPIO_PIN0 ,
  EXTI_GPIO_PIN1 ,
  EXTI_GPIO_PIN2 ,
  EXTI_GPIO_PIN3 ,
  EXTI_GPIO_PIN4 ,
  EXTI_GPIO_PIN5 ,
  EXTI_GPIO_PIN6 ,
  EXTI_GPIO_PIN7 ,
  EXTI_GPIO_PIN8 ,
  EXTI_GPIO_PIN9 , 
  EXTI_GPIO_PIN10,
  EXTI_GPIO_PIN11,
  EXTI_GPIO_PIN12,
  EXTI_GPIO_PIN13,
  EXTI_GPIO_PIN14,
  EXTI_GPIO_PIN15

}EXTI_GPIO_PINS_t;


 /**
 * @brief 
 * 
 * 
 */


typedef enum {

  EXTI_GPIO_PORTA ,
  EXTI_GPIO_PORTB ,
  EXTI_GPIO_PORTC 

 }EXTI_GPIO_PORTS_t;



 /**
 * @brief 
 * 
 * 
 */

 

STD_Return_Type MCAL_EXTI_enableLine(uint8 copy_line);
STD_Return_Type MCAL_EXTI_disableLine(uint8 copy_line);
STD_Return_Type MCAL_EXTI_triggerMode(uint8 copy_line,uint8 copy_triggerMode);
STD_Return_Type MCAL_EXTI_PIN_INIT(uint8 copy_pinID , uint8 copy_portID , uint8 copy_triggerMode );
void EXTI0_IRQHandler (void);
void MCAL_EXTI_getfunc(void(*func_ptr)(void));






#endif /*<EXTI_INTERFACE_H_*/
