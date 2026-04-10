//TodoFileEditV3_3.cpp
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <climits>

//using namespace std;

enum class Menu {
    MainMenu,
    LoadMenu,
    Writemenu,
    ShowMenu,
    RemoveMenu,
    SaveMenu,
    ReplaceMenu,
    Nothing
};

enum class showMenu {
    ShowFileMenu,
    ShowLoadedMenu
};

enum class removeMenu {
    RemoveLineMenu,
    RemoveAllMenu
};

void Drawmenu(Menu menu) {
    switch (menu) {
    case Menu::MainMenu:
        std::cout << "==[MAIN MENU]==\n";
        std::cout << "1. load\n";
        std::cout << "2. write\n";
        std::cout << "3. show\n";
        std::cout << "4. remove\n";
        std::cout << "5. save\n";
        std::cout << "6. replace\n";
        std::cout << "7. exit\n";
        std::cout << "\n";
        break;

    case Menu::ShowMenu:
        std::cout << "==[SHOW MENU]==\n";
        std::cout << "1. see file\n";
        std::cout << "2. see loaded\n";
        std::cout << "3. back\n";
        std::cout << "\n";
        break;

    case Menu::RemoveMenu:
        std::cout << "==[REMOVE MENU]==\n";
        std::cout << "1. remove line\n";
        std::cout << "2. clear all lines\n";
        std::cout << "3. back\n";
        std::cout << "\n";
        break;

    case Menu::Nothing:
        break;
    }
}

class filework {

private:
    std::vector<std::string> loaded;

public:
    void load(std::string filename) {
        std::ifstream fileread(filename, std::ios_base::in);
        if (!fileread.is_open()) {
            std::cout << "ошибка чтения: файл не может быть открыт\n";
        }
        else {
            std::string buffer;
            while (getline(fileread, buffer)) {
                loaded.push_back(buffer);
            }
            fileread.close();
        }
    }

    void write(std::string lines) {
        loaded.push_back(lines);
    }

    void remove(int index) {
        if (index >= 0 && index < loaded.size()) {
            loaded.erase(loaded.begin() + index);
        }
        else std::cout << "ошибка: несуществующий номер строки\n\n";
    }

    void clearall() {
        loaded.clear();
    }

    void save(std::string filename) {
        std::ofstream filewrite(filename, std::ios_base::out);
        if (!filewrite.is_open()) {
            std::cout << "ошибка записи: файл скорее всего только для чтения\n";
        }
        else {
            for (std::string t : loaded) {
                filewrite << t << std::endl;
            }
            filewrite.close();
        }
    }

    void showfile(std::string filename) {
        std::ifstream filesee(filename);
        if (!filesee.is_open()) {
            std::cout << "ошибка чтения: файл не может быть открыт\n";
        }
        else {
            std::string buffer;
            int i = 0;
            while (getline(filesee, buffer)) {
                std::cout << i << ": " << buffer << std::endl;
                i++;
            }
            filesee.close();
        }
    }

    void showstring() {
        for (std::size_t i = 0; i < loaded.size(); i++) {
            std::cout << i << ": " << loaded[i] << std::endl;
        }
    }

    void replace(int index, std::string line) {
        if (index >= 0 && index < loaded.size()) {
            loaded[index] = line;
        }
        else std::cout << "ошибка: неправильный индекс";
    }

    std::size_t checksize() {
        return loaded.size();
    }
};

bool tryParseInt(const std::string& s, int& out) { //не обращать внимание код не мой!
    try {
        std::size_t pos;
        out = stoi(s, &pos);

        // если после числа есть мусор (типа "12abc")
        if (pos != s.size()) return false;

        return true;
    }
    catch (...) {
        return false;
    }
}

int GetIntInput(int min = INT_MIN, int max = INT_MAX, Menu CurrentMenu = Menu::Nothing) {
    while (true) {
        Drawmenu(CurrentMenu);

        std::string input1;
        getline(std::cin, input1);

        int input;

        if (!tryParseInt(input1, input)) {
            std::cout << "\nошибка: неправильный ввод\n\n";
            continue;
        }

        if (input < min || input > max) {
            std::cout << "\nошибка: неправильный выбор\n\n";
            continue;
        }

        return input;
    }
}




void WaitEnter() {
    std::cout << "\nнажмите Enter чтобы продолжить...";
    std::string temp;
    getline(std::cin, temp);
}

int main()
{
    setlocale(LC_ALL, "RU");

    filework file;

    Menu menu = Menu::MainMenu;
    //showMenu showState = showMenu::ShowFileMenu;
    //removeMenu removeState = removeMenu::RemoveLineMenu;

    while (true) {
        switch (menu) {
        case Menu::MainMenu: {

            int input = GetIntInput(1, 7, Menu::MainMenu);

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
                std::cout << "==[LOAD MENU]==\n";
                std::cout << "enter file name: \n";
                std::string filename;
                getline(std::cin, filename);
                file.load(filename);
                //возрат на MainMenu
                std::cout << "\n";
                menu = Menu::MainMenu;
                continue;
            }
            break;


            case Menu::Writemenu: {
                std::cout << "==[WRITE MENU]==\n";
                std::cout << "enter lines: \n";
                std::string buffer;
                getline(std::cin, buffer);
                file.write(buffer);
                std::cout << "\n";
                //возрат на MainMenu
                menu = Menu::MainMenu;
                continue;

            }
            break;


            case Menu::ShowMenu: {

                int input = GetIntInput(1, 3, Menu::ShowMenu);
                
                //внутреняя развилка на 1, 2 и 3 вариант.
                switch (input) {
                case 1: {
                    std::cout << "==[SHOW MENU]==\n";
                    std::cout << "enter file name:\n";
                    std::string buffer;
                    getline(std::cin, buffer);
                    std::cout << "file contains: \n\n";
                    file.showfile(buffer);
                    WaitEnter();
                    std::cout << "\n";
                    //возрат на MainMenu
                    menu = Menu::MainMenu;
                    continue;
                }
                case 2: {
                    std::cout << "==[SHOW MENU]==\n";
                    std::cout << "loaded lines is: \n\n";
                    file.showstring();
                    WaitEnter();
                    std::cout << "\n";
                    //возрат на MainMenu
                    menu = Menu::MainMenu;
                    continue;
                }
                case 3:
                    //возрат на MainMenu
                    menu = Menu::MainMenu;
                    continue;
                default:
                    std::cout << "неверный выбор\n\n";
                    break;
                }
            }
            break;


            case Menu::RemoveMenu: {

                int input = GetIntInput(1, 3, Menu::RemoveMenu);

                switch (input) {
                case 1: {
                    std::cout << "==[REMOVE MENU]==\n";
                    std::cout << "number of line?: \n";
                    std::string inputbuffer1;
                    int inputbuffer = GetIntInput();
                    file.remove(inputbuffer);
                    //возрат на MainMenu
                    menu = Menu::MainMenu;
                    continue;
                 }
                case 2: {
                    std::cout << "==[REMOVE MENU]==\n";
                    file.clearall();
                    std::cout << "loaded lines cleared\n";
                    //возрат на MainMenu
                    menu = Menu::MainMenu;
                    continue;
                 }
                case 3: 
                    //возрат на MainMenu
                    menu = Menu::MainMenu;
                    continue;
                default:
                    std::cout << "неверный выбор\n\n";
                    break;
                }
            }
            break;


            case Menu::SaveMenu: {
                std::cout << "==[SAVE MENU]==\n";
                std::cout << "enter file name:\n";
                std::cout << "\n";
                std::string filename;
                getline(std::cin, filename);
                file.save(filename);
                //возрат на MainMenu
                menu = Menu::MainMenu;
                continue;
            }
            break;


            case Menu::ReplaceMenu: {
                //replace logic
                std::cout << "enter number of line: \n";
                
                int input = GetIntInput(0, INT_MAX, Menu::Nothing);

                std::cout << "\n" << "enter your line: \n";
                std::string input2;

                getline(std::cin, input2);
                std::cout << "\n";
                file.replace(input, input2);
                //возрат на MainMenu
                menu = Menu::MainMenu;
                continue;
            }
            break;
        }
    }
}
//Maybe final version, maked at 11.04.2026
