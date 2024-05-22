#include "Weapon.hpp"

Weapon::Weapon(str::string type){
	this->type = type;
}

const str::string & Weapon::getType(void){
	return (this->type);
}
