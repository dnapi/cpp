class AMateria
{
	protected:
		std::string const& type
	public:
		AMateria();
		~AMateria();
		AMateria(std::string const& type);
		AMateria& operator=(AMateria& other);
		std::string const& getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
