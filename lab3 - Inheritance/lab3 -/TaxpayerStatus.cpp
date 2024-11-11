#include "TaxpayerStatus.h"



const int Taxpayer::getCurrentYear() {

	const int BEGIN_OF_COUNT = 1900;

	tm currentDayTime;
	int currentYear;
	//получаем текущее время-дату 
	std::chrono::system_clock::time_point nowDateTime = std::chrono::system_clock::now();

	time_t intermediateDayTime = std::chrono::system_clock::to_time_t(nowDateTime);
	// рассчитываем время по текущему часовому поясу 
	localtime_s(&currentDayTime, &intermediateDayTime);
	currentYear = BEGIN_OF_COUNT + currentDayTime.tm_year;
	return currentYear;
}


void Taxpayer::sumTaxCalculator() {
	sum_tax = (double)income_with_tax * income_tax_percentage;
}

void Taxpayer::sumIncomeCalculator() {
	sum_income = double(income_with_tax) * (1 - income_tax_percentage) + double(income_without_tax);
}


Taxpayer::Taxpayer(const char* temp_INN, const int& temp_year, const float& temp_income_without_tax, const float& temp_income_with_tax) {

	if (temp_year < min_year) {
		throw std::exception("Ошибка: нельзя указать год меньше 1900-го" + 1);
	}

	if (temp_year > max_year) {
		throw std::exception("Ошибка: нельзя указать год больше 2024-го");
	}

	if (temp_year < 0) {
		throw std::exception("Ошибка: нельзя указать отрицательный год");
	}
	if (temp_INN == nullptr) {
		throw std::exception("Ошибка: ИНН не может быть нулевым указателем");

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

	sumTaxCalculator();
	sumIncomeCalculator();

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
	sumTaxCalculator();
	sumIncomeCalculator();
}

 void Taxpayer::AddIncome(const float& temp_income_after_tax) {
	 if (temp_income_after_tax < 0) {
		 throw std::exception("Ошибка: доход не может быть отрицательным");
	 }
	 income_with_tax += temp_income_after_tax/(1- income_tax_percentage);
	 sumTaxCalculator();
	 sumIncomeCalculator();
 }

 void Taxpayer::ShowTaxpayer() const {
	 std::cout << "ИНН: " << GetINN() << std::endl;
	 std::cout << "Год: " << GetYear() << std::endl;
	 std::cout << "Налогооблагаемый доход: " << GetIncomeWithTax() << std::endl;
	 std::cout << "Неналогооблагаемый доход: " <<  GetIncomeWithoutTax() << std::endl;
	 std::cout << "Сумма подоходного налога: " << GetSumTax() << std::endl;
	 std::cout << "Сумма доходов: " << GetSumIncome() << std::endl << std::endl;
 }

 Taxpayer& Taxpayer::operator >> (const double& temp_income_after_tax){
	 this->AddIncome(temp_income_after_tax);
	 return *this;
 }

const char const* Taxpayer::GetINN() const {
	 return INN;
 }
int Taxpayer::GetYear() const {
	return year;
}

 float Taxpayer::GetIncomeWithTax() const {
	 return income_with_tax;
 }

 float Taxpayer:: GetIncomeWithoutTax() const {
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

 double& operator += (double& sum_all_tax, Taxpayer& target_taxpayer) { // не уверен что стоило помещать перегрузку оператора вне класса сюда же
	 return (sum_all_tax += target_taxpayer.GetSumTax());
 };

