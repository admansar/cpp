#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <list>
#include <iterator>
#include <vector>


#define RED		"\x1b[31m"
#define GREEN	"\x1b[32m"
#define YELLOW	"\x1b[33m"
#define RESET	"\x1b[0m"

class PmergeMe
{
	private :
		std::list<int>		list;
		std::vector<int>	vector;
		bool				sorted;
		bool				has_last_elem;
		int					last_elem;
		double				vect_time;
		double				list_time;


		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe&	operator=(const PmergeMe &other);

		typedef std::pair<int, int> 						Pair;

		/************************VECTOR************************/

		typedef std::vector<std::pair <int, int > > 		VectorPair;


		void				insert_sort(VectorPair &tmp_vect, int n);
		void				sort_merge (VectorPair &tmp_vect);
		void				insert_elem(VectorPair &tmp_vect, Pair element, int n);
		std::vector<int>	creat_insert_index (std::vector <int> pend_chain);
		std::vector<int>	buil_jacob_insert(int size);
		void				print_vect_pair (VectorPair &tmp_vect);
		long int			jacobsthal(long int n);
		bool				is_number(char **av);
		void				merge_insert_sort(std::vector<int> &vect);
		VectorPair			split_to_sorted_pair (std::vector<int> &vect);

		/************************LIST************************/

		typedef	std::list<std::pair <int, int > > 			ListPair;

		void			merge_insert_sort(std::list<int> &list);
		void			insert_sort(ListPair &tmp_list, int n);
		void			insert_elem(ListPair &tmp_vect, Pair element, int n);
		void			print_list_pair (ListPair &list);
		void			sort_merge (ListPair &tmp_list);
		std::list<int>	creat_insert_index (std::list<int> pend_chain);
		std::list <int>	buil_jacob_insert_l(int size);
		ListPair		split_to_sorted_pair (std::list<int> &list);

		/************************SHARED************************/


		template <typename Iterator>
			Iterator	next (Iterator it, int n);
		template <typename T>
			size_t		binary_search(T &v, int to_in);
		template <typename T>
			std::string	printer(T type);
		template <typename Container>
			bool		isSorted(const Container& container);
		template <typename T>
			void		insert_at_index (T &type, int elem);
		/*****************************************************/

	public :
		PmergeMe(int ac, char **av);

		~PmergeMe();
};

#endif
