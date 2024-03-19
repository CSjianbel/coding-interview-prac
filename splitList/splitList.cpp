#include <iostream>
using namespace std;

// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 NULL
//                                    ^
// tmp
//                ^
// res
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

  print(head);

  Node* second_half = splitList(head);

  print(head);
  print(second_half);

  return 0;
}
