// MechineLearningFunc.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ActivationFunc.h"

int main()
{


	std::vector<double> src{ 1.23f,4.14f,-3.23f,-1.23f, 5.21f, 0.234f, -0.78f, 6.23f };
	int length = src.size();
	std::vector<double> dst1(length), dst2(length);

	fprintf(stderr, "source vector:\n");

	for (int i=0;i<length;i++)
	{
		std::cout << src[i]<<" ";
		if (i==length-1)
		{
			std::cout<<std::endl;
		}
	}

	ActivationFunc af;

	af.softMax_normal(src.data(), dst1.data(), length);

	std::cout << "softmax:" << std::endl;
	for (int i = 0; i<length; i++)
	{

		std::cout << dst1[i] << " ";
		if (i == length-1)
		{
			std::cout << std::endl;
		}
	}


	//af.softMax_normal(src.data(),dst2.data(), length);
	//for (int i = 0; i<length; i++)
	//{
	//	std::cout << dst2[i] << " ";
	//	if (i == length)
	//	{
	//		std::cout << std::endl;
	//	}
	//}


	system("pause");

    return 0;
}

