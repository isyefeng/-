#include "osp_global_str.h"

///********************************************************************
// *@创建人:揭成
// *@功能:内存比较
// *
// *@输入: 	pur_add  :指向目的地址
// *       		src_ptr :指向源地址
// *      		lenth:数据长度
// *@输出:	NONE
//********************************************************************/
//BOOL  osp_memcmp( const void * pur_add, const void*src_ptr, Bsize_t lenth )
//{
//	Bsize_t index;
//	char*p_pur = ( char* )pur_add;
//	char*p_src = ( char* )src_ptr;
//	for ( index = 0;index < lenth;index++ )
//	{
//		if ( p_pur[index] != p_src[index] )
//		{
//			return BOOL_0;
//		}
//	}
//	return BOOL_1;
//}

///********************************************************************
// *@创建人:揭成
// *@功能:内存复制
// *
// *@输入: pur_add  :指向目标地址
// * 		 pad_data :指向源地址
// *       lenth:数据长度
// *@输出:NONE
//********************************************************************/
//void osp_memcpy( void * pur_add, void*src_ptr, Bsize_t lenth )
//{
//	Bsize_t index;
//	char*p_pur = ( char* )pur_add;
//	char*p_src = ( char* )src_ptr;
//	for ( index = 0;index < lenth;index++ )
//	{
//		p_pur[index] = p_src[index];
//	}
//	return ;
//}

///*********************************************************************
//*@函数名称:测试字符长度
//*@创建人:揭成
//*@输入: psrc  :要测试的字符串
//*@输出:字符长度
//*********************************************************************/
//Bsize_t osp_strlen( char*psrc )
//{
//	Bsize_t lenth = 0;
//	while (( *psrc ) != ASCII_NULL )
//	{
//		lenth++;
//		psrc++;
//	}
//	return lenth;
//}

///*********************************************************************
//*@函数名称:将字符串pstr2合并到pstr1
//*@创建人:揭成
//*@输入: pstr1  pstr2
//*@ output :NONE
//*必须确保pstr1 有足够的空间
//*********************************************************************/
//void osp_strcat( char*pstr1, char*pstr2 )
//{
//	char*pch;
//	pch = ( char* )pstr1 + osp_strlen( pstr1 );
//	osp_memcpy(( u8_t* )pch,
//				  ( u8_t* )pstr2,
//				  ( osp_strlen( pstr2 ) + 1 ) );
//	return;
//}

///********************************************************************
// * @创建人 :揭成
// * @功能 :在字符串中定位一个字符串
// * @输入 :psrc 字符串  pserch 待查询的字符串
// *
// *@输出 :查询到字符的位置
//********************************************************************/
//char* osp_strstr( char*psrc, char*psearch )
//{
//	Bsize_t offset;
//	Bsize_t psearch_lenth = osp_strlen( psearch );
//	Bsize_t psrc_lenth = osp_strlen( psrc );
//	for ( offset = 0;offset < psrc_lenth;offset++ )
//	{
//		if ( osp_memcmp( &psrc[offset],
//							psearch,
//							psearch_lenth ) )
//		{
//			return &( psrc[offset] );
//		}
//	}
//	return PNULL;
//}


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


