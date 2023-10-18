#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
	: sorted(false), has_last_elem(false), last_elem(-1)
{}

PmergeMe::PmergeMe(const PmergeMe& other)
	:  list(other.list), vector(other.vector), sorted (other.sorted), has_last_elem(other.has_last_elem), last_elem(other.last_elem)
{}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	sorted = other.sorted;
	list = other.list;
	vector = other.vector;
	has_last_elem = other.has_last_elem;
	last_elem = other.last_elem;
	return (*this);
}

	template <typename Iterator>
Iterator PmergeMe::next (Iterator it, int n)
{
	std::advance (it, n);
	return (it);
}

bool PmergeMe::is_number(char **av)
{
	int i;
	int j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!std::isdigit (av[i][j]))
			{
				std::cerr << "Error : bad args '"<<  av[i] << "'\n";
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

	template <typename T>
std::string PmergeMe::printer(T type)
{
	typename T::iterator i = type.begin();

	while (i !=  type.end())
	{
		std::cout << *i << " ";
		i++;
	}
	//	std::cout << "\n=====================" << std::endl;
	return ("\n");
}

	template <typename T>
size_t PmergeMe::binary_search(T &v, int to_in)
{
	int lower;
	int upper;
	int mid;

	lower = 0;
	upper = v.size() - 1;
	while (lower <= upper)
	{
		mid = lower + (upper - lower) / 2;
		if (to_in < *PmergeMe::next (v.begin(), mid))
			upper = mid - 1;
		else if (to_in > *PmergeMe::next (v.begin(), mid))
			lower = mid + 1;
		else
			return (mid);
	}
	return (lower);
}

	template <typename Container>
bool PmergeMe::isSorted(const Container& container) 
{
	typename Container::const_iterator it = container.begin();
	typename Container::const_iterator next = it;

	++next;
	while (next != container.end()) 
	{
		if (*it > *next) 
			return false;
		++it;
		++next;
	}

	return true;
}

long int PmergeMe::jacobsthal(long int n)
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

	template <typename T>
void PmergeMe::insert_at_index (T &type, int elem)
{
	int i;

	i = binary_search (type, elem);
	type.insert (PmergeMe::next(type.begin (), i), elem);
}

/************************VECTOR************************/

void PmergeMe::print_vect_pair (VectorPair &tmp_vect)
{
	size_t i;

	i = -1;
	while (++i < tmp_vect.size())
		std::cout << "[" << tmp_vect[i].first << " - "<< tmp_vect[i].second << "] ";
	std::cout << std::endl;
}

void PmergeMe::print_list_pair (ListPair &list)
{
	ListPair::iterator i;

	i = list.begin ();
	while (i != list.end())
	{
		std::cout << "[" << i->first << " - "<< i->second << "] ";
		i++;
	}
	std::cout << std::endl;
}

std::vector <int> PmergeMe::buil_jacob_insert(int size)
{
	std::vector <int> jacob;
	int jacob_index;

	jacob_index = 3;
	while (jacobsthal (jacob_index) < size - 1)
	{
		jacob.push_back (jacobsthal (jacob_index));
		jacob_index++;
	}
	return (jacob);
}

std::vector <int> PmergeMe::creat_insert_index (std::vector <int> pend_chain)
{
	bool last_was_jacob;
	int pen_size;
	std::vector <int> index_seq;

	last_was_jacob = false;
	pen_size = pend_chain.size();
	index_seq.push_back(1);
	if (pen_size == 1)
		return (index_seq);
	std::vector <int> jacob_seq = buil_jacob_insert(pen_size);
	int i = 1;
	while (i <= pen_size)
	{
		if (jacob_seq.size () != 0 && !last_was_jacob)
		{
			index_seq.push_back (jacob_seq[0]);
			jacob_seq.erase (jacob_seq.begin ());
			last_was_jacob = true;
		}
		else
		{
			std::vector <int>::iterator it = index_seq.begin ();
			while (it != index_seq.end ())
			{
				if (*it == i)
					i++;
				it++;
			}
			index_seq.push_back (i);
			last_was_jacob = false;
			i++;
		}
	}
	return (index_seq);
}

void PmergeMe::insert_elem(VectorPair &tmp_vect, Pair element, int n)
{
	if (n < 0)
		tmp_vect [0] = element;
	else if (element.second >= tmp_vect[n].second)
	{
		if (n == static_cast<int>(tmp_vect.size() - 1))
			tmp_vect.push_back (element);
		else
			tmp_vect[n + 1] = element;
	}
	else
	{
		if (n == static_cast<int>(tmp_vect.size() - 1))
			tmp_vect.push_back (tmp_vect[n]);
		else
			tmp_vect[n + 1] = tmp_vect[n];
		insert_elem (tmp_vect, element, n - 1);
	}
}


void PmergeMe::insert_sort(VectorPair &tmp_vect, int n)
{
	if (n == 0)
		return ;
	insert_sort (tmp_vect, n - 1);
	insert_elem (tmp_vect, tmp_vect[n], n - 1);
}

void PmergeMe::sort_merge (VectorPair &tmp_vect)
{
	std::vector<int> main_chain;
	std::vector<int> pend_chain;

	size_t i = 0;
	while (i < tmp_vect.size())
	{
		main_chain.push_back (tmp_vect[i].second);
		pend_chain.push_back (tmp_vect[i].first);
		i++;
	}
	std::vector<int> index_seq = creat_insert_index (pend_chain);
	std::vector<int>::iterator it = index_seq.begin ();
	while (it != index_seq.end ())
	{
		insert_at_index (main_chain, pend_chain[*it - 1]);
		it++;
	}
	vector = main_chain;
}

std::vector<std::pair<int, int> > PmergeMe::split_to_sorted_pair (std::vector<int> &vect)
{
	size_t i;
	VectorPair tmp_vect;
	int tmp;

	i = 0;
	while (i < vect.size())
	{
		tmp_vect.push_back(std::make_pair (vect[i], vect [i + 1]));
		i += 2;
	}
	i = 0;
	while (i < tmp_vect.size())
	{
		if (tmp_vect[i].first > tmp_vect[i].second)
		{
			tmp = tmp_vect[i].first;
			tmp_vect[i].first = tmp_vect[i].second;
			tmp_vect[i].second = tmp;
		}
		i++;
	}
	return (tmp_vect);
}

void PmergeMe::merge_insert_sort(std::vector<int> &vect)
{
	VectorPair tmp_vect;

	if (vect.size() % 2 == 1)
	{
		has_last_elem = true;
		last_elem = vect.back();
		vect.pop_back();
	}
	tmp_vect = split_to_sorted_pair (vect);
	insert_sort(tmp_vect, tmp_vect.size() - 1);
	sort_merge (tmp_vect);
	if (has_last_elem)
		insert_at_index (vector, last_elem);
}

/************************LIST************************/

std::list <int> PmergeMe::buil_jacob_insert_l(int size)
{
	std::list <int> jacob;
	int jacob_index = 3;

	while (jacobsthal (jacob_index) < size - 1)
	{
		jacob.push_back (jacobsthal (jacob_index));
		jacob_index++;
	}
	return (jacob);
}

std::list<int> PmergeMe::creat_insert_index (std::list<int> pend_chain)
{
	bool last_was_jacob = false;
	int pen_size = pend_chain.size();
	std::list <int> index_seq;

	index_seq.push_back(1);
	if (pen_size == 1)
		return (index_seq);
	std::list <int> jacob_seq = buil_jacob_insert_l(pen_size);
	int i = 1;
	while (i <= pen_size)
	{
		if (jacob_seq.size () != 0 && !last_was_jacob)
		{
			index_seq.push_back (*jacob_seq.begin ());
			jacob_seq.erase (jacob_seq.begin ());
			last_was_jacob = true;
		}
		else
		{
			std::list <int>::iterator it = index_seq.begin ();
			while (it != index_seq.end ())
			{
				if (*it == i)
					i++;
				it++;
			}
			index_seq.push_back (i);
			last_was_jacob = false;
			i++;
		}
	}
	return (index_seq);
}

void PmergeMe::sort_merge (ListPair &tmp_list)
{
	std::list<int> main_chain;
	std::list<int> pend_chain;

	ListPair::iterator i = tmp_list.begin ();
	while (i != tmp_list.end())
	{
		main_chain.push_back (i->second);
		pend_chain.push_back (i->first);
		i++;
	}
	std::list <int> index_seq = creat_insert_index (pend_chain);
	std::list<int>::iterator it = index_seq.begin ();
	while (it != index_seq.end ())
	{
		insert_at_index (main_chain, *PmergeMe::next(pend_chain.begin (), *it - 1));
		it++;
	}
	list = main_chain;
}

void PmergeMe::insert_elem(ListPair &list_tmp, Pair element, int n)
{
	if (n < 0)
		*list_tmp.begin () = element;
	else if (element.second >= PmergeMe::next(list_tmp.begin (), n)->second)
	{
		if (n == static_cast<int>(list_tmp.size() - 1))
			list_tmp.push_back (element);
		else
			*PmergeMe::next(list_tmp.begin(), n + 1) = element;
	}
	else
	{
		if (n == static_cast<int>(list_tmp.size() - 1))
			list_tmp.push_back (*PmergeMe::next(list_tmp.begin(), n));
		else
			*PmergeMe::next(list_tmp.begin(), n + 1) = *PmergeMe::next(list_tmp.begin(), n);
		insert_elem (list_tmp, element, n - 1);
	}
}

void PmergeMe::insert_sort(ListPair &tmp_list, int n)
{
	if (n == 0)
		return ;
	insert_sort (tmp_list, n - 1);
	insert_elem (tmp_list, *PmergeMe::next(tmp_list.begin(), n), n - 1);
}

std::list<std::pair<int, int> > PmergeMe::split_to_sorted_pair (std::list<int> &list)
{
	ListPair tmp_list;
	std::list<int>::iterator i;
	int tmp;
	i = list.begin ();
	while (i != list.end())
	{
		tmp_list.push_back(std::make_pair (*i, *PmergeMe::next (i, 1)));
		std::advance(i, 2);
	}
	ListPair::iterator it = tmp_list.begin();
	while (it != tmp_list.end())
	{
		if (it->first > it->second)
		{
			tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
		it++;
	}
	return (tmp_list);
}

void PmergeMe::merge_insert_sort(std::list<int> &list)
{
	ListPair tmp_list;

	if (list.size() % 2 == 1)
	{
		has_last_elem = true;
		last_elem = list.back();
		list.pop_back();
	}
	tmp_list = split_to_sorted_pair (list);
	insert_sort(tmp_list, tmp_list.size() - 1);
	sort_merge (tmp_list);
	if (has_last_elem)
		insert_at_index (list, last_elem);
}


/****************************************************/

PmergeMe::PmergeMe(int ac, char **av)
{
	size_t	i;
	clock_t start;
	clock_t end;
	int *arr = new int[--ac];

	if (!is_number(++av))
		return ;
	i = -1;
	while (av[++i])
		arr[i] = atoi (av[i]);
	// rod std::atoi
	i = 0;
	vector.reserve(ac);
	while (static_cast<int>(i) < ac)
	{
		vector.push_back (arr[i]);
		list.push_back (arr[i]);
		i++;
	}
	delete[] arr;

	std::cout << RED << "sequence Before: " <<  printer(vector) << std::endl;

	start = clock();
	merge_insert_sort (vector);
	end = clock();
	vect_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	start = clock();
	merge_insert_sort (list);
	end = clock();
	list_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;


	std::cout << GREEN << "sequence after: " <<  printer(list) << RESET << std::endl;

	std::cout << "vector is " << (isSorted(vector) ? "sorted " : "not sorted") << " in : " << vect_time << " second" << std::endl;
	std::cout << "list   is " << (isSorted(list) ? "sorted " : "not sorted") << " in : " << list_time << " second" << std::endl;
}

PmergeMe::~PmergeMe()
{}


