#include "application.hpp"
#include "priority-queue.hpp"

Application::Application(std::string appString){
  //IMPLEMENT_ME();
  tasks = new PriorityQueue();
  std::string temp = "";
  size = 0;
  int caseVal = 0;
  for(int i = 0; i < appString.length(); i++){
    if(appString[i] == ' '){
      switch(caseVal){
        case 0:
          id = stoi(temp);
          caseVal++;
          temp = "";
          break;
        case 1:
          name = temp;
          caseVal++;
          temp = "";
          break;
      }

    }
    else if(appString[i] == ')'){
      temp = temp + appString[i];
      Task* newTask = new Task(temp);
      tasks->addElem(newTask);
      size++;
      temp = "";
    }
    else{
      temp = temp + appString[i];
    }
  }
}


Application::Application(int i,
                         std::string appName,
                         Task* ts,
                         int size){
  //IMPLEMENT_ME();
  id = i;
  name = appName;
  tasks = new PriorityQueue(ts, ts->getTtl());
  this->size = size;
}

int Application::getId(){
  return this->id;
}


std::string Application::getName(){
  return this->name;
}



PriorityQueue* Application::getTasks(){
  return this->tasks;
}



int Application::getSize(){
  //IMPLEMENT_ME();
  return this->size;
}
