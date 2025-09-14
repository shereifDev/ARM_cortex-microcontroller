/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @date    :  9Sep25                   ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  SYSTICK_program.h        ****************/
/****************************************************************************/

/*_______________________________</LIB>_________________________________*/

#include "BIT_MATH.h"
#include "STD_TYPES.h" 

/*_______________________________</MCAL>_________________________________*/

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"


static (*global_callBack_ptr)(void);






STD_Return_Type MCAL_SYSTICK_init(void){

  STD_Return_Type local_FunctionStatus = E_NOK;

  // make sure the timer is disable
  CLR_BIT(SYSTICK->STK_CTRL,STK_CTRL_ENABLE);

  // select the clock source of SYSTICk 
  #if  SYSTICK_CLKSOURCE == SYSTICK_CLKSOURCE_PROCESSOR_CLOCK_DIV_8  
  CLR_BIT(SYSTICK->STK_CTRL,STK_CTRL_CLKSOURCE);

  #elif YSTICK_CLKSOURCE == SYSTICK_CLKSOURCE_PROCESSOR_CLOCK_DIV_1
  SET_BIT(SYSTICK->STK_CTRL,STK_CTRL_CLKSOURCE);
  
  #else 
  #error "invalid choice .. select SYSTICK_CLKSOURCE_PROCESSOR_CLOCK_DIV_8/1"

  #endif /*<SYSTICK_CLKSOURCE*/


  // SysTick exception request  selection
  #if  SYSTICK_EXCEPTION_REQUEST  ==  DISABLE  
  CLR_BIT(SYSTICK->STK_CTRL, STK_CTRL_TICKINT);

  #elif SYSTICK_EXCEPTION_REQUEST  ==  ENABLE  
  SET_BIT(SYSTICK->STK_CTRL, STK_CTRL_TICKINT);

  #else 
  #error "invalid choice .. select DISABLE/ENABLE "

  #endif /*<SYSTICK_EXCEPTION_REQUEST*/


  local_FunctionStatus = E_OK;

return (local_FunctionStatus);

}

//////////////___________________________________________________________*_*////


STD_Return_Type MCAL_SYSTICK_xinit(uint32 copy_loadVal){

 STD_Return_Type local_FunctionStatus = E_NOK;

  // make sure the timer is disable
  CLR_BIT(SYSTICK->STK_CTRL,STK_CTRL_ENABLE);

  // select the clock source of SYSTICk 
  #if  SYSTICK_CLKSOURCE == SYSTICK_CLKSOURCE_PROCESSOR_CLOCK_DIV_8  
  CLR_BIT(SYSTICK->STK_CTRL,STK_CTRL_CLKSOURCE);

  #elif YSTICK_CLKSOURCE == SYSTICK_CLKSOURCE_PROCESSOR_CLOCK_DIV_1
  SET_BIT(SYSTICK->STK_CTRL,STK_CTRL_CLKSOURCE);
  
  #else 
  #error "invalid choice .. select SYSTICK_CLKSOURCE_PROCESSOR_CLOCK_DIV_8/1"

  #endif /*<SYSTICK_CLKSOURCE*/


  // SysTick exception request  selection
  #if  SYSTICK_EXCEPTION_REQUEST  ==  DISABLE  
  CLR_BIT(SYSTICK->STK_CTRL, STK_CTRL_TICKINT);

  #elif SYSTICK_EXCEPTION_REQUEST  ==  ENABLE  
  SET_BIT(SYSTICK->STK_CTRL, STK_CTRL_TICKINT);

  #else 
  #error "invalid choice .. select DISABLE/ENABLE   "

  #endif /*<SYSTICK_EXCEPTION_REQUEST*/

  // load start count val 
  SYSTICK ->STK_LOAD = copy_loadVal ;

  local_FunctionStatus = E_OK;

return (local_FunctionStatus);

}

//////////////___________________________________________________________*_*////


void MCAL_SYSTICK_startCounting(void){

  SET_BIT(SYSTICK->STK_CTRL,STK_CTRL_ENABLE );

}

//////////////___________________________________________________________*_*////


void MCAL_SYSTICK_stopCounting(void){

  CLR_BIT(SYSTICK->STK_CTRL,STK_CTRL_ENABLE );

}


//////////////___________________________________________________________*_*////

void MCAL_SYSTICK_reset(void){

  // disable the counter 
  CLR_BIT(SYSTICK->STK_CTRL,STK_CTRL_ENABLE );

  // exception request disable  
  CLR_BIT(SYSTICK->STK_CTRL,STK_CTRL_TICKINT );

  // clear the reload val 
  SYSTICK ->STK_LOAD = 0 ;

  // clear the current val 
  SYSTICK ->STK_VAL = 0 ;

}

//////////////___________________________________________________________*_*////


uint32 MCAL_SYSTICK_getRemainingCounts(void){

  return SYSTICK ->STK_VAL ;
}







