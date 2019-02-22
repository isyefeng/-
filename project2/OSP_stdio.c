/*********************************************************************************************
*            �麣�����������޹�˾
*            http://www.zhkh.com
* ģ������:ϰ��ͨ���Ժ���֧��
* ����ʱ��:2010-06-23
* ������˾ :����
* �ļ�����:OSP.c
* ������ :�ҳ�
* ��������:���ú������ϡ�
*----------------------------------------------------------------
�޸ļ�¼:

�޸�����:

�޸���:

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
 *@������:�ҳ�
 *@����:�ڴ渴��
 *
 *@����: pur_add  :ָ��Ŀ���ַ
 * 		 pad_data :ָ��Դ��ַ
 *       lenth:���ݳ���
 *@���:NONE
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
 *@������:�ҳ�
 *@����:�ڴ����
 *
 *@����: 	pur_add  :ָ�������ڴ濪ʼ��ַ
 *       	pad_data :�������
 *      	lenth    :���ݳ���
 *@���:	NONE
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
 *@������:�ҳ�
 *@����:�ڴ�Ƚ�
 *
 *@����: 	pur_add  :ָ��Ŀ�ĵ�ַ
 *       		src_ptr :ָ��Դ��ַ
 *      		lenth:���ݳ���
 *@���:	NONE
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
*@��������:�����ַ�����
*@������:�ҳ�
*@����: psrc  :Ҫ���Ե��ַ���
*@���:�ַ�����
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
*@��������:���ַ���pstr2�ϲ���pstr1
*@������:�ҳ�
*@����: pstr1  pstr2
*@ output :NONE
*����ȷ��pstr1 ���㹻�Ŀռ�
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
*   @��������:�����ַ���
*   @������:�ҳ�
*   @����: psrc  :Ҫ�����ַ���
*
*    @ output :�ַ�����
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
 * @������ :�ҳ�
 * @���� :���ַ����ж�λһ���ַ���
 * @���� :psrc �ַ���  chr ����ѯ���ַ�
 *
 *@��� :��ѯ���ַ���λ��
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
 * @������ :�ҳ�
 * @���� :���ַ����ж�λһ���ַ���
 * @���� :psrc �ַ���  pserch ����ѯ���ַ���
 *
 *@��� :��ѯ���ַ���λ��
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
 * @������:�ҳ�
 * @����  :���ַ����ж�λһ���ַ��������ض�λ���ĸ���
 * @����  : phead �ַ���ͷ��
 *		    pend  �ַ���β
 *		    paddr ��Ŷ�λ�����ַ���ַ
 *
 * @��� :��ѯ���ַ���λ��
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
 * @������ :�ҳ�
 * @���� :���ַ����ж�λһ���ַ������������һ����λ����
 * @���� :phead �ַ���ͷ��
 *		  pend  �ַ���β
 *		  pserch ����ѯ���ַ���
 * @��� :��ѯ���ַ���λ��
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
*@��������:�ַ�����ת
*@������:�ҳ�
*@����:
*@���: NONE
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
*@��������:int ת�����ַ���
*@������:�ҳ�
*@����:
*@���: NONE
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
*@����?float ת�����ַ���
*@������:�ҳ�
*@����:
*@ output : NONE
*BOOL_0 :ȥ��������
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
*@��������:�ַ�ת����INT
*@������:�ҳ�
*@����:
*@���: NONE
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
*@��������:�ַ�ת����INT
*@������:�ҳ�
*@����:
*@���: NONE
*********************************************************************/
long osp_atol( char *pdes )
{
	return atoi( pdes );
}
/********************************************************************
 *@������:�ҳ�
 *@����:��һ�����ۼӺ�
 *
 *@����:Phead ����ͷ  size ���鳤�� data_type  ��������
 *
 *@���:����ĺ�
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
 * @������ :�ҳ�
 * @����:��������ת����2λ������
 *
 * @����:NONE
 *
 *@���:NONE
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
 * @������ :�ҳ�
 * @���� :�����������������С��
 * @���� :src Ҫ����ĸ�������plong ���λ��棬ppoint С������
 *
 *@��� :NONE
********************************************************************/
void osp_float_putoff_point( float fsrc, long *plong, float*ppoint )
{
	*plong = ( long )fsrc;
	*ppoint = fsrc - *plong;
	return;
}
/********************************************************************
 * @������ :�ҳ�
 * @���� :��������������
 * @���� :src Ҫ����ĸ�����
 *
 *@��� :�����ĸ�����
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
 * @������ :�ҳ�
 * @���� :ȥ���ַ�����ָ���������ַ�
 * @���� :psrc ԭ�ַ�����ch ָ���ַ�
 *
 *@��� :NONE
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
 * @������ :�ҳ�
 * @���� :��pbuf��������ַ�
 * @���� :pbuf,buf_len����,str�ַ���
 *
 *��
 *		char buf[20];
 *		osp_sprintf(buf,20,"is %d %s",10,"abc");
 *		"is 10 abc"
 *
 *@��� :NONE
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
 *@������ :�ҳ�
 *@���� :�ж��ַ��ǲ��������ַ�
 *@���� :asc ��
 *
 *@��� : '0'-'9'
********************************************************************/
BOOL  osp_decide_num( char asc )
{
	return DECCHK( asc );
}

/*****************************************************************************
* @��    ��:������
* @������:global_float_to_bcd
* @��������:������ת����ָ�����ȵ�bcd��
* @�������:bcd_buf: BCD�뻺��ָ��,bcd_integer_bits:BCD������λ,
*			bcd_point_bits:bcd��С��λ,fsrc: ��ת��������
* @�������:NONE
* @�� �� ֵ:NONE
* @��    ע:bcd_integer_bits + bcd_point_bits ������ż��ֵ
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
		
	for (cnt = 0; cnt < bcd_point_bits; cnt++) 	/*�����涨С��λ*/
		fsrc *= 10.0f;
	bcd_integer = (long)(fsrc+0.6f);					/*��ȡ����������Чֵ,+0.6��ֹȡ����������*/

	bcd_str_len = global_ltoa(bcd_integer, buf);
	global_string_reversal(buf);
	if (buf[bcd_str_len - 1] == '-')
	{
		bcd_num_len = bcd_str_len - 1;			/*��ȥ����*/
		f_negtive_num = 1;
	}
	else
	{
		bcd_num_len = bcd_str_len;
		f_negtive_num = 0;
	}
	
	while(bcd_num_len < bcd_integer_bits + bcd_point_bits) /*����������'0'*/
		buf[bcd_num_len++] = '0';
	
	for (cnt = 0; cnt < bcd_bytes; cnt++)					/*ת����BCD��*/
	{
		bcd_buf[cnt] = (GLOBAL_CTON(buf[cnt*2+1]) << 4) + 
					GLOBAL_CTON(buf[cnt*2]);
	} 

	if (f_negtive_num)  									/*�������λ��1*/
		bcd_buf[bcd_bytes - 1] |= 0x80;

	return bcd_bytes;
}

/*****************************************************************************
* @��    ��:������
* @������:global_float_to_bcd
* @��������:������ת����ָ�����ȵ�bcd��
* @�������:bcd_buf: BCD�뻺��ָ��,bcd_bytes:BCD���ֽ���,
*			lvalue:��ת��������
* @�������:NONE
* @�� �� ֵ:NONE
* @��    ע:
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
		bcd_num_len = bcd_str_len - 1;			/*��ȥ����*/
		f_negtive_num = 1;
	}
	else
	{
		bcd_num_len = bcd_str_len;
		f_negtive_num = 0;
	}
	
	while(bcd_num_len < bcd_bytes*2) /*����������'0'*/
		buf[bcd_num_len++] = '0';
	
	for (cnt = 0; cnt < bcd_bytes; cnt++)					/*ת����BCD��*/
	{
		bcd_buf[cnt] = (GLOBAL_CTON(buf[cnt*2+1]) << 4) + 
					GLOBAL_CTON(buf[cnt*2]);
	} 

	if (f_negtive_num)  									/*�������λ��1*/
		bcd_buf[bcd_bytes - 1] |= 0x80;

	return bcd_bytes;

}
/*****************************************************************************
* @��    ��:������
* @������:global_bcd_to_string
* @��������:bcd����ת�����ַ���
* @�������:pdes:ת������ַ�������ָ��,bcd_buf:bcd�뻺��ָ��,
*			bcd_size:bcd���ֽ���
* @�������:
* @�� �� ֵ:�ַ�������
* @��    ע:�ַ�������ȫ��Ϊ����:'0'-'9'
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
* @��    ��:������
* @������:global_string_to_bcd
* @��������:�ַ���ת����BCD��
* @�������:bcd_buf:bcd�뻺��,bcd_size:bcd���ֽ���,psrc:�ַ���ָ��
* @�������:NONE
* @�� �� ֵ:bcd���ֽ���
* @��    ע:�ַ�������ȫ��Ϊ����:'0'-'9'
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
* @��    ��:������
* @������:global_memory_reverse
* @��������:�ڴ����ݷ�ת
* @�������:buf: ��������
*			buf_size:���ݴ�С
* @�������:NONE
* @�� �� ֵ:NONE
* @��    ע:
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
* @��    ��:������
* @������:global_DL645_string_reverse
* @��������:
* @�������:NONE
* @�������:NONE
* @�� �� ֵ:NONE
* @��    ע:
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
* @��    ��:������
* @������:global_bcd_to_float
* @��������:BCD��ת������
* @�������:buf:bcd������,bcd_integer_bits:bcd������λ��
*			bcd_integer_bits:bcdС��λ
*			sign:����λ���(1:ת�����з������ݣ�0:ת�����޷�����)
* @�������:NONE
* @�� �� ֵ:������ֵ
* @��    ע:
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
		shadow_bcd_buf[bcd_bytes-1] &= 0x7F;		/*ȥ������λ*/
	
	for (cnt = 0; cnt < bcd_point_bits; cnt++)	/*��ȡBCD��СλȨֵ*/
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
* @��    ��:������
* @������:global_bcd_to_long
* @��������:BCD��ת����
* @�������:buf:bcd������,
*			bcd_size:BCD�ֽ���
*			sign:����λ���(1:ת�����з������ݣ�0:ת�����޷�����)
* @�������:NONE
* @�� �� ֵ:NONE
* @��    ע:
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
		shadow_bcd_buf[bcd_size-1] &= 0x7F;		/*ȥ������λ*/

	for (cnt = 0; cnt < bcd_size; cnt++)
	{
		bcd_convert_hex(shadow_bcd_buf[cnt], &U8_temp);
		ltemp += U8_temp*time;
		time *= 100u;
	}
	if (sign == 1)
	{
		if (bcd_buf[bcd_size-1] & 0x80)		/*���Ϊ1��Ϊ����*/
		{
			ltemp *= -1;
		}
	}
	return ltemp;
}

/*****************************************************************************
* @��    ��:������
* @������:global_digit_string_to_bcd
* @��������:�����ַ���תBCD��
* @�������:bcd_bytes:ת����BCD���ֽ���
*			psrc_str:Դ�ַ���
* @�������:bcd_buf:bcd��
* @�� �� ֵ:NONE
* @��    ע:�ַ�������ȫ��������
*****************************************************************************/
BOOL  osp_digit_string_to_bcd(uint8_t *bcd_buf, uint16_t bcd_bytes, const char *p_src_str)
{
	uint16_t index = 0;
	uint8_t *p_shadow_buf = NULL;
	uint16_t shadow_buf_size = bcd_bytes*2 + 1;
	uint16_t src_str_len = 0;

	/*�����Ϸ��Լ��*/
	if (p_src_str == NULL || bcd_buf == NULL) 
		return FALSE;
	if (bcd_bytes == 0)
		return FALSE;
	

	src_str_len = global_strlen((char*)p_src_str);
	if (src_str_len == 0)							/*���ַ���*/
		return FALSE;
	
	for (index = 0; index < src_str_len; index++)	/*����ַ����Ƿ��Ϊ����*/
	{
		if (!osp_decide_num(p_src_str[index]))
			return FALSE;
	}
	
	p_shadow_buf = app_malloc(shadow_buf_size);
	if (p_shadow_buf == NULL)
		return FALSE;
	GLOBAL_MEMCLR(p_shadow_buf,shadow_buf_size);
	
	/*�����ַ��������û���*/
	strncpy((char*)p_shadow_buf,p_src_str,bcd_bytes*2);
		
	osp_DL645_string_reverse(p_shadow_buf, bcd_bytes*2);	/*��ת*/
	
	for (index = 0; index < bcd_bytes; index++)
	{
		bcd_buf[index] = (global_CtoN(p_shadow_buf[index*2 + 1]) << 4)| global_CtoN(p_shadow_buf[index*2]);
	}
	app_free(p_shadow_buf);

	return TURE;
}

/*****************************************************************************
* @��    ��:������
* @������:osp_hex_char_to_hex
* @��������:16�����ַ�ת��Ϊ16������
* @�������:16�����ַ�
* @�������:NONE
* @�� �� ֵ:16������
* @��    ע:�确0��תΪ0x0, 'a'תΪ0xA, 'A'תΪ0xA
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
* @��    ��:������
* @������:osp_hex_string_to_hex
* @��������:16�����ַ���ת16������
* @�������:�ַ���
* @�������:NONE
* @�� �� ֵ:NONE
* @��    ע:�� "2679" ��ת��: 0x2679
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
* @��    ��:������
* @������:osp_hex_nstring_to_hex
* @��������:ת��ָ���ֽ�16�����ַ���ת16������
* @�������:�ַ���
* @�������:NONE
* @�� �� ֵ:NONE
* @��    ע:�� "2679" ��ת��: 0x2679
*****************************************************************************/
u8_t osp_2hexchar_to_hex(char high_4bit_char,char low_4bit_char)
{
	u8_t u8_value = 0;
	
	u8_value |= osp_hex_char_to_hex(low_4bit_char);
	u8_value |= (osp_hex_char_to_hex(high_4bit_char) << 4);
	return u8_value;
}

/*****************************************************************************
* @��    ��:������
* @������:osp_hexstring_to_array
* @��������:������
* @�������:16�����ַ���ת 16��������
* @�������:NONE
* @�� �� ֵ:NONE
* @��    ע:��"2679"ת��: [0x26,0x79],
*			ע�⻺������㹻��
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
		array[index] = osp_hex_char_to_hex(hexstring[len - 1 - index*2]);	/*������λ*/
		index++;
	}
	for (; index < array_size; index++)		/*��0*/
	{
		array[index] = 0x0;
	}
	return ;

}

