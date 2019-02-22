/*********************************************************************************************
*            珠海科荟电器有限公司
*            http://www.zhkh.com
* 模块名称:习惯通用性函数支持
* 创建时间:2010-06-23
* 所属公司 :科荟
* 文件名称:OSP.c
* 创建人 :揭成
* 功能描述:常用函数集合。
*----------------------------------------------------------------
修改记录:

修改日期:

修改人:

**********************************************************************************************************/
#include	"stm32f10x.h"

#define	Bsize_t	 unsigned char
#define	u8_t		 unsigned char
#define	BOOL	 unsigned char
#define	u32_t	 unsigned int

#define	TURE		1
#define	FALSE		0

#define	BOOL_0		0
#define	BOOL_1		1
#define	PNULL 		0

#define	ASCII_NULL	0


/********************************************************************
 *@创建人:揭成
 *@功能:内存复制
 *
 *@输入: pur_add  :指向目标地址
 * 		 pad_data :指向源地址
 *       lenth:数据长度
 *@输出:NONE
********************************************************************/
void osp_memcpy( void * pur_add, void*src_ptr, Bsize_t lenth )
{
	Bsize_t index;
	char*p_pur = ( char* )pur_add;
	char*p_src = ( char* )src_ptr;
	for ( index = 0;index < lenth;index++ )
	{
		p_pur[index] = p_src[index];
	}
	return ;
}
/********************************************************************
 *@创建人:揭成
 *@功能:内存填充
 *
 *@输入: 	pur_add  :指向待填充内存开始地址
 *       	pad_data :填充数据
 *      	lenth    :数据长度
 *@输出:	NONE
********************************************************************/
void osp_memset( void*pur_add, u8_t pad_data, Bsize_t lenth )
{
	Bsize_t index;
	u8_t*p_pur = ( u8_t* )pur_add;
	for ( index = 0;index < lenth;index++ )
	{
		p_pur[index] = pad_data;
	}
	return ;
}
/********************************************************************
 *@创建人:揭成
 *@功能:内存比较
 *
 *@输入: 	pur_add  :指向目的地址
 *       		src_ptr :指向源地址
 *      		lenth:数据长度
 *@输出:	NONE
********************************************************************/
BOOL  osp_memcmp( const void * pur_add, const void*src_ptr, Bsize_t lenth )
{
	Bsize_t index;
	char*p_pur = ( char* )pur_add;
	char*p_src = ( char* )src_ptr;
	for ( index = 0;index < lenth;index++ )
	{
		if ( p_pur[index] != p_src[index] )
		{
			return BOOL_0;
		}
	}
	return BOOL_1;
}
/*********************************************************************
*@函数名称:测试字符长度
*@创建人:揭成
*@输入: psrc  :要测试的字符串
*@输出:字符长度
*********************************************************************/
Bsize_t osp_strlen( char*psrc )
{
	Bsize_t lenth = 0;
	while (( *psrc ) != ASCII_NULL )
	{
		lenth++;
		psrc++;
	}
	return lenth;
}
/*********************************************************************
*@函数名称:将字符串pstr2合并到pstr1
*@创建人:揭成
*@输入: pstr1  pstr2
*@ output :NONE
*必须确保pstr1 有足够的空间
*********************************************************************/
void osp_strcat( char*pstr1, char*pstr2 )
{
	char*pch;
	pch = ( char* )pstr1 + osp_strlen( pstr1 );
	osp_memcpy(( u8_t* )pch,
				  ( u8_t* )pstr2,
				  ( osp_strlen( pstr2 ) + 1 ) );
	return;
}
/*********************************************************************
*   @函数名称:复制字符串
*   @创建人:揭成
*   @输入: psrc  :要复制字符串
*
*    @ output :字符长度
*
*********************************************************************/
char* osp_strcpy( char*pdest, char*psrc )
{
	Bsize_t len = 0;
	char*pdest_shadow =  pdest ;
	while ( *psrc != ASCII_NULL )
	{
		*pdest++ = *psrc++;
		len++;
	}
	*pdest = ASCII_NULL;
	return ( pdest_shadow );
}
/********************************************************************
 * @创建人 :揭成
 * @功能 :在字符串中定位一个字符串
 * @输入 :psrc 字符串  chr 待查询的字符
 *
 *@输出 :查询到字符的位置
********************************************************************/
char* osp_strchr( char*psrc, char chr)
{
	Bsize_t offset;
	Bsize_t psrc_lenth = osp_strlen( psrc );
	for ( offset = 0;offset < psrc_lenth;offset++ )
	{
		if ( psrc[offset] == chr)
		{
			return &( psrc[offset] );
		}
	}
	return PNULL;
}
/********************************************************************
 * @创建人 :揭成
 * @功能 :在字符串中定位一个字符串
 * @输入 :psrc 字符串  pserch 待查询的字符串
 *
 *@输出 :查询到字符的位置
********************************************************************/
char* osp_strstr( char*psrc, char*psearch )
{
	Bsize_t offset;
	Bsize_t psearch_lenth = osp_strlen( psearch );
	Bsize_t psrc_lenth = osp_strlen( psrc );
	for ( offset = 0;offset < psrc_lenth;offset++ )
	{
		if ( osp_memcmp( &psrc[offset],
							psearch,
							psearch_lenth ) )
		{
			return &( psrc[offset] );
		}
	}
	return PNULL;
}
/********************************************************************
 * @创建人:揭成
 * @功能  :在字符串中定位一个字符串，返回定位到的个数
 * @输入  : phead 字符串头，
 *		    pend  字符串尾
 *		    paddr 存放定位到的字符地址
 *
 * @输出 :查询到字符的位置
********************************************************************/
Bsize_t osp_strstr_all( char*phead, char*pend, char*psearch, char*paddr[])
{
	char*pch;
	Bsize_t num = 0;
	while ( 1 )
	{
		pch = osp_strstr( phead, psearch );
		if (( pch < pend ) && ( pch != PNULL ) )
		{
			paddr[num] = pch;
			phead = pch + 1;
			num++;
		}
		else
		{
			break;
		}
	}
	return num;
}
/********************************************************************
 * @创建人 :揭成
 * @功能 :在字符串中定位一个字符串，返回最后一个定位到的
 * @输入 :phead 字符串头，
 *		  pend  字符串尾
 *		  pserch 待查询的字符串
 * @输出 :查询到字符的位置
********************************************************************/
char* osp_strstr_end( char*phead, char*pend, char*psearch )
{
	char*pch;
	char*pret = PNULL;
	while ( 1 )
	{
		pch = osp_strstr( phead, psearch );
		if (( pch < pend ) && ( pch != PNULL ) )
		{
			( pret < pch ) ? ( pret = pch ) : ( pret = pret );
			phead = pch + 1;
		}
		else
		{
			break;
		}
	}
	return pret;
}
/*********************************************************************
*@函数名称:字符串反转
*@创建人:揭成
*@输入:
*@输出: NONE
*********************************************************************/
void osp_strrvsal( char *psrc )
{
	char *pshadow_1 = psrc;
	char *pshadow_2;
	char temp;
	pshadow_2 = ( char* )psrc + ( osp_strlen( psrc ) - 1 );
	while ( pshadow_1 < pshadow_2 )
	{
		if ( *pshadow_1 != *pshadow_2 )
		{
			temp = *pshadow_1;
			*pshadow_1 = *pshadow_2;
			*pshadow_2 = temp;
		}
		++pshadow_1;
		--pshadow_2;
	}
}
/*********************************************************************
*@函数名称:int 转换成字符串
*@创建人:揭成
*@输入:
*@输出: NONE
*********************************************************************/
Bsize_t osp_ltoa( long isrc, char *pdes )
{
	long  itemp = isrc;
	int offset = 0;
	if ( itemp < 0 )
	{
		isrc = isrc * ( -1 );
	}
	do
	{
		pdes[offset++] = isrc % 10 + '0';
		isrc = isrc / 10;
	}
	while ( isrc > 0 );
	if ( itemp < 0 )
	{
		pdes[offset++] = '-';
	}
	pdes[offset] = ASCII_NULL;
	osp_strrvsal( pdes );
	return ( osp_strlen( pdes ) );
}
/*********************************************************************
*@函?float 转换成字符串
*@创建人:揭成
*@输入:
*@ output : NONE
*BOOL_0 :去抖过程中
*********************************************************************/
Bsize_t osp_ftoa( float fsrc , char*pdes, Bsize_t point_bit )
{
	long ltemp, lmul;
	float fpoint;
	char point[15] = "";
	osp_float_putoff_point( fsrc, &ltemp, &fpoint );
	if ( ltemp == 0 && fsrc < 0 )
	{
		pdes[0] = '-';
		pdes[1] = '0';
		pdes[2] = ASCII_NULL;
	}
	else osp_ltoa( ltemp, pdes );
	fpoint = GLOBAL_ABS( fpoint );
	if ( fpoint > 0 )
	{
		( point_bit > 6 ) ? ( point_bit = 6 ) : ( point_bit = point_bit );
		lmul = 1;
		while ( point_bit > 0 )
		{
			lmul = 10 * lmul;
			point_bit--;
		}
		ltemp = ( long )( fpoint * lmul );
		ltemp = GLOBAL_ABS( ltemp );
		osp_ltoa( ltemp, point );
		while (( *GET_STRING_END( point ) == '0' ) && ( osp_strlen( point ) > 0 ) )
		{
			*GET_STRING_END( point ) = ASCII_NULL;
		}
		osp_strcat( pdes, "." );
		lmul /= 10;
		while ( ltemp < lmul )
		{
			osp_strcat( pdes, "0" );
			lmul /= 10;
		}
		osp_strcat( pdes, point );
		while ( *GET_STRING_END( pdes ) == '.' )
		{
			osp_strcat( pdes, "0" );
		}
	}
	return osp_strlen( pdes );
}

/*********************************************************************
*@函数名称:字符转换成INT
*@创建人:揭成
*@输入:
*@输出: NONE
*********************************************************************/
float  osp_atof( char *pdes )
{
	float  itemp = 0.0;
	Bsize_t offset;
	float   Mdata = 10;
	Bsize_t string_size = osp_strlen( pdes );
	for ( offset = (( pdes[0] == '-' ) ? 1 : 0 );offset < string_size;offset++ )
	{
		if ( pdes[offset] == '.' )
		{
			Mdata = 0.1;
			continue;
		}
		if ( Mdata == 10 )
		{
			itemp = itemp * 10 + GLOBAL_CTON( pdes[offset] );
		}
		else
		{
			itemp =  itemp + GLOBAL_CTON( pdes[offset] ) * Mdata ;
			Mdata *= (( float )0.1 );
		}
	}
	if ( pdes[0] == '-' )
	{
		itemp = -itemp;
	}
	return itemp;
}
/*********************************************************************
*@函数名称:字符转换成INT
*@创建人:揭成
*@输入:
*@输出: NONE
*********************************************************************/
long osp_atol( char *pdes )
{
	return atoi( pdes );
}
/********************************************************************
 *@创建人:揭成
 *@功能:求一队列累加和
 *
 *@输入:Phead 数组头  size 数组长度 data_type  数组类型
 *
 *@输出:所求的和
********************************************************************/
Bsize_t  osp_sum_array( void*Phead, Bsize_t size, Bsize_t data_type )
{
	Bsize_t  sum  = 0;
	float    fsum = 0;
	Bsize_t  index;
	for ( index = 0;index < size;index++ )
	{
		if ( data_type == IS_CHAR || data_type == IS_UNSIGN_CHAR )
		{
			sum += ( *(( u8_t* )Phead + index ) );
		}
		else if ( data_type == IS_INT || data_type == IS_UNSIGN_INT )
		{
			sum += ( *(( int* )Phead + index ) );
		}
		else if ( data_type == IS_FLOAT )
		{
			fsum += ( *(( float* )Phead + index ) );
		}
	}
	if ( data_type == IS_FLOAT ) return fsum;
	return sum;
}
/********************************************************************
 * @创建人 :揭成
 * @功能:数字类型转换，2位数以内
 *
 * @输入:NONE
 *
 *@输出:NONE
********************************************************************/
void  osp_hex_to_bcd( u8_t src, u8_t *bcd_src )
{
	u8_t tmp = 0;
	while ( src >= 10 )
	{
		src -= 10;
		tmp += 16;
	}
	tmp += src;
	*bcd_src = tmp;
	return ;
}
void  osp_bcd_to_hex( u8_t bcd_src, u8_t *pur_ptr )
{
	u8_t tmp = 0;
	while ( bcd_src >= 16 )
	{
		bcd_src -= 16;
		tmp += 10;
	}
	tmp += bcd_src;
	*pur_ptr = tmp;
	return ;
}
/********************************************************************
 * @创建人 :揭成
 * @功能 :浮点数分离出整数和小数
 * @输入 :src 要处理的浮点数，plong 整形缓存，ppoint 小数缓存
 *
 *@输出 :NONE
********************************************************************/
void osp_float_putoff_point( float fsrc, long *plong, float*ppoint )
{
	*plong = ( long )fsrc;
	*ppoint = fsrc - *plong;
	return;
}
/********************************************************************
 * @创建人 :揭成
 * @功能 :浮点数四舍五入
 * @输入 :src 要处理的浮点数
 *
 *@输出 :处理后的浮点数
********************************************************************/
float  osp_round_off_float( float src )
{
	long ltemp;
	float fpoint;
	osp_float_putoff_point( GLOBAL_ABS( src ), &ltemp, &fpoint );
	( fpoint > ( float )0.4 ) ? ( fpoint = 1 ) : ( fpoint = 0 );
	return( src > 0 ) ? (( float )ltemp + fpoint ) : ( -(( float )ltemp + fpoint ) );
}
/********************************************************************
 * @创建人 :揭成
 * @功能 :去掉字符串中指定的所有字符
 * @输入 :psrc 原字符串，ch 指定字符
 *
 *@输出 :NONE
********************************************************************/
void  osp_string_filter( char*psrc, char ch )
{
	Bsize_t offset, shoffset;
	Bsize_t strlen = osp_strlen( psrc );
	char *pshadow = app_malloc( strlen + 2 );
	if ( !pshadow ) return;
	GLOBAL_MEMCLR( pshadow, ( strlen + 2 ) );
	shoffset = 0;
	for ( offset = 0;offset < strlen;offset++ )
	{
		if ( psrc[offset] != ch )
		{
			pshadow[shoffset] = psrc[offset];
			shoffset++;
		}
	}
	osp_memcpy( psrc, pshadow, strlen );
	app_free( pshadow );
	return;
}
/********************************************************************
 * @创建人 :揭成
 * @功能 :在pbuf后面添加字符
 * @输入 :pbuf,buf_len长度,str字符串
 *
 *如
 *		char buf[20];
 *		osp_sprintf(buf,20,"is %d %s",10,"abc");
 *		"is 10 abc"
 *
 *@输出 :NONE
********************************************************************/
int osp_sprintf( char* pbuf, Bsize_t buf_len, char* str, ... )
{
	va_list arp;
	char c, d, s[16], *p;
	Bsize_t ofs,len;
	ofs = 0;
	buf_len -= 1;
	va_start( arp, str );
	GLOBAL_MEMCLR( pbuf, buf_len );
	while ( 1 )
	{
		c = *str++;
		if ( c == 0 ) break;			
		if ( c != '%' )  				
		{
			if (( 1 + ofs ) < buf_len )pbuf[ofs++] = c;
			continue;
		}
		c = *str++;
		if ( !c ) break;
		d = UPCASE( c );
		switch ( d )  				
		{
		case 'S' :					
			p = va_arg( arp, char* );
			len = osp_strlen( p );
			if (( len + ofs ) < buf_len )
			{
				osp_strcpy( &pbuf[ofs], p );
				ofs += len;
			}
			continue;
		case 'C' :					
			len = 1;
			if (( len + ofs ) < buf_len )
			{
				pbuf[ofs++] = ( char )va_arg( arp, int );
			}
			continue;
        case 'F':
			len = osp_ftoa(( float )va_arg( arp, double ), s,3);
			if (( len + ofs ) < buf_len )
			{
				osp_strcat( pbuf, s );
				ofs += len;
			}		
			continue;
		case 'L' :
			len = osp_ltoa(( long )va_arg( arp, long ), s );
			if (( len + ofs ) < buf_len )
			{
				osp_strcat( pbuf, s );
				ofs += len;
			}
			continue;
		case 'D' :					
		case 'U' :					
			len = osp_ltoa(( int )va_arg( arp, int ), s );
			if (( len + ofs ) < buf_len )
			{
				osp_strcat( pbuf, s );
				ofs += len;
			}
			continue;
		default:					
			continue;
		}
	}
	va_end( arp );
	pbuf[ofs] = 0;
	return ofs;
}

/********************************************************************
 *@创建人 :揭成
 *@功能 :判断字符是不是数字字符
 *@输入 :asc 码
 *
 *@输出 : '0'-'9'
********************************************************************/
BOOL  osp_decide_num( char asc )
{
	return DECCHK( asc );
}

/*****************************************************************************
* @作    者:阳永锋
* @函数名:global_float_to_bcd
* @功能描述:浮点数转换成指定长度的bcd码
* @输入参数:bcd_buf: BCD码缓存指针,bcd_integer_bits:BCD码整数位,
*			bcd_point_bits:bcd码小数位,fsrc: 待转换浮点数
* @输出参数:NONE
* @返 回 值:NONE
* @备    注:bcd_integer_bits + bcd_point_bits 必须数偶数值
*****************************************************************************/
uint8_t  osp_float_to_bcd(uint8_t *bcd_buf,uint8_t bcd_integer_bits,
							uint8_t bcd_point_bits,float fsrc)
{ 
	char 	buf[20] = "";
	uint8_t cnt = 0;
	long 	bcd_integer = 0;
	uint8_t bcd_str_len = 0;
	uint8_t bcd_num_len = 0;
	uint8_t f_negtive_num = 0;
	const uint8_t bcd_bytes = (bcd_integer_bits + bcd_point_bits)/2;
		
	for (cnt = 0; cnt < bcd_point_bits; cnt++) 	/*保留规定小数位*/
		fsrc *= 10.0f;
	bcd_integer = (long)(fsrc+0.6f);					/*截取浮点数的有效值,+0.6防止取整四舍五入*/

	bcd_str_len = global_ltoa(bcd_integer, buf);
	global_string_reversal(buf);
	if (buf[bcd_str_len - 1] == '-')
	{
		bcd_num_len = bcd_str_len - 1;			/*减去负号*/
		f_negtive_num = 1;
	}
	else
	{
		bcd_num_len = bcd_str_len;
		f_negtive_num = 0;
	}
	
	while(bcd_num_len < bcd_integer_bits + bcd_point_bits) /*不足数据填'0'*/
		buf[bcd_num_len++] = '0';
	
	for (cnt = 0; cnt < bcd_bytes; cnt++)					/*转换成BCD码*/
	{
		bcd_buf[cnt] = (GLOBAL_CTON(buf[cnt*2+1]) << 4) + 
					GLOBAL_CTON(buf[cnt*2]);
	} 

	if (f_negtive_num)  									/*负数最高位置1*/
		bcd_buf[bcd_bytes - 1] |= 0x80;

	return bcd_bytes;
}

/*****************************************************************************
* @作    者:阳永锋
* @函数名:global_float_to_bcd
* @功能描述:浮点数转换成指定长度的bcd码
* @输入参数:bcd_buf: BCD码缓存指针,bcd_bytes:BCD码字节数,
*			lvalue:待转换长整形
* @输出参数:NONE
* @返 回 值:NONE
* @备    注:
*****************************************************************************/
uint8_t  osp_long_to_bcd(uint8_t *const bcd_buf,const uint8_t bcd_bytes,
									long lvalue)
{ 
	char 	buf[20] = "";
	uint8_t cnt = 0;
	uint8_t bcd_str_len = 0;
	uint8_t bcd_num_len = 0;
	uint8_t f_negtive_num = 0;

		
	bcd_str_len = global_ltoa(lvalue, buf);
	global_string_reversal(buf);
	if (buf[bcd_str_len - 1] == '-')
	{
		bcd_num_len = bcd_str_len - 1;			/*减去负号*/
		f_negtive_num = 1;
	}
	else
	{
		bcd_num_len = bcd_str_len;
		f_negtive_num = 0;
	}
	
	while(bcd_num_len < bcd_bytes*2) /*不足数据填'0'*/
		buf[bcd_num_len++] = '0';
	
	for (cnt = 0; cnt < bcd_bytes; cnt++)					/*转换成BCD码*/
	{
		bcd_buf[cnt] = (GLOBAL_CTON(buf[cnt*2+1]) << 4) + 
					GLOBAL_CTON(buf[cnt*2]);
	} 

	if (f_negtive_num)  									/*负数最高位置1*/
		bcd_buf[bcd_bytes - 1] |= 0x80;

	return bcd_bytes;

}
/*****************************************************************************
* @作    者:阳永锋
* @函数名:global_bcd_to_string
* @功能描述:bcd码组转换成字符串
* @输入参数:pdes:转换后的字符串缓存指针,bcd_buf:bcd码缓存指针,
*			bcd_size:bcd码字节数
* @输出参数:
* @返 回 值:字符串长度
* @备    注:字符串必须全部为数字:'0'-'9'
*****************************************************************************/
uint8_t osp_bcd_to_string(char *pdes,uint8_t *bcd_buf, uint8_t bcd_size)
{
	uint8_t cnt = 0;
	
	for (cnt = 0; cnt < bcd_size; cnt++)
	{
		pdes[cnt*2+1] = global_NtoC(bcd_buf[cnt]&0x0f);
		pdes[cnt*2] = global_NtoC((bcd_buf[cnt]>>4) & 0x0f);
	}
	pdes[cnt*2] = ASCII_NULL;
	return cnt*2;
}

/*****************************************************************************
* @作    者:阳永锋
* @函数名:global_string_to_bcd
* @功能描述:字符串转换成BCD码
* @输入参数:bcd_buf:bcd码缓存,bcd_size:bcd码字节数,psrc:字符串指针
* @输出参数:NONE
* @返 回 值:bcd码字节数
* @备    注:字符串必须全部为数字:'0'-'9'
*****************************************************************************/
uint8_t osp_string_to_bcd(uint8_t *bcd_buf, uint8_t bcd_size, char *psrc)
{
	uint8_t cnt = 0;
	uint8_t len = global_strlen(psrc);
	uint8_t bcd_hight = 0;
	uint8_t bcd_low = 0;

	for (cnt = 0; cnt < bcd_size; cnt++)		
	{	
		if (cnt*2 < len)
			bcd_low = global_CtoN(psrc[cnt*2]);
		else
			bcd_low = 0;
		if (cnt*2 +1 < len)
			bcd_hight= global_CtoN(psrc[cnt*2 + 1]);
		else
			bcd_hight = 0;
		bcd_buf[cnt] = (bcd_low << 4) + bcd_hight;
	}
	return bcd_size;
}

/*****************************************************************************
* @作    者:阳永锋
* @函数名:global_memory_reverse
* @功能描述:内存内容翻转
* @输入参数:buf: 数据内容
*			buf_size:数据大小
* @输出参数:NONE
* @返 回 值:NONE
* @备    注:
*****************************************************************************/
void osp_memory_reverse(uint8_t *buf, uint32_t buf_size)
{
	uint32_t cnt = 0;
	uint8_t *p_temp_buf = app_malloc(buf_size);

	if (p_temp_buf)
	{
		for (cnt = 0; cnt < buf_size; cnt++)
		{
			p_temp_buf[buf_size-1-cnt] = buf[cnt];	
		}
		global_memcpy(buf, p_temp_buf, buf_size);
		app_free(p_temp_buf);
	}
	return;
}

/*****************************************************************************
* @作    者:阳永锋
* @函数名:global_DL645_string_reverse
* @功能描述:
* @输入参数:NONE
* @输出参数:NONE
* @返 回 值:NONE
* @备    注:
*****************************************************************************/
void osp_DL645_string_reverse(uint8_t *buf,uint8_t buf_len)
{
	uint8_t len = 0;
	
	if (buf[buf_len-1] == '\0')
	{
		len = global_strlen((char*)buf);
	}
	else
	{
		len = buf_len;
	}			
	osp_memory_reverse(buf,len);
	return;
}



/*****************************************************************************
* @作    者:阳永锋
* @函数名:global_bcd_to_float
* @功能描述:BCD码转浮点数
* @输入参数:buf:bcd码数据,bcd_integer_bits:bcd码整数位，
*			bcd_integer_bits:bcd小数位
*			sign:符号位标记(1:转换成有符号数据，0:转换成无符号数)
* @输出参数:NONE
* @返 回 值:浮点数值
* @备    注:
*****************************************************************************/
float osp_bcd_to_float(const uint8_t *bcd_buf, uint8_t bcd_integer_bits,
								uint8_t bcd_point_bits,uint8_t sign)
{
	uint8_t cnt = 0;
	float Mtime = 1.0f;
	float ftemp = 0.0f;
	uint8_t U8_temp = 0;
	const uint8_t bcd_bytes = (bcd_integer_bits + bcd_point_bits)/2;
	uint8_t shadow_bcd_buf[20] = {0};
	
	global_memcpy(shadow_bcd_buf, (uint8_t*)bcd_buf, bcd_bytes);
	if (sign == 1)
		shadow_bcd_buf[bcd_bytes-1] &= 0x7F;		/*去除符号位*/
	
	for (cnt = 0; cnt < bcd_point_bits; cnt++)	/*获取BCD最小位权值*/
		Mtime *= 0.1f;
		
	for (cnt = 0; cnt < bcd_bytes; cnt++)
	{
		bcd_convert_hex(shadow_bcd_buf[cnt], &U8_temp);
		ftemp += (float)U8_temp * Mtime;
		Mtime *= 100.0f;
	}
	if (sign == 1)
	{
		if (bcd_buf[bcd_bytes-1] & 0x80)
		{
			ftemp *= -1.0f;
		}
	}
	return ftemp;
}


/*****************************************************************************
* @作    者:阳永锋
* @函数名:global_bcd_to_long
* @功能描述:BCD码转整数
* @输入参数:buf:bcd码数据,
*			bcd_size:BCD字节数
*			sign:符号位标记(1:转换成有符号数据，0:转换成无符号数)
* @输出参数:NONE
* @返 回 值:NONE
* @备    注:
*****************************************************************************/
long osp_bcd_to_long(const uint8_t *bcd_buf, uint8_t bcd_size, uint8_t sign)
{
	uint8_t cnt = 0;
	uint8_t U8_temp = 0;
	
	long time = 1;
	long ltemp = 0;
	uint8_t shadow_bcd_buf[20] = {0};

	global_memcpy(shadow_bcd_buf, (void*)bcd_buf, bcd_size);
	if (sign == 1)
		shadow_bcd_buf[bcd_size-1] &= 0x7F;		/*去除符号位*/

	for (cnt = 0; cnt < bcd_size; cnt++)
	{
		bcd_convert_hex(shadow_bcd_buf[cnt], &U8_temp);
		ltemp += U8_temp*time;
		time *= 100u;
	}
	if (sign == 1)
	{
		if (bcd_buf[bcd_size-1] & 0x80)		/*最高为1，为负数*/
		{
			ltemp *= -1;
		}
	}
	return ltemp;
}

/*****************************************************************************
* @作    者:阳永锋
* @函数名:global_digit_string_to_bcd
* @功能描述:数字字符串转BCD码
* @输入参数:bcd_bytes:转换的BCD码字节数
*			psrc_str:源字符串
* @输出参数:bcd_buf:bcd码
* @返 回 值:NONE
* @备    注:字符串必须全部是数字
*****************************************************************************/
BOOL  osp_digit_string_to_bcd(uint8_t *bcd_buf, uint16_t bcd_bytes, const char *p_src_str)
{
	uint16_t index = 0;
	uint8_t *p_shadow_buf = NULL;
	uint16_t shadow_buf_size = bcd_bytes*2 + 1;
	uint16_t src_str_len = 0;

	/*参数合法性检查*/
	if (p_src_str == NULL || bcd_buf == NULL) 
		return FALSE;
	if (bcd_bytes == 0)
		return FALSE;
	

	src_str_len = global_strlen((char*)p_src_str);
	if (src_str_len == 0)							/*空字符串*/
		return FALSE;
	
	for (index = 0; index < src_str_len; index++)	/*检测字符串是否读为数字*/
	{
		if (!osp_decide_num(p_src_str[index]))
			return FALSE;
	}
	
	p_shadow_buf = app_malloc(shadow_buf_size);
	if (p_shadow_buf == NULL)
		return FALSE;
	GLOBAL_MEMCLR(p_shadow_buf,shadow_buf_size);
	
	/*拷贝字符串到备用缓存*/
	strncpy((char*)p_shadow_buf,p_src_str,bcd_bytes*2);
		
	osp_DL645_string_reverse(p_shadow_buf, bcd_bytes*2);	/*翻转*/
	
	for (index = 0; index < bcd_bytes; index++)
	{
		bcd_buf[index] = (global_CtoN(p_shadow_buf[index*2 + 1]) << 4)| global_CtoN(p_shadow_buf[index*2]);
	}
	app_free(p_shadow_buf);

	return TURE;
}

/*****************************************************************************
* @作    者:阳永锋
* @函数名:osp_hex_char_to_hex
* @功能描述:16进制字符转换为16进制数
* @输入参数:16进制字符
* @输出参数:NONE
* @返 回 值:16进制数
* @备    注:如‘0’转为0x0, 'a'转为0xA, 'A'转为0xA
*****************************************************************************/
u8_t osp_hex_char_to_hex(char ch)
{
	u8_t u8_value = 0;
	
	if (ch >= '0' && ch <= '9')
		u8_value = ch - '0';
	else if (ch >= 'A' && ch <= 'F')
		u8_value = ch - 'A' + 10u;
	else if (ch >= 'a' && ch <= 'f')
		u8_value = ch - 'a' + 10u;
	else
		u8_value = 0;
	
	return u8_value;
}

/*****************************************************************************
* @作    者:阳永锋
* @函数名:osp_hex_string_to_hex
* @功能描述:16进制字符串转16进制数
* @输入参数:字符串
* @输出参数:NONE
* @返 回 值:NONE
* @备    注:如 "2679" 则转成: 0x2679
*****************************************************************************/
u32_t osp_hex_string_to_hex(const char *psrc)
{
	uint8_t cnt = 0;
	u8_t u8_temp = 0;
	u32_t u32_temp = 0;
	uint8_t len = global_strlen((char*)psrc);

	if(len > 8) 
		return 0;
	
	for (cnt = 0; cnt < len; cnt++)		
	{	
		u8_temp = osp_hex_char_to_hex(psrc[len - cnt -1]);
		u32_temp |=  (u8_temp << (4*cnt)); 
	}
	return u32_temp;
}

/*****************************************************************************
* @作    者:阳永锋
* @函数名:osp_hex_nstring_to_hex
* @功能描述:转换指定字节16进制字符串转16进制数
* @输入参数:字符串
* @输出参数:NONE
* @返 回 值:NONE
* @备    注:如 "2679" 则转成: 0x2679
*****************************************************************************/
u8_t osp_2hexchar_to_hex(char high_4bit_char,char low_4bit_char)
{
	u8_t u8_value = 0;
	
	u8_value |= osp_hex_char_to_hex(low_4bit_char);
	u8_value |= (osp_hex_char_to_hex(high_4bit_char) << 4);
	return u8_value;
}

/*****************************************************************************
* @作    者:阳永锋
* @函数名:osp_hexstring_to_array
* @功能描述:阳永锋
* @输入参数:16进制字符串转 16进制数据
* @输出参数:NONE
* @返 回 值:NONE
* @备    注:如"2679"转成: [0x26,0x79],
*			注意缓存必须足够大
*****************************************************************************/
void osp_hexstring_to_array(uint8_t array[],u8_t array_size, const char* hexstring)
{
	uint8_t index = 0;
	u8_t u8_temp = 0;
	u8_t real_len = 0;
	uint8_t len = global_strlen((char*)hexstring);

	if (len > array_size *2)
		real_len = array_size *2;
	else
		real_len = len;
	
	for (index = 0; index < real_len / 2 ; index++)		
	{	
		u8_temp = osp_hex_char_to_hex(hexstring[len -1 - index*2]);
		u8_temp |= (osp_hex_char_to_hex(hexstring[len -2 - index*2]) << 4);
		array[index] = u8_temp;
	}
	if (real_len % 2 != 0)		
	{
		array[index] = osp_hex_char_to_hex(hexstring[len - 1 - index*2]);	/*填充最高位*/
		index++;
	}
	for (; index < array_size; index++)		/*补0*/
	{
		array[index] = 0x0;
	}
	return ;

}

