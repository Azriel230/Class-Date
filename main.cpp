#include <iostream>
#include "date.h"

int main()
{
	Date date(1, 1, 2020);

	//for(int i = 100; i <= 1000; i+=100)
	//{
	//	Date newDate = date - i;
	//	std::cout << newDate << std::endl;
	//}

	Date d1(01, 01, 2020);
	Date d2(2, 6, 2023);

	std::cout << d1 - d2;
	
	return 0;
}
