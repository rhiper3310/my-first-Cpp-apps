#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

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
    }

    void clearall() {
        loaded.clear();
    }

    void save(string filename) {
        ofstream filewrite(filename, ios_base::out);
        if (!filewrite.is_open()) {
            cout << "ошибка записи: фал скорее всего только для чтения\n";
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

            string input1;
            getline(cin, input1);

            int input;
            if (!tryParseInt(input1, input)) {
                cout << "\n" << "ошибка: неправильный ввод\n\n";
                continue;
            }

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
            default:
                cout << "неверный выбор\n";
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

                string input1;
                getline(cin, input1);

                int input;
                if (!tryParseInt(input1, input)) {
                    cout << "\n" << "ошибка: неправильный ввод\n\n";
                    continue;
                }
                //внутреняя развилка на 1, 2 и 3 вариант.
                switch (input) {
                case 1: {
                    cout << "==[SHOW MENU]==\n";
                    cout << "enter file name:\n";
                    string buffer;
                    getline(cin, buffer);
                    cout << "file contains: \n\n";
                    file.showfile(buffer);
                    getchar();
                    cout << "\n";
                    //возрат на MainMenu
                    menu = Menu::MainMenu;
                    continue;
                }
                case 2: {
                    cout << "==[SHOW MENU]==\n";
                    cout << "loaded lines is: \n\n";
                    file.showstring();
                    getchar();
                    cout << "\n";
                    //возрат на MainMenu
                    menu = Menu::MainMenu;
                    continue;
                }
                case 3:
                    //возрат на MainMenu
                    menu = Menu::MainMenu;
                    continue;
                }
            }
            break;


            case Menu::RemoveMenu: {
                cout << "==[REMOVE MENU]==\n";
                cout << "1. remove line\n";
                cout << "2. clear all lines\n";
                cout << "3. back\n";
                cout << "\n";

                string input1;
                getline(cin, input1);

                int input;
                if (!tryParseInt(input1, input)) {
                    cout << "\n" << "ошибка: неправильный ввод\n\n";
                    continue;
                }

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
                    cout << "==[remove menu]==\n";
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
                }
            }
            break;


            case Menu::SaveMenu: {
                cout << "==[save menu]==\n";
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
                string input1;
                getline(cin, input1);

                int input;
                if (!tryParseInt(input1, input)) {
                    cout << "\n" << "ошибка: неправильный ввод\n\n";
                    continue;
                }
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
