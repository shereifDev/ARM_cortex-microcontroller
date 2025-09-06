/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @date    :  27Aug25                  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  GPIO_interface.h         ****************/
/****************************************************************************/




#ifndef   GPIO_INTERFACE_H_
#define   GPIO_INTERFACE_H_


/**
 * @brief include some header files we use it inside this file 
 * 
 * @example - include "STD_TYPES.h" to use STD_Retrun_Type macro .. 
 *          - include "BIT_MATH.h" to use uint8 ..  
 */

#include "STD_TYPES.h"
#include  "BIT_MATH.h"


//////////////___________________________________________________________*_*////


/**
 * @brief Macros to detect the max number of PORTS and PINS 
 * 
 */

#define      GPIO_PORTS_NUMBER       3
#define      GPIO_PINS_NUMBER        16


//////////////___________________________________________________________*_*////


/**
 * @brief  Enumerates the available GPIO ports
 * 
 * 
 * 
 */

typedef enum {

  GPIO_PORTA ,
  GPIO_PORTB ,
  GPIO_PORTC 

}GPIO_PORTS_t;


//////////////___________________________________________________________*_*////


/**
 * @brief Enumerates the available GPIO Pins
 * 
 * 
 */

typedef enum{

  GPIO_PIN0 ,
  GPIO_PIN1 ,
  GPIO_PIN2 ,
  GPIO_PIN3 ,
  GPIO_PIN4 ,
  GPIO_PIN5 ,
  GPIO_PIN6 ,
  GPIO_PIN7 ,
  GPIO_PIN8 ,
  GPIO_PIN9 , 
  GPIO_PIN10,
  GPIO_PIN11,
  GPIO_PIN12,
  GPIO_PIN13,
  GPIO_PIN14,
  GPIO_PIN15

}GPIO_PINS_t;


//////////////___________________________________________________________*_*////


/**
 * @brief GPIO Pin Logic..
 * 
 *        - GPIO_LOW =  0 .. send logic low (0 V)   to specific pin
 *        - GPIO_HIGH = 1 .. send logic high(3.3 V) to specific pin
 */

typedef enum {

    GPIO_LOW,
    GPIO_HIGH

}GPIO_PIN_LOGIC_t;


//////////////___________________________________________________________*_*////


/**
 * @brief 
 * 
 * 
 * 
 */

typedef struct {

  uint8 copy_portId:2 ;
  uint8 copy_pinId:4  ;
  uint8 copy_pinMode:4 ;

}GPIO_PIN_CFG_t;


//////////////___________________________________________________________*_*////


/**
 * @brief 
 * 
 * 
 * 
 */

#define      GPIO_INPUT_ANALOG_MOD            0b0000   // -->> the pin work as input analog pin                                         
#define      GPIO_INPUT_FLOATING_MOD          0b0100   // -->> the pin work as input floating pin                                       
#define      GPIO_INPUT_PP_MOD                0b1000   // -->> the pin work as input pull up/down pin         
    
    
#define      GPIO_OUTPUT_GPPP_10MHZ           0b0001   // -->> the pin work as output push pull  pin @10MHZ freq                        
#define      GPIO_OUTPUT_GPOD_10MHZ           0b0101   // -->> the pin work as output open drain pin @10MHZ freq                        
#define      GPIO_OUTPUT_AFPP_10MHZ           0b1001   // -->> the pin work as output Alternative  function push pull pin @10MHZ freq   
#define      GPIO_OUTPUT_AFOD_10MHZ           0b1101   // -->> the pin work as output Alternative function open drain  pin @10MHZ freq  
    
    
#define      GPIO_OUTPUT_GPPP_2MHZ            0b0010   // -->> the pin work as output push pull  pin @2MHZ freq                         
#define      GPIO_OUTPUT_GPOD_2MHZ            0b0110   // -->> the pin work as output open drain pin @2MHZ freq                         
#define      GPIO_OUTPUT_AFPP_2MHZ            0b1010   // -->> the pin work as output Alternative  function push pull pin @2MHZ freq    
#define      GPIO_OUTPUT_AFOD_2MHZ            0b1110   // -->> the pin work as output Alternative function open drain  pin @2MHZ freq   
    
    
#define      GPIO_OUTPUT_GPPP_50MHZ           0b0011   // -->> the pin work as output push pull  pin @50MHZ freq                        
#define      GPIO_OUTPUT_GPOD_50MHZ           0b0111   // -->> the pin work as output open drain pin @50MHZ freq                        
#define      GPIO_OUTPUT_AFPP_50MHZ           0b1011   // -->> the pin work as output Alternative  function push pull pin @50MHZ freq   
#define      GPIO_OUTPUT_AFOD_50MHZ           0b1111   // -->> the pin work as output Alternative function open drain  pin @50MHZ freq  


//////////////___________________________________________________________*_*////



/**
 * @brief 
 * 
 * 
 * 
 */

STD_Return_Type MCAL_GPIO_PIN_INITIALIZE(GPIO_PIN_CFG_t *ptr);
STD_Return_Type MCAL_GPIO_PIN_WRITE_LOGIC(GPIO_PIN_CFG_t *ptr,GPIO_PIN_LOGIC_t copy_pinLogic);
STD_Return_Type MCAL_PIO_PIN_READ_LOGIC(GPIO_PIN_CFG_t *ptr,GPIO_PIN_LOGIC_t *copy_pinLogic);
STD_Return_Type MCAL_GPIO_PIN_TOGGLE_LOGIC(GPIO_PIN_CFG_t *ptr);


STD_Return_Type MCAL_GPIO_PORT_DIRECTION_INITIALIZE();
STD_Return_Type MCAL_GPIO_PORT_GET_DIRECTION();
STD_Return_Type MCAL_GPIO_PORT_WRITE_LOGIC();
STD_Return_Type MCAL_GPIO_PORT_READ_LOGIC();
STD_Return_Type MCAL_GPIO_PORT_TOGGLE_LOGIC();



#endif  /*< GPIO_INTERFACE_H_*/