#pragma once

#include <string>
#include <iostream>

class Harl{
	public:
		Harl(void);
		~Harl(void);
		void	printStr(std::string str) const;
		void	complain(std::string level);
		void	complainAll(int startLevel);
		int		levelToInt(std::string level);
	private :
//		typedef	void	(Harl::*MemberFunction)(void);
//		MemberFunction	_functions[5];
		void	(Harl::*_functions[5])(void);
		std::string _LevelList[5];
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void	silence(void);
};
