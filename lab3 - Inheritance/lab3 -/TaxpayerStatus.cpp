#include "TaxpayerStatus.h"



const int Taxpayer::getCurrentYear() {

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


void Taxpayer::sumTaxCalculator() {
	sum_tax = (double)income_with_tax * income_tax_percentage;
}

void Taxpayer::sumIncomeCalculator() {
	sum_income = double(income_with_tax) * (1 - income_tax_percentage) + double(income_without_tax);
}


Taxpayer::Taxpayer(const char* temp_INN, const int& temp_year, const float& temp_income_without_tax, const float& temp_income_with_tax) {

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

	sumTaxCalculator();
	sumIncomeCalculator();

	memset(INN, 0, sizeof(char) * (INN_SIZE + 1));
	strcpy_s(INN, sizeof(char) * (INN_SIZE + 1), temp_INN);

}


 void Taxpayer::AddIncome(const float& temp_income, bool with_tax) { //������-�� ��� ����� ���������� ��� ������ ����� + ����� ��� ������� ��� ���������� ������

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

 void Taxpayer::AddIncome(const float& temp_income_after_tax) {
	 if (temp_income_after_tax < 0) {
		 throw std::exception("������: ����� �� ����� ���� �������������");
	 }
	 income_with_tax += temp_income_after_tax/(1- income_tax_percentage);
	 sumTaxCalculator();
	 sumIncomeCalculator();
 }

 void Taxpayer::ShowTaxpayer() const {
	 std::cout << "���: " << GetINN() << std::endl;
	 std::cout << "���: " << GetYear() << std::endl;
	 std::cout << "���������������� �����: " << GetIncomeWithTax() << std::endl;
	 std::cout << "������������������ �����: " <<  GetIncomeWithoutTax() << std::endl;
	 std::cout << "����� ����������� ������: " << GetSumTax() << std::endl;
	 std::cout << "����� �������: " << GetSumIncome() << std::endl << std::endl;
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

 double& operator += (double& sum_all_tax, Taxpayer& target_taxpayer) { // �� ������ ��� ������ �������� ���������� ��������� ��� ������ ���� ��
	 return (sum_all_tax += target_taxpayer.GetSumTax());
 };

