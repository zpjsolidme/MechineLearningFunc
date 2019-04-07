//��֪��ģ��
#pragma once


#include <vector>
#include <array>


class Perceptron
{
	
private:
	std::vector<double> w;
	double b;
	unsigned long indim = 0;

	std::vector<std::vector<double>> inData;//���ļ���������
	std::vector<std::vector<double>> trainData;//�ָ���ѵ�����ݣ����������ֵ
	std::vector<std::vector<double>> testData;
	std::vector<std::vector<double>> trainDataF;//������ѵ�����ݣ�����
	std::vector<std::vector<double>> testDataF;
	std::vector<double> trainDataGT;//��ֵ
	std::vector<double> testDataGT;

public:
	void getData(const std::string &filename);//�������ݵ�vector��
	void run();
	void splitDat(const float&);
	void createFeatureGT();
	void setDim(const unsigned long &iDim) { indim = iDim; };
	double inference(std::vector<double> &);
	void initialize(std::vector<double>& init);
	void train(const int &step, const float &lr);
	int predict(const std::vector<double>&inputData);//Ԥ��
	double loss(const std::vector<double> &inputData, const double &groundTruth);
public:
	std::pair<std::vector<double>, double> computeGradient(const std::vector<double>& inputData, const double &groundTruth);
	std::vector<std::vector<double>> getTestDataFeature() { return testDataF; };
	std::vector<double> getTestGT() { return testDataGT; };





};