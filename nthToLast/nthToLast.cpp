#include <iostream>
using namespace std;

/*
 * Problem Statement:
 *
 * Nth-to-last Linked List Element
 *
 * - Given a singly linked list
 * - Create a function that returns the nth-to-last element of the list
 * 
 * e.g.
 *
 * 1 -> 2 -> 3 -> 4 -> 5 -> NULL
 *
 * N = 3
 *
 * nth-to-last-element = 3
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

/*
 * Brute force: O(2N)
 *  1. Traverse the list to find its element
 *  2. Traverse the list from 1 to length - N 
 *
 * 2-Pointer Approach: O(N)
 *  1. Traverse the list
 *     - For each node of the list
 *     - 
 *  
 * N = 3 
 *
 * 1 -> 2 -> 3 -> 4 -> 5 -> NULL
 *                     ^
 * curr
 *           ^
 * res
 *
 */
int nthToLastElement(Node *head, int N) {
  Node *curr = head;
  Node *res = NULL;

  while (curr) {

    if (N == 1) res = head;
    if (N < 1) res = res->next;
     
    N--;
    curr = curr->next;
  }

  return res->data;

  // int length = 0;
  // Node *tmp = head;
  // while (tmp) {
  //   length++;
  //   tmp = tmp->next;
  // }
  //
  // for (int i = 0; i < length - N; i++) {
  //   head = head->next;
  // }
  //
  // return head->data;
}

int main(void) {
  Node *head = NULL;
  prepend(&head, 5);
  prepend(&head, 4);
  prepend(&head, 3);
  prepend(&head, 2);
  prepend(&head, 1);
  print(head);
  
  int n;
  cin >> n;

  int res = nthToLastElement(head, n);
  cout << res << '\n';

  deleteList(head);
  return 0;
}
