/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @date    :  30Aug25                  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  AFIO_private.h           ****************/
/****************************************************************************/




#ifndef   AFIO_PRIVATE_H_
#define   AFIO_PRIVATE_H_




#define      AFIO_BASE_ADDRESS           0x40010000 

#define      AFIO_EXTICR1       (*((volatile uint32 *)(AFIO_BASE_ADDRESS+0x08)))
#define      AFIO_EXTICR2       (*((volatile uint32 *)(AFIO_BASE_ADDRESS+0x0C)))
#define      AFIO_EXTICR3       (*((volatile uint32 *)(AFIO_BASE_ADDRESS+0x10)))
#define      AFIO_EXTICR4       (*((volatile uint32 *)(AFIO_BASE_ADDRESS+0x14)))








#endif  /*< AFIO_PRIVATE_H_*/