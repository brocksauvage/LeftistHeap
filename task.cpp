#include "task.hpp"
#include "util.hpp"

Task::Task(int id, int p, int aid, int t): tid(id), nice(p), appId(aid), ttl(t) {
  left = nullptr;
  right = nullptr;
}

Task::Task(std::string task){
  //IMPLEMENT_ME();
  int iterator = 0;
  left = nullptr;
  right = nullptr;
  for(int i = 0; i < task.size(); i++){
    if(task[i] != '(' && task[i] != ')' && task[i] != ' ' && task[i] != ',')
    {
      switch(iterator){
        case 0:
          tid = atoi(&task[i]);
          break;
        case 1:
          nice = atoi(&task[i]);
          break;
        case 2:
          appId = atoi(&task[i]);
          break;
        case 3:
          ttl = atoi(&task[i]);
          break;
      }
        iterator++;
    }
  }
  rank = 0;
}

int Task::getTid() {
  return this->tid;
}

int Task::getNice() {
  return this->nice;
}

int Task::getAppId(){
  return this->appId;
}

int Task::getTtl(){
  return this->ttl;
}

Task* Task::getLeft(){
  return this->left;
}

Task* Task::getRight(){
  return this->right;
}

void Task::setLeft(Task* left){
  this->left = left;
}

void Task::setRight(Task* right){
  this->right = right;
}

int Task::getRank(){
  return this->rank;
}

void Task::setRank(int rank){
  this->rank = rank;
}

int Task::getSize(){
  return this->size;
}

void Task::setSize(int size){
  this->size = size;
}
