#pragma once
#include "TaxpayerStatus.h"

class PropertyTaxDeduction : public Taxpayer{

private:

	const int max_housing_cost = 2 * pow(10, 6);

	double housing_cost = 0;
	double sum_deduction = 0;

	void sumDeductionCalculator();

public:

	using Taxpayer::Taxpayer; //нашёл решение, без этой строчки конструктор базового класса не работал

	void SetHousingCost(double temp_housing_cost);

	void ShowTaxpayer() const override;

	double GetHousingCost() const;

	double GetSumDeduction() const;

	virtual ~PropertyTaxDeduction();
};

