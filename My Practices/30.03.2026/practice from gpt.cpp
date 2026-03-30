#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/*
//задание1
class add {
private:
    vector<string> slova;
public:
    void addd(string a) {
        slova.push_back(a);
    };

    void view() {
        for (string t : slova) {
            cout << t << endl;
        }
    }
};

int main() {
    add adddd;
    adddd.addd("banana");
    adddd.addd("apple");
    adddd.addd("orange");
    adddd.view();
}
*/

//задание2
/*
class xd {
public:
    void view(string a) {
        vector<string> burmalda;
        burmalda.push_back(a);
        for (string t : burmalda) {
            cout << t << endl;
        }
    }
};

int main() {
    vector<string> nestring;
    nestring.push_back("tarakan");
    nestring.push_back("kartoshka");
    nestring.push_back("творожок");
    xd xdd;
    //xdd.view(nestring);   //а че так???
    xdd.view("six seveeeen");
}
*/

//задание3
/*
class spisok {
private:
    vector<string> xddd;
public:
    void dobavit(string a) {
        xddd.push_back(a);
    };
    void posmotret() {
        for (string t : xddd) {
            cout << t << endl;
        }
    }
};
int main() {
    spisok xdddd;
    xdddd.dobavit("Учеба");
    vector<string> xd;
    xd.push_back("net");
    //xdddd.dobavit(xd);    //а че так???
    string strelka = "patapim";
    xdddd.dobavit(strelka); //а почему так можно???
    string masiv[1] = { "Игры" };
    //xdddd.dobavit(masiv); //а так почему нельзя?
    xdddd.posmotret();
}
*/

//задача4
/*
class strah {
private:
    vector<string> maboy;
public:
    void udalit(int index) {
        if (index >= 0 && index < maboy.size()) {
            maboy.erase(maboy.begin() + index);
        }
    };
    void dobavit(string textmb) {
        maboy.push_back(textmb);
    };
    void showNOW() {
        for (string txti : maboy) {
            cout << txti << endl;
        };
    };
};
int main() {
    strah nestrashno;
    nestrashno.dobavit("chotka");
    string j = "kriper";
    nestrashno.dobavit(j);
    nestrashno.dobavit("chort");
    nestrashno.showNOW();
    nestrashno.udalit(2);
    nestrashno.showNOW();
}
*/

//задача5
/*
class normaldaki {
private:
    vector<string> qwerty;
public:
    void save(){
        ofstream filesave("todomb.txt", ios_base::out);

        if (!filesave.is_open()) {
            cout << "ошибочка вышла, кент, файл чето не открывается";
        }
        else {
            for (string t : qwerty) {
                filesave << t << endl;
                filesave.close();
            }
        }
    }
    void add(string a) {
        qwerty.push_back(a);
    }
    void showNOWfile() {
        ifstream fileshow("todomb.txt", ios_base::in);
        if (!fileshow.is_open()) {
            cout << "ошибочка вышла, кент, файл чето не открывается";
        }
        else {
            string bufer;
            while (getline(fileshow, bufer)) {
                cout << bufer << endl;
                fileshow.close();
            }
        }

    }
    void showNOWstring() {
        for (string t : qwerty) {
            cout << t << endl;
        }
    }
};
int main() {
    normaldaki burmalda;
    burmalda.add("TripiTropi");
    string a, b, c;
    a = "colt"; b = "volt"; c = "pult";
    burmalda.add("a"); burmalda.add("b"); burmalda.add("c");
    burmalda.showNOWstring();
    burmalda.add("NotInCout");
    burmalda.save();
    cout << "\n\n";
    burmalda.showNOWfile();
}
*/  

//задача6
class noob {
private:
    vector<string> pro;
public:
    //void load(string a) {         //как так сделать чтобы можно было так
    void load() {
        //ifstream loadfile(a);     //как так сделать чтобы можно было так
        ifstream loadfile("todomb.txt");
        if (!loadfile.is_open()) {
            cout << "ошибочка вышла, кент, файл чето не открывается";
        }
        else {
            string mbbufer;
            while (getline(loadfile, mbbufer)) {
                pro.push_back(mbbufer);
            }
            loadfile.close();
        }
    }
    void load2(string filename) {         //как так сделать чтобы можно было так
        ifstream loadfile(filename);     //как так сделать чтобы можно было так
        if (!loadfile.is_open()) {
            cout << "ошибочка вышла, кент, файл чето не открывается";
        }
        else {
            string mbbufer;
            while (getline(loadfile, mbbufer)) {
                pro.push_back(mbbufer);
            }
            loadfile.close();
        }
    }
    void add(string a) {
        pro.push_back(a);
    }
    void remove(int index) {
        if (index >= 0 && index < pro.size()) {
            pro.erase(pro.begin() + index);
        }
    }
    void showALLNOWfile() {
        ifstream loadfile("todomb.txt");
        if (!loadfile.is_open()) {
            cout << "ошибочка вышла, кент, файл чето не открывается";
        }
        else {
            string mbbufer;
            while (getline(loadfile, mbbufer)) {
                cout << mbbufer << endl;
            }
            loadfile.close();
        }
    }
    void showALLNOWstring() {
        for (string t : pro) {
            cout << t << endl;
        }
    }

};
int main() {
    noob realPRO;
    //string a = "hi.txt";  //как так сделать чтобы можно было так
    realPRO.load();             //загрузил в vector<string> pro
    realPRO.showALLNOWstring(); //выгрузил через cout все что было в vector<string> pro
    cout << "\n\n\n";           //просто отступил
    realPRO.remove(3);          //стер 3(4) строку в vector<string> pro
    realPRO.showALLNOWstring(); //выгрузил через cout все что было в vector<string> pro
    cout << "\n";               //просто отступил
    realPRO.showALLNOWfile();   //выгрузил через cout все что было в todomb.txt
    cout << "\n\n";
    realPRO.load2("hi.txt");
    realPRO.showALLNOWstring();

};
