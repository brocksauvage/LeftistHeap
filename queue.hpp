#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "task.hpp"


struct Node{
  Task* task;
  Node* next;
};

class Queue {

private:

public:

  Queue();

  ~Queue();

  void enqueue(Task* task);

  void traverse(int identity, int (*op)(Task*));

  int size;

  Node* front;

  Node* back;
};

#endif //PRIORITY_QUEUE_HPP defined
