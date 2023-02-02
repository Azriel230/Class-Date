#include <iostream>
#include "date.h"

Date::Date(int day_, int month_, int year_)
{
	if (day_ > 0 || day_ <= 31 && month_ > 0 || month_ <= 12 || year_ >= 1970 || year_ <= 2099) //���� ��������� � ������������ ���������� ���������
	{
		if (month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10 || month_ == 12)
		{
			m_day = day_;
			m_month = month_;
			m_year = year_;
		}
		else if (month_ == 2)
		{
			if (year_ % 4 == 0) //���������, ��� ��� ����������: ������� �� �� 4
			{
				if (year_ % 100 == 0) //���� ��, �� �������� ��?
				{
					if (year_ % 400 == 0) //���� ��, �� ������� �� �� 400 � ��������� ���-�� ����
					{
						if (day_ <= 29) //����������!
						{
							m_day = day_;
							m_month = month_;
							m_year = year_;
						}
						else //������ � ����: ������������ �-�� ����
						{
							m_day = 1;
							m_month = 1;
							m_year = 1970;
						}
					}
					else //��� �������� ���������, �� �� �� ��������� �� 400 -> ��� �������
					{
						if (day_ <= 28) //�������� ���-�� ����
						{
							m_day = day_;
							m_month = month_;
							m_year = year_;
						}
						else //������ � ����: ������������ �-�� ����
						{
							m_day = 1;
							m_month = 1;
							m_year = 1970;
						}
					}
				}
				else //��� �� ��������, ������ ����������. �������� �-�� ����
				{
					if (day_ <= 29) //����������!
					{
						m_day = day_;
						m_month = month_;
						m_year = year_;
					}
					else //������ � ����: ������������ �-�� ����
					{
						m_day = 1;
						m_month = 1;
						m_year = 1970;
					}
				}
			}
			else //��� �������
			{
				if (day_ <= 28) //�������� ���-�� ����
				{
					m_day = day_;
					m_month = month_;
					m_year = year_;
				}
				else //������ � ����: ������������ �-�� ����
				{
					m_day = 1;
					m_month = 1;
					m_year = 1970;
				}
			}
		}
		else if (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11)
		{
			if (day_ <= 30) //�������� �-�� ����
			{
				m_day = day_;
				m_month = month_;
				m_year = year_;
			}
			else //������ � ����, ������������ �-�� ����
			{
				m_day = 1;
				m_month = 1;
				m_year = 1970;
			}
		}
	}
	else // �����-�� ������ � ����
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

