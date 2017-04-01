#include "boost/bind.hpp"
#include "boost/function.hpp"
#include "iostream"

typedef boost::function<void()> F1;
typedef boost::function<void(int, int)> F2;

void overload() {
   std::cout << "param = " << std::endl;
}

void action (F2 f) {
  f(1,1);
}

class Class
{
 public: // interface
  void overload(int param1, int param2) {
    std::cout << "param1 = " << param1 << " ,param2 = " << param2 << std::endl;
  }
};


int main(int arg, char** argv)
{
  F1 f1;
  F2 f2;

  f1 = boost::bind(overload); // can bind normally

  Class* objPtr = new Class();
  f2 = boost::bind(&Class::overload, objPtr, _1, _2);

  //f1();
  f2(2,3);

  //action (f1);
  action (boost::bind(overload));
}
