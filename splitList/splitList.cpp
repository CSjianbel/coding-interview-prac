#include <iostream>
using namespace std;

/*
 * Porblem Statement:
 *
 * Split Linked List:
 *
 * - Given a singly linked list
 * - Split the list in half 
 * - Your function must return the head of the second half of the List
 * - In the case of odd length lists, the first half will have the extra node
 * - The first half must also be disconnected from the seccond half
 */
struct Node {
  int data;
  Node* next;

  Node(int _d, Node* _n) : data(_d), next(_n) {}
};

void prepend(Node **head, int data) {
  Node *newNode = new Node(data, *head);
  *head = newNode;
}

void print(Node *head) {
  while (head) {
    cout << head->data << ' ';
    head = head->next;
  }
  cout << endl;
}

void deleteList(Node *head) {
  while (head) {
    Node* tmp = head;
    head = head->next;
    delete tmp;
  }
}

Node* splitList(Node *head) {
  Node* tmp = head;
  Node* second_half = head;
  int ctr = 0;


  while (tmp) {
    if (ctr % 2 == 0 && ctr > 0) {
      second_half = second_half->next;
    }

    tmp = tmp->next;
    ctr++;
  }

  tmp = second_half;
  second_half = second_half->next;
  tmp->next = NULL;

  return second_half;
}


int main(void) {
  Node *head = NULL;
  int n;
  cin >> n;

  while (n--) {
    int tmp;
    cin >> tmp;
    prepend(&head, tmp);
  }

  cout << "Input list: ";
  print(head);

  Node* second_half = splitList(head);

  cout << "First half: ";
  print(head);
  cout << "Second half: ";
  print(second_half);

  return 0;
}
