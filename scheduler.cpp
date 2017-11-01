#include "scheduler.hpp"
#include "task.hpp"
#include "util.hpp"

Scheduler::Scheduler(){
  this->schedule = new PriorityQueue();
  //IMPLEMENT_ME();
}

void Scheduler::addApplicationToSchedule(Application* app){
  //IMPLEMENT_ME();
    this->schedule->concat(app->getTasks());
}

Task* Scheduler::executeNextOnProcessor(){
  //IMPLEMENT_ME();
  return this->schedule->deleteMinElem();
}

bool Scheduler::isEmpty(){
  if(this->schedule->getRoot() != nullptr){
    return false;
  }
  return true;
}

int Scheduler::scheduleSize(){
  //IMPLEMENT_ME();
  return this->schedule->getSize();
}
