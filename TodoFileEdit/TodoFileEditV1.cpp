//TodoFileEditV1.cpp
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

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
            while (getline(filesee, buffer)) {
                cout << buffer << endl;
            }
            filesee.close();
        }
    }

    void showstring() {
        for (string t : loaded) {
            cout << t << endl;
        }
    }

    int retunr() {
        return 0;
    }
};



int main() {
    setlocale(LC_ALL, "RU");
    filework file;
    vector<int> history;

    int menu = 0;

    while (true) {
        if (menu == 0) {
            cout << "1. load\n";
            cout << "2. write\n";
            cout << "3. show\n";
            cout << "4. remove\n";
            cout << "5. save\n";
            cout << "6. exit\n";
            cout << "\n";
        }
        else if (menu == 1) {
            cout << "==[load menu]==\n";
            cout << "enter file name: \n";
            string filename;
            cin >> filename;
            file.load(filename);
            menu = 0;
            cout << "\n";
            continue;
        }
        else if (menu == 2) {
            cout << "==[write menu]==\n";
            cout << "enter lines: \n";
            string buffer;
            cin.ignore();
            getline(cin, buffer);
            file.write(buffer);
            menu = 0;
            continue;
        }
        else if (menu == 3) {
            cout << "==[show menu]==\n";
            cout << "1. see file\n";
            cout << "2. see loaded\n";
            cout << "3. back\n";
            cout << "\n";
        }
        else if (menu == 4) {
            cout << "==[remove menu]==\n";
            cout << "1. remove line\n";
            cout << "2. clear all lines\n";
            cout << "3. back\n";
            cout << "\n";
        }
        else if (menu == 5) {
            cout << "==[save menu]==\n";
            cout << "enter file name:\n";
            cout << "\n";
            string filename;
            cin >> filename;
            file.save(filename);
            menu = 0;
            continue;
        }
        else if (menu == 6) {
            cout << "\n" << "exiting...\n";
            file.retunr();
            menu = 0;
            break;
        }
        else if (menu == 7) {
            cout << "==[show menu]==\n";
            cout << "enter file name:\n";
            string buffer;
            cin >> buffer;
            cout << "file contains: \n\n";
            file.showfile(buffer);
            getchar();
            getchar();
            cout << "\n";
            menu = 0;
            continue;
        }
        else if (menu == 8) {
            cout << "==[show menu]==\n";
            cout << "loaded lines is: \n\n";
            file.showstring();
            getchar();
            getchar();
            cout << "\n";
            menu = 0;
            continue;
        }
        else if (menu == 9) {
            cout << "==[remove menu]==\n";
            cout << "number of line?: \n";
            int inputbuffer;
            cin >> inputbuffer;
            file.remove(inputbuffer);
            menu = 0;
            continue;
        }
        else if (menu == 10) {
            cout << "==[remove menu]==\n";
            file.clearall();
            cout << "loaded lines cleared\n";
            menu = 0;
            continue;
        }


        int input;
        cin >> input;

        if (menu == 0 && input == 6) { 
            break;
        }
        else if (menu == 4 && input == 3) {
            menu = 0;
            continue;
        }
        else if (menu == 3 && input == 3) {
            menu = 0;
            continue;
        }
        else if (menu == 3 && input == 2) {
            menu = 8;
            continue;
        }
        else if (menu == 3 && input == 1) {
            menu = 7;
            continue;
        }
        else if (menu == 4 && input == 1) {
            menu = 9;
            continue;
        }
        else if (menu == 4 && input == 2) {
            menu = 10;
            continue;
        }
        else if (menu == 0 && input > 6) {
            cout << "действие указано не верно\n";
            continue;
        }
        else {
            cout << "действие указано не верно\n";
        }
        
        

        history.push_back(menu);
        menu = input;
    }
}
//i make it 31.03.2026-01.04.2026
