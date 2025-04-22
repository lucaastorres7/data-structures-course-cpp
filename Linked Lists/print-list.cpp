#include <iostream>
using namespace std;

class Node{
  public:
    int value;
    Node* next;

  Node(int value){
    this->value = value;
    this->next = nullptr;
  }
};

class LinkedList{
  private:
    Node* head;
    Node* tail;
    int length;

  public:
    LinkedList(int value){
      Node* newNode = new Node(value);
      head = newNode;
      tail = newNode;
      length = 1;
    }

    void printList(){
      Node* temp = head;

      while(temp){ // é o mesmo que (temp != nullptr)
        cout << temp->value << endl; // printa o valor do nó
        temp = temp->next; // vai para o próximo nó até o nullptr
      }
    }

    void getHead(){
      cout << "Head: " << head->value << endl;
    }

    void getTail(){
      cout << "Tail: " << tail->value << endl;
    }

    void getLength(){
      cout << "Length: " << length << endl;
    }
};

int main(){
  LinkedList* myLinkedList = new LinkedList(4);

  myLinkedList->getHead();
  myLinkedList->getTail();
  myLinkedList->getLength();
  myLinkedList->printList();
}