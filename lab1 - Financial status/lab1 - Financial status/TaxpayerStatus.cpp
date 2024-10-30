#include "TaxpayerStatus.h"


void Taxpayer::SumTaxCalrulator() {
	sum_tax = (double)income_with_tax * income_tax_percentage;
}

void Taxpayer::SumIncomeCalrulator() {
	sum_income = double(income_with_tax) * (1 - income_tax_percentage) + double(income_without_tax);
}

/*Taxpayer::Taxpayer(const char* temp_INN, const int& temp_year) {

	if (temp_year < min_year) {
		throw std::exception("Ошибка: нельзя указать год меньше 1900-го");
	}

	if (temp_year > max_year) {
		throw std::exception("Ошибка: нельзя указать год больше 2024-го");
	}

	if (temp_year < 0) {
		throw std::exception("Ошибка: нельзя указать отрицательный год");
	}
	if (strlen(temp_INN) != INN_SIZE) {
		throw std::exception("Ошибка: указан неверный размер ИНН (размер должен составлять 12 символов)");

	}
	for (int i = 0; i < INN_SIZE; i++) {
		if (!isdigit(temp_INN[i]))
			throw std::exception("Ошибка: некорректные символы при вводе ИНН");

	}

	year = temp_year;

	INN = new char[INN_SIZE + 1];

	memset(INN, 0, sizeof(char) * (INN_SIZE + 1));
	strcpy_s(INN, sizeof(char) * (INN_SIZE + 1), temp_INN);

}*/

// из того что придумал: либо перегрузка, либо аргументы по умолчанию и оставить 1 конструктор;
//выберу второй, так как более практичный 

Taxpayer::Taxpayer(const char* temp_INN, const int& temp_year, const float& temp_income_without_tax, const float& temp_income_with_tax) {

	if (temp_year < min_year) {
		throw std::exception("Ошибка: нельзя указать год меньше 1900-го");
	}

	if (temp_year > max_year) {
		throw std::exception("Ошибка: нельзя указать год больше 2024-го");
	}

	if (temp_year < 0) {
		throw std::exception("Ошибка: нельзя указать отрицательный год");
	}
	if (strlen(temp_INN) != INN_SIZE) {
		throw std::exception("Ошибка: указан неверный размер ИНН (размер должен составлять 12 символов)");

	}
	if (temp_income_without_tax < 0 || temp_income_with_tax < 0) {
		throw std::exception("Ошибка: доход не может быть отрицательным");
	}

	for (int i = 0; i < INN_SIZE; i++) {
		if (!isdigit(temp_INN[i]))
			throw std::exception("Ошибка: некорректные символы при вводе ИНН");

	}

	year = temp_year;

	INN = new char[INN_SIZE + 1];

	income_without_tax += temp_income_without_tax;
	income_with_tax += temp_income_with_tax;

	SumTaxCalrulator();
	SumIncomeCalrulator();

	memset(INN, 0, sizeof(char) * (INN_SIZE + 1));
	strcpy_s(INN, sizeof(char) * (INN_SIZE + 1), temp_INN);

}


 void Taxpayer::AddIncome(const float& temp_income, bool with_tax) { //почему-то при вводе параметров даёт ввести число + забыл что сказали про именование флагов

	if (temp_income < 0) {
		throw std::exception("Ошибка: доход не может быть отрицательным");
	}
	else if (!with_tax) {
		income_without_tax += temp_income;
	}
	else {
		income_with_tax += temp_income;
	}
	SumTaxCalrulator();
	SumIncomeCalrulator();
}

 void Taxpayer::AddIncomeAfterTax(const float& temp_income_after_tax) {
	 if (temp_income_after_tax < 0) {
		 throw std::exception("Ошибка: доход не может быть отрицательным");
	 }
	 income_with_tax += temp_income_after_tax/(1 - income_tax_percentage);
	 SumTaxCalrulator();
	 SumIncomeCalrulator();
 }

 void Taxpayer::ShowTaxpayer() const {
	 std::cout << "ИНН: " << GetINN() << std::endl;
	 std::cout << "Год: " << GetYear() << std::endl;
	 std::cout << "Налогооблагаемый доход: " << GetIncome_WithTax() << std::endl;
	 std::cout << "Неналогооблагаемый доход: " << GetIncome_WithoutTax() << std::endl;
	 std::cout << "Сумма подоходного налога: " << GetSumTax() << std::endl;
	 std::cout << "Сумма доходов: " << GetSumIncome() << std::endl << std::endl;
 }

 void Taxpayer::operator >> (const double& temp_income_after_tax){
	 this->AddIncomeAfterTax(temp_income_after_tax);
	 //return *this;
 }

const char const* Taxpayer::GetINN() const {
	 return INN;
 }
int Taxpayer::GetYear() const {
	return year;
}

 float Taxpayer::GetIncome_WithTax() const {
	 return income_with_tax;
 }

 float Taxpayer::GetIncome_WithoutTax() const {
	 return income_without_tax;
 }

 double Taxpayer::GetSumTax() const {
	 return sum_tax;
 }

 double Taxpayer::GetSumIncome() const {
	 return sum_income;
 }
 double Taxpayer::GetIncomeTaxPercentage() const {
	 return income_tax_percentage;
 }

 Taxpayer::~Taxpayer() {
	 delete[] INN;
 }

 int operator += (double& sum_all_tax, Taxpayer& target_taxpayer) { // не уверен что стоило помещать перегрузку оператора вне класса сюда же
	 return (sum_all_tax += target_taxpayer.GetSumTax());
 };

