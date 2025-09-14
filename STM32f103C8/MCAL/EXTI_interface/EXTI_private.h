/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @date    :  29Aug25                  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  EXTI_private.h           ****************/
/****************************************************************************/




#ifndef   EXTI_PRIVATE_H_
#define   EXTI_PRIVATE_H_



#define        EXTI_BASE_ADDRESS       0x40010400

typedef struct
{
  volatile uint32 IMR;    
  volatile uint32 EMR;    
  volatile uint32 RTSR;   
  volatile uint32 FTSR;   
  volatile uint32 SWIER;  
  volatile uint32 PR;     
} EXTI_RegDef_t;

#define     EXTI    ((EXTI_RegDef_t *) EXTI_BASE_ADDRESS)



#endif /*<EXTI_PRIVATE_H_*/
