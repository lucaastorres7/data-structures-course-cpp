#include <iostream>
using namespace std;

class Cookie{
  private:
    string color;

  public:
    Cookie(string color){
      this->color = color;
    }

    string getColor(){
      return color;
    }

    void setColor(string color){
      this->color = color;
    }
};

int main(){
  Cookie *cookie1 = new Cookie("green");
  Cookie *cookie2 = new Cookie("blue");

  cookie1->setColor("purple");

  cout << "Cookie1: " << cookie1->getColor() << endl;
  cout << "Cookie2: " << cookie2->getColor() << endl;
}