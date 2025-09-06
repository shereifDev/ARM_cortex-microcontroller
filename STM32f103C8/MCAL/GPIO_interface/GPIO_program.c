/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @date    :  27Aug25                  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  GPIO_program.c           ****************/
/****************************************************************************/



/*<------------------------</LIB>---------------------------*/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*<------------------------</MCAL>---------------------------*/

#include  "GPIO_interface.h"
#include  "GPIO_private.h"
#include  "GPIO_config.h"










STD_Return_Type MCAL_GPIO_PIN_INITIALIZE(GPIO_PIN_CFG_t *ptr){

  STD_Return_Type local_FunctionStatus = E_OK ;

  if((NULL == ptr) || (ptr->copy_portId >= GPIO_PORTS_NUMBER) || (ptr->copy_pinId >= GPIO_PINS_NUMBER)){

    local_FunctionStatus = E_NOK ;
  }else{

    switch (ptr->copy_portId)
    {
      case GPIO_PORTA:
        if(ptr->copy_pinId<8){  
          GPIO_PORTA_CRL &= (~(0b1111) << (ptr->copy_pinId)*4);
          GPIO_PORTA_CRL |= (ptr->copy_pinMode << (ptr->copy_pinId)*4);
        }else if(ptr->copy_pinId<16){
          GPIO_PORTA_CRH &= (~(0b1111) << ((ptr->copy_pinId)-8)*4);
          GPIO_PORTA_CRH |= (ptr->copy_pinMode << ((ptr->copy_pinId)-8)*4);
        }else{
          /*NO THING*/
        }
        break;

      case GPIO_PORTB:
          if(ptr->copy_pinId<8){  
          GPIO_PORTB_CRL &= (~(0b1111) << (ptr->copy_pinId)*4);
          GPIO_PORTB_CRL |= (ptr->copy_pinMode << (ptr->copy_pinId)*4);
        }else if(ptr->copy_pinId<16){
          GPIO_PORTB_CRH &= (~(0b1111) << ((ptr->copy_pinId)-8)*4);
          GPIO_PORTB_CRH |= (ptr->copy_pinMode << ((ptr->copy_pinId)-8)*4);
        }else{
          /*NO THING*/
        }
        break;

        case GPIO_PORTC:
        if(ptr->copy_pinId<8){  
          GPIO_PORTC_CRL &= (~(0b1111) << (ptr->copy_pinId)*4);
          GPIO_PORTC_CRL |= (ptr->copy_pinMode << (ptr->copy_pinId)*4);
        }else if(ptr->copy_pinId<16){
          GPIO_PORTC_CRH &= (~(0b1111) << ((ptr->copy_pinId)-8)*4);
          GPIO_PORTC_CRH |= (ptr->copy_pinMode << ((ptr->copy_pinId)-8)*4);
        }else{
          /*NO THING*/
        }
        break;

      default:
        local_FunctionStatus = E_NOK ;
        break;
    }
  } 

 return (local_FunctionStatus);

}



/*___________________________________________________________________________ */



STD_Return_Type MCAL_GPIO_PIN_WRITE_LOGIC(GPIO_PIN_CFG_t *ptr,GPIO_PIN_LOGIC_t copy_pinLogic){

  STD_Return_Type local_FunctionStatus = E_OK ;

  if((NULL == ptr) || (ptr->copy_portId >= GPIO_PORTS_NUMBER) ||(ptr->copy_pinId >= GPIO_PINS_NUMBER)){

  local_FunctionStatus = E_NOK ;
  }else{

      switch (ptr->copy_portId)
      {

      case GPIO_PORTA:
        if(copy_pinLogic == GPIO_HIGH)      SET_BIT(GPIO_PORTA_ODR,ptr->copy_pinId);
        else if(copy_pinLogic == GPIO_LOW)  CLR_BIT(GPIO_PORTA_ODR,ptr->copy_pinId);
        else   /*No thing*/ 
        break;
      
      case GPIO_PORTB:
        if(copy_pinLogic == GPIO_HIGH)      SET_BIT(GPIO_PORTB_ODR,ptr->copy_pinId);
        else if(copy_pinLogic == GPIO_LOW)  CLR_BIT(GPIO_PORTB_ODR,ptr->copy_pinId);
        else   /*No thing*/ 
        break;
      
      
      case GPIO_PORTC:
        if(copy_pinLogic == GPIO_HIGH)      SET_BIT(GPIO_PORTC_ODR,ptr->copy_pinId);
        else if(copy_pinLogic == GPIO_LOW)  CLR_BIT(GPIO_PORTC_ODR,ptr->copy_pinId);
        else   /*No thing*/ 
        break;
      
      
      default:
        local_FunctionStatus = E_NOK ;
        break;
      }
}

 return (local_FunctionStatus);
}




/*___________________________________________________________________________ */




STD_Return_Type MCAL_GPIO_PIN_READ_LOGIC(GPIO_PIN_CFG_t *ptr,GPIO_PIN_LOGIC_t *copy_pinLogic){


  STD_Return_Type local_FunctionStatus = E_OK ;

  if((NULL == ptr) || (NULL == copy_pinLogic) || (ptr->copy_portId >= GPIO_PORTS_NUMBER) || (ptr->copy_pinId >= GPIO_PINS_NUMBER)){

     local_FunctionStatus = E_NOK ;
  }else{

      switch (ptr->copy_portId)
      {

        case GPIO_PORTA:
          *copy_pinLogic = READ_BIT(GPIO_PORTA_IDR,ptr->copy_pinId);
          break;
        
        case GPIO_PORTB:
          *copy_pinLogic = READ_BIT(GPIO_PORTB_IDR,ptr->copy_pinId);
          break;
        
        
        case GPIO_PORTC:
          *copy_pinLogic = READ_BIT(GPIO_PORTC_IDR,ptr->copy_pinId);
          break;
          
        default:
          local_FunctionStatus = E_NOK ;
          break;
      }
}

  return (local_FunctionStatus);

}



/*___________________________________________________________________________ */



STD_Return_Type MCAL_GPIO_PIN_TOGGLE_LOGIC(GPIO_PIN_CFG_t *ptr){

  STD_Return_Type local_FunctionStatus = E_OK ;

  if((NULL == ptr) || (ptr->copy_portId >= GPIO_PORTS_NUMBER) ||(ptr->copy_pinId >= GPIO_PINS_NUMBER)){

  local_FunctionStatus = E_NOK ;
  }else{

      switch (ptr->copy_portId)
      {

        case GPIO_PORTA:TOGG_BIT(GPIO_PORTA_ODR,ptr->copy_pinId);break;
        case GPIO_PORTB:TOGG_BIT(GPIO_PORTB_ODR,ptr->copy_pinId);break; 
        case GPIO_PORTC:TOGG_BIT(GPIO_PORTC_ODR,ptr->copy_pinId);break; 
        default: local_FunctionStatus = E_NOK;break;
    
     }
}

 return (local_FunctionStatus);

}



