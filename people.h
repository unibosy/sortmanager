#pragma once
//#include "base.h"
#include "string"
#include "iostream"

class People /*: public Base*/ {
public:
  People() :height_(0), gender_(-1) { ; }
  ~People() { std::cout << "destruct people" << std::endl; }
  //can only call 'const' members trough references to const
  int age() const { return age_; }
  std::string name() const { return name_; }
  std::string id() { return id_; }
  
  void setID(std::string& id) { id_ = id; }

  void setAge(int age) { age_ = age; }
  void setName(std::string name) { name_ = name; }

  int height() const { return height_; }
  int gender() const { return gender_; }

  void setHeight(int height) { height_ = height_; }
  void setGender(int gender) { gender = gender_; }
private:
  int height_;
  int gender_;//-1:unknown,0:man,1:femal
  int age_;
  std::string name_;
  std::string id_;
};
