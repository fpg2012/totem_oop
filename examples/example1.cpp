/*
** author: fpg2012 
** email: fpg2012@foxmail.com
** license: the MIT license
** date: Jan 1st, 2018
**
** copyright 2018 fpg2012
** ALL RIGHTS RESERVED
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 重要的前置声明 
class Course;

class Student {
 public:
  Student() = default;
  Student(const string name) : name_(name) {}
  Student(const Student&);
  ~Student() = default;
  void joinCourse(Course *course);
  const string getName() const { return name_; }
 private:
  string name_;
  Course *course_;
};

class Course {
 public:
  Course() = default;
  Course(string name) : name_(name) {}
  Course(const Course&);
  ~Course() = default;
  void addStudent(Student *student);
  void printMembers () const;
 private:
  vector<Student*> members_;
  string name_;
};

void Course::addStudent(Student *student) { members_.push_back(student); }

void Course::printMembers () const {
  cout << "Members of " << name_ << " :" << endl;
  for(auto stu : members_) {
    cout << stu->getName() << endl;
  }
  cout << endl;
}

void Student::joinCourse(Course *course) {
  course_ = course;
  // 这里用了this 
  course->addStudent(this);
}

int main(){
  Student a("Wallace"), b("Einstain"), c("Newton");
  Course oi("Oi"), math("Math");
  a.joinCourse(&oi);
  b.joinCourse(&math);
  c.joinCourse(&math);
  oi.printMembers();
  math.printMembers();
	return 0;
}
