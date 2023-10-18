#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <deque>

class RPN
{
	private :
		RPN();
		RPN(const RPN &other);
		RPN& operator= (const RPN &other);
		
		static bool is_op(std::string a);
		static bool check(std::string all);
		static void print_d(std::deque<int> deque_num);
		static void found_suc_space (std::string a);
		static int do_op (int *saver, std::string op);
		static void take_args(std::deque<std::string> &all, std::string av);


	public :
		static int rpn(std::string av);
		~RPN();
};

#endif
