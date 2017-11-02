#ifndef UTIL_HPP
#define UTIL_HPP

#include<iostream>
#include<cstdio>

#define IMPLEMENT_ME() printf("unimplmemented %s\n", __PRETTY_FUNCTION__)


int dummy(int a, int b);

int print(Task* root){
  std::cout << root->getTid() << "(" << root->getAppId() << ")" << " ";
  return 0;
}

int deleteHelper(Task* root){
  delete root;
  return 0;
}

#endif //UTIL_HPP defined
