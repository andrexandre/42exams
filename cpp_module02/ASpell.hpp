#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>
#include "ATarget.hpp"

using namespace std;

class ATarget;

class ASpell
{
	public:
		ASpell(const string &name, const string &effects) : name(name), effects(effects) {}
		virtual ~ASpell() {}
		const string &getName() const { return name; }
		const string &getEffects() const { return effects; }
		virtual ASpell *clone() const = 0;
		void launch(const ATarget &target);

	protected:
		string name;
		string effects;
};

#endif