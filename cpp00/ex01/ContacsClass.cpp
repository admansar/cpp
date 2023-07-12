#include "PhoneBook.h"

void Contact::init_info()
{
	info.name.clear();
	info.last_name.clear();
	info.nickname.clear();
	info.phone_number.clear();
	info.darkest_secret.clear();
}

void Contact::contact_ls(int index)
{
	std::cout << "|    "  << index + 1 << "     |";
	print_it_cool(this->info.name);
	print_it_cool(this->info.last_name);
	print_it_cool(this->info.nickname);
	std::cout << std::endl << "+-------------------------------------------+" << std::endl;
}


void Contact::contact_ls_details(int index)
{
	std::cout << std::endl;
	std::cout << "\t\tname         : " << this->info.name << std::endl;
	std::cout << "\t\tlast name    : " << this->info.last_name << std::endl;
	std::cout << "\t\tnick name    : " << this->info.nickname << std::endl;
	std::cout << "\t\tphone number : " << this->info.phone_number << std::endl;
	std::cout << std::endl;
}

void Contact::add_contacts()
{
	std::cout << "\t---------------|ADDING MODE|---------------" << std::endl;
	std::cout << "\nname : ";
	std::cin >> this->info.name;
	std::cout << "\nlast_name : ";
	std::cin >> this->info.last_name;
	std::cout << "\nnickname : ";
	std::cin >> this->info.nickname;
	std::cout << "\nPhone number : ";
	std::cin >> this->info.phone_number;
	std::cout << "\nwhat is you darkest secret :";
	std::cin >> this->info.darkest_secret;
	std::cout << "\t+----------------------------------------+" << std::endl;
	std::cout << "\t|           successfully added           |" << std::endl;
	std::cout << "\t+----------------------------------------+" << std::endl << std::endl;
}
