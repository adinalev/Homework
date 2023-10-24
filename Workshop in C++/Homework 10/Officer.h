#pragma once
#include "Soldier.h"

class Officer : public Soldier
{
private:
	int socioMetric;
public:
	int getSocioMetric();
	void setSocio(int sm);

	// methods overriden from parent class
	bool medal() override;
	void print() override;
	string soldierType() override;
};

