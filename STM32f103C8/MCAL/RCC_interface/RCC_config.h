/****************************************************************************/
/******************* AUTHOR     :  sherif osama abdelkareem *****************/
/******************* DATE       :  25Aug25                  *****************/
/******************* VERSION    :  0X01                     *****************/
/******************* FILE NAME  :  RCC_config.h             *****************/
/****************************************************************************/





#ifndef  RCC_CONFIG_H_
#define  RCC_CONFIG_H_

/**
 * 
 *  @brief
 * 
 *   select system clk ...
 *   ur options is___
 *           . RCC_HSI (high speed internal)
 *           . RCC_HSE (high speed external)
 *           . RCC_PLL
 
*/

#define     RCC_SYSclk       RCC_HSI



/**
 * 
 * @brief
 * 
 * ur options is ...
 *           . RCC_RC_CLK  
 *           . RCC_CRYSTAL_CLK
 *             
 */
 
#if RCC_SYSclk == RCC_HSE 

#define     RCC_CLK_BYPASS     RCC_CRYSTAL_CLK

#endif /* RCC_SYSclk */



#endif /*RCC_CONFIG_H_*/




