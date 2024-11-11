#include "PropertyTaxDeduction.h"

void PropertyTaxDeduction::sumDeductionCalculator() {

	if (housing_cost > max_housing_cost) {
		sum_deduction = max_housing_cost * 0.13;
	}

	else if (housing_cost > 0) {
		sum_deduction = housing_cost * 0.13;
	}
}

void PropertyTaxDeduction::SetHousingCost(double temp_housing_cost) {

	if (temp_housing_cost < 0) {
		throw std::exception("Ошибка: стоимость жилья не может быть отрицательной");
	}

	housing_cost = temp_housing_cost;
	sumDeductionCalculator();

}

void PropertyTaxDeduction::ShowTaxpayer() const {
	std::cout << "ИНН: " << GetINN() << std::endl;
	std::cout << "Год: " << GetYear() << std::endl;
	std::cout << "Налогооблагаемый доход: " << GetIncomeWithTax() << std::endl;
	std::cout << "Неналогооблагаемый доход: " << GetIncomeWithoutTax() << std::endl;
	std::cout << "Сумма подоходного налога: " << GetSumTax() << std::endl;
	std::cout << "Сумма доходов: " << GetSumIncome() << std::endl;
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