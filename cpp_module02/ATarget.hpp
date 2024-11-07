#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"

using namespace std;

class ASpell;

class ATarget
{
	public:
		ATarget(const string &type) : type(type) {}
		virtual ~ATarget() {}
		const string &getType() const { return type; }
		virtual ATarget *clone() const = 0;
		void getHitBySpell(const ASpell &spell) const;

	protected:
		string type;
};

#endif