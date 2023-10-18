#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <ctime>

class  BitcoinExchange
{
	private :
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);


	public :
		static void data_parse(std::string data, std::map<size_t,float> &map);
		static void btc(std::string data, std::map<size_t,float> map);

		typedef std::map<size_t, float>::iterator iter;

		template <typename T>
			static T abs(T a);

		~BitcoinExchange();
};

#endif
