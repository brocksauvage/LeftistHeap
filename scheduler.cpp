#include "scheduler.hpp"
#include "task.hpp"

Scheduler::Scheduler(){
  this->schedule = new PriorityQueue();
  size = 0;
  //IMPLEMENT_ME();
}

void Scheduler::addApplicationToSchedule(Application* app){
  //IMPLEMENT_ME();
  size += app->getSize();
  this->schedule->concat(app->getTasks());
}

Task* Scheduler::executeNextOnProcessor(){
  //IMPLEMENT_ME();
  size--;
  return this->schedule->deleteMinElem();
}

bool Scheduler::isEmpty(){
  if(this->size != 0){
    return false;
  }
  return true;
}

int Scheduler::scheduleSize(){
  //IMPLEMENT_ME();
  return this->size;
}
