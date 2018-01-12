/*
** author: fpg2012
** email: fpg2012@foxmail.com
** license: the MIT license
** date: Jan 12th, 2018
**
** copyright 2018 fpg2012
** ALL RIGHTS RESERVED
*/

#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::ostream;
using std::endl;

class Teacher {
 public:
  Teacher();
  Teacher(string name);
  ~Teacher();
  const string getName() const;

 private:
  string name_, number_;
  int age_;
  bool sex_;
};

struct Foo {
  string name, number;
  int age;
  bool sex;
};

class Student {
 public:
  Student();
  Student(string name);
  Student(ostream &os);
  Student(const Teacher teacher);
  ~Student();
  const string getName() const;
  Student &operator=(const Foo foo);

 private:
  string name_, number_;
  int age_;
  bool sex_;
};

Student::Student() = default;
Student::Student(string name) : name_(name) { cout << "HELLO" << endl; }
Student::Student(ostream &os) : name_("hello") { cout << "test!" << endl; }
Student::~Student() = default;
Student::Student(const Teacher teacher) : name_(teacher.getName()) {}
Teacher::~Teacher() = default;
Teacher::Teacher(string name) : name_(name) {}
const string Student::getName() const { return name_; }
const string Teacher::getName() const { return name_; }
Student &Student::operator=(const Foo foo) {
  name_ = foo.name;
  return *this;
}

int main() {
  Student stu1(cout);
  cout << stu1.getName() << endl;
  Teacher tea1("anonymous");
  stu1 = tea1;
  cout << stu1.getName() << endl;
  Foo foo;
  foo.name = "fool";
  stu1 = foo;
  cout << stu1.getName() << endl;
  return 0;
}

// 输出将会如下:
//
// test!
// hello
// anonymous
// fool
//
