
#include "TaxpayerStatus.h"
#include "PropertyTaxDeduction.h"
#include <vector>

int main() {

	double sum_all_tax = 0;

	setlocale(LC_ALL, "ru");

	try {
		Taxpayer<13, int>  vova("223111111111", 2008);
		Taxpayer<13, int>  oleg("223453330119", 2005);

		vova.AddIncome(567, true);
		vova.ShowTaxpayer();

		oleg.AddIncome(1000, false); //����� ������ ����� ������ �����, ��� ��������� ������ ������ �� ��������
		oleg.AddIncome(1000, true);
		oleg.AddIncome(87);
		oleg >> 5453 >> 14567;
		oleg.ShowTaxpayer();

		(sum_all_tax += oleg) += vova;
		//sum_all_tax += vova;
		 

		//std::cout << "����� ����� ������� = " << sum_all_tax << std::endl << std::endl;

		PropertyTaxDeduction<13, int> artem("777753330119", 2000, 90000, 100000);
		artem.AddIncome(100000, false);
		artem.SetHousingCost(3500000);
		artem.ShowTaxpayer();

		//TaxServiceInformation* docks[2];
		//docks[0] = &vova;

		std::vector<ITaxServiceInformation<13, int>*> taxpayers_list;
		taxpayers_list.push_back(&vova);

		taxpayers_list.push_back(&oleg);
		
		taxpayers_list.push_back(&artem);


		for (ITaxServiceInformation<13, int>* element : taxpayers_list) {
			std::cout << "����������������: \n" << " ���: " << element->GetINN() << std::endl << " ���: " << element->GetYear() << std::endl;
			std::cout << "������, �� ���������� ��������: " << element->GetSumTax() << std::endl << std::endl;
		}
		//artem = new PropertyTaxDeduction;
	}

	

	catch (std::exception catchedException) {
		std::cout << catchedException.what();
		return -1;
	}
	
	
}