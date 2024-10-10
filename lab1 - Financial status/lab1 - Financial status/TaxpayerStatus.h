#pragma once
#include <string.h>
//#include <exception>
//#include <locale>
#include <iostream>

//using namespace std;

const unsigned int INN_size = 12;

class Taxpayer {
private:
	char* INN = NULL;
	int year = -1;
	int income_with_tax = 0;
	int income_without_tax = 0;
	int sum_tax = -1;
	int sum_income = -1;

	const double income_tax_percentage = 0.13;

	void SumTaxCalrulator() {
		sum_tax = float(income_with_tax) * income_tax_percentage;
	}

	void SumIncomeCalrulator() {
		sum_income = float(income_with_tax) * (1 - income_tax_percentage) + income_without_tax;
	}


public:
	Taxpayer(const char *temp_INN, int temp_year) {

		if (temp_year < 0 || temp_year >(pow(10,4))) {
			std::cout << temp_year << std::endl;
			throw std::exception("Ошибка: указан неверный год");
		}

		year = temp_year;

		if (strlen(temp_INN) != INN_size) {
			throw std::exception("Ошибка: указан неверный размер ИНН");
			
		}

		for (int i = 0; i < INN_size; i++) {
			if(isalpha(temp_INN[i]))
				throw std::exception("Ошибка: ИНН не должен содержать буквы");

		}
		
		INN = new char[INN_size+1];
		memset(INN, 0, sizeof(char) * (INN_size + 1));
		strcpy(INN, temp_INN);

	}

	void AddIncome(int temp_income, bool with_tax) {
		if (temp_income < 0) {
			throw std::exception("Ошибка: доход не может быть отрицательным");
		}

		else if (with_tax == false)
			income_without_tax = temp_income;

		else {
			income_with_tax = temp_income;
		}
		SumTaxCalrulator();
		SumIncomeCalrulator();
	}

	void ShowTaxpayer() {
		std::cout << "ИНН: " << GetINN() << std::endl;
		std::cout << "Год: " << GetYear() << std::endl;
		std::cout << "Налогооблагаемый доход: " << GetIncome_WithTax() << std::endl;
		std::cout << "Неналогооблагаемый доход: " << GetIncome_WithoutTax() << std::endl;
		std::cout << "Сумма подоходного налога: " << GetSumTax() << std::endl;
		std::cout << "Сумма доходов: " << GetSumIncome() << std::endl;
	}

	const char* GetINN() {
		return INN;
	}

	const int GetYear() {
		return year;
	}

	const int GetIncome_WithTax() {
		return income_with_tax;
	}

	const int GetIncome_WithoutTax() {
		return income_without_tax;
	}

	const int GetSumTax() {
		return sum_tax;
	}

	const int GetSumIncome() {
		return sum_income;
	}
	const float GetIncomeTaxPercentage() {
		return income_tax_percentage;
	}

	~Taxpayer() {
		delete[] INN;
	}
};