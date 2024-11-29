#pragma once
#include "TaxpayerStatus.h"

template <int TAX_PERCENTAGE = 13, typename TAX_FORMAT = double>
class PropertyTaxDeduction final : public Taxpayer<TAX_PERCENTAGE, TAX_FORMAT> {

private:

	const int MAX_HOUSING_COST = 2 * pow(10, 6);

	TAX_FORMAT housing_cost = 0;
	TAX_FORMAT sum_deduction = 0;

	void sumDeductionCalculator();

public:
	PropertyTaxDeduction(const char* temp_INN,
		const int& temp_year,
		const TAX_FORMAT& temp_income_without_tax = 0,
		const TAX_FORMAT& temp_income_with_tax = 0);
	//using Taxpayer::Taxpayer; //нашёл решение, без этой строчки конструктор базового класса не работал

	void SetHousingCost(const TAX_FORMAT& temp_housing_cost);

	void ShowTaxpayer() const override;

	TAX_FORMAT GetHousingCost() const;

	TAX_FORMAT GetSumDeduction() const;

	virtual ~PropertyTaxDeduction();
};

