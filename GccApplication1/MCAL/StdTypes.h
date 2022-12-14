/*
 * StdTypes.h
 *
 * Created: 10/1/2022 6:39:42 AM
 * Author : Mohamed Nagy
 */ 


#ifndef STDTYPES_H_
#define STDTYPES_H_
#include <stdlib.h>

/************************************************************************/
/*                     section:data type declaration                    */
/************************************************************************/

typedef		unsigned char			uint8;
typedef		unsigned short			uint16;
typedef		unsigned int			uint32;

typedef		signed char				sint8;
typedef		signed short			sint16;
typedef		signed int				sint32;

typedef		uint8				Std_ReturnType;

/************************************************************************/
/*                     section:macro declaration                        */
/************************************************************************/

#define		ZERO_INIT				0	

#define		E_OK					1
#define		E_NOT_OK				0



#endif /* STDTYPES_H_ */