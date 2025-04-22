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

    ~LinkedList(){
      Node* temp = head;
      while(head){
        head = head->next;
        delete temp;
        temp = head;
      }
    }

    void printList(){
      Node* temp = head;

      while(temp){
        cout << temp->value << endl;
        temp = temp->next;
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