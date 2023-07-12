#ifndef CONTACT_HPP
#define CONTACT_HPP

typedef struct infos
{
	std::string name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
}				contacts_info;

class Contact
{
	private:
		contacts_info info;
	public:
		void init_info();
		void add_contacts();
		void contact_ls(int);
		void contact_ls_details(int);
};

#endif
