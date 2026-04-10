//TodoFileEditV3_2f.cpp
//THIS BUGGED VERSION, WITH TROUBLES ON MENU OUTPUT

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

void DrawMainMenu();
void DrawShowMenu();
void DrawRemoveMenu();
void DrawNothing();

class filework {

private:
    vector<string> loaded;

public:
    void load(string filename) {
        ifstream fileread(filename, ios_base::in);
        if (!fileread.is_open()) {
            cout << "ошибка чтения: файл не может быть открыт\n";
        }
        else {
            string buffer;
            while (getline(fileread, buffer)) {
                loaded.push_back(buffer);
            }
            fileread.close();
        }
    }

    void write(string lines) {
        loaded.push_back(lines);
    }

    void remove(int index) {
        if (index >= 0 && index < loaded.size()) {
            loaded.erase(loaded.begin() + index);
        }
        else cout << "ошибка: несуществующий номер строки\n\n";
    }

    void clearall() {
        loaded.clear();
    }

    void save(string filename) {
        ofstream filewrite(filename, ios_base::out);
        if (!filewrite.is_open()) {
            cout << "ошибка записи: файл скорее всего только для чтения\n";
        }
        else {
            for (string t : loaded) {
                filewrite << t << endl;
            }
            filewrite.close();
        }
    }

    void showfile(string filename) {
        ifstream filesee(filename);
        if (!filesee.is_open()) {
            cout << "ошибка чтения: файл не может быть открыт\n";
        }
        else {
            string buffer;
            int i = 0;
            while (getline(filesee, buffer)) {
                cout << i << ": " << buffer << endl;
                i++;
            }
            filesee.close();
        }
    }

    void showstring() {
        for (size_t i = 0; i < loaded.size(); i++) {
            cout << i << ": " << loaded[i] << endl;
        }
    }

    int retunr() {
        return 0;
    }

    void test() {
        cout << loaded.size();
    };

    void replace(int index, string line) {
        if (index >= 0 && index < loaded.size()) {
            loaded[index] = line;
        }
        else cout << "ошибка: неправильный индекс";
    }

    size_t checksize() {
        return loaded.size();
    }
};

bool tryParseInt(const string& s, int& out) { //не обращать внимание код не мой!
    try {
        size_t pos;
        out = stoi(s, &pos);

        // если после числа есть мусор (типа "12abc")
        if (pos != s.size()) return false;

        return true;
    }
    catch (...) {
        return false;
    }
}

int GetIntInput(int min = INT_MIN, int max = INT_MAX, void (*drawMenu)() = DrawNothing) {
    while (true) {
        drawMenu();

        string input1;
        getline(cin, input1);

        int input;

        if (!tryParseInt(input1, input)) {
            cout << "\nошибка: неправильный ввод\n\n";
            continue;
        }

        if (input < min || input > max) {
            cout << "\nошибка: неправильный выбор\n\n";
            continue;
        }

        return input;
    }
}




void WaitEnter() {
    cout << "\nнажмите Enter чтобы продолжить...";
    string temp;
    getline(cin, temp);
}



int main()
{
    setlocale(LC_ALL, "RU");

    filework file;

    enum class Menu { 
        MainMenu,
        LoadMenu, 
        Writemenu, 
        ShowMenu,
        RemoveMenu, 
        SaveMenu, 
        ReplaceMenu 
    };

    enum class showMenu { 
        ShowFileMenu, 
        ShowLoadedMenu 
    }; 

    enum class removeMenu { 
        RemoveLineMenu, 
        RemoveAllMenu 
    };

    Menu menu = Menu::MainMenu;
    showMenu showState = showMenu::ShowFileMenu;
    removeMenu removeState = removeMenu::RemoveLineMenu;

    while (true) {
        switch (menu) {
        case Menu::MainMenu: {
            cout << "==[MAIN MENU]==\n";
            cout << "1. load\n";
            cout << "2. write\n";
            cout << "3. show\n";
            cout << "4. remove\n";
            cout << "5. save\n";
            cout << "6. replace\n";
            cout << "7. exit\n";
            cout << "\n";

            int input = GetIntInput(1, 7, DrawMainMenu);

            switch (input) {
            case 1:
                menu = Menu::LoadMenu;
                break;
            case 2:
                menu = Menu::Writemenu;
                break;
            case 3:
                menu = Menu::ShowMenu;
                break;
            case 4:
                menu = Menu::RemoveMenu;
                break;
            case 5:
                menu = Menu::SaveMenu;
                break;
            case 6:
                menu = Menu::ReplaceMenu;
                break;
            case 7:
                return 0;
                break;
                }
            }
            break;


            case Menu::LoadMenu: {
                cout << "==[LOAD MENU]==\n";
                cout << "enter file name: \n";
                string filename;
                getline(cin, filename);
                file.load(filename);
                //возрат на MainMenu
                cout << "\n";
                menu = Menu::MainMenu;
                continue;
            }
            break;


            case Menu::Writemenu: {
                cout << "==[WRITE MENU]==\n";
                cout << "enter lines: \n";
                string buffer;
                getline(cin, buffer);
                file.write(buffer);
                cout << "\n";
                //возрат на MainMenu
                menu = Menu::MainMenu;
                continue;

            }
            break;


            case Menu::ShowMenu: {
                cout << "==[SHOW MENU]==\n";
                cout << "1. see file\n";
                cout << "2. see loaded\n";
                cout << "3. back\n";
                cout << "\n";

                int input = GetIntInput(1, 3, DrawShowMenu);
                
                //внутреняя развилка на 1, 2 и 3 вариант.
                switch (input) {
                case 1: {
                    cout << "==[SHOW MENU]==\n";
                    cout << "enter file name:\n";
                    string buffer;
                    getline(cin, buffer);
                    cout << "file contains: \n\n";
                    file.showfile(buffer);
                    WaitEnter();
                    cout << "\n";
                    //возрат на MainMenu
                    menu = Menu::MainMenu;
                    continue;
                }
                case 2: {
                    cout << "==[SHOW MENU]==\n";
                    cout << "loaded lines is: \n\n";
                    file.showstring();
                    WaitEnter();
                    cout << "\n";
                    //возрат на MainMenu
                    menu = Menu::MainMenu;
                    continue;
                }
                case 3:
                    //возрат на MainMenu
                    menu = Menu::MainMenu;
                    continue;
                default:
                    cout << "неверный выбор\n\n";
                    break;
                }
            }
            break;


            case Menu::RemoveMenu: {
                cout << "==[REMOVE MENU]==\n";
                cout << "1. remove line\n";
                cout << "2. clear all lines\n";
                cout << "3. back\n";
                cout << "\n";

                int input = GetIntInput(1, 3, DrawRemoveMenu);

                switch (input) {
                case 1: {
                    cout << "==[REMOVE MENU]==\n";
                    cout << "number of line?: \n";
                    string inputbuffer1;
                    getline(cin, inputbuffer1);
                    int inputbuffer = stoi(inputbuffer1);
                    file.remove(inputbuffer);
                    //возрат на MainMenu
                    menu = Menu::MainMenu;
                    continue;
                 }
                case 2: {
                    cout << "==[REMOVE MENU]==\n";
                    file.clearall();
                    cout << "loaded lines cleared\n";
                    //возрат на MainMenu
                    menu = Menu::MainMenu;
                    continue;
                 }
                case 3: 
                    //возрат на MainMenu
                    menu = Menu::MainMenu;
                    continue;
                default:
                    cout << "неверный выбор\n\n";
                    break;
                }
            }
            break;


            case Menu::SaveMenu: {
                cout << "==[SAVE MENU]==\n";
                cout << "enter file name:\n";
                cout << "\n";
                string filename;
                getline(cin, filename);
                file.save(filename);
                //возрат на MainMenu
                menu = Menu::MainMenu;
                continue;
            }
            break;


            case Menu::ReplaceMenu: {
                //replace logic
                cout << "enter number of line: \n";
                
                int input = GetIntInput();

                cout << "\n" << "enter your line: \n";
                string input2;

                getline(cin, input2);
                cout << "\n";
                file.replace(input, input2);
                //возрат на MainMenu
                menu = Menu::MainMenu;
                continue;
            }
            break;
        }
    }
}

void DrawMainMenu() {
    cout << "==[MAIN MENU]==\n";
    cout << "1. load\n";
    cout << "2. write\n";
    cout << "3. show\n";
    cout << "4. remove\n";
    cout << "5. save\n";
    cout << "6. replace\n";
    cout << "7. exit\n";
    cout << "\n";
}

void DrawShowMenu() {
    cout << "==[SHOW MENU]==\n";
    cout << "1. see file\n";
    cout << "2. see loaded\n";
    cout << "3. back\n";
    cout << "\n";
}

void DrawRemoveMenu() {
    cout << "==[REMOVE MENU]==\n";
    cout << "1. remove line\n";
    cout << "2. clear all lines\n";
    cout << "3. back\n";
    cout << "\n";
}

void DrawNothing() {

}
