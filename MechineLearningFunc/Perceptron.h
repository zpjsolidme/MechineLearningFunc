//感知机模型
#pragma once


#include <vector>
#include <array>


class Perceptron
{
	
private:
	std::vector<double> w;
	double b;
	unsigned long indim = 0;

	std::vector<std::vector<double>> inData;//从文件都的数据
	std::vector<std::vector<double>> trainData;//分割后的训练数据，里面包含真值
	std::vector<std::vector<double>> testData;
	std::vector<std::vector<double>> trainDataF;//真正的训练数据，特征
	std::vector<std::vector<double>> testDataF;
	std::vector<double> trainDataGT;//真值
	std::vector<double> testDataGT;

public:
	void getData(const std::string &filename);//加载数据到vector中
	void run();
	void splitDat(const float&);
	void createFeatureGT();
	void setDim(const unsigned long &iDim) { indim = iDim; };
	double inference(std::vector<double> &);
	void initialize(std::vector<double>& init);
	void train(const int &step, const float &lr);
	int predict(const std::vector<double>&inputData);//预测
	double loss(const std::vector<double> &inputData, const double &groundTruth);
public:
	std::pair<std::vector<double>, double> computeGradient(const std::vector<double>& inputData, const double &groundTruth);
	std::vector<std::vector<double>> getTestDataFeature() { return testDataF; };
	std::vector<double> getTestGT() { return testDataGT; };





};