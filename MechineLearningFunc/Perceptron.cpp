
#include "stdafx.h"
#include "Perceptron.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>


void Perceptron::run()
{
	getData("F:\\MechineLearning\\datas\\Perceptron\\perceptrondata.csv");
	splitData(0.6);
	createFeatureGT();
	train(200, 1.0);
	std::vector <std::vector<double>> testData = getTestDataFeature();
	std::vector<double> testGT = getTestGT();

	for (int i=0;i<testData.size();++i)
	{
		std::cout << i << std::endl;
		std::cout << "The right class is " << testGT[i] << std::endl;
		int out = predict(testData[i]);
		std::cout << "The predict class is " << out << std::endl;
	}
}

int Perceptron::getData(const std::string &filename)
{
	std::string line;
	std::vector<double> tmpData;
	std::ifstream fin(filename);

	while (getline(fin, line))
	{
		std::istringstream sin(line);
		std::string data;

		while (getline(sin, data, ','))
		{
			tmpData.push_back(atof(data.c_str()));
		}

		indim = tmpData.size();
		indim -= 1;
		inData.push_back(tmpData);
		tmpData.clear();

	}
	return 0;

	//	while (!sin.eof())
	//	{	
	//		getline(sin, data, ',');
	//		if (line.empty())
	//		{
	//			continue;
	//		}
	//		stringstream stringin(line);
	//		while (stringin>> datas)
	//		{		
	//			tmpData.push_back(datas);
	//			//tmpData.push_back(atof(data.c_str()));
	//		}
	//		indim = tmpData.size();
	//		indim -= 1;
	//		inData.push_back(tmpData);
	//	}
	//}
}
int Perceptron::splitData(const float &trainTotoalRation)
{

	random_shuffle(inData.begin(), inData.end());//随机
	
	unsigned long size = inData.size();
	unsigned long trainSize = inData.size()*trainTotoalRation;

	std::cout << "totoal data is" << size << " ,train data has" << trainSize << std::endl;


	for (int i=0;i<size;i++)
	{
		if (i<trainSize)
		{
			trainData.push_back(inData[i]);
		}
		else
		{
			testData.push_back(inData[i]);			
		}
	}

	

	

	return 0;
}

int Perceptron::createFeatureGT()
{
	//const auto& 只读取元素，不拷贝
	for (const auto& data:trainData)
	{
		std::vector<double> trainf;
		trainf.assign(data.begin(), data.end());
		trainDataF.push_back(trainf);
		trainDataGT.push_back(*(data.end() - 1));
	}

	for (const auto& data : testData)
	{
		std::vector<double>testf;
		testf.assign(data.begin(), data.end());
		testDataF.push_back(testf);
		testDataGT.push_back(*(data.end() - 1));
	}
	
	return 0;
}

int Perceptron::initialize(std::vector<double> &init)
{
	if (init.size()!=indim+1)
	{
		std::cout << "input dimension is should be " + std::to_string(indim + 1) << std::endl;
		throw init.size();
	}

	w.assign(init.begin(), init.end());
	b = *(w.end() - 1);
	return 0;
}

double Perceptron::inference(const std::vector<double> &inputdata)
{

	//计算损失和预测结果  wx+b
	if (inputdata.size()!=indim)
	{
		std::cout << "输入数据维度不正确" << std::endl;
		throw inputdata.size();
	}

	double sum_tem = 0.0;
	for (int i=0;i<inputdata.size();i++)
	{
		double tem=0.0;
		tem = inputdata[i] * w[i];
		tem += b;
		sum_tem += tem;
	}

	
	return sum_tem;
}

double Perceptron::loss(const std::vector<double>& inputData, const double & groundTruth)
{
	double infer = inference(inputData);
	double loss = -1 * groundTruth*infer;

	std::cout << "loss is " << loss << std::endl;
	return loss;

}

std::pair<std::vector<double>, double> Perceptron::computeGradient(const std::vector<double>& inputData, const double & groundTruth)
{
	double lossVal = loss(inputData, groundTruth);
	std::vector<double>wi;
	double bi;
	if (lossVal>=0.0)
	{
		for (auto indata:inputData)
		{
			wi.push_back(indata*groundTruth);
		}
		bi = groundTruth;
	}
	else
	{
		for (auto indata:inputData)
		{
			wi.push_back(0.0);
		}
		bi = 0.0;
	}
	return std::pair<std::vector<double>, double>(wi,bi);
}

void Perceptron::train(const int & step, const float & lr)
{
	std::vector<double>init = { 1.0,1.0,1.0 };
	initialize(init);
	int count = 0;

	clock_t start, finish;
	double totaltime;
	start = clock();

	for (int i=0;i<step;i++)
	{
		if (count==trainDataF.size()-1)
		{
			count = 0;
		}
		std::vector<double> inputData = trainDataF[count];
		double groupTruth = trainDataGT[count];
		auto grad = computeGradient(inputData, groupTruth);

		auto grad_w = grad.first;
		auto grad_b = grad.second;

		for (int j=0;j<indim;j++)
		{
			w[j] += lr * (grad_w[j]);
		}
		b += lr * (grad_b);
		count++;
	}

	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	std::cout << "\n此程序的运行时间为" << totaltime << "秒！" << std::endl;

}

int Perceptron::predict(const std::vector<double>& inputData)
{
	double out = inference(inputData);

	if (out>=0.0)
	{
		return 1;
	}
	else
	{
		return -1;
	}

}
