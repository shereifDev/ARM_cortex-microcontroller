/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @date    :  27Aug25                  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  GPIO_private.h           ****************/
/****************************************************************************/




#ifndef   GPIO_PRIVATE_H_
#define   GPIO_PRIVATE_H_



/**
 * @brief 
 * 
 * 
 * 
 */

#define      GPIO_PORTA_BASE_ADDRESS       0x40010800
#define      GPIO_PORTB_BASE_ADDRESS       0x40010C00 
#define      GPIO_PORTC_BASE_ADDRESS       0x40011000


/**
 * @brief 
 * 
 * 
 * 
 */

#define     GPIO_PORTA_CRL     (*((volatile uint32*)(GPIO_PORTA_BASE_ADDRESS + 0X00))) 
#define     GPIO_PORTA_CRH     (*((volatile uint32*)(GPIO_PORTA_BASE_ADDRESS + 0X04))) 
#define     GPIO_PORTA_IDR     (*((volatile uint32*)(GPIO_PORTA_BASE_ADDRESS + 0X08))) 
#define     GPIO_PORTA_ODR     (*((volatile uint32*)(GPIO_PORTA_BASE_ADDRESS + 0X0C))) 
#define     GPIO_PORTA_BSRR    (*((volatile uint32*)(GPIO_PORTA_BASE_ADDRESS + 0X10))) 
#define     GPIO_PORTA_BRR     (*((volatile uint32*)(GPIO_PORTA_BASE_ADDRESS + 0X14))) 
#define     GPIO_PORTA_LCKR    (*((volatile uint32*)(GPIO_PORTA_BASE_ADDRESS + 0X18))) 


/**
 * @brief 
 * 
 * 
 * 
 */

#define     GPIO_PORTB_CRL     (*((volatile uint32*)(GPIO_PORTB_BASE_ADDRESS + 0X00))) 
#define     GPIO_PORTB_CRH     (*((volatile uint32*)(GPIO_PORTB_BASE_ADDRESS + 0X04))) 
#define     GPIO_PORTB_IDR     (*((volatile uint32*)(GPIO_PORTB_BASE_ADDRESS + 0X08))) 
#define     GPIO_PORTB_ODR     (*((volatile uint32*)(GPIO_PORTB_BASE_ADDRESS + 0X0C))) 
#define     GPIO_PORTB_BSRR    (*((volatile uint32*)(GPIO_PORTB_BASE_ADDRESS + 0X10))) 
#define     GPIO_PORTB_BRR     (*((volatile uint32*)(GPIO_PORTB_BASE_ADDRESS + 0X14))) 
#define     GPIO_PORTB_LCKR    (*((volatile uint32*)(GPIO_PORTB_BASE_ADDRESS + 0X18))) 


/**
 * @brief 
 * 
 * 
 * 
 */

#define     GPIO_PORTC_CRL     (*((volatile uint32*)(GPIO_PORTC_BASE_ADDRESS + 0X00))) 
#define     GPIO_PORTC_CRH     (*((volatile uint32*)(GPIO_PORTC_BASE_ADDRESS + 0X04))) 
#define     GPIO_PORTC_IDR     (*((volatile uint32*)(GPIO_PORTC_BASE_ADDRESS + 0X08))) 
#define     GPIO_PORTC_ODR     (*((volatile uint32*)(GPIO_PORTC_BASE_ADDRESS + 0X0C))) 
#define     GPIO_PORTC_BSRR    (*((volatile uint32*)(GPIO_PORTC_BASE_ADDRESS + 0X10))) 
#define     GPIO_PORTC_BRR     (*((volatile uint32*)(GPIO_PORTC_BASE_ADDRESS + 0X14))) 
#define     GPIO_PORTC_LCKR    (*((volatile uint32*)(GPIO_PORTC_BASE_ADDRESS + 0X18))) 





#endif  /*< GPIO_PRIVATE_H_*/