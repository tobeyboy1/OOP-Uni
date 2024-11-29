#include "TaxpayerStatus.h"

template
Taxpayer<13, int>;

template <int TAX_PERCENTAGE, typename TAX_FORMAT>
const int Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>::getCurrentYear() {

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

template <int TAX_PERCENTAGE, typename TAX_FORMAT>
void Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>::sumIncomeCalculator() {
	sum_income = TAX_FORMAT(income_with_tax) * (1 - ((double)income_tax_percentage/100)) + TAX_FORMAT(income_without_tax);
}

template <int TAX_PERCENTAGE, typename TAX_FORMAT>
void Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>::sumTaxCalculator() {
	sum_tax = (TAX_FORMAT)income_with_tax * ((double)income_tax_percentage/100);

}

template <int TAX_PERCENTAGE, typename TAX_FORMAT>
Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>::Taxpayer(const char* temp_INN, const int& temp_year, const TAX_FORMAT& temp_income_without_tax, const TAX_FORMAT& temp_income_with_tax) {

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

	sumTaxCalculator(); //пока вручну менять тип, если нужно попробовать сократить использование функции до 1 раза
	sumIncomeCalculator();

	memset(INN, 0, sizeof(char) * (INN_SIZE + 1));
	strcpy_s(INN, sizeof(char) * (INN_SIZE + 1), temp_INN);

}

template <int TAX_PERCENTAGE, typename TAX_FORMAT>
 void Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>::AddIncome(const TAX_FORMAT& temp_income, bool with_tax) { //почему-то при вводе параметров даёт ввести число + забыл что сказали про именование флагов

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
 template <int TAX_PERCENTAGE, typename TAX_FORMAT>
 void Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>::AddIncome(const TAX_FORMAT& temp_income_after_tax) {
	 if (temp_income_after_tax < 0) {
		 throw std::exception("Ошибка: доход не может быть отрицательным");
	 }
	 income_with_tax += temp_income_after_tax/(1- (income_tax_percentage / 100.0));
	 sumTaxCalculator();
	 sumIncomeCalculator();
 }

 template <int TAX_PERCENTAGE, typename TAX_FORMAT>
 void Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>::ShowTaxpayer() const {
	 std::cout << "ИНН: " << GetINN() << std::endl;
	 std::cout << "Год: " << GetYear() << std::endl;
	 std::cout << "Налогооблагаемый доход: " << GetIncomeWithTax() << std::endl;
	 std::cout << "Неналогооблагаемый доход: " <<  GetIncomeWithoutTax() << std::endl;
	 std::cout << "Сумма подоходного налога после вычета: " << GetSumTax() << std::endl;
	 std::cout << "Сумма доходов: " << GetSumIncome() << std::endl << std::endl;
 }

 template <int TAX_PERCENTAGE, typename TAX_FORMAT>
 Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>& Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>::operator >> (const TAX_FORMAT& temp_income_after_tax){
	 this->AddIncome(temp_income_after_tax);
	 return *this;
 }

template <int TAX_PERCENTAGE, typename TAX_FORMAT>
const char const* Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>::GetINN() const {
	 return INN;
 }

template <int TAX_PERCENTAGE, typename TAX_FORMAT>
int Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>::GetYear() const {
	return year;
}

template <int TAX_PERCENTAGE, typename TAX_FORMAT>
TAX_FORMAT Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>::GetIncomeWithTax() const {
	 return income_with_tax;
 }

 template <int TAX_PERCENTAGE, typename TAX_FORMAT>
 TAX_FORMAT Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>:: GetIncomeWithoutTax() const {
	 return income_without_tax;
 }

 template <int TAX_PERCENTAGE, typename TAX_FORMAT>
 TAX_FORMAT Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>::GetSumTax() const {
	 return sum_tax;
 }

 template <int TAX_PERCENTAGE, typename TAX_FORMAT>
 TAX_FORMAT Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>::GetSumIncome() const {
	 return sum_income;
 }

 template <int TAX_PERCENTAGE, typename TAX_FORMAT>
 TAX_FORMAT Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>::GetIncomeTaxPercentage() const {
	 return income_tax_percentage;
 }

 template <int TAX_PERCENTAGE, typename TAX_FORMAT>
 Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>::~Taxpayer() {
	 delete[] INN;
 }



