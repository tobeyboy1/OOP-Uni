#pragma once
#include <string.h>
#include <exception>
#include <locale>
//#include <iostream>


const unsigned int INN_size = 12;

class Taxpayer {
private:
	char* INN;
	unsigned int year = -1;
	unsigned int income_with_tax = -1;
	unsigned int income_without_tax = -1;
	unsigned int sum_tax = -1;
	unsigned int sum_income = -1;
	const float income_tax_percentage = 0.13;

public:
	Taxpayer(char* temp_INN, int& temp_year) {

		if (temp_year < 0 || temp_year >(10 ^ 4)) {
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
		
		INN = new char[INN_size];
		INN = temp_INN;

	}


	~Taxpayer() {
		delete[] INN;
	}
};