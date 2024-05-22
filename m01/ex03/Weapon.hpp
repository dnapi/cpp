#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon{
	public:
		Weapon(str::string type);
		const str::string & getType(void);
	private:
		std::string type;
};

#endif
