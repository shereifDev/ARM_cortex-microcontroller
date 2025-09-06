/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @date    :  29Aug25                  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  NVIC_interface.h         ****************/
/****************************************************************************/


#include "NVIC_private.h"



#ifndef   NVIC_interface_H_
#define   NVIC_interface_H_


/**
 * @brief  
 * 
 * 
 */

typedef enum {

  INTERRUPT_IS_NOT_PENDING ,
  INTERRUPT_IS_PENDING

}NVIC_INTERRUPT_STATUS_t ;


/**
 * @brief  
 * 
 * 
 */

typedef enum {

  NVIC_WWDG_IRQn           ,                  
  NVIC_PVD_IRQn            ,    
  NVIC_TAMPER_IRQn         ,
  NVIC_RTC_IRQn            ,
  NVIC_FLASH_IRQn          ,   
  NVIC_RCC_IRQn            ,
  NVIC_EXTI0_IRQn          , 
  NVIC_EXTI1_IRQn          ,
  NVIC_EXTI2_IRQn          ,
  NVIC_EXTI3_IRQn          ,
  NVIC_EXTI4_IRQn          ,
  NVIC_DMA1_Channel1_IRQn  ,     
  NVIC_DMA1_Channel2_IRQn  ,    
  NVIC_DMA1_Channel3_IRQn  ,   
  NVIC_DMA1_Channel4_IRQn  ,  
  NVIC_DMA1_Channel5_IRQn  ,
  NVIC_DMA1_Channel6_IRQn  ,
  NVIC_DMA1_Channel7_IRQn  ,
  NVIC_ADC1_2_IRQn         ,
  NVIC_USB_HP_CAN_TX_IRQn  ,
  NVIC_USB_LP_CAN_RX0_IRQn ,
  NVIC_CAN_RX1_IRQn        ,
  NVIC_CAN_SCE_IRQn        ,
  NVIC_EXTI9_5_IRQn        ,       
  NVIC_TIM1_BRK_IRQn       ,  
  NVIC_TIM1_UP_IRQn        , 
  NVIC_TIM1_TRG_COM_IRQn   , 
  NVIC_TIM1_CC_IRQn        ,   
  NVIC_TIM2_IRQn           ,
  NVIC_TIM3_IRQn           ,
  NVIC_TIM4_IRQn           ,
  NVIC_I2C1_EV_IRQn        , 
  NVIC_I2C1_ER_IRQn        ,
  NVIC_I2C2_EV_IRQn        ,
  NVIC_I2C2_ER_IRQn        ,
  NVIC_SPI1_IRQn           ,
  NVIC_SPI2_IRQn           ,
  NVIC_USART1_IRQn         ,   
  NVIC_USART2_IRQn         ,  
  NVIC_USART3_IRQn         , 
  NVIC_EXTI15_10_IRQn      ,
  NVIC_RTCAlarm_IRQn       ,       
  NVIC_USBWakeup_IRQn      , 
  NVIC_TIM8_BRK_IRQn       , 
  NVIC_TIM8_UP_IRQn        ,
  NVIC_TIM8_TRG_COM_IRQn   ,   
  NVIC_TIM8_CC_IRQn        ,
  NVIC_ADC3_IRQn           ,
  NVIC_FSMC_IRQn           ,
  NVIC_SDIO_IRQn           ,
  NVIC_TIM5_IRQn           ,
  NVIC_SPI3_IRQn           ,
  NVIC_UART4_IRQn          ,  
  NVIC_UART5_IRQn          , 
  NVIC_TIM6_IRQn           ,
  NVIC_TIM7_IRQn           ,
  NVIC_DMA2_Channel1_IRQn  ,   
  NVIC_DMA2_Channel2_IRQn  ,  
  NVIC_DMA2_Channel3_IRQn  , 
  NVIC_DMA2_Channel4_5_IRQn  

}IRQn_Type ;


/**
 * @brief  
 * 
 * 
 */


typedef enum
{
  GROUP0,
	GROUP1,
	GROUP2,
	GROUP3,
	GROUP4,
	GROUP5,
	GROUP6,
	GROUP7,
	GROUP8,
	GROUP9,
	GROUP10,
	GROUP11,
	GROUP12,
	GROUP13,
	GROUP14,
	GROUP15,
}group_priority;


/**
 * @brief  
 * 
 * 
 */

typedef enum
{

  SUB_PRIORITY0,
  SUB_PRIORITY1,
  SUB_PRIORITY2,
  SUB_PRIORITY3,
  SUB_PRIORITY4,
  SUB_PRIORITY5,
  SUB_PRIORITY6,
  SUB_PRIORITY7,
  SUB_PRIORITY8,
  SUB_PRIORITY9,
  SUB_PRIORITY10,
  SUB_PRIORITY11,
  SUB_PRIORITY12,
  SUB_PRIORITY13,
  SUB_PRIORITY14,
  SUB_PRIORITY15

}subgroup_priority;



/**
 * @brief  
 * 
 * 
 */


typedef struct {

#if (PRIORITY_GROUPING == _16_GROUPS_0_SUB)
IRQn_Type Copy_IRQn ;
group_priority Copy_GroupPriority;

#elif (PRIORITY_GROUPING == _4_GROUPS_4_SUB)
IRQn_Type Copy_IRQn ;
subgroup_priority Copy_SubPriority ;
group_priority Copy_GroupPriority;


#elif (PRIORITY_GROUPING == _2_GROUPS_8_SUB)
IRQn_Type Copy_IRQn ;
subgroup_priority Copy_SubPriority ;
group_priority Copy_GroupPriority;


#elif (PRIORITY_GROUPING == _0_GROUPS_16_SUB)
IRQn_Type Copy_IRQn ;
subgroup_priority Copy_SubPriority ;


#elif (PRIORITY_GROUPING == _8_GROUPS_2_SUB)
IRQn_Type Copy_IRQn ;
subgroup_priority Copy_SubPriority ;
group_priority Copy_GroupPriority;


#endif  /*_PRIORITY_GROUPING_*/

}NVIC_PRIORITY_GROUPING_t;




/**
 * @defgroup  NVIC functions prototype 
 * 
 */


 
/**
 * @brief  this function enable prephiral`s IRQ  
 * 
 * @example to enable ADC3 interrupt --> MCAL_NVIC_EnableIRQ(NVIC_ADC3_IRQn);
 * 
 */

STD_Return_Type MCAL_NVIC_EnableIRQ(IRQn_Type Copy_IRQn);

/**
 * @brief  this function disable prephiral`s IRQ  
 * 
 * @example to disable ADC3 interrupt --> MCAL_NVIC_DisableIRQ(NVIC_ADC3_IRQn);
 * 
 */

STD_Return_Type MCAL_NVIC_DisableIRQ(IRQn_Type Copy_IRQn);


/**
 * @brief  this function set pending prephiral`s IRQ  
 * 
 * @example to set pending ADC3 interrupt --> MCAL_NVIC_SetPendingIRQ(NVIC_ADC3_IRQn);
 * 
 */

STD_Return_Type MCAL_NVIC_SetPendingIRQ(IRQn_Type Copy_IRQn);


/**
 * @brief  this function CLR pending prephiral`s IRQ  
 * 
 * @example to clear pending ADC3 interrupt --> MCAL_NVIC_SetPendingIRQ(NVIC_ADC3_IRQn);
 * 
 */


STD_Return_Type MCAL_NVIC_ClearPendingIRQ(IRQn_Type Copy_IRQn);


/**
 * @brief  this function get pending prephiral`s IRQ  
 * 
 * @example to get pending ADC3 interrupt..
 * 
 * NVIC_INTERRUPT_STATUS_t pendingflag ;
 * MCAL_NVIC_SetPendingIRQ(NVIC_ADC3_IRQn,&pendingflag);
 * 
 * @note it assign INTERRUPT_IS_NOT_PENDING or INTERRUPT_IS_PENDING in the variable 
 * 
 */

STD_Return_Type MCAL_NVIC_GetPendingIRQ(IRQn_Type Copy_IRQn, NVIC_INTERRUPT_STATUS_t *Copy_ReturnPendingFlag);



/**
 * @brief  
 * 
 * 
 */

STD_Return_Type MCAL_NVIC_SetPriority(NVIC_PRIORITY_GROUPING_t *ptr);
STD_Return_Type MCAL_NVIC_GetPriority(IRQn_Type IRQn, uint8 *Copy_Priority);






#endif  /**<NVIC_interface_H_*/