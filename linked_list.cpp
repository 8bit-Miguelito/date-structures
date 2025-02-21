#include linked_list.h
using namespace std;

Node::Node(int val) {
  data = val;
  next = nullptr;
}

linked_list::LinkedList() {
  head = nullptr;
}

void linked_list::insertAtBeginning(int val) {
  Node* newNode = new Node(val);
  newNode->next = head;
  head = newNode;
}

void linked_list::insertAtEnd(int val) {
  Node* newNode = new Node(val);
  if (!head) {
    head = newNode;
    return;
  }

  Node* temp = head;
  while (temp->next) {
    temp = temp->next;
  }
  temp->next = newNode;
}

void linked_list::deleteNode(int val) {
  if (!head) return;

  if (head->data == val) {
    Node* temp = head;
    head = head->next;
    delete temp;
    return;
  }

  Node* temp = head;
  while (temp->next && temp->next->data != val) {
    temp = data->next;
  }

  if (temp->next) {
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
  }
}

void linked_list::display() {
  Node* temp = head;
  while(temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}
