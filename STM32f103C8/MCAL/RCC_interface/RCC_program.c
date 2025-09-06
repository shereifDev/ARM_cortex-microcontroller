/****************************************************************************/
/********************** @author  : sherif osama abdelkareem  ****************/
/********************** @date    :  25Aug25                  ****************/
/********************** @version :  0X01                     ****************/
/********************** @file    :  RCC_program.c            ****************/
/****************************************************************************/



/*---------------------------------</LIB>--------------------------------- */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*---------------------------------</MCAL>--------------------------------- */

#include  "RCC_interface.h"
#include  "RCC_private.h"
#include  "RCC_config.h"






STD_Return_Type MCAL_RCC_INITIALIZE_SYSCLK(){

    STD_Return_Type local_FunctionStatus = E_NOK ;

    #if RCC_SYSclk   ==   RCC_HSE
   
         #if   RCC_CLK_BYPASS == RCC_RC_CLK       // External RC clk will the source of clk syestem 
            SET_BIT(RCC_CR,RCC_CR_HSEBYP);

         #elif RCC_CLK_BYPASS == RCC_CRYSTAL_CLK  // External CRYSTAL clk will the source of clk syestem 
            CLR_BIT(RCC_CR,RCC_CR_HSEBYP);

         #else 
         #error "WRONG CHOICE ! you have only two choice 1) RCC_CRYSTAL_CLK 2) RCC_RC_CLK"

         #endif  /*RCC_CLK_BYPASS*/

          
         SET_BIT(RCC_CR,RCC_CR_HSEON );     // enable RCC_HSE
         while(!(READ_BIT(RCC_CR,RCC_CR_HSERDY)));   // wait until external crystal clk be stable 
         /*<select the external clk to be the source of clk */
         SET_BIT(RCC_CFGR,RCC_CFGR_SW0);   
         CLR_BIT(RCC_CFGR,RCC_CFGR_SW1);

         local_FunctionStatus = E_OK ;

    #elif RCC_SYSclk  ==   RCC_HSI
         SET_BIT(RCC_CR,RCC_CR_HSION);
         while(!(READ_BIT(RCC_CR,RCC_CR_HSIRDY)));   // wait until internal high speed clk be stable 
         /*<select the internal clk to be the source of clk */ 
         CLR_BIT(RCC_CFGR,RCC_CFGR_SW0);
         CLR_BIT(RCC_CFGR,RCC_CFGR_SW1);
       
         local_FunctionStatus= E_OK ;

    #elif RCC_SYSclk  ==   RCC_PLL
         SET_BIT(RCC_CR,RCC_CR_PLLON);
         while(!(READ_BIT(RCC_CR,RCC_CR_PLLRDY)));   // wait until PLL clk be stable 
         /*<select the PLL clk to be the source of clk */ 
         CLR_BIT(RCC_CFGR,RCC_CFGR_SW0);
         SET_BIT(RCC_CFGR,RCC_CFGR_SW1);   
         
         local_FunctionStatus = E_OK ;

    #else 
      #error "WRONG CHOICE ! you have only three choice 1) RCC_HSE 2) RCC_HSI 3) RCC_PLL "

    #endif/*RCC_SYSclk */

   return (local_FunctionStatus);

  }


/*___________________________________________________________________________ */



 STD_Return_Type MCAL_RCC_ENABLE_PERIPHERAL(uint8 copy_busId , uint8 copy_peripheralId){

          STD_Return_Type local_FunctionStatus = E_NOK;

          switch(copy_busId){

               case RCC_AHB :
               SET_BIT(RCC_AHBENR,copy_peripheralId);
               local_FunctionStatus = E_OK;
               break;

               case RCC_APB1 :
               SET_BIT(RCC_APB1ENR,copy_peripheralId);
               local_FunctionStatus = E_OK;
               break;


               case RCC_APB2  :
               SET_BIT(RCC_APB2ENR,copy_peripheralId);
               local_FunctionStatus = E_OK;
               break;

               default:
               local_FunctionStatus = E_NOK;
               break;
          }

          return (local_FunctionStatus);

 }


/*___________________________________________________________________________ */

  STD_Return_Type MCAL_RCC_DISABLE_PERIPHERAL(uint8 copy_busId , uint8 copy_peripheralId){

     
          STD_Return_Type local_FunctionStatus = E_NOK;

          switch(copy_busId){

               case RCC_AHB :
               CLR_BIT(RCC_AHBENR,copy_peripheralId);
               local_FunctionStatus = E_OK;
               break;

               case RCC_APB1 :
               CLR_BIT(RCC_APB1ENR,copy_peripheralId);
               local_FunctionStatus = E_OK;
               break;


               case RCC_APB2  :
               CLR_BIT(RCC_APB2ENR,copy_peripheralId);
               local_FunctionStatus = E_OK;
               break;

               default:
               local_FunctionStatus = E_NOK;
               break;
          }

          return (local_FunctionStatus);

}








