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

	char* INN = NULL; // ������� ����� �������� ������ ��� ��� ����� ���

	const unsigned int INN_size = 12;

	int year = -1;
	float income_with_tax = 0;
	float income_without_tax = 0;
	double sum_tax = -1;
	double sum_income = -1;

	const double income_tax_percentage = 0.13; //�������������� float � double, �������� ������ �� double

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
			throw std::exception("������: ������ ������� ��� ������ 1900-��");
		}

		if (temp_year > max_year) {
			std::cout << temp_year << std::endl;
			throw std::exception("������: ������ ������� ��� ������ 2024-��");
		}

		if (temp_year < 0) {
			std::cout << temp_year << std::endl;
			throw std::exception("������: ������ ������� ������������� ���");
		}

		year = temp_year;

		if (strlen(temp_INN) != INN_size) {
			throw std::exception("������: ������ �������� ������ ���");
			
		}

		for (int i = 0; i < INN_size; i++) {
			if(isalpha(temp_INN[i]))
				throw std::exception("������: ��� �� ������ ��������� �����");

		}
		
		INN = new char[INN_size+1];
		memset(INN, 0, sizeof(char) * (INN_size + 1));
		strcpy(INN, temp_INN);

	}

	void AddIncome(const float &temp_income, bool with_tax) { //������-�� ��� ����� ���������� ��� ������ ����� + ����� ��� ������� ��� ���������� ������

		if (temp_income < 0) {
			throw std::exception("������: ����� �� ����� ���� �������������");
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
		std::cout << "���: " << GetINN() << std::endl;
		std::cout << "���: " << GetYear() << std::endl;
		std::cout << "���������������� �����: " << GetIncome_WithTax() << std::endl;
		std::cout << "������������������ �����: " << GetIncome_WithoutTax() << std::endl;
		std::cout << "����� ����������� ������: " << GetSumTax() << std::endl;
		std::cout << "����� �������: " << GetSumIncome() << std::endl;
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