#ifndef HARL_HPP
#define HARL_HPP

class Harl
{
	private :
		void debug ();
		void info();
		void warning();
		void error();
		bool found;
	public :
		Harl();
		void complain(std::string level);
};

#endif
