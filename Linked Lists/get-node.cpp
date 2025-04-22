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
        cout << temp->value << " ";
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

    void prependNode(int value){
      Node* newNode = new Node(value);

      if(length == 0){
        head = newNode;
        tail = newNode;
      } else{
        newNode->next = head;
        head = newNode;
      }
      length++;
    }

    void deleteFirst(){
      if(length == 0) return;
      Node* temp = head;

      if(length == 1){
        head = nullptr;
        tail = nullptr;
      } else{
        head = head->next;
      }

      length--;
      delete temp;
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

    Node* getNode(int index){
      if (index < 0 || index >= length){
        return nullptr;
      }
      Node* temp = head;

      for(int i = 0; i < index; i++){
        temp = temp->next;
      }
      return temp;
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
  LinkedList* myLinkedList = new LinkedList(0);
  myLinkedList->appendNode(1);
  myLinkedList->appendNode(2);
  myLinkedList->appendNode(3);

  cout << "Value: \n";
  cout << myLinkedList->getNode(2)->value;
}