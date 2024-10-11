
#define _CRT_SECURE_NO_WARNINGS
#include "TaxpayerStatus.h"


int main() {
	setlocale(LC_ALL, "ru");

	try {
		Taxpayer oleg("223453330151", 2005);
		oleg.AddIncome(1000, false); //можно вместо флага писать число, как исправить внутри класса не придумал
		oleg.AddIncome(1000, true);
		oleg.ShowTaxpayer();

	}
	catch (std::exception catchedException) {
		std::cout << catchedException.what();
		return -1;
	}
}