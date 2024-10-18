#pragma once
#include <string.h>
//#include <exception>
//#include <locale>
#include <iostream>

//using namespace std;


#define DEBUG
class Taxpayer {
private:

	enum YearLimits {
		max_year = 2024,
		min_year = 1900
	};

	char* INN = NULL; // ругался когда поставил размер ИНН над самим ИНН

	const unsigned int INN_SIZE = 12;

	int year = -1;
	float income_with_tax = 0;
	float income_without_tax = 0;
	double sum_tax = -1;
	double sum_income = -1;

	const double income_tax_percentage = 0.13; //преобразовывал float в double, пришлось менять на double

	void SumTaxCalrulator();

	void SumIncomeCalrulator();


public:
	Taxpayer(const char* temp_INN, const int& temp_year);

	void AddIncome(const float &temp_income, bool with_tax);

	void ShowTaxpayer() const;

	const char const* GetINN() const;

	int GetYear() const;

	float GetIncome_WithTax() const;

	float GetIncome_WithoutTax() const;

	double GetSumTax() const;

	double GetSumIncome() const;

	double GetIncomeTaxPercentage() const;

	~Taxpayer();
};