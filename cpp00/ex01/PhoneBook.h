#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <stdio.h>
# include <unistd.h>
# include <string>
# include "Contact.hpp"
# include "phonebook.hpp"

void	print_it_cool(std::string c);
void	gener_ws(int len);
int		more_info(Contact *contact, int contact_index);
void	print_just_ten(std::string str);
void	decoration(void);

#endif
