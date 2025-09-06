/****************************************************************************/
/******************* AUTHOR     :  sherif osama abdelkareem *****************/
/******************* DATE       :  25Aug25                  *****************/
/******************* VERSION    :  0X01                     *****************/
/******************* FILE NAME  :  RCC_private.h            *****************/
/****************************************************************************/





#ifndef   RCC_PRIVATE_H_
#define   RCC_PRIVATE_H_

/**
 * @brief
 * 
 * RCC REGISTERS DEFINETIONS
 * 
 */
#define        RCC_Base_Adress             0x40021000  
#define        RCC_CR                (*((volatile uint32 *)(RCC_Base_Adress+0x00)))
#define        RCC_CFGR              (*((volatile uint32 *)(RCC_Base_Adress+0x04)))
#define        RCC_CIR               (*((volatile uint32 *)(RCC_Base_Adress+0x08)))
#define        RCC_APB2RSTR          (*((volatile uint32 *)(RCC_Base_Adress+0x0C)))
#define        RCC_APB1RSTR          (*((volatile uint32 *)(RCC_Base_Adress+0x10)))
#define        RCC_AHBENR            (*((volatile uint32 *)(RCC_Base_Adress+0x14)))
#define        RCC_APB2ENR           (*((volatile uint32 *)(RCC_Base_Adress+0x18)))
#define        RCC_APB1ENR           (*((volatile uint32 *)(RCC_Base_Adress+0x1C)))
#define        RCC_BDCR              (*((volatile uint32 *)(RCC_Base_Adress+0x20)))
u


//////////////_______________________________________________________*_*////

/**
 * @brief
 * 
 * 
 * 
 */

#define    RCC_HSI     0
#define    RCC_HSE     1
#define    RCC_PLL     2

#define    RCC_RC_CLK           0
#define    RCC_CRYSTAL_CLK      1


//////////////_______________________________________________________*_*////

/**
 * @brief
 * 
 * RCC REGISTERS`S BITS DEFINETIONS
 * 
 */

#define         RCC_CR_HSION            0  
#define         RCC_CR_HSIRDY           1
#define         RCC_CR_HSEON            16
#define         RCC_CR_HSEBYP           18
#define         RCC_CR_HSERDY           17
#define         RCC_CR_PLLON            24 
#define         RCC_CR_PLLRDY           25

#define         RCC_CFGR_SW0            0
#define         RCC_CFGR_SW1            1        



#endif /* RCC_PRIVATE_H_*/