#include <iostream>
#include <string>
#include "ASpell.hpp"

using namespace std;

class Polymorph : public ASpell
{
	public:
		Polymorph() : ASpell("Polymorph", "turned into a critter") {}
		~Polymorph() {}
		Polymorph *clone() const { return new Polymorph(); }
};
