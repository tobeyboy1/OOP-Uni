#pragma once


template <int TAX_PERCENTAGE = 13, typename TAX_FORMAT = double>
class ITaxServiceInformation { //приписка I для интерфейса
public:
	virtual void ShowTaxpayer() const = 0;

	virtual const char const* GetINN() const = 0;

	virtual int GetYear() const = 0;

	virtual TAX_FORMAT GetIncomeWithTax() const=0;

	virtual TAX_FORMAT GetIncomeWithoutTax() const=0;

	virtual TAX_FORMAT GetSumTax() const=0;

	virtual	TAX_FORMAT GetSumIncome() const=0;

	virtual TAX_FORMAT GetIncomeTaxPercentage() const=0;

	virtual ~ITaxServiceInformation() {};

};
