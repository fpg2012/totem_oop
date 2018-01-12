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

class Foo {
 public:
  Foo(int a = 0) : a_(a) {}
  void test() const { std::cout << "this example makes no sense" << std::endl; }

 private:
  int a_;
};

class Bar {
 public:
  Bar(int a = 1) : a_(a) {}
  explicit Bar(const Foo foo) : Bar(0) { foo.test(); }

 private:
  int a_;
};

int main() {
  Foo foo(233);
  Bar bar1(foo); // 正确，会输出"this example makes no sense"
  // Bar bar2 = foo; // 错误，隐式转换被阻止
  return 0;
}