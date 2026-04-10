//TodoFileEditV2.cpp
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
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
            cout << "6. replace\n";
            cout << "7. exit\n";
            cout << "\n";
        }
        else if (menu == 1) {
            cout << "==[load menu]==\n";
            cout << "enter file name: \n";
            string filename;
            getline(cin, filename);
            file.load(filename);
            menu = 0;
            cout << "\n";
            continue;
        }
        else if (menu == 2) {
            cout << "==[write menu]==\n";
            cout << "enter lines: \n";
            string buffer;
            getline(cin, buffer);
            file.write(buffer);
            cout << "\n";
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
            getline(cin, filename);
            file.save(filename);
            menu = 0;
            continue;
        }
        else if (menu == 6) {
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
            menu = 0;
            continue;
        }
        else if (menu == 7) {
            cout << "==[show menu]==\n";
            cout << "enter file name:\n";
            string buffer;
            getline(cin, buffer);
            cout << "file contains: \n\n";
            file.showfile(buffer);
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
            cout << "\n";
            menu = 0;
            continue;
        }
        else if (menu == 9) {
            cout << "==[remove menu]==\n";
            cout << "number of line?: \n";
            string inputbuffer1;
            getline(cin, inputbuffer1);
            int inputbuffer = stoi(inputbuffer1);
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
        else if (menu == 11) {

        }




        string input1;
        getline(cin, input1);

        int input;
        if (!tryParseInt(input1, input)) {
            cout << "\n" << "ошибка: неправильный ввод\n\n";
            continue;
        }
    
        if (menu == 0) {
            if (input == 1) menu = 1;
            else if (input == 2) menu = 2;
            else if (input == 3) menu = 3;
            else if (input == 4) menu = 4;
            else if (input == 5) menu = 5;
            else if (input == 6) menu = 6;
            else if (input == 7) break;
            else cout << "ошибка: неверный ввод\n\n";
        }
        else if (menu == 3) {
            if (input == 1) menu = 7;
            else if (input == 2) menu = 8;
            else if (input == 3) { menu = 0; continue; }
        }
        else if (menu == 4) {
            if (input == 1) menu = 9;
            else if (input == 2) menu = 10;
            else if (input == 3) { menu = 0; continue; }
        }
    }
}
