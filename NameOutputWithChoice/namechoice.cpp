#include<iostream>

using namespace std;

int print(int x);


int main(int argc, char *argv[])
{
setlocale(LC_ALL, "RU");

 
 cout << "enter number:\n";
 cout << "1. Полное имя\n";
 cout << "2. Только имя\n";
 cout << "3. Только фамилия\n";
 cout << "4. Только отчество\n";
 cout << "5. Склонить...\n\n";
 int a;
 cin >> a;
 cout << "\n";
 print(a);
 return 0;
}

int print(int x) {
 if (x == 1) {
  cout << "\nИван Иванович Иванов";
  }
 else if (x == 2) {
  cout << "\nИван"; 
   }
 else if (x == 3) {
  cout << "\nИванов";
  }
 else if (x == 4) {
  cout << "\nИванович";
  }
 else if (x == 5) {
  cout << "\nenter number:\n";
  cout << "1. Полное имя\n";
  cout << "2. Только имя\n";
  cout << "3. Только фамилию\n";
  cout << "4. Только отчество\n";
  cout << "\n";
  int b;
  cin >> b;
  cout << "\n";
  if (b == 1) {
   cout << "Иванов" << "а "<< "Иван" << "а " << "Иванович" << "а" << "\n";
  }
  else if (b == 2) {
    cout << "Иван" << "а" << "\n";
    }
  else if (b == 3) {
   cout << "Иванов" << "а" << "\n";
    }
  else if (b == 4) {
    cout << "Иванов" << "ича" << "\n";
    }
  else {
 cout << "не пиши ерунду";
  }
  }
 else {
 cout << "не пиши ерунду";
  }
  return 0;
 }
