#include <iostream>
#include <string>
#include "ATarget.hpp"

using namespace std;

class BrickWall : public ATarget
{
	public:
		BrickWall() : ATarget("Inconspicuous Red-brick Wall") {}
		~BrickWall() {}
		BrickWall *clone() const { return new BrickWall(); }
};
