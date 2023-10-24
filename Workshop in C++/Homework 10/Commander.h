#pragma once
#include "PrivateSoldier.h"

class Commander : public PrivateSoldier
{
protected:
	bool isCombat; // indicates whether the commander is combat or not
public:
	// methods overriden from parent class
	bool medal() override;
	void print() override;
	string soldierType() override;

	//Commander();

	// copy and move
	//Commander(Commander&& comm);
	//Commander(const Commander& other);

	//setter and getter for isCombat
	void setIsCombat(bool is);
	bool getIsCombat();
};

