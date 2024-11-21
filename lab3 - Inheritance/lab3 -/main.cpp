//#define _CRT_SECURE_NO_WARNINGS
#include "TaxpayerStatus.h"
#include "PropertyTaxDeduction.h"

int main() {

	double sum_all_tax = 0;

	setlocale(LC_ALL, "ru");

	try {
		Taxpayer vova("223111111111", 2008);
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
		 

		std::cout << "����� ����� ������� = " << sum_all_tax << std::endl << std::endl;

		PropertyTaxDeduction artem("777753330119", 2000, 90000, 100000);
		artem.AddIncome(100000, false);
		artem.SetHousingCost(3500000);
		artem.ShowTaxpayer();


		//artem = new PropertyTaxDeduction;
	}

	

	catch (std::exception catchedException) {
		std::cout << catchedException.what();
		return -1;
	}
	
	
}