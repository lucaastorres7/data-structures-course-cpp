#include <iostream>
using namespace std;

int main(){
  int* num1 = new int(11);
  int* num2 = num1;

  *num1 = 22;
  int* num3 = new int(33);

  num2 = num3;

  cout << "num1 = " << *num1 << endl;
  cout << "num2 = " << *num2 << endl;
  cout << "num3 = " << *num3 << endl;
}