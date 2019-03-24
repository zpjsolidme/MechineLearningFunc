#include "stdafx.h"
#include "ActivationFunc.h"


ActivationFunc::ActivationFunc()
{
}


ActivationFunc::~ActivationFunc()
{
}



//template<typename _Tp>
//int softMax_normal(const _Tp *src, const _Tp *dst, int length)
//{
//	const _Tp alpha= *std::max_element(src, src + length);//STL算法，找到最大元素
//	_Tp denominator{ 0 };//定义分母
//
//	for (int i = 0; i<length; ++i)
//	{
//		dst[i] = std::exp(src[i] - alpha);// e(x+c)
//		denominator += {dst[i]};
//	}
//
//	for (int i; i<length; ++i)
//	{
//		dst[i] = dst[i] / denominator;
//	}
//
//	return 0;
//}
//
//
//template<typename _Tp>
//int ActivationFunc::softMax(const _Tp * src, const _Tp * dst, int length)
//{
//	for (int i=0;i<length;++i)
//	{
//	dst[i] =(_Tp)(1. / 1. + exp(src[i] + alpha));
//	}
//	return 0;
//}
//
//
//
//template<typename _Tp>
//int softMax_fast(const _Tp *src, const _Tp *dst, int length)
//{
//	for (int i=0;i<length;++i)
//	{
//		dst[i] = (_Tp)(src[i] / (1. + fabs(src[i])));
//		return 0;
//	}
//}