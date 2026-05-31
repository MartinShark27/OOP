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
                        if (recipes[b].getName() == recipeName){
                            recipes[b].addTag(tag);
                            status = true;
                            break;
                        }
                    } 
                }
            }
            if (!status){throw "Tag or recipe not found";}
        }
         void Plan(vector<Recipes>& recipes, vector<string>& tags){
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
};

int main(){

    srand(time(0));
}