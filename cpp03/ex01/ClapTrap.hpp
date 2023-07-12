#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
	private :
		std::string name;
		unsigned int hit_point;
		unsigned int energy_point;
		unsigned int attack_damage;
		bool died;
	public :
		ClapTrap();
		ClapTrap(ClapTrap &other);
		ClapTrap(std::string name);
		std::string get_name();
		void set_name(std::string name);
		unsigned int get_hit_point();
		unsigned int get_energy_point();
		unsigned int get_attack_damage();
		bool get_life_stats();
		void set_hit_point(unsigned int l);
		void set_energy_point(unsigned int l);
		void set_attack_damage(unsigned int l);
		void set_life_stats(bool l);
		ClapTrap& operator=(ClapTrap &other);
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		~ClapTrap();
};

#endif
