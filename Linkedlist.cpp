#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;
struct node{
  int data;
  node* next;
};

class Linkedlist{
private:
  node* head;
  node* tail;
  int count;
public:
  Linkedlist();
  void createListofNodes(int value);
  int getSizeofList();
  void printList();
  void insertBefore(int value);
  void inserAtPosition( int value, int position);
  void deleteBefore();
  void deleteAfter();
  void deleteAtPosition(int position);
  bool find(int target);
};

Linkedlist::Linkedlist(){
  head = NULL;
  tail = NULL;
  count=0;
}
//We first create a node, check if the linkedlist is empty to make the new node a head and tail,
//If it is  not empty,  we insert the new created node to the end.
void Linkedlist::createListofNodes(int value){
  node* temp = new node();
  temp -> data = value;
  temp -> next = NULL;
  if(head == NULL){
    head = temp;
    tail = temp;
    count++;
    temp=NULL;
  }else{
    tail -> next = temp;
    tail = temp;
    count++;
  }

}

void Linkedlist::printList(){
  node* temp = new node();
  temp = head;
  while(temp != NULL){
    cout << temp->data << " ";
    temp = temp -> next;
  }
  cout<<endl;
 }

 void Linkedlist:: insertBefore(int value){
   node* temp = new node();
   temp -> data = value;
   temp -> next = head;
   head = temp;
   temp=NULL;
   count++;
 }

 // This function insert a node at a specific position other than first and last
void Linkedlist:: inserAtPosition(int value, int position){
  if(position < count){    // we need to check the list size first to see if position is a valid input
    node* current = new node();
    node* previous = new node();
    node* nextNode = new node();
    current=head;
    for(int i = 1; i < position; i++ ){
      current = current -> next;
      if ( i == position - 2 ){
        previous = current;
      }
    }
    nextNode = current;
    node* temp = new node();
    temp -> data = value;
    temp -> next = NULL;
    current = temp;
    current -> next = nextNode;
    previous -> next = current;
    temp = NULL;
    count++;

  }else{
    cout<< " Invalid position"<<endl;
  }


}
int Linkedlist:: getSizeofList(){
  return count;
}
void Linkedlist:: deleteBefore(){
   node* temp = new node();
   temp = head;
   head = head -> next;
   temp = NULL;
   count--;

}

void Linkedlist:: deleteAfter(){
  node* temp = new node();
  node* previous = new node();
  temp = head;
  while(temp -> next != NULL){
    previous = temp;
    temp = temp -> next;
  }
  previous -> next = NULL;
  tail = previous;
  temp =NULL;
  previous = NULL;
  count--;
}

void Linkedlist:: deleteAtPosition(int position){
  node* current = new node();
  node* previous = new node();
  current= head;
  for(int i = 1; i < position; i++){
    current = current -> next;
    if ( i == position - 2 ){
      previous = current;
    }
  }
  previous -> next = current -> next;
  current = NULL;
  count--;
}
int main(int argc, char* argv[]){
  Linkedlist list;
vector<int> datas = {1,3,2,4,8,5};

for(int x: datas){
  list.createListofNodes(x);
}
cout<<" Before inserting element in front: " << endl;
list.printList();

cout<<" After inserting elements in front: " << endl;
list.insertBefore(7);
list.insertBefore(15);
list.printList();
cout<<" After adding an element at a specific position: " << endl;
list.inserAtPosition(9,3);
list.printList();
cout<<" After deleting the first node: " << endl;
list.deleteBefore();
list.printList();
cout<<" After deleting the last node: " << endl;
list.deleteAfter();
list.printList();
cout<<" After deleting the node at a specific position: " << endl;
list.deleteAtPosition(5);
list.printList();

string text = "abanw";

int x = text[4];
cout << "x: " << x << endl;

  return 0;
}
