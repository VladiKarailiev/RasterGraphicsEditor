#pragma once
#include <iostream>
struct RGB
{
	int red;
	int green;
	int blue;

	friend std::ostream& operator<<(std::ostream&, const RGB&);
};
/// tva ne trqq da e int!
/// dr op trqq se razpishe
