#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

class Ingridients{
    private:
        string iname;
        string amount;

    public:
        friend class Recipes;
        Ingridients(string i, string a) : iname(i), amount(a){}
};