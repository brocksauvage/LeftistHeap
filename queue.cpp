#include "queue.hpp"


Queue::Queue(){
  size = 0;
  front = nullptr;
  back = nullptr;
}

Queue::~Queue(){
  Node* temp = front;
  while(front != nullptr){
    front = front->next;
    delete temp;
    temp = front;
  }
}

void Queue::enqueue(Task* task){
  Node* newTask = new Node();
  newTask->next = nullptr;
  newTask->task = task;

  if(size == 0){
    front = newTask;
    back = newTask;
  }
  else{
    newTask->next = back;
    back = newTask;
  }
}

void Queue::traverse(int identity, int (*op)(Task*)){
  Node* temp = front;
  while(temp != nullptr){
    op(temp->task);
    temp = temp->next;
  }
}
