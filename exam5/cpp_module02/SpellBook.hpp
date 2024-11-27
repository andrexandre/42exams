#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"

using namespace std;

class SpellBook
{
	public:
		SpellBook() {}
		~SpellBook() {}
		void learnSpell(ASpell *spell)
		{
			if (spell)
				sb[spell->getName()] = spell->clone();
		}
		void forgetSpell(string const &spell)
		{
			sb.erase(spell);
		}
		ASpell *createSpell(string const &spell)
		{
			if (sb.find(spell) != sb.end())
				return sb[spell];
			return NULL;
		}

	private:
		map<string, ASpell *> sb;
};

#endif