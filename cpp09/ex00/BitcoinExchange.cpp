#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange (const BitcoinExchange &other)
{
	(void)other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;
	return (*this);
}

	template <typename T>
T BitcoinExchange::abs(T a)
{
	return ((a >= 0) ? a : -a);
}

float str_to_double(std::string str)
{
	char			*end;

	return (std::strtod (str.c_str(), &end));
}

bool not_equal(std::tm before, std::tm *after)
{
	if (before.tm_year != after->tm_year)
		return (1);
	if (before.tm_mon != after->tm_mon)
		return (1);
	if (before.tm_mday != after->tm_mday)
		return (1);
	return (0);
}

bool valid_date(std::string key, size_t &key_s)
{
	std::string		day;
	std::string		month;
	std::string		year;
	std::tm			m;
	std::tm			*m_after;
	int				in;
	time_t			res;

	in = key.find ("-");
	if (in == -1)
		return (0);
	key_s = 0;
	year = key.substr(0, in);
	month = key.substr(in + 1, key.size());
	in = month.find ("-");
	if (in != -1)
	{
		day = month.substr(in + 1);
		month = month.substr(0, in);
		in = day.find("-");
		if (in != -1)
			return (std::cout << "Error: bad input => " << key << std::endl, 0);
	}
	if ((day.size() == 0) || (month.size() == 0) || (year.size() == 0))
		return (std::cout << "Error: bad input => " << key << std::endl, 0);
	m.tm_year = str_to_double(year) - 1900;
	m.tm_mon = str_to_double(month);
	m.tm_mday = str_to_double(day);
	m.tm_hour = 0;
	m.tm_min = 0;
	m.tm_sec = 0;
	res = std::mktime (&m);
	m_after = std::localtime (&res);
	if (not_equal (m, m_after))
		return (std::cout << "Error: bad input => " << key << std::endl, 0);
	key_s =  str_to_double(month + day) + (m.tm_year * 1e4);
	return (1);
}

bool valid_num(double value)
{
	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (0);
	}
	else if (value > 1e3)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (0);
	}
	return (1);
}

void BitcoinExchange::data_parse (std::string file_name, std::map<size_t, float> &map)
{
	std::ifstream	file;
	std::string		line;
	std::string		key;
	size_t			key_s;
	std::string		value_str;
	float			value;
	int				find;


	file.open (file_name);
	if (!file)
	{
		std::cerr << "Error: could not open data file\n";
		exit(1);
	}
	getline (file, line);
	find = line.find(",");
	if (find == -1)
	{
		std::cerr << "Error while reading from data file\n";
		exit (1);
	}
	key = line.substr(0, find);
	if (!(key == "date"))
	{
		std::cerr << "Error : where is date in data file ?\n";
		exit (1);
	}

	while (getline (file, line))
	{
		find = line.find(",");
		if (find != -1)
		{
			key = line.substr (0, find);
			value_str = line.substr (find + 1, line.size ());
			value = str_to_double(value_str);
			if (valid_date(key, key_s) && valid_num(value))
				map[key_s] = value;
		}
		else
			std::cerr << "Error: bad input => " << line << std::endl;
	}
}

//std::string time_debug(time_t time)
//{
//	std::tm *m;
//
//	m = std::localtime(&time);
//	std::cout <<  m->tm_year << "-" << m->tm_mon << "-" << m->tm_mday;
//	return ("");
//}


void BitcoinExchange::btc (std::string file_name, std::map<size_t, float> map)
{
	std::ifstream	file;
	std::string		line;
	std::string		key;
	std::string		value_str;
	iter			it;
	iter			closest_one;
	float			value;
	int				find;
	size_t			key_s;
	float			your_pocket_value;

	BitcoinExchange::data_parse ("data.csv", map);
	file.open (file_name);
	if (!file)
	{
		std::cerr << "Error: could not open file\n";
		return ;	
	}
	getline (file, line);
	find = line.find(" | ");
	if (find != -1)
	{
		key = line.substr(0, find);
		if (!(key == "date"))
		{
			std::cerr << "Error : where is date ?\n";
			return ;
		}
	}
	while (getline (file, line))
	{
		find = line.find(" | ");
		if (find != -1)
		{
			key = line.substr (0, find);
			value_str = line.substr (find + 3, line.size ());
			value = str_to_double(value_str);
			if (valid_date(key, key_s) && valid_num(value))
			{
				it = map.find(key_s);
				if (it != map.end())
					your_pocket_value = (it->second) * value;
				else
				{
					it = map.begin();
					iter closest_one = it;
					while (it != map.end())
					{
						if (it->first > key_s)
						{
							if (it != map.begin())
								closest_one = --it;
							break;
						}
						if (BitcoinExchange::abs<size_t>(it->first - key_s) < BitcoinExchange::abs<size_t>(closest_one->first - key_s) && !(closest_one->first > key_s))
							closest_one = it;
						it++;
					}
					your_pocket_value = (closest_one->second) * value;
				}
				std::cout << key << " => " << value_str << " = "  << your_pocket_value << std::endl;
			}
		}
		else
			std::cerr << "Error: bad input => " << line << std::endl;
	}
}

BitcoinExchange::~BitcoinExchange()
{}
