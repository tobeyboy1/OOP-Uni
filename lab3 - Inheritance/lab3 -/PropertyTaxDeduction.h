#pragma once
#include "TaxpayerStatus.h"

class PropertyTaxDeduction : public Taxpayer{

private:

	const int MAX_HOUSING_COST = 2 * pow(10, 6);

	double housing_cost = 0;
	double sum_deduction = 0;

	void sumDeductionCalculator();

public:
	PropertyTaxDeduction(const char* temp_INN,
		const int& temp_year,
		const float& temp_income_without_tax = 0,
		const float& temp_income_with_tax = 0);
	//using Taxpayer::Taxpayer; //нашёл решение, без этой строчки конструктор базового класса не работал

	void SetHousingCost(double temp_housing_cost);

	void ShowTaxpayer() const override;

	double GetHousingCost() const;

	double GetSumDeduction() const;

	virtual ~PropertyTaxDeduction();
};

