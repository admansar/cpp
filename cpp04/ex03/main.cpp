#include <iostream>

class AMateria;
/****************ICharacter****************/
class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

/****************AMateria****************/

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		AMateria(AMateria const &other);
		AMateria &operator=(AMateria const &other);
		AMateria(std::string const & type);
		std::string const & getType() const; 
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		virtual ~AMateria();
};

AMateria::AMateria()
	: type("AMateria")
{}

AMateria::AMateria(AMateria const &other)
	:type (other.type)
{}

AMateria::AMateria(std::string const &type)
	:type(type)
{}

AMateria &AMateria::operator=(AMateria const &other)
{
	type = other.type;
	return (*this);
}


std::string const &AMateria::getType() const
{
	return (type);
}


void AMateria::use(ICharacter& target)
{
	std::cout << "i mean who need to use the " << target.getName() << std::endl;
}

AMateria::~AMateria()
{}

/****************Ice****************/

class Ice : public AMateria
{
	public :
		Ice();
		Ice(Ice const &other);
		Ice &operator=(Ice const &other);
		AMateria *clone () const ;
		void use(ICharacter& target);
		~Ice();
};

Ice::Ice()
	:AMateria("ice")
{}

Ice::Ice(Ice const &other)
	:AMateria(other)
{}

Ice &Ice::operator=(Ice const &other)
{
	type = other.type;
	return (*this);
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

Ice::~Ice()
{}

/****************Cure****************/

class Cure : public AMateria
{
	public :
		Cure();
		Cure(Cure const &other);
		Cure &operator=(Cure const &other);
		AMateria *clone () const ;
		void use(ICharacter& target);
		~Cure();
};


Cure::Cure()
	:AMateria("cure")
{}

Cure::Cure(Cure const &other)
	:AMateria(other)
{}

Cure &Cure::operator=(Cure const &other)
{
	type = other.type;
	return (*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

Cure::~Cure()
{}

/****************Character****************/
class Character : public ICharacter
{
	private :
		std::string	name;
		AMateria	*inventaire[4];
		int			index;
	public:
		Character(std::string name);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		~Character(); 
};

Character::Character(std::string name)
	:name(name), index(0)
{
	int i;

	i = 0;
	while (i < 4)
	{
		inventaire[i] = NULL;
		i++;
	}
}

std::string const &Character::getName() const
{
	return (name);
}

void Character::equip(AMateria *m)
{
	if (index < 4 && !inventaire[index])
	{
		inventaire[index] = m->clone();
		delete m;
		if (index < 4)
			index++;
	}
	else
	{
		std::cout << "pas d'emplacement vide pour cette inventaire : " << m << std::endl;
	}
}

void Character::unequip(int idx)
{
	if (idx < 4)
	{
		if (idx > index)
		{
			std::cout << "you cant unequip something you didnt equip !!\n";
		}
		else
		{
			delete inventaire[idx];
			inventaire[idx] = NULL;
		}
	}
	else
	{
		std::cout << "really ??, how can i unequip in a plcae that you dont have unloocked yet!!\n";
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 4)
	{
		if (idx <= index)
		{
			if (inventaire[idx]->getType() == "ice" || inventaire[idx] ->getType() == "cure")
				inventaire[idx]->use(target);
			else
				std::cout << "type is not defined\n";
		}
		else
			std::cout << "no inventaire is in there !!\n";
	}
	else
	{
		std::cout << "really ??, you really know that you didnt unlock more space for more then 4 inventaire\n";
	}
}

Character::~Character()
{
	int i;

	i = 0;
	while (i < index)
		delete inventaire[i++];
}

/****************IMateriaSource****************/

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};


class MateriaSource : public IMateriaSource
{
	private :
		AMateria	*materia[4];
		int			index;
		std::string	name;
	public :
		MateriaSource();
		MateriaSource(std::string name);
		MateriaSource(MateriaSource const &other);
		MateriaSource &operator=(MateriaSource const &other);
		void learnMateria(AMateria *m);
		AMateria *createMateria(std::string const &type);
		~MateriaSource();
};

MateriaSource::MateriaSource()
	:index(0), name("")
{
	int i;

	i = 0;
	while (i < 4)
	{
		materia[i] = NULL;
		i++;
	}
}

MateriaSource::MateriaSource(std::string name)
	:index(0), name(name)
{
	int i;

	i = 0;
	while (i < 4)
	{
		materia[i] = NULL;
		i++;
	}
}

MateriaSource::MateriaSource(MateriaSource const &other)
	:index(0), name(other.name)
{
	int i;

	i = 0;
	while (i < 4)
	{
		materia[i] = other.materia[i];
		i++;
	}
}

AMateria  *MateriaSource::createMateria(std::string const &type)
{
	if (type == "ice")
		return (new Ice());
	else if (type == "cure")
		return (new Cure());
	return (0);
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	int i;

	i = 0;
	index = other.index;
	name = other.name;
	while (i < 4)
	{
		delete materia[i];
		materia[i] = other.materia[i];
		i++;
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (index < 4)
	{
		materia[index] = m->clone();
		delete m;
		index++;
	}
	else
	{
		std::cout << "sorry , but the max is 4 materia\n";
	}
}

MateriaSource::~MateriaSource()
{
	int i;

	i = 0;
	while (i < index)
		delete materia[i++];
}

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}
