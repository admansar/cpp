#include "PhoneBook.h"

void PhoneBook::init_PhoneBook()
{
	int i;

	i = 0;
	contact_index = 0;
	full = 0;
	while (i < 8)
	{
		contact[i].init_info(); 
		i++;
	}
}

void PhoneBook::ls()
{
	int i;

	i = -1;
	if (this->full)
	{
		decoration();
		while (++i < 8)
			contact[i].contact_ls(i);
		i = more_info(contact, 8);
	}
	else if (contact_index)
	{
		decoration();
		while (++i < contact_index)
			contact[i].contact_ls(i);
		i = more_info(contact, contact_index);
	}
	if (i + 1)
 		contact[i-1].contact_ls_details(i-1);
	else
		std::cout << "nothing in or wrong index" << std::endl;
}

void PhoneBook::add_contact()
{
	if (this->contact_index == 8)
	{
		this->full = 1;
		this->contact_index = 0;
	}
	this->contact[this->contact_index].add_contacts();
	this->contact_index++;
}
