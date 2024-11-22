//#define _CRT_SECURE_NO_WARNINGS
#include "TaxpayerStatus.h"
#include "PropertyTaxDeduction.h"
#include <vector>

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
		oleg.AddIncome(87);
		oleg >> 5453 >> 14567;
		oleg.ShowTaxpayer();

		(sum_all_tax += oleg) += vova;
		//sum_all_tax += vova;
		 

		//std::cout << "Общая сумма налогов = " << sum_all_tax << std::endl << std::endl;

		PropertyTaxDeduction artem("777753330119", 2000, 90000, 100000);
		artem.AddIncome(100000, false);
		artem.SetHousingCost(3500000);
		artem.ShowTaxpayer();

		//TaxServiceInformation* docks[2];
		//docks[0] = &vova;

		std::vector<TaxServiceInformation*> taxpayers_list;
		taxpayers_list.push_back(&vova);

		taxpayers_list.push_back(&oleg);
		
		taxpayers_list.push_back(&artem);


		for (TaxServiceInformation* element : taxpayers_list) {
			std::cout << "Налогоплательщик: \n" << element->GetINN() << std::endl << element->GetYear() << std::endl;
			std::cout << "Налоги, не подлежащие возврату: " << element->GetSumTax() << std::endl << std::endl;
		}
		//artem = new PropertyTaxDeduction;
	}

	

	catch (std::exception catchedException) {
		std::cout << catchedException.what();
		return -1;
	}
	
	
}