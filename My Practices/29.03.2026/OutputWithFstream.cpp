#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    ofstream create("SO.txt");
    if (!create.is_open()) {
        return 1;
    }
    else {
        create << "продолжи тут:";
        create.close();
    }


    fstream file("SO.txt", ios::in | ios::out);
    if (!file.is_open()) {
        return 1;
    }
    else {
        string text;
        getline(file, text);
        file.clear();
        file.seekp(0, ios::end);
        file << " а че продолжать?";
        file.close();
    }


    fstream troll("SO.txt", ios::in | ios::out);
    if (!troll.is_open()) {
        return 1;
    }
    else {
        string old;
        getline(troll, old);
        troll.clear();
        troll.seekp(0);
        troll << "только не " << old;
        troll.close();
    }


    // вывод результата
    ifstream fin("SO.txt");
    if (!fin.is_open()) {
        return 1;
    }
    else {
        string text;
        getline(fin, text);
        cout << text;
    }
}
