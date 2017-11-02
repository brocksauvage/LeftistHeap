#include "task.hpp"


Task::Task(int id, int p, int aid, int t): tid(id), nice(p), appId(aid), ttl(t) {
  left = nullptr;
  right = nullptr;
}

Task::Task(std::string task){
  //IMPLEMENT_ME();
  int iterator = 0;
  left = nullptr;
  right = nullptr;
  std::string temp = "";
  for(int i = 0; i < task.size(); i++){
    if(task[i] == ',')
    {
      switch(iterator){
        case 0:
          tid = stoi(temp);
          break;
        case 1:
          nice = stoi(temp);
          break;
        case 2:
          appId = stoi(temp);
          break;
        case 3:
          ttl = stoi(temp);
          break;
      }
        iterator++;
        temp = "";
    }
    else if(task[i] != '(' && task[i] != ')' && task[i] != ' '){
      temp = temp+task[i];
    }
  }
  rank = 0;
}

int Task::getTid() {
  if(this != nullptr){
    return this->tid;
  }
  return -1;
}

int Task::getNice() {
  if(this != nullptr){
    return this->nice;
  }
  return -1;
}

int Task::getAppId(){
  if(this != nullptr){
    return this->appId;
  }
  return -1;
}

int Task::getTtl(){
  if(this != nullptr){
    return this->ttl;
  }
  return -1;
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
  if(this != nullptr){
    return this->rank;
  }
  return -1;
}

void Task::setRank(int rank){
  this->rank = rank;
}

int Task::getSize(){
  if(this != nullptr){
    return this->size;
  }
  return -1;
}

void Task::setSize(int size){
  this->size = size;
}
