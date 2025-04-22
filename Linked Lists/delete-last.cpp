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

    void appendNode(int value){
      Node* newNode = new Node(value);

      if(length == 0){
        this->head = newNode;
        this->tail = newNode;
      } 
      else {
        tail->next = newNode;
        this->tail = newNode;
      }
      length++;
    }

    void deleteLast(){
      if(length == 0) return;
      Node* temp = head;

      if (length == 1){
        head = nullptr;
        tail = nullptr;
      } else {
        Node* pre = head;

        while(temp->next){
          pre = temp;
          temp = temp->next;
        }
        
        tail = pre;
        tail->next = nullptr;
      }

      length--;
      delete temp;
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
  myLinkedList->appendNode(9);

  cout << "LL now: \n";
  myLinkedList->printList();

  myLinkedList->deleteLast();
  cout << "\nAfter delete last once: \n";
  myLinkedList->printList();

  myLinkedList->deleteLast();
  cout << "\nAfter delete last twice: \n";
  myLinkedList->printList();

  myLinkedList->deleteLast();
  cout << "\nAfter delete last thrice: \n";
  myLinkedList->printList();
}