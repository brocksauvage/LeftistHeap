#include "priority-queue.hpp"
#include "util.hpp"


///////////////////////////////////
// Private Functions Definitions //
///////////////////////////////////

//////////////////////////////////
// Public functions Definitions //
//////////////////////////////////

PriorityQueue::PriorityQueue(){
  //IMPLEMENT_ME();
  root = nullptr;
  size = 0;
}

PriorityQueue::PriorityQueue(Task* tasks, int taskSize){
  //IMPLEMENT_ME();
  root = tasks;
  size = taskSize;
}

PriorityQueue::~PriorityQueue() {
  //IMPLEMENT_ME();
  int (*deleteFunction)(Task*);
  deleteFunction = &deleteHelper;
  postorderTraversal(0, deleteFunction);
}

Task* PriorityQueue::getRoot(){
  return this->root;
}

int PriorityQueue::getSize(){
  return this->size;
}

Task* PriorityQueue::merge(Task* h1, Task* h2){

  if(h1 == nullptr){
    return h2;
  }
  else if(h2== nullptr){
    return h1;
  }
  else{
      if(h1->getNice() > h2->getNice()){
        Task* temp = h1;
        h1 = h2;
        h2 = temp;
      }

      h1->setRight(merge(h1->getRight(), h2));
      computeRank(h1);

      if(h1->getLeft()->getRank() < h1->getRight()->getRank()){
        Task* temp = h1->getLeft();
        h1->setLeft(h1->getRight());
        h1->setRight(temp);
      }
  }
  return h1;
}

void PriorityQueue::concat(PriorityQueue* that){
  //IMPLEMENT_ME();
  this->root = merge(this->root, that->root);
}

int PriorityQueue::computeRank(Task* task){
  int rank = 0;
  Task* temp = task;
  while(temp->getLeft() != nullptr || temp->getRight() != nullptr){
    if(temp->getRight() != nullptr){
      temp = temp->getRight();
    }
    else if(temp->getLeft() != nullptr){
      temp = temp->getLeft();
    }
    rank++;
  }
  return rank;
}
void PriorityQueue::addElem(Task* task) {
  //IMPLEMENT_ME();
  this->size += task->getTtl();
  PriorityQueue* newQueue = new PriorityQueue(task, task->getTtl());
  concat(newQueue);
}

Task* PriorityQueue::deleteMinElem(){
  //IMPLEMENT_ME();
  if(this->root != nullptr){
    Task* deleteElem = this->root;
    Task* rightTree = this->root->getRight();
    this->root = this->root->getLeft();
    this->size -= deleteElem->getTtl();
    PriorityQueue* newQueue = new PriorityQueue(rightTree, rightTree->getTtl());
    concat(newQueue);
    return deleteElem;
  }
  return nullptr;
}

int PriorityQueue::inorderTraversal(int identity, int (*op)(Task*)){
  //IMPLEMENT_ME();
  Queue* inorderQueue = new Queue();
  Node* temp = inorderQueue->front;
  inorderQueue->enqueue(this->root);
  while(temp != nullptr){
    if(temp->task->getLeft() != nullptr){
      inorderQueue->enqueue(temp->task->getLeft());
    }
    if(temp->task->getRight() != nullptr){
      inorderQueue->enqueue(temp->task->getRight());
    }
    temp = temp->next;
  }
  inorderQueue->traverse(identity, op);
  return 0;
}

int PriorityQueue::postorderTraversal(int identity, int (*op)(Task*)){
  //IMPLEMENT_ME();
  postOrderHelper(this->root, identity, op);
  return 0;
}

Task* PriorityQueue::postOrderHelper(Task* root, int identity, int (*op)(Task*)){
  if(root->getLeft() != nullptr){
    postOrderHelper(root->getLeft(), identity, op);
  }
  if(root->getRight() != nullptr){
    postOrderHelper(root->getRight(), identity, op);
  }
  op(root);
  return nullptr;
}
