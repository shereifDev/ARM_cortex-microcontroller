/****************************************************************************/
/******************* AUTHOR     :  sherif osama abdelkareem *****************/
/******************* DATE       :  29Aug25                  *****************/
/******************* VERSION    :  0X01                     *****************/
/******************* FILE NAME  :  NVIC_config.h             *****************/
/****************************************************************************/






#ifndef   NVIC_config_H_
#define   NVIC_config_H_


/**
 * @brief  Selects the system interrupt priority grouping 
 * 
 * @note Choose one of the available options below ..
 * 
 * _16_GROUPS_0_SUB  
 * _8_GROUPS_2_SUB   
 * _4_GROUPS_4_SUB   
 * _2_GROUPS_8_SUB   
 * _0_GROUPS_16_SUB  
 * 
 * 
 */

 
#define          PRIORITY_GROUPING         _8_GROUPS_2_SUB       








#endif  /**<NVIC_config_H_*/