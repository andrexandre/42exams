#include <iostream>
#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

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
			sb.learnSpell(spell);
		}
		void forgetSpell(string spell)
		{
			sb.forgetSpell(spell);
		}
		void launchSpell(string spell, const ATarget &target)
		{
			ASpell *tmp = sb.createSpell(spell);
			if (tmp)
				tmp->launch(target);
		}

	private:
		string name;
		string title;
		SpellBook sb;
};
