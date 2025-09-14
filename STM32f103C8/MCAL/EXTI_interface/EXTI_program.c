/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @date    :  29Aug25                  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  EXTI_program.c           ****************/
/****************************************************************************/



/*<-------------------------------</LIB>-----------------------------------*/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*<-------------------------------</MCAL>-----------------------------------*/

#include  "EXTI_interface.h"
#include  "EXTI_private.h"
#include  "EXTI_config.h"
#include  "AFIO_interface.h"


static (*global_callBack_ptr)(void);




/*<-------------------------------</FUNC IMP>-----------------------------------*/


STD_Return_Type MCAL_EXTI_enableLine(uint8 copy_line){

  STD_Return_Type local_FunctionStatus = E_OK ;
  if(copy_line >= MAX_EXTI_LINES){
    local_FunctionStatus = E_NOK ;
  }else{
    SET_BIT(EXTI->IMR,copy_line);
  }

 return (local_FunctionStatus);
}

/*___________________________________________________________________________ */


STD_Return_Type MCAL_EXTI_disableLine(uint8 copy_line){
  
  STD_Return_Type local_FunctionStatus = E_OK ;
  if(copy_line >= MAX_EXTI_LINES){
    local_FunctionStatus = E_NOK ;
  }else{
    CLR_BIT(EXTI->IMR,copy_line);
  }

 return (local_FunctionStatus);

}

//////////////___________________________________________________________*_*////



STD_Return_Type MCAL_EXTI_triggerMode(uint8 copy_line,uint8 copy_triggerMode){

  STD_Return_Type local_FunctionStatus = E_OK ;
  if(copy_line >= MAX_EXTI_LINES ){
    local_FunctionStatus = E_NOK ;
  }else{

    switch (copy_triggerMode)
    {
      case EXTI_RISING_TRIGGER:
      SET_BIT(EXTI->RTSR,copy_line);
      CLR_BIT(EXTI->FTSR,copy_line);
      break;
      
      case EXTI_FALLING_TRIGGER:
      SET_BIT(EXTI->FTSR,copy_line);
      CLR_BIT(EXTI->RTSR,copy_line);
      break;
      
      case EXTI_ON_CHANGE_TRIGGER:
      SET_BIT(EXTI->FTSR,copy_line);
      SET_BIT(EXTI->RTSR,copy_line);
      break;

      default:
      local_FunctionStatus = E_NOK ;
      break;
    }
  }

return (local_FunctionStatus);

}


//////////////___________________________________________________________*_*////



STD_Return_Type MCAL_EXTI_PIN_INIT(uint8 copy_pinID , uint8 copy_portID , uint8 copy_triggerMode ){

  STD_Return_Type local_FunctionStatus = E_OK ;
  local_FunctionStatus &= MCAL_EXTI_enableLine(copy_pinID) ;
  local_FunctionStatus &= MCAL_AFIO_selectSourceOfExternalInterrupt(copy_pinID,copy_portID);
  local_FunctionStatus &= MCAL_EXTI_triggerMode(copy_pinID,copy_triggerMode);

 return (local_FunctionStatus);

}


//////////////___________________________________________________________*_*////



void EXTI0_IRQHandler (void){

global_callBack_ptr();

}



//////////////___________________________________________________________*_*////



void MCAL_EXTI_getfunc(void(*func_ptr)(void)){

if(func_ptr != NULL){
  global_callBack_ptr = func_ptr ;
}

}







