#include <iostream>
#include <string>
#include <map>
#include "ATarget.hpp"

using namespace std;

class TargetGenerator
{
	public:
		TargetGenerator() {}
		~TargetGenerator() {}
		void learnTargetType(ATarget *target)
		{
			if (target)
				sb[target->getType()] = target->clone();
		}
		void forgetTargetType(string const &target)
		{
			sb.erase(target);
		}
		ATarget *createTarget(string const &target)
		{
			if (sb.find(target) != sb.end())
				return sb[target];
			return NULL;
		}

	private:
		map<string, ATarget *> sb;
};
