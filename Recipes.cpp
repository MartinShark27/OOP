#include "Ingridients.cpp"

class Recipes{
    friend class cookBook;
    private:
        string name;
        vector<Ingridients> ingridients;
        vector<string> tags;
        int cookTime;
        int calories;
    public:
        //1
        Recipes(string n, int c, int t) : name(n), calories(c), cookTime(t){}

        void addIngridient(const string i, const string a){
            ingridients.push_back(Ingridients(i, a));
        }

        void printRecipe() const{
            cout << name << endl << endl;
            for(int i =0; i < (int)ingridients.size(); i++){
                cout << ingridients[i].iname << " " << ingridients[i].amount << endl << endl;
            }
            for (int i =0; i < (int)tags.size(); i++){
                cout << tags[i] <<endl;
            }
                cout << "Cook Time: " << cookTime << endl;
                cout << "Calories: " << calories << endl;
        }
        void addTag(const string& tag) {
            tags.push_back(tag);
        }
        
        
        bool hasTag(const string& tag) const{
            for (int i=0; i < (int)tags.size(); i++){
                if (tags[i] == tag){
                    return true;
                }
            }
            return false;
        }   
};