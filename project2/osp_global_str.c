#include "osp_global_str.h"

///********************************************************************
// *@������:�ҳ�
// *@����:�ڴ�Ƚ�
// *
// *@����: 	pur_add  :ָ��Ŀ�ĵ�ַ
// *       		src_ptr :ָ��Դ��ַ
// *      		lenth:���ݳ���
// *@���:	NONE
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
// *@������:�ҳ�
// *@����:�ڴ渴��
// *
// *@����: pur_add  :ָ��Ŀ���ַ
// * 		 pad_data :ָ��Դ��ַ
// *       lenth:���ݳ���
// *@���:NONE
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
//*@��������:�����ַ�����
//*@������:�ҳ�
//*@����: psrc  :Ҫ���Ե��ַ���
//*@���:�ַ�����
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
//*@��������:���ַ���pstr2�ϲ���pstr1
//*@������:�ҳ�
//*@����: pstr1  pstr2
//*@ output :NONE
//*����ȷ��pstr1 ���㹻�Ŀռ�
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
// * @������ :�ҳ�
// * @���� :���ַ����ж�λһ���ַ���
// * @���� :psrc �ַ���  pserch ����ѯ���ַ���
// *
// *@��� :��ѯ���ַ���λ��
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


