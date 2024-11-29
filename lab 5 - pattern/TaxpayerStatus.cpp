#include "TaxpayerStatus.h"

template
Taxpayer<13, int>;

template <int TAX_PERCENTAGE, typename TAX_FORMAT>
const int Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>::getCurrentYear() {

	const int BEGIN_OF_COUNT = 1900;

	tm currentDayTime;
	int currentYear;
	//�������� ������� �����-���� 
	std::chrono::system_clock::time_point nowDateTime = std::chrono::system_clock::now();

	time_t intermediateDayTime = std::chrono::system_clock::to_time_t(nowDateTime);
	// ������������ ����� �� �������� �������� ����� 
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
		throw std::exception("������: ������ ������� ��� ������ 1900-��" + 1);
	}

	if (temp_year > max_year) {
		throw std::exception("������: ������ ������� ��� ������ 2024-��");
	}

	if (temp_year < 0) {
		throw std::exception("������: ������ ������� ������������� ���");
	}
	if (temp_INN == nullptr) {
		throw std::exception("������: ��� �� ����� ���� ������� ����������");

	}
	if (strlen(temp_INN) != INN_SIZE) {
		throw std::exception("������: ������ �������� ������ ��� (������ ������ ���������� 12 ��������)");

	}
	if (temp_income_without_tax < 0 || temp_income_with_tax < 0) {
		throw std::exception("������: ����� �� ����� ���� �������������");
	}

	for (int i = 0; i < INN_SIZE; i++) {
		if (!isdigit(temp_INN[i]))
			throw std::exception("������: ������������ ������� ��� ����� ���");

	}

	year = temp_year;

	INN = new char[INN_SIZE + 1];

	income_without_tax += temp_income_without_tax;
	income_with_tax += temp_income_with_tax;

	sumTaxCalculator(); //���� ������ ������ ���, ���� ����� ����������� ��������� ������������� ������� �� 1 ����
	sumIncomeCalculator();

	memset(INN, 0, sizeof(char) * (INN_SIZE + 1));
	strcpy_s(INN, sizeof(char) * (INN_SIZE + 1), temp_INN);

}

template <int TAX_PERCENTAGE, typename TAX_FORMAT>
 void Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>::AddIncome(const TAX_FORMAT& temp_income, bool with_tax) { //������-�� ��� ����� ���������� ��� ������ ����� + ����� ��� ������� ��� ���������� ������

	if (temp_income < 0) {
		throw std::exception("������: ����� �� ����� ���� �������������");
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
		 throw std::exception("������: ����� �� ����� ���� �������������");
	 }
	 income_with_tax += temp_income_after_tax/(1- (income_tax_percentage / 100.0));
	 sumTaxCalculator();
	 sumIncomeCalculator();
 }

 template <int TAX_PERCENTAGE, typename TAX_FORMAT>
 void Taxpayer<TAX_PERCENTAGE, TAX_FORMAT>::ShowTaxpayer() const {
	 std::cout << "���: " << GetINN() << std::endl;
	 std::cout << "���: " << GetYear() << std::endl;
	 std::cout << "���������������� �����: " << GetIncomeWithTax() << std::endl;
	 std::cout << "������������������ �����: " <<  GetIncomeWithoutTax() << std::endl;
	 std::cout << "����� ����������� ������ ����� ������: " << GetSumTax() << std::endl;
	 std::cout << "����� �������: " << GetSumIncome() << std::endl << std::endl;
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



