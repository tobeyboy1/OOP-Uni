#include "PropertyTaxDeduction.h"

void PropertyTaxDeduction::sumDeductionCalculator() {

	if (housing_cost > MAX_HOUSING_COST) {
		sum_deduction = MAX_HOUSING_COST * 0.13;
	}

	else if (housing_cost > 0) {
		sum_deduction = housing_cost * 0.13;
	}

	if (sum_deduction > sum_tax) {
		sum_deduction = sum_tax;
	}
	sum_tax -= sum_deduction;
}

PropertyTaxDeduction::PropertyTaxDeduction(const char* temp_INN, const int& temp_year, const float& temp_income_without_tax, const float& temp_income_with_tax) :
	Taxpayer(temp_INN, temp_year, temp_income_without_tax, temp_income_with_tax) {}

void PropertyTaxDeduction::SetHousingCost(double temp_housing_cost) {

	if (temp_housing_cost < 0) {
		throw std::exception("Ошибка: стоимость жилья не может быть отрицательной");
	}

	housing_cost = temp_housing_cost;
	sumDeductionCalculator();

}

void PropertyTaxDeduction::ShowTaxpayer() const {

	Taxpayer::ShowTaxpayer();
	std::cout << "Стоимость жилья: " << GetHousingCost() << std::endl;
	std::cout << "Cумма вычета: " << GetSumDeduction() << std::endl << std::endl;
}

double PropertyTaxDeduction::GetHousingCost() const{
	return housing_cost;
}

double PropertyTaxDeduction::GetSumDeduction() const {
	return sum_deduction;
}

PropertyTaxDeduction::~PropertyTaxDeduction() {};