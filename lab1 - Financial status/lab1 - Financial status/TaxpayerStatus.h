#pragma once
#include <string.h>
//#include <exception>
//#include <locale>
#include <iostream>
#include <chrono>
#include <time.h> 
#include <sstream>
//using namespace std;


#define DEBUG
class Taxpayer {
private:

	static const unsigned int SPAN_OF_YEARS = 124;

	const int max_year = getCurrentYear();
	const int min_year = max_year - SPAN_OF_YEARS;

	/*enum YearLimits {
		max_year = 2024,
		min_year = 1900
	};*/

	char* INN = NULL; // ругался когда поставил размер ИНН над самим ИНН

	static const unsigned int INN_SIZE = 12;

	int year = -1;
	float income_with_tax = 0;
	float income_without_tax = 0;
	double sum_tax = 0;
	double sum_income = 0;

	const double income_tax_percentage = 0.13; //преобразовывал float в double, пришлось менять на double

	const int getCurrentYear();

	void sumTaxCalculator();

	void sumIncomeCalculator();


public:
	Taxpayer(const char* temp_INN, const int& temp_year);

	void AddIncome(const float &temp_income, bool with_tax);

	void ShowTaxpayer() const;

	const char const* GetINN() const;

	int GetYear() const;

	float GetIncomeWithTax() const;

	float GetIncomeWithoutTax() const;

	double GetSumTax() const;

	double GetSumIncome() const;

	double GetIncomeTaxPercentage() const;

	~Taxpayer();
};