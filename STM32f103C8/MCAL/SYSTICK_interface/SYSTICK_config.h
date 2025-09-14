/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @date    :  9Sep25                   ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  SYSTICK_config.h         ****************/
/****************************************************************************/



#ifndef   SYSTICK_CONGIF_H_
#define   SYSTICK_CONGIF_H_


/**
 * @brief  select the SYSTICK clk source 
 * @note you have two options ...
 *       1- SYSTICK_CLKSOURCE_PROCESSOR_CLOCK_DIV_8
 *       2- SYSTICK_CLKSOURCE_PROCESSOR_CLOCK_DIV_1
 * 
 */

#define    SYSTICK_CLKSOURCE    SYSTICK_CLKSOURCE_PROCESSOR_CLOCK_DIV_8   


//////////////___________________________________________________________*_*////


/**
 * @brief SysTick exception request enable or disable 
 * @note you have two options ... 
 *     1-ENABLE 
 *       = Counting down to zero to asserts the SysTick exception request 
 *     2-DISABLE 
 *       = Counting down to zero does not assert the SysTick exception request
 */

#define    SYSTICK_EXCEPTION_REQUEST        ENABLE  


//////////////___________________________________________________________*_*////















#endif  /*< SYSTICK_CONGIF_H_*/