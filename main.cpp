#include "CookBook.cpp"


int main() {
    srand(time(0));
    cookBook cookbook;
    string input;

    while (true) {
        cout << "\nWhat do you want to do?\n";
        cout << "1. Add recipe\n";
        cout << "2. Add ingridient to recipe\n";
        cout << "3. Delete recipe\n";
        cout << "4. Add tag to cookbook\n";
        cout << "5. Add tag to recipe(tag has to be in cookbook)\n";
        cout << "6. Print recipe by name\n";
        cout << "7. Print recipes by tag\n";
        cout << "8. Print recipes by ingridient\n";
        cout << "9. Calories total\n";
        cout << "10. Weekly plan\n";
        cout << "11. Difficulty\n";
        cout << "12. Light recipes\n";
        cout << "exit\n\n> ";

        getline(cin, input);

        if (input == "exit") break;

        try {
            if (input == "1") {
                string name; int cal, cookTime;
                cout << "Name: "; getline(cin, name);
                cout << "Calories: "; cin >> cal;
                cout << "Cook time: "; cin >> cookTime;
                cin.ignore();
                cookbook.addRecipe(name, cal, cookTime);
                cout << "Recipe added!\n";

            } else if (input == "2") {
                string name, iname, amount;
                cout << "Recipe name: "; getline(cin, name);
                cout << "Ingredient name: "; getline(cin, iname);
                cout << "Amount: "; getline(cin, amount);
                cookbook.addIngridientToRecipe(name, iname, amount);
                cout << "Ingredient added!\n";

            } else if (input == "3") {
                string name;
                cout << "Recipe name: "; getline(cin, name);
                cookbook.deleteRecipe(name);

            } else if (input == "4") {
                string tag;
                cout << "Tag: "; getline(cin, tag);
                cookbook.addTags(tag);
                cout << "Tag added!\n";

            } else if (input == "5") {
                string tag, name;
                cout << "Tag: "; getline(cin, tag);
                cout << "Recipe name: "; getline(cin, name);
                cookbook.addTagToRecipe(tag, name);
                cout << "Tag added to recipe!\n";

            } else if (input == "6") {
                string name;
                cout << "Recipe name: "; getline(cin, name);
                cookbook.getRecipe(name);

            } else if (input == "7") {
                string tag;
                cout << "Tag: "; getline(cin, tag);
                cookbook.PrintByTag(tag);

            } else if (input == "8") {
                string ing;
                cout << "Ingredient: "; getline(cin, ing);
                cookbook.printByIngridient(ing);

            } else if (input == "9") {
                cookbook.getTotalCalories();

            } else if (input == "10") {
                cookbook.Plan();

            } else if (input == "11") {
                string name;
                cout << "Recipe name: "; getline(cin, name);
                cookbook.Difficulty(name);

            } else if (input == "12") {
                int cal;
                cout << "Max calories: "; cin >> cal;
                cin.ignore();
                cookbook.light(cal);

            } else {
                cout << "Unknown command\n";
            }

        } catch (const char* e) {
            cout << "Error: " << e << "\n";
        }
    }

    return 0;
}