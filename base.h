#pragma once
#include "string"

class Base {
public:
  Base() : age_(0),name_("") { ; }
  virtual ~Base() { ; }

  virtual int age() const { return age_; }
  virtual std::string name() const { return name_; }

  virtual void setAge(int age) { age_ = age; }
  virtual void setName(std::string name) { name_ = name; }

private:
  int age_;
  std::string name_;
};