#include<iostream>
#include<string>

using namespace std;

int main()
{
string action;
int num1;
int num2;
cin >> num1;
cin >> action;
cin >> num2;
if (action == "+") {
  cout << "=" << "\n" << num1 + num2;
 }
else if (action == "-") {
 cout << "=" << "\n" << num1 - num2;
 }
else if (action == "*") {
 cout << "=" << "\n" << num1 * num2;
 }
else if (action == "/") {
  cout << "=" << "\n" << num1 / num2;
 }
else {
 printf("не пиши фигню");
 }       
}
