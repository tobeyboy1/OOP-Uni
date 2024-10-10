
#define _CRT_SECURE_NO_WARNINGS
#include "TaxpayerStatus.h"


void main() {
	setlocale(LC_ALL, "ru");

	try {
		Taxpayer Oleg("223453330151", 2005);
		Oleg.AddIncome(1000, false);
		Oleg.AddIncome(1000, true);
		Oleg.ShowTaxpayer();

	}
	catch (std::exception catchedException) {
		std::cout << catchedException.what();
	}
}