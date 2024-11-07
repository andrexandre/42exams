#include <iostream>
#include <string>
#include "ATarget.hpp"

using namespace std;

class Dummy : public ATarget
{
	public:
		Dummy() : ATarget("Target Practice Dummy") {}
		~Dummy() {}
		Dummy *clone() const { return new Dummy(); }
};
