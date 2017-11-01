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
}

PriorityQueue::PriorityQueue(Task* tasks, int taskSize){
  //IMPLEMENT_ME();
  root = tasks;
}

PriorityQueue::~PriorityQueue() {
  IMPLEMENT_ME();
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
  else if(h2 == nullptr){
    return h1;
  }
  else if(h1->getTid() > h2->getTid()){
    Task* temp = h1->getLeft();
    h1->setLeft(h2->getLeft());
    h2->setLeft(temp);
    temp = h1->getRight();
    h1->setRight(h2->getRight());
    h2->setRight(temp);
    temp = h1;
    h1 = h2;
    h2 = temp;
  }
  h1->setRight(merge(h1->getRight(), h2));
  h1->setRank(computeRank(h1));
  if(h1->getLeft()->getRank() < h1->getRight()->getRank()){
    Task* swap = h1->getLeft();
    h1->setLeft(h1->getRight());
    h1->setRight(swap);
  }
  return h1;
}

void PriorityQueue::concat(PriorityQueue* that){
  //IMPLEMENT_ME();
  if(this->root == nullptr || that->root == nullptr){
    return;
  }
  else{
      if(this->root > that->root){
        Task* temp = this->root;
        this->root = that->root;
        that->root = temp;
      }

      this->root->setRight(merge(this->root->getRight(), that->root));
      computeRank(this->root);
      if(this->root->getLeft()->getRank() < this->root->getRight()->getRank()){
        Task* temp = this->root->getLeft();
        this->root->setLeft(this->root->getRight());
        this->root->setRight(temp);
      }
  }
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
  PriorityQueue* newQueue = new PriorityQueue(task, task->getSize());
  concat(newQueue);
}

Task* PriorityQueue::deleteMinElem(){
  //IMPLEMENT_ME();
  Task* deleteElem = this->root;
  Task* rightTree = this->root->getRight();
  this->root = this->root->getLeft();
  PriorityQueue* newQueue = new PriorityQueue(rightTree, rightTree->getSize());
  concat(newQueue);
  return deleteElem;
}

int PriorityQueue::inorderTraversal(int identity, int (*op)(Task*)){
  IMPLEMENT_ME();
  return 0;
}

int PriorityQueue::postorderTraversal(int identity, int (*op)(Task*)){
  IMPLEMENT_ME();
  return 0;
}
