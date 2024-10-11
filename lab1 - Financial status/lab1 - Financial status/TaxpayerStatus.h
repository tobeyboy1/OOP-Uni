#pragma once
#include <string.h>
//#include <exception>
//#include <locale>
#include <iostream>

//using namespace std;



enum YearLimits {
	max_year = 2024,
	min_year = 1900
};

class Taxpayer {
private:

	char* INN = NULL; // ругался когда поставил размер ИНН над самим ИНН

	const unsigned int INN_size = 12;

	int year = -1;
	float income_with_tax = 0;
	float income_without_tax = 0;
	double sum_tax = -1;
	double sum_income = -1;

	const double income_tax_percentage = 0.13; //преобразовывал float в double, пришлось менять на double

	void SumTaxCalrulator() {
		sum_tax = double(income_with_tax) * income_tax_percentage;
	}

	void SumIncomeCalrulator() {
		sum_income = double(income_with_tax) * (1 - income_tax_percentage) + double(income_without_tax);
	}


public:
	Taxpayer(const char *temp_INN, const int& temp_year) {

		if (temp_year < min_year && temp_year >= 0) {
			std::cout << temp_year << std::endl;
			throw std::exception("Ошибка: нельзя указать год меньше 1900-го");
		}

		if (temp_year > max_year) {
			std::cout << temp_year << std::endl;
			throw std::exception("Ошибка: нельзя указать год больше 2024-го");
		}

		if (temp_year < 0) {
			std::cout << temp_year << std::endl;
			throw std::exception("Ошибка: нельзя указать отрицательный год");
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

	void AddIncome(const float &temp_income, bool with_tax) { //почему-то при вводе параметров даёт ввести число + забыл что сказали про именование флагов

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

	void ShowTaxpayer() const{
		std::cout << "ИНН: " << GetINN() << std::endl;
		std::cout << "Год: " << GetYear() << std::endl;
		std::cout << "Налогооблагаемый доход: " << GetIncome_WithTax() << std::endl;
		std::cout << "Неналогооблагаемый доход: " << GetIncome_WithoutTax() << std::endl;
		std::cout << "Сумма подоходного налога: " << GetSumTax() << std::endl;
		std::cout << "Сумма доходов: " << GetSumIncome() << std::endl;
	}

	char* GetINN() const {
		return INN;
	}

	int GetYear() const {
		return year;
	}

	float GetIncome_WithTax() const {
		return income_with_tax;
	}

	float GetIncome_WithoutTax() const {
		return income_without_tax;
	}

	double GetSumTax() const {
		return sum_tax;
	}

	double GetSumIncome() const {
		return sum_income;
	}
	double GetIncomeTaxPercentage() const {
		return income_tax_percentage;
	}

	~Taxpayer() {
		delete[] INN;
	}
};