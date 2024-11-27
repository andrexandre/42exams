#include <iostream>
#include <string>
#include "ASpell.hpp"

using namespace std;

class Fwoosh : public ASpell
{
	public:
		Fwoosh() : ASpell("Fwoosh", "fwooshed") {}
		~Fwoosh() {}
		Fwoosh *clone() const { return new Fwoosh(); }
};
