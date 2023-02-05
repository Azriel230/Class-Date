#include <iostream>
#include "date.h"

bool Date::IsLeapYear() const
{
	if (m_year % 4 == 0)
	{
		if (m_year % 100 == 0)
		{
			if (m_year % 400 == 0)
				return true;
			else
				return false;
		}
		else return true;
	}
	else return false;
}

Date Date::MinDate(Date obj1_, Date obj2_) const
{
	if (obj1_ == obj2_)
		return obj1_;

	if (obj1_.m_year < obj2_.m_year)
		return obj1_;
	else if (m_year > obj2_.m_year)
		return obj2_;
	else
	{
		if (obj1_.m_month < obj2_.m_month)
			return obj1_;
		else if (m_month > obj2_.m_month)
			return obj2_;
		else
		{
			if (obj1_.m_day < obj2_.m_day)
				return obj1_;
			else
				return obj2_;
		}
	}
}

Date Date::MaxDate(Date obj1_, Date obj2_) const
{
	if (obj1_ == obj2_)
		return obj1_;

	if (obj1_.m_year < obj2_.m_year)
		return obj2_;
	else if (obj1_.m_year > obj2_.m_year)
		return obj1_;
	else
	{
		if (obj1_.m_month < obj2_.m_month)
			return obj2_;
		else if (obj1_.m_month > obj2_.m_month)
			return obj1_;
		else
		{
			if (obj1_.m_day < obj2_.m_day)
				return obj2_;
			else
				return obj1_;
		}
	}
}

Date::Date(int day_, int month_, int year_)
{
	if (day_ > 0 || day_ <= 31 && month_ > 0 || month_ <= 12 || year_ >= 1970 || year_ <= 2099) 
	{
		if (month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10 || month_ == 12)
		{
			m_day = day_;
			m_month = month_;
			m_year = year_;
		}
		else if (month_ == 2)
		{
			if (IsLeapYear())
			{
				if (day_ <= 29)
				{
					m_day = day_;
					m_month = month_;
					m_year = year_;
				}
				else
				{
					m_day = 1;
					m_month = 1;
					m_year = 1970;
				}
			}
			else
			{
				if (day_ <= 28)
				{
					m_day = day_;
					m_month = month_;
					m_year = year_;
				}
				else
				{
					m_day = 1;
					m_month = 1;
					m_year = 1970;
				}
			}
		}
		else if (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11)
		{
			if (day_ <= 30) 
			{
				m_day = day_;
				m_month = month_;
				m_year = year_;
			}
			else 
			{
				m_day = 1;
				m_month = 1;
				m_year = 1970;
			}
		}
	}
	else 
	{
		m_day = 1;
		m_month = 1;
		m_year = 1970;
	}
}

Date::Date(const Date& obj_)
{
	m_day = obj_.m_day;
	m_month = obj_.m_month;
	m_year = obj_.m_year;
}

Date& Date::operator=(const Date& obj_)
{
	m_day = obj_.m_day;
	m_month = obj_.m_month;
	m_year = obj_.m_year;

	return *this;
}

bool Date::operator==(const Date& obj_)
{
	return (m_day == obj_.m_day && m_month == obj_.m_month && m_year == obj_.m_year);
}

bool Date::operator!=(const Date& obj_)
{
	return !(m_day == obj_.m_day && m_month == obj_.m_month && m_year == obj_.m_year);
}

int Date::GetDay() const
{
	return m_day;
}

int Date::GetMonth() const
{
	return m_month;
}

int Date::GetYear() const
{
	return m_year;
}

Date Date::operator+ (int days_)
{
	bool leapYearFlag = false;

	Date newDate(*this);

	while (days_ > 0)
	{
		if (newDate.m_month == 1 || newDate.m_month == 3 || newDate.m_month == 5 || newDate.m_month == 7 || newDate.m_month == 8 || newDate.m_month == 10 || newDate.m_month == 12)
		{
			while (newDate.m_day != 32 && days_ > 0)
			{
				days_--;
				newDate.m_day++;
			}
			if (newDate.m_day == 32)
			{
				newDate.m_day = 1;
				newDate.m_month++;
			}
			if (newDate.m_month == 13)
			{
				newDate.m_month = 1;
				newDate.m_year++;
				leapYearFlag = false;
			}
		}
		else if (newDate.m_month == 2)
		{
			leapYearFlag = newDate.IsLeapYear();
			if (leapYearFlag)
			{
				while (newDate.m_day != 30 && days_ > 0)
				{
					days_--;
					newDate.m_day++;
				}
				if (newDate.m_day == 30)
				{
					newDate.m_day = 1;
					newDate.m_month++;
				}
				if (newDate.m_month == 13)
				{
					newDate.m_month = 1;
					newDate.m_year++;
					leapYearFlag = false;
				}
			}
			else
			{
				while (newDate.m_day != 29 && days_ > 0)
				{
					days_--;
					newDate.m_day++;
				}
				if (newDate.m_day == 29)
				{
					newDate.m_day = 1;
					newDate.m_month++;
				}
				if (newDate.m_month == 13)
				{
					newDate.m_month = 1;
					newDate.m_year++;
					leapYearFlag = false;
				}
			}
		}
		else if (newDate.m_month == 4 || newDate.m_month == 6 || newDate.m_month == 9 || newDate.m_month == 11)
		{
			while (newDate.m_day != 31 && days_ > 0)
			{
				days_--;
				newDate.m_day++;
			}
			if (newDate.m_day == 31)
			{
				newDate.m_day = 1;
				newDate.m_month++;
			}
			if (newDate.m_month == 13)
			{
				newDate.m_month = 1;
				newDate.m_year++;
				leapYearFlag = false;
			}
		}
	}

	return newDate;
}

Date Date::operator- (int days_)
{
	bool leapYearFlag = false;

	Date newDate(*this);

	while (days_ > 0)
	{
		while (newDate.m_day > 0 && days_ > 0)
		{
			newDate.m_day--;
			days_--;
		}
		
		if (newDate.m_day == 0)
		{
			newDate.m_month--;

			if (newDate.m_month == 0)
			{
				newDate.m_year--;
				newDate.m_month = 12;
				newDate.m_day = 31;
				leapYearFlag = false;
			}
			else if (newDate.m_month == 1 || newDate.m_month == 3 || newDate.m_month == 5 || newDate.m_month == 7 || newDate.m_month == 8 || newDate.m_month == 10)
			{
				newDate.m_day = 31;
			}
			else if (newDate.m_month == 4 || newDate.m_month == 6 || newDate.m_month == 9 || newDate.m_month == 11)
			{
				newDate.m_day = 30;
			}
			else if (newDate.m_month == 2)
			{
				leapYearFlag = newDate.IsLeapYear();
				if (leapYearFlag)
					newDate.m_day = 29;
				else
					newDate.m_day = 28;
			}
		}
	}

	return newDate;
}

int Date::operator- (Date obj_)
{
	int countDifDays = 0;

	if (*this == obj_)
		return countDifDays;

	Date minDate = MinDate(*this, obj_);
	Date maxDate = MaxDate(*this, obj_);

	while (maxDate != minDate)
	{
		maxDate = maxDate - 1;
		countDifDays++;
	}

	return countDifDays;
}

std::ostream& operator<<(std::ostream& stream, const Date& obj)
{
	stream << obj.m_day << '.' << obj.m_month << '.' << obj.m_year;
	return stream;
}
