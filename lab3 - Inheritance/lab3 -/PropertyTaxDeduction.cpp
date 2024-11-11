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
		throw std::exception("������: ��������� ����� �� ����� ���� �������������");
	}

	housing_cost = temp_housing_cost;
	sumDeductionCalculator();

}

void PropertyTaxDeduction::ShowTaxpayer() const {
	std::cout << "���: " << GetINN() << std::endl;
	std::cout << "���: " << GetYear() << std::endl;
	std::cout << "���������������� �����: " << GetIncomeWithTax() << std::endl;
	std::cout << "������������������ �����: " << GetIncomeWithoutTax() << std::endl;
	std::cout << "����� ����������� ������: " << GetSumTax() << std::endl;
	std::cout << "����� �������: " << GetSumIncome() << std::endl;
	std::cout << "��������� �����: " << GetHousingCost() << std::endl;
	std::cout << "C���� ������: " << GetSumDeduction() << std::endl << std::endl;
}

double PropertyTaxDeduction::GetHousingCost() const{
	return housing_cost;
}

double PropertyTaxDeduction::GetSumDeduction() const {
	return sum_deduction;
}

PropertyTaxDeduction::~PropertyTaxDeduction() {};