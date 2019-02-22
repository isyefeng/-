#ifndef __OSP_GLOBAL_STR_H__
#define	__OSP_GLOBAL_STR_H__

#include "include_type.h"

void 	osp_memset( void*pur_add, u8_t pad_data, Bsize_t lenth );
char* 	osp_strstr( char*psrc, char*psearch );
void 	osp_strcat( char*pstr1, char*pstr2 );
Bsize_t 	osp_strlen( char*psrc );
void 	osp_memcpy( void * pur_add, void*src_ptr, Bsize_t lenth );
BOOL  	osp_memcmp( const void * pur_add, const void*src_ptr, Bsize_t lenth );


#endif
