#include "Recipes.cpp"

class cookBook{
    private:
        vector<Recipes> recipes;
        vector<string> allTags;
    public:
        Recipes& addRecipe(string n, int c, int t){
            recipes.push_back(Recipes(n, c, t));
            return recipes.back();
        }
        void addTags(const string tag){
            allTags.push_back(tag);
        }
        void addTagToRecipe(const string tag, const string recipeName){
            bool status = false;
            for (int a=0; a < (int)allTags.size(); a++){
                if (allTags[a] == tag){
                    for (int b=0; b < (int)recipes.size(); b++){
                        if (recipes[b].name == recipeName){
                            recipes[b].addTag(tag);
                            status = true;
                            break;
                        }
                    } 
                }
            }
            if (!status){throw "Tag or recipe not found";}
        }
        void addIngridientToRecipe(const string& recipeName, const string& i, const string& a){
            for (int b = 0; b < (int)recipes.size(); b++){
                if (recipes[b].name == recipeName){
                    recipes[b].ingridients.push_back(Ingridients(i, a));
                    return;
                }
            }
            throw "Recipe not found";
        }
        //2
        void getRecipe(const string& name){
            for (int i=0; i < (int)recipes.size(); i++){
                if (recipes[i].name == name){
                    recipes[i].printRecipe();
                }else{ throw "Recipe not found";}
            }
        }
        //3
        void PrintByTag(const string& tag){
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
        void getTotalCalories() const{
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

        void deleteRecipe(const string& name){
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
        //5
        void printByIngridient(const string& ingridient){
            if (recipes.size() == 0) {
             throw "No recipes in cookbook!";
             return;
            }
            bool status = false;
            cout << "Recipes found with " << ingridient << ":" << endl;
            for (int i=0; i < recipes.size(); i++){
                for (int c=0; c < recipes[i].ingridients.size(); c++){
                    if (recipes[i].ingridients[c].getIname() == ingridient){
                        status = true;
                        recipes[i].printRecipe();
                    }
                }
            }
            if (!status){throw "Ingridient not found";}
        }
        //6
        void light(int cal){
            if (recipes.size() == 0) {
             throw "No recipes in cookbook!";
             return;
            }
            for (int i=0; i < recipes.size(); i++){
                if (recipes[i].calories <= cal){
                    recipes[i].printRecipe();
                }
            }
        }
        //7
        void Plan(){
            cout << "type over to end" << endl << "Excluded tags:" << endl;
            vector<string> tager;
            int index = 0;
                while(true){
                    bool status = false;
                    string input;
                    getline(cin, input);
                    if (input == "over"){ break;}
                    for (int i=0; i < (int)tager.size(); i++){
                        if (tager[i] == input){throw "Tag already added";}    
                    }
                    for (int n=0; n < (int)allTags.size(); n++){
                        if (allTags[n] == input){
                            status = true;
                            break;
                        }
                    }
                    if (!status){throw "Tag not found";}
                    
                    tager.push_back(input);
                }
            string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
            for(int i=0; i < 7; i++){
                int r = rand() % recipes.size();
                for(int l=0; l < (int)tager.size(); l++){
                    if (recipes[r].hasTag(tager[l])){
                        break;
                    }
                }
                cout << days[i] << ":" << endl << endl;
                recipes[r].printRecipe();
            }
        }
        //8
        void Difficulty(const string& name){
            if (recipes.size() == 0) {
             throw "No recipes in cookbook!";
             return;
            }
            bool status = false;
            int difficulty = 0;
            for (int i=0; i < recipes.size(); i++){
                if (recipes[i].name == name){
                    status = true;
                    if (recipes[i].cookTime > 10 || recipes[i].cookTime < 20){difficulty++;}
                    if (recipes[i].cookTime >= 20 || recipes[i].cookTime < 30){difficulty+=2;}
                    if (recipes[i].cookTime >= 30 || recipes[i].cookTime < 45){difficulty+=3;}
                    if (recipes[i].cookTime >= 45 || recipes[i].cookTime < 60){difficulty+=4;}
                    if (recipes[i].cookTime >= 60){difficulty+=5;}
                    if (recipes[i].ingridients.size() > 3 || recipes[i].ingridients.size() < 5){difficulty++;}
                    if (recipes[i].ingridients.size() >= 5 || recipes[i].ingridients.size() < 7){difficulty+=2;}
                    if (recipes[i].ingridients.size() >= 7 || recipes[i].ingridients.size() < 10){difficulty+=3;}
                    if (recipes[i].ingridients.size() >= 10 || recipes[i].ingridients.size() < 15){difficulty+=4;}
                    if (recipes[i].ingridients.size() >= 15){difficulty+=5;}
                    cout << "difficulty 0/10: " << difficulty << endl;
                    break;
                }

            }
            if (!status){throw "Recipe not found";}
        }
};