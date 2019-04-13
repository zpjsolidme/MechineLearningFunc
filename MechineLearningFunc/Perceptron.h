//��֪��ģ��
#pragma once


#include <vector>
#include <array>


class Perceptron
{
	
public:

	std::vector<double> w;
	double b;
	unsigned long indim = 0;

	std::vector<std::vector<double>> inData;//���ļ���ȡ����
	std::vector<std::vector<double>> trainData;//�ָ���ѵ�����ݣ����������ֵ
	std::vector<std::vector<double>> testData;
	std::vector<std::vector<double>> trainDataF;//������ѵ�����ݣ�����
	std::vector<std::vector<double>> testDataF;
	std::vector<double> trainDataGT;//��ֵ
	std::vector<double> testDataGT;

public:
	void run();
	int getData(const std::string &filename);//�������ݵ�vector��
	int splitData(const float &trainTotoalRation);//�ָ�ѵ�����Ͳ��Լ�
	int createFeatureGT();//��ȡ����
	int initialize(std::vector<double>& init);//��ʼ������
	double inference(const std::vector<double> &inputdata);
	double loss(const std::vector<double> &inputData, const double &groundTruth);//������ʧ
	void setDim(const unsigned long &iDim) { indim = iDim; };


	void train(const int &step, const float &lr);
	int predict(const std::vector<double>&inputData);//Ԥ��
	
public:
	std::pair<std::vector<double>, double> computeGradient(const std::vector<double>& inputData, const double &groundTruth);//
	std::vector<std::vector<double>> getTestDataFeature() { return testDataF; };
	std::vector<double> getTestGT() { return testDataGT; };





};