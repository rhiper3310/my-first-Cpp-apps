//TodoFileEditV3_4.cpp
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <climits>

//using namespace std;

bool DebugMode = false;

enum class Menu {
    MainMenu,
    LoadMenu,
    Writemenu,
    ShowMenu,
    RemoveMenu,
    SaveMenu,
    ReplaceMenu,
    DevFeaturesMenu,
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
        if (DebugMode == true) std::cout << "вывод главного меню...\n";
        std::cout << "==[MAIN MENU]==\n";
        std::cout << "1. load\n";
        std::cout << "2. write\n";
        std::cout << "3. show\n";
        std::cout << "4. remove\n";
        std::cout << "5. save\n";
        std::cout << "6. replace\n";
        std::cout << "7. devFeatures\n";
        std::cout << "8. exit\n";
        std::cout << "\n";
        break;

    case Menu::ShowMenu:
        if (DebugMode == true) std::cout << "вывод меню вывода...\n";
        std::cout << "==[SHOW MENU]==\n";
        std::cout << "1. see file\n";
        std::cout << "2. see loaded\n";
        std::cout << "3. back\n";
        std::cout << "\n";
        break;

    case Menu::RemoveMenu:
        if (DebugMode == true) std::cout << "вывод меню удаления...\n";
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

class IFileStorage {
public:
    virtual void load(const std::string& filename) = 0;
    virtual void save(const std::string& filename) = 0;
    virtual void write(const std::string& line) = 0;
    virtual void remove(int index) = 0;
    virtual void clearall() = 0;
    virtual void replace(int index, const std::string& line) = 0;
    virtual void showfile(const std::string& filename) = 0;
    virtual void showstring() = 0;
    virtual std::size_t checksize() = 0;
    virtual ~IFileStorage() = default;
};

class filework : public IFileStorage{
private:
    std::vector<std::string> loaded;

public:
    void load(const std::string& filename) override {
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

    void write(const std::string& lines) override {
        
        loaded.push_back(lines);
        
    }

    void remove(int index) override {
        if (index >= 0 && index < loaded.size()) {
            loaded.erase(loaded.begin() + index);
        }
        else std::cout << "ошибка: несуществующий номер строки\n\n";
    }

    void clearall() override {
        loaded.clear();
       
    }

    void save(const std::string& filename) override {
        
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

    void showfile(const std::string& filename) override {
        
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

    void showstring() override {

        for (std::size_t i = 0; i < loaded.size(); i++) {
            std::cout << i << ": " << loaded[i] << std::endl;
        }

    }

    void replace(int index, const std::string& line) override {
        
        if (index >= 0 && index < loaded.size()) {

            loaded[index] = line;

        }
        else std::cout << "ошибка: неправильный индекс";
    }

    std::size_t checksize() override {
        return loaded.size();
    }
};

class LoggingDecorator : public IFileStorage {
private:
    IFileStorage* wrappee;
public:
    LoggingDecorator(IFileStorage* target) : wrappee(target) {}

    void load(const std::string& filename) override {
        if (DebugMode) std::cout << "[LOG] Загрузка файла: " << filename << "\n";
        wrappee->load(filename);
        if (DebugMode) std::cout << "[LOG] Загрузка завершена\n";
    }

    void save(const std::string& filename) override {
        if (DebugMode) std::cout << "[LOG] Сохранение в файл: " << filename << "\n";
        wrappee->save(filename);
        if (DebugMode) std::cout << "[LOG] Сохранение завершено\n";
    }

    void write(const std::string& line) override {
        if (DebugMode) std::cout << "[LOG] Добавление строки: " << line << "\n";
        wrappee->write(line);
    }

    void remove(int index) override {
        if (DebugMode) std::cout << "[LOG] Удаление строки с индексом " << index << "\n";
        wrappee->remove(index);
    }

    void clearall() override {
        if (DebugMode) std::cout << "[LOG] Очистка всех строк\n";
        wrappee->clearall();
    }

    void replace(int index, const std::string& line) override {
        if (DebugMode) std::cout << "[LOG] Замена строки " << index << " на \"" << line << "\"\n";
        wrappee->replace(index, line);
    }

    void showfile(const std::string& filename) override {
        if (DebugMode) std::cout << "[LOG] Показ файла: " << filename << "\n";
        wrappee->showfile(filename);
    }

    void showstring() override {
        if (DebugMode) std::cout << "[LOG] Показ загруженных строк\n";
        wrappee->showstring();
    }

    std::size_t checksize() override {
        if (DebugMode) std::cout << "[LOG] Запрос размера\n";
        return wrappee->checksize();
    }
};

bool tryParseInt(const std::string& s, int& out) { //не обращать внимание код не мой!
    if (DebugMode == true) std::cout << "парсинг введеного...\n";
    try {
        std::size_t pos;
        out = stoi(s, &pos);

        // если после числа есть мусор (типа "12abc")
        if (pos != s.size()) return false;

        return true;
        if (DebugMode == true) std::cout << "парсинг введеного прошел проверку и вернул истину(правду)\n";
    }
    catch (...) {
        return false;
        if (DebugMode == true) std::cout << "парсинг введеного прошел проверку и вернул ложь(неправду)\n";
    }
}

int GetIntInput(int min = INT_MIN, int max = INT_MAX, Menu CurrentMenu = Menu::Nothing) {
    if (DebugMode == true) std::cout << "попытка получения от пользователя целочисленного ввода...\n";
    while (true) {
        Drawmenu(CurrentMenu);

        std::string input1;
        getline(std::cin, input1);

        int input;

        if (!tryParseInt(input1, input)) {
            std::cout << "\nошибка: неправильный ввод\n\n";
            std::cin.clear(); // сбрасываем флаги ошибок (если есть)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очищаем буфер до конца строки
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
    if (DebugMode == true) std::cout << "попытка получения любого ввода для продолжения...\n";
    std::cout << "\nнажмите Enter чтобы продолжить...";
    std::string temp;
    getline(std::cin, temp);
}

int main()
{
    setlocale(LC_ALL, "RU");

    filework core;
    LoggingDecorator logged(&core);
    IFileStorage* storage = nullptr;

    // В зависимости от DebugMode выбираем, что использовать
    if (DebugMode)
        storage = &logged;
    else
        storage = &core;

    Menu menu = Menu::MainMenu;
    //showMenu showState = showMenu::ShowFileMenu;
    //removeMenu removeState = removeMenu::RemoveLineMenu;

    while (true) {
        switch (menu) {
        case Menu::MainMenu: {

            int input = GetIntInput(1, 8, Menu::MainMenu);

            switch (input) {
            case 1:
                menu = Menu::LoadMenu;
                if (DebugMode == true) std::cout << "вход в меню загрузки...\n";
                break;
            case 2:
                menu = Menu::Writemenu;
                if (DebugMode == true) std::cout << "вход в меню записи...\n";
                break;
            case 3:
                menu = Menu::ShowMenu;
                if (DebugMode == true) std::cout << "вход в меню вывода...\n";
                break;
            case 4:
                menu = Menu::RemoveMenu;
                if (DebugMode == true) std::cout << "вход в меню удаления...\n";
                break;
            case 5:
                menu = Menu::SaveMenu;
                if (DebugMode == true) std::cout << "вход в меню сохранения...\n";
                break;
            case 6:
                menu = Menu::ReplaceMenu;
                if (DebugMode == true) std::cout << "вход в меню замены...\n";
                break;
            case 7:
                menu = Menu::DevFeaturesMenu;
                if (DebugMode == true) std::cout << "вход в меню утилит разработчика...\n";
                break;
            case 8:
                if (DebugMode == true) std::cout << "выход из прграммы...\n";
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
                storage->load(filename);
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
                storage->write(buffer);
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
                    storage->showfile(buffer);
                    WaitEnter();
                    std::cout << "\n";
                    //возрат на MainMenu
                    menu = Menu::MainMenu;
                    continue;
                }
                case 2: {
                    std::cout << "==[SHOW MENU]==\n";
                    std::cout << "loaded lines is: \n\n";
                    storage->showstring();
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
                    storage->remove(inputbuffer);
                    //возрат на MainMenu
                    menu = Menu::MainMenu;
                    continue;
                 }
                case 2: {
                    std::cout << "==[REMOVE MENU]==\n";
                    storage->clearall();
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
                storage->save(filename);
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
                storage->replace(input, input2);
                //возрат на MainMenu
                menu = Menu::MainMenu;
                continue;
            }
            break;


            case Menu::DevFeaturesMenu: {
                std::cout << "===[DevFEATURES MENU]===\n";
                std::cout << "1. debug mode(current: " << (DebugMode ? "ON " : "OFF ") << ")\n";
                std::cout << "2. back\n";

                int input = GetIntInput(1, 2, Menu::Nothing);

                switch (input) {
                case 1: {
                    DebugMode = !DebugMode;
                    if (DebugMode) {
                        storage = &logged;
                        std::cout << "Debug mode is now ON\n";
                    }
                    else {
                        storage = &core;
                        std::cout << "Debug mode is now OFF\n";
                    }
                    break;
                }

                case 2: {
                    //возрат на MainMenu
                    menu = Menu::MainMenu;
                    continue;
                 }
                }
            }
                                      break;
        }
    }
}
