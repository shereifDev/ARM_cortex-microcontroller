/****************************************************************************/
/******************* AUTHOR     :  sherif osama abdelkareem *****************/
/******************* DATE       :  25Aug25                  *****************/
/******************* VERSION    :  0X01                     *****************/
/******************* FILE NAME  :  STD_TYPES.h              *****************/
/****************************************************************************/





#ifndef  STD_TYPES_H_
#define  STD_TYPES_H_
 

#define     SET_BIT(reg , bit)	   reg|=(1<<bit)
#define     CLR_BIT(reg , bit)	   reg&=(~(1<<bit)) 
#define     READ_BIT(reg , bit)    (reg&(1<<bit))>>bit    
#define     TOGG_BIT(reg , bit)	   reg^=(1<<bit)






#define      STD_Return_Type      uint8   
#define      E_OK                   1 
#define      E_NOK                  0


#define      NULL               ((void *)0x00)

#endif /*STD_TYPES_H_*/