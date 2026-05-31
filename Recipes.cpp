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
        
        //2
        void getRecipe(const vector<Recipes>& recipes, const string& name){
            for (int i=0; i < (int)recipes.size(); i++){
                if (recipes[i].name == name){
                    recipes[i].printRecipe();
                }else{ throw "Recipe not found";}
            }
        }
        //3
        void PrintByTag(const vector<Recipes>& recipes, const string& tag){
            bool status = false;
            cout << "Recipes found with " << tag << ":" << endl;
            for (int i=0; i < (int)recipes.size(); i++){
                for (int c=0; c < (int)recipes[i].tags.size(); c++){
                    if (recipes[i].tags[c] == tag){
                        status = true;
                        recipes[i].printRecipe();
                    }
                }
            }
            if (!status){throw "Tag not found";}
        }
        //4
        void getTotalCalories(vector<Recipes>& recipes) const{
            cout << "type over to end" << endl << "What did you eat?" << endl << endl;
            int totalCal = 0;

            while(true){
                string input;
                getline (cin, input);
                bool status = false;
                if (input == "over"){ break;}
                for (int i=0; i < (int)recipes.size(); i++){
                    if (recipes[i].name == input){
                        totalCal += recipes[i].calories;
                        status = true;
                        break;
                    }
                }
                if (!status){throw "Last recipe not found";}
            }
            cout << "Total calories consumed:" << totalCal << endl;
        }

        void deleteRecipe(vector<Recipes>& recipes, const string& name){
            bool status = false;
            for(int i=0; i < (int)recipes.size(); i++){
                if (recipes[i].name == name){
                    recipes.erase(recipes.begin() + i);
                    status = true;
                    break;
                }
            }
            if (!status){throw "Recipe not found";}
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