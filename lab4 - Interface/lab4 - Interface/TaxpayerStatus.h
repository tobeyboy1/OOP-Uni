#pragma once
#include <string.h>
//#include <exception>
//#include <locale>
#include <iostream>
#include <chrono>
#include <time.h> 
#include <sstream>
//#include <iomanip>
//using namespace std;
#include "TaxServiceInform.h"




#define DEBUG
class Taxpayer : public TaxServiceInformation {
private:

	// получение текущей даты-времени 

	static const unsigned int SPAN_OF_YEARS = 124;

	const int max_year = getCurrentYear();
	const int min_year = max_year - SPAN_OF_YEARS;


	char* INN = NULL; // ругался когда поставил размер ИНН над самим ИНН

	static const unsigned int INN_SIZE = 12;

	int year = -1;
	float income_with_tax = 0;
	float income_without_tax = 0;
	double sum_income = 0;

	const double income_tax_percentage = 0.13; //преобразовывал float в double, пришлось менять на double

	const int getCurrentYear();

	void sumTaxCalculator();

	void sumIncomeCalculator();

protected:

	double sum_tax = 0;

public:
	//Taxpayer(const char* temp_INN, const int& temp_year);

	Taxpayer(const char* temp_INN, const int& temp_year, const float& temp_income_without_tax=0, const float& temp_income_with_tax=0);

	Taxpayer() = delete;

	void AddIncome(const float &temp_income, bool with_tax);

	void AddIncome(const float& temp_income_after_tax);

	virtual void ShowTaxpayer() const override;

	Taxpayer& operator >> (const double& temp_income_after_tax);

	virtual const char const* GetINN() const override;

	virtual int GetYear() const override;

	virtual float GetIncomeWithTax() const override;

	virtual float GetIncomeWithoutTax() const override;

	virtual double GetSumTax() const override;

	virtual double GetSumIncome() const override;

	virtual double GetIncomeTaxPercentage() const override;

	virtual ~Taxpayer() override;
};

double& operator += (double& sum_all_tax, Taxpayer& target_taxpayer); // не уверен что стоило помещать перегрузку оператора вне класса сюда же