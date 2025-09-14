/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @date    :  9Sep25                   ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  SYSTICK_private.h        ****************/
/****************************************************************************/



#ifndef   SYSTICK_PRIVATE_H_
#define   SYSTICK_PRIVATE_H_




/**
 * @brief   include used header files 
 * 
 * 
 */

#include  "BIT_MATH.h"

//////////////___________________________________________________________*_*////

/**
 *  @brief  SYSTICK registers definitions 
 *
 */

#define        SYSTICK_BASE_ADDERSS         0xE000E010

typedef struct {

volatile uint32 STK_CTRL  ;          /*<SysTick control and status register*/
volatile uint32 STK_LOAD  ;          /*<SysTick reload value register */
volatile uint32 STK_VAL   ;          /*<SysTick current value register*/
volatile uint32 STK_CALIB ;          /*<SysTick calibration value register*/

}SYSTICK_REG_DEF_t ;

#define        SYSTICK           ((SYSTICK_REG_DEF_t *)SYSTICK_BASE_ADDERSS)

//////////////___________________________________________________________*_*////

/**
 * @brief SysTick control and status register (STK_CTRL) BITS dEFINITIONS 
 * 
 * 
 */

 #define           STK_CTRL_ENABLE                0
 #define           STK_CTRL_TICKINT               1
 #define           STK_CTRL_CLKSOURCE             2
 #define           STK_CTRL_COUNTFLAG             16

 
//////////////___________________________________________________________*_*////


/**
 *  @brief  SYSTICK PROCESSOR CLK SELECTIONS 
 *
 */

 #define     SYSTICK_CLKSOURCE_PROCESSOR_CLOCK_DIV_8   0
 #define     SYSTICK_CLKSOURCE_PROCESSOR_CLOCK_DIV_1   1


//////////////___________________________________________________________*_*////


/**
 *  @brief  SYSTICK EXCEPTION REQUEST 
 *
 */


 #define             DISABLE        0 
 #define             ENABLE         1 



#endif  /*< SYSTICK_PRIVATE_H_*/