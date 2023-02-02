#include <iostream>

class Date
{
	int m_day;
	int m_month;
	int m_year;

public:

	Date(int day_, int month_, int year_);

	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
};