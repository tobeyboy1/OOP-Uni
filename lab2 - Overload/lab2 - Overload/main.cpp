//#define _CRT_SECURE_NO_WARNINGS
#include "TaxpayerStatus.h"
int main() {

	double sum_all_tax = 0;

	setlocale(LC_ALL, "ru");

	try {
		Taxpayer vova("223111111111", 20080);
		Taxpayer oleg("223453330119", 2005);

		vova.AddIncome(567, true);
		vova.ShowTaxpayer();

		oleg.AddIncome(1000, false); //����� ������ ����� ������ �����, ��� ��������� ������ ������ �� ��������
		oleg.AddIncome(1000, true);
		oleg.AddIncome(87);
		oleg >> 5453 >> 14567;
		oleg.ShowTaxpayer();

		(sum_all_tax += oleg) += vova;
		//sum_all_tax += vova;

		std::cout << "����� ����� ������� = " << sum_all_tax << std::endl;
	}
	catch (std::exception catchedException) {
		std::cout << catchedException.what();
		return -1;
	}
	
	
}