#include <string>
#pragma once

using namespace std;

class ThingOb
{
    private:
    protected:
		string name;
		string description;
    public:
    	ThingOb(string name, string description);
    	string getName() const { return name; };
    	string getDescription() const { return description; };
};