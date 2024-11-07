#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

using namespace std;

class Warlock
{
	public:
		Warlock(const string &name, const string &title) : name(name), title(title)
		{
			cout << name << ": This looks like another boring day.\n";
		}
		~Warlock()
		{
			cout << name << ": My job here is done!\n";
		}
		const string &getName() const { return name; }
		const string &getTitle() const { return title; }
		void setTitle(const string &title) { this->title = title; }
		void introduce() const
		{
			cout << name << ": I am " << name << ", " << title << "!\n";
		}
		void learnSpell(ASpell *spell)
		{
			if (spell)
				sb[spell->getName()] = spell->clone();
		}
		void forgetSpell(string spell)
		{
			sb.erase(spell);
		}
		void launchSpell(string spell, const ATarget &target)
		{
			if (sb.find(spell) != sb.end())
				sb[spell]->launch(target);
		}

	private:
		string name;
		string title;
		map<string, ASpell *> sb;
};
