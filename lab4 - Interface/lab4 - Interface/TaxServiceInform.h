#pragma once
class TaxServiceInformation {
public:
	virtual void ShowTaxpayer() const = 0;

	virtual const char const* GetINN() const = 0;

	virtual int GetYear() const = 0;

	virtual float GetIncomeWithTax() const=0;

	virtual float GetIncomeWithoutTax() const=0;

	virtual double GetSumTax() const=0;

	virtual double GetSumIncome() const=0;

	virtual double GetIncomeTaxPercentage() const=0;

	virtual ~TaxServiceInformation() {};

};
