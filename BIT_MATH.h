#define VALUE_1 1

#ifndef  _BIT_MATH_H 
#define  _BIT_MATH_H 




#define  SET_BIT(REG,BIT)        (REG|=VALUE_1<<BIT)
#define  CLR_BIT(REG,BIT)        (REG&=~(VALUE_1<<BIT))
#define  TOGGLE_BIT(REG,BIT)     (REG^=VALUE_1<<BIT) 
#define  GET_BIT(REG,BIT)         (REG>>BIT&0x01)


#endif 