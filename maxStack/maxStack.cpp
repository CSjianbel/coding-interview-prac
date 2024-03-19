#include <iostream>
#include <limits.h>
using namespace std;

/*
 * Problem Statement:
 * 
 * Max Stack:
 *
 * - Design a Stack data structure
 * - Operations: Push, Pop, Max Val 
 * - All operations must run on O(1) time complexity
 */

struct StackNode {
  int m_data;
  StackNode* m_next;
  int m_prev_max;

  StackNode(int data, StackNode* next, int prev_max) : m_data(data), m_next(next), m_prev_max(prev_max) {}
};

class Stack {
  StackNode* m_head;
  int m_max_value;

public:
  void push(int x);
  void pop();
  int top();
  int maxValue();
  bool isEmpty();

  Stack() : m_head(NULL), m_max_value(INT_MIN) {}
  ~Stack();
};

Stack::~Stack() {
  while (!this->isEmpty()) {
    this->pop();
  }
}

void Stack::push(int x) {
  StackNode* new_node = new StackNode(x, this->m_head, this->m_max_value);
  this->m_max_value = max(this->m_max_value, x);
  this->m_head = new_node;
}


void Stack::pop() {
  m_max_value = this->m_head->m_prev_max;
  StackNode* tmp = this->m_head;
  this->m_head = this->m_head->m_next;
  delete tmp;
}

int Stack::top() {
  return this->m_head->m_data;
}

int Stack::maxValue() {
  return this->m_max_value;
}

bool Stack::isEmpty() {
  return this->m_head;
}

int main(void) {
  Stack stack;

  stack.push(5);
  stack.push(4);
  stack.push(3);
  stack.push(2);
  stack.push(1);
  cout << stack.maxValue() << endl;
  stack.push(10);
  cout << stack.maxValue() << endl;
  stack.pop();
  cout << stack.maxValue() << endl;
  return -1;
}

