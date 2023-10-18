#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN& RPN::operator=(const RPN &other)
{
	(void)other;
	return (*this);
}

bool RPN::is_op(std::string a)
{
	if (a == "+" || a == "-" || a == "*" || a == "/")
		return (true);
	return (false);
}

bool RPN::check(std::string all)
{
	size_t i;
	bool re;

	i = 0;
	re = false;
	while (i < all.size() && !re)
	{
		if (!std::isdigit(all[i]))
		{
			if (is_op(all))
				re = false;
			else
				re = true;
		}
		i++;
	}
	if (i > 1)
		re = true;
	return (re);
}

void RPN::print_d(std::deque<int> deque_num)
{
	size_t i = 0;

	while (i < deque_num.size())
	{
		std::cout << deque_num[i] << " ";
		i++;
	}
	std::cout << "\n";
}

void RPN::found_suc_space (std::string a)
{
	int i;

	i = -1;
	while (++i < static_cast<int>(a.size()) - 1)
		if (a[i] == ' ' && a[i + 1] == ' ')
		{
			a.erase(i, 1);
			i = -1;
		}
}

int RPN::do_op (int *saver, std::string op)
{
	if (op == "+")
		return (saver [1] + saver [0]);
	if (op == "-")
		return (saver [1] - saver [0]);
	if (op == "*")
		return (saver [1] * saver [0]);
	if (op == "/")
	{
		if (saver[0] == 0)
		{
			std::cout << "interdit de diviser par 0\n";
			exit (1);
		}
		return (saver [1] / saver [0]);
	}
	// pas div sur 0
	else
		return (std::cerr << "something went wrong :(\n", -1);
}

void RPN::take_args(std::deque<std::string> &all, std::string av)
{
	std::string				word;
	std::istringstream		iss(av);

	while (std::getline (iss, word, ' '))
		all.push_back(word);
}

int RPN::rpn(std::string av)
{
	std::deque<int>			rpn;
	int						saver[2];
	std::deque<std::string>	all;
	size_t					i;

	found_suc_space(av);
	take_args(all, av);
	i = -1;
	while (++i < all.size())
		if (RPN::check(all[i]))
			return (std::cerr << "Error" << std::endl, 1);
	i = -1;
	while (++i < all.size())
		if (RPN::is_op(all[i]))
		{
			if (rpn.size() < 2)
				return (std::cerr << "its called RPN, so dont try to use it like PN\n", 1);
			//	std::cout << "operation : " << all[i] << "\n";
			saver[0] = rpn.back ();
			rpn.pop_back();
			saver[1] = rpn.back ();
			rpn.pop_back();
			rpn.push_back (do_op(saver, all[i]));
		}
		else 
		{
			rpn.push_back (std::atoi(all[i].c_str()));
			//print_d(rpn);
		}
	std::cout << rpn[0] << std::endl;
	return (0);
}

RPN::~RPN()
{}
