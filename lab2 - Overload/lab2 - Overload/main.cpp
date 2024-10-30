
//#define _CRT_SECURE_NO_WARNINGS
#include "TaxpayerStatus.h"


int main() {

	double sum_all_tax = 0;

	setlocale(LC_ALL, "ru");

	try {
		Taxpayer vova("223111111111", 2008);
		Taxpayer oleg("223453330119", 2005);

		vova.AddIncome(567, true);
		vova.ShowTaxpayer();

		oleg.AddIncome(1000, false); //можно вместо флага писать число, как исправить внутри класса не придумал
		oleg.AddIncome(1000, true);
		oleg.AddIncomeAfterTax(87);
		oleg >> 871;
		oleg.ShowTaxpayer();

		sum_all_tax += oleg;
		sum_all_tax += vova;

		std::cout << "Общая сумма налогов = " << sum_all_tax << std::endl;
	}
	catch (std::exception catchedException) {
		std::cout << catchedException.what();
		return -1;
	}
	
	
}