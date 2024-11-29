#include "PropertyTaxDeduction.h"

template
PropertyTaxDeduction<13, int>;

template <int TAX_PERCENTAGE, typename TAX_FORMAT>
void PropertyTaxDeduction<TAX_PERCENTAGE, TAX_FORMAT>::sumDeductionCalculator() {

	if (housing_cost > MAX_HOUSING_COST) {
		sum_deduction = MAX_HOUSING_COST * 0.13;
	}

	else if (housing_cost > 0) {
		sum_deduction = housing_cost * 0.13;
	}

	if (sum_deduction > PropertyTaxDeduction<TAX_PERCENTAGE, TAX_FORMAT>::sum_tax) {
		sum_deduction = PropertyTaxDeduction<TAX_PERCENTAGE, TAX_FORMAT>::sum_tax;
	}
	PropertyTaxDeduction<TAX_PERCENTAGE, TAX_FORMAT>::sum_tax -= sum_deduction;
}

template <int TAX_PERCENTAGE, typename TAX_FORMAT>
PropertyTaxDeduction<TAX_PERCENTAGE, TAX_FORMAT>::PropertyTaxDeduction(const char* temp_INN, const int& temp_year, const TAX_FORMAT& temp_income_without_tax, const TAX_FORMAT& temp_income_with_tax) :
	Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>(temp_INN, temp_year, temp_income_without_tax, temp_income_with_tax) {}

template <int TAX_PERCENTAGE, typename TAX_FORMAT>
void PropertyTaxDeduction<TAX_PERCENTAGE, TAX_FORMAT>::SetHousingCost(const TAX_FORMAT& temp_housing_cost) {

	if (temp_housing_cost < 0) {
		throw std::exception("Ошибка: стоимость жилья не может быть отрицательной");
	}

	housing_cost = temp_housing_cost;
	sumDeductionCalculator();

}

template <int TAX_PERCENTAGE, typename TAX_FORMAT>
void PropertyTaxDeduction<TAX_PERCENTAGE, TAX_FORMAT>::ShowTaxpayer() const {

	Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>::ShowTaxpayer();
	std::cout << "Стоимость жилья: " << GetHousingCost() << std::endl;
	std::cout << "Cумма вычета: " << GetSumDeduction() << std::endl << std::endl;
}

template <int TAX_PERCENTAGE, typename TAX_FORMAT>
TAX_FORMAT PropertyTaxDeduction<TAX_PERCENTAGE, TAX_FORMAT>::GetHousingCost() const{
	return housing_cost;
}

template <int TAX_PERCENTAGE, typename TAX_FORMAT>
TAX_FORMAT PropertyTaxDeduction<TAX_PERCENTAGE, TAX_FORMAT>::GetSumDeduction() const {
	return sum_deduction;
}

template <int TAX_PERCENTAGE, typename TAX_FORMAT>
PropertyTaxDeduction<TAX_PERCENTAGE, TAX_FORMAT>::~PropertyTaxDeduction() {};