#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class PhoneBook
{
	private :
		Contact contact[8];
		int		contact_index;
		int		full;
	public :
		void init_PhoneBook();
		void add_contact();
		void ls();
};

#endif
