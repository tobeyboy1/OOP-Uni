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





template <int TAX_PERCENTAGE = 13, typename TAX_FORMAT = double>
class Taxpayer : public ITaxServiceInformation<TAX_PERCENTAGE, TAX_FORMAT> {
private:

	// получение текущей даты-времени 

	static const unsigned int SPAN_OF_YEARS = 124;

	const int max_year = getCurrentYear();
	const int min_year = max_year - SPAN_OF_YEARS;


	char* INN = NULL; // ругался когда поставил размер ИНН над самим ИНН

	static const unsigned int INN_SIZE = 12;

	TAX_FORMAT income_tax_percentage = TAX_PERCENTAGE;

	int year = -1;
	TAX_FORMAT income_with_tax = 0;
	TAX_FORMAT income_without_tax = 0;
	TAX_FORMAT sum_income = 0;

	const int getCurrentYear();

	void sumTaxCalculator();

	void sumIncomeCalculator();

protected:

	TAX_FORMAT sum_tax = 0;

public:
	//Taxpayer(const char* temp_INN, const int& temp_year);

	Taxpayer(const char* temp_INN, const int& temp_year, const TAX_FORMAT& temp_income_without_tax=0, const TAX_FORMAT& temp_income_with_tax=0);

	Taxpayer() = delete;

	void AddIncome(const TAX_FORMAT& temp_income, bool with_tax);

	void AddIncome(const TAX_FORMAT& temp_income_after_tax);

	virtual void ShowTaxpayer() const override;

	Taxpayer& operator >> (const TAX_FORMAT& temp_income_after_tax);

	virtual const char const* GetINN() const override;

	virtual int GetYear() const override;

	virtual TAX_FORMAT GetIncomeWithTax() const override;

	virtual TAX_FORMAT GetIncomeWithoutTax() const override;

	virtual TAX_FORMAT GetSumTax() const override;

	virtual TAX_FORMAT GetSumIncome() const override;

	virtual TAX_FORMAT GetIncomeTaxPercentage() const override;

	virtual ~Taxpayer() override;
};


template <int TAX_PERCENTAGE, typename TAX_FORMAT>
double& operator += (double& sum_all_tax, Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>& target_taxpayer) { // не уверен что стоило помещать перегрузку оператора вне класса сюда же
	return (sum_all_tax += target_taxpayer.GetSumTax());
};