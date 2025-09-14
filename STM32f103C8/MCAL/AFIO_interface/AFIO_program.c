/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @date    :  30Aug25                  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  AFIO_program.c           ****************/
/****************************************************************************/



/*<------------------------</LIB>---------------------------*/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*<------------------------</MCAL>---------------------------*/

#include  "AFIO_interface.h"
#include  "AFIO_private.h"
#include  "AFIO_config.h"




STD_Return_Type  MCAL_AFIO_selectSourceOfExternalInterrupt(uint8 copy_line , uint8 copy_portMap){

  STD_Return_Type local_FunctionStatus = E_OK ;
    if(copy_line >= MAX_EXTI_LINES || copy_portMap >= MAX_EXTI_LINE_PINS){
      local_FunctionStatus = E_NOK ;
    }else{
      uint8 local_RegQuarterIndex =  copy_line % 4 ;
      if(copy_line < 4){
        AFIO_EXTICR1 &= (~((0b1111) << (local_RegQuarterIndex*4)));
        AFIO_EXTICR1 |= (copy_portMap << (local_RegQuarterIndex*4));
      }else if(copy_line < 8) {
        AFIO_EXTICR2 &= (~((0b1111) << (local_RegQuarterIndex*4)));
        AFIO_EXTICR2 |= (copy_portMap << (local_RegQuarterIndex*4));
      }else if(copy_line < 12){
        AFIO_EXTICR3 &= (~((0b1111) << (local_RegQuarterIndex*4)));
        AFIO_EXTICR3 |= (copy_portMap << (local_RegQuarterIndex*4));
      }else{
        AFIO_EXTICR4 &= (~((0b1111) << (local_RegQuarterIndex*4)));
        AFIO_EXTICR4 |= (copy_portMap << (local_RegQuarterIndex*4));
      }   
    }

  return (local_FunctionStatus);
}
