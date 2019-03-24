#pragma once

#include <math.h>
#include <string>
#include <iostream>	
#include <vector>

#include <opencv2/opencv.hpp>

using namespace cv;


class ActivationFunc
{
public:
	ActivationFunc();
	~ActivationFunc();





public:

	template<typename _Tp>
	int softMax_normal( _Tp *src,  _Tp *dst,int length);
	template<typename _Tp>
	int softMax(const _Tp *src, const _Tp *dst, int length);
	template<typename _Tp>
	int softMax_fast(const _Tp *src, const _Tp *dst, int length);

};

template<typename _Tp>
inline int ActivationFunc::softMax_normal( _Tp * src,  _Tp * dst, int length)
{
	const _Tp alpha= *std::max_element(src, src + length);//STL�㷨���ҵ����Ԫ��
	_Tp denominator{ 0 };//�����ĸ
	
	for (int i = 0; i<length; ++i)
	{
		dst[i] = std::exp(src[i] - alpha);// e(x+c)
		denominator += dst[i];
	}
	
	for (int i=0; i<length; ++i)
	{
		dst[i] = dst[i] / denominator;
	}
	
	return 0;
}
