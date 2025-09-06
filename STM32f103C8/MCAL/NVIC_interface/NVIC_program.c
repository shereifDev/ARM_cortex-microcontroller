/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @date    :  29Aug25                  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  NVIC_program.c           ****************/
/****************************************************************************/



/*---------------------------------</LIB>--------------------------------- */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
/*---------------------------------</MCAL>--------------------------------- */
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"







STD_Return_Type MCAL_NVIC_EnableIRQ(IRQn_Type Copy_IRQn){

  STD_Return_Type local_FunctionStatus = E_NOK;

  if(Copy_IRQn < 32){
    SET_BIT(NVIC_ISER0,Copy_IRQn);
  }else if(Copy_IRQn < 64){
    SET_BIT(NVIC_ISER1,Copy_IRQn-32);
  }else if(Copy_IRQn < 94){
    SET_BIT(NVIC_ISER2,Copy_IRQn-64);
  }else{
         /*No thing*/
  }

  local_FunctionStatus = E_OK;

return (local_FunctionStatus);
}

/*___________________________________________________________________________ */

STD_Return_Type MCAL_NVIC_DisableIRQ(IRQn_Type Copy_IRQn){

   STD_Return_Type local_FunctionStatus = E_NOK;

  if(Copy_IRQn < 32){
    SET_BIT(NVIC_ICER0,Copy_IRQn);
  }else if(Copy_IRQn < 64){
    SET_BIT(NVIC_ICER1,Copy_IRQn-32);
  }else if(Copy_IRQn < 94){
    SET_BIT(NVIC_ICER2,Copy_IRQn-64);
  }else{
         /*No thing*/
  }

  local_FunctionStatus = E_OK;

return (local_FunctionStatus);

}


/*___________________________________________________________________________ */


STD_Return_Type MCAL_NVIC_SetPendingIRQ(IRQn_Type Copy_IRQn){

  
  STD_Return_Type local_FunctionStatus = E_NOK;

  if(Copy_IRQn < 32){
    SET_BIT(NVIC_ISPR0,Copy_IRQn);
  }else if(Copy_IRQn < 64){
    SET_BIT(NVIC_ISPR1,Copy_IRQn-32);
  }else if(Copy_IRQn < 94){
    SET_BIT(NVIC_ISPR2,Copy_IRQn-64);
  }else{
         /*No thing*/
  }

  local_FunctionStatus = E_OK;

return (local_FunctionStatus);

}


/*___________________________________________________________________________ */


STD_Return_Type MCAL_NVIC_ClearPendingIRQ(IRQn_Type Copy_IRQn){

  STD_Return_Type local_FunctionStatus = E_NOK;

  if(Copy_IRQn < 32){
    SET_BIT(NVIC_ICPR0,Copy_IRQn);
  }else if(Copy_IRQn < 64){
    SET_BIT(NVIC_ICPR1,Copy_IRQn-32);
  }else if(Copy_IRQn < 94){
    SET_BIT(NVIC_ICPR2,Copy_IRQn-64);
  }else{
         /*No thing*/
  }

  local_FunctionStatus = E_OK;

return (local_FunctionStatus);

}


/*___________________________________________________________________________ */


STD_Return_Type MCAL_NVIC_GetPendingIRQ(IRQn_Type Copy_IRQn, NVIC_INTERRUPT_STATUS_t *Copy_PendingFlag){

  STD_Return_Type local_FunctionStatus = E_OK;
  if(NULL == Copy_PendingFlag){
    local_FunctionStatus = E_NOK;
  }else{
    if(Copy_IRQn < 32){
       *Copy_PendingFlag = READ_BIT(NVIC_ISPR0,Copy_IRQn);
    }else if(Copy_IRQn < 64){
       *Copy_PendingFlag = READ_BIT(NVIC_ISPR1,Copy_IRQn-32);
    }else if(Copy_IRQn < 94){
       *Copy_PendingFlag = READ_BIT(NVIC_ISPR2,Copy_IRQn-64);
    }else{
    /*No thing*/
    }
  }
return (local_FunctionStatus); 
}

/*___________________________________________________________________________ */


STD_Return_Type MCAL_NVIC_SetPriority(NVIC_PRIORITY_GROUPING_t *ptr){

  STD_Return_Type local_FunctionStatus = E_OK;



  #if (PRIORITY_GROUPING == _16_GROUPS_0_SUB)

    if(NULL == ptr || (ptr->Copy_IRQn) > MAX_NUMBER_OF_IRQ || ptr->Copy_GroupPriority >= MAX_NUMBER_OF_GROUBS){
      local_FunctionStatus = E_NOK;
    }else{

       SCB_AIRCR = _16_GROUPS_0_SUB;
       NVIC_IPR_BASE_ADDRESS[Copy_IRQn] &= (~(0b1111) << 4 );
       NVIC_IPR_BASE_ADDRESS[Copy_IRQn] |= (ptr->Copy_GroupPriority << 4) ;
    }

  #elif (PRIORITY_GROUPING == _4_GROUPS_4_SUB)
    if(NULL == ptr || (ptr->Copy_IRQn) > MAX_NUMBER_OF_IRQ || ptr->Copy_GroupPriority >= MAX_NUMBER_OF_GROUBS || ptr->Copy_SubPriority >= MAX_NUMBER_OF_PRIORITY){
          local_FunctionStatus = E_NOK;
    }else{

          SCB_AIRCR = _4_GROUPS_4_SUB;
          NVIC_IPR_BASE_ADDRESS[Copy_IRQn] &= (~(0b1111) << 4 );
          NVIC_IPR_BASE_ADDRESS[Copy_IRQn] |= (ptr->Copy_SubPriority << 4) | (ptr->Copy_GroupPriority << 6) ;
    }

  #elif (PRIORITY_GROUPING == _2_GROUPS_8_SUB)
  if(NULL == ptr || (ptr->Copy_IRQn) > MAX_NUMBER_OF_IRQ || ptr->Copy_GroupPriority >= MAX_NUMBER_OF_GROUBS || ptr->Copy_SubPriority >= MAX_NUMBER_OF_PRIORITY){
          local_FunctionStatus = E_NOK;
  }else{

          SCB_AIRCR = _2_GROUPS_8_SUB;
          NVIC_IPR_BASE_ADDRESS[Copy_IRQn] &= (~(0b1111) << 4 );
          NVIC_IPR_BASE_ADDRESS[Copy_IRQn] |= (ptr->Copy_SubPriority << 4) | (ptr->Copy_GroupPriority << 7) ;
   }


  #elif (PRIORITY_GROUPING == _0_GROUPS_16_SUB)
  if(NULL == ptr || (ptr->Copy_IRQn) > MAX_NUMBER_OF_IRQ || ptr->Copy_SubPriority >= MAX_NUMBER_OF_PRIORITY){
            local_FunctionStatus = E_NOK;
  }else{

          SCB_AIRCR = _0_GROUPS_16_SUB;
          NVIC_IPR_BASE_ADDRESS[Copy_IRQn] &= (~(0b1111) << 4 );
          NVIC_IPR_BASE_ADDRESS[Copy_IRQn] |= (ptr->Copy_SubPriority << 4) ;
  }

  #elif (PRIORITY_GROUPING == _8_GROUPS_2_SUB)
    if(NULL == ptr || (ptr->Copy_IRQn) > MAX_NUMBER_OF_IRQ || ptr->Copy_GroupPriority >= MAX_NUMBER_OF_GROUBS || ptr->Copy_SubPriority >= MAX_NUMBER_OF_PRIORITY){
            local_FunctionStatus = E_NOK;
    }else{

            SCB_AIRCR = _8_GROUPS_2_SUB;
            NVIC_IPR_BASE_ADDRESS[Copy_IRQn] &= (~(0b1111) << 4 );
            NVIC_IPR_BASE_ADDRESS[Copy_IRQn] |= (ptr->Copy_SubPriority << 4) | (ptr->Copy_GroupPriority << 5) ;
    }


  #endif  /*_PRIORITY_GROUPING_*/



 return (local_FunctionStatus); 

  
}


/*___________________________________________________________________________ */


