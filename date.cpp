#include <iostream>
#include "date.h"

Date::Date(int day_, int month_, int year_)
{
	if (day_ > 0 || day_ <= 31 && month_ > 0 || month_ <= 12 || year_ >= 1970 || year_ <= 2099) //дата находится в потенциально корректных значениях
	{
		if (month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10 || month_ == 12)
		{
			m_day = day_;
			m_month = month_;
			m_year = year_;
		}
		else if (month_ == 2)
		{
			if (year_ % 4 == 0) //проверяем, что год високосный: делится ли на 4
			{
				if (year_ % 100 == 0) //если да, то столетие ли?
				{
					if (year_ % 400 == 0) //если да, то делится ли на 400 и проверяем кол-во дней
					{
						if (day_ <= 29) //високосный!
						{
							m_day = day_;
							m_month = month_;
							m_year = year_;
						}
						else //ошибка в дате: неправильное к-во дней
						{
							m_day = 1;
							m_month = 1;
							m_year = 1970;
						}
					}
					else //год является столетием, но он не поделился на 400 -> год обычный
					{
						if (day_ <= 28) //проверим кол-во дней
						{
							m_day = day_;
							m_month = month_;
							m_year = year_;
						}
						else //ошибка в дате: неправильное к-во дней
						{
							m_day = 1;
							m_month = 1;
							m_year = 1970;
						}
					}
				}
				else //год не столетие, значит високосный. Проверим к-во дней
				{
					if (day_ <= 29) //високосный!
					{
						m_day = day_;
						m_month = month_;
						m_year = year_;
					}
					else //ошибка в дате: неправильное к-во дней
					{
						m_day = 1;
						m_month = 1;
						m_year = 1970;
					}
				}
			}
			else //год обычный
			{
				if (day_ <= 28) //проверим кол-во дней
				{
					m_day = day_;
					m_month = month_;
					m_year = year_;
				}
				else //ошибка в дате: неправильное к-во дней
				{
					m_day = 1;
					m_month = 1;
					m_year = 1970;
				}
			}
		}
		else if (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11)
		{
			if (day_ <= 30) //проверим к-во дней
			{
				m_day = day_;
				m_month = month_;
				m_year = year_;
			}
			else //ошибка в дате, неправильное к-во дней
			{
				m_day = 1;
				m_month = 1;
				m_year = 1970;
			}
		}
	}
	else // какая-то ошибка в дате
	{
		m_day = 1;
		m_month = 1;
		m_year = 1970;
	}
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

