#pragma once
#include <iostream>
struct RGB
{
	int red;
	int green;
	int blue;

	friend std::ostream& operator<<(std::ostream&, const RGB&);
};
