#include <iostream>
#include <string>

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
		const string &getName() const {return name;}
		const string &getTitle() const {return title;}
		void setTitle(const string &title) {this->title = title;}
		void introduce() const
		{
			cout << name << ": I am " << name << ", " << title << "!\n";
		}

	private:
		string name;
		string title;
};
