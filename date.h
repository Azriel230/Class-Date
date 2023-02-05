#include <iostream>

class Date
{
	int m_day;
	int m_month;
	int m_year;

public:

	bool IsLeapYear() const;
	Date MinDate(Date obj1_, Date obj2_) const;
	Date MaxDate(Date obj1_, Date obj2_) const;


	Date(int day_, int month_, int year_);
	Date(const Date& obj_);

	~Date() {}

	Date& operator=(const Date& obj_);
	bool operator==(const Date& obj_);
	bool operator!=(const Date& obj_);

	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;

	Date operator+ (int days_);
	Date operator- (int days_);

	int operator- (Date obj_);

	friend std::ostream& operator<<(std::ostream& stream, const Date& obj);
};
