// http://www.boost.org/doc/libs/1_64_0/libs/smart_ptr/enable_shared_from_this.html
// http://www.drdobbs.com/weak-pointers/184402026

#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <cassert>
#include <iostream>

class Y: public boost::enable_shared_from_this<Y>
{
public:

    boost::shared_ptr<Y> f()
    {
        return shared_from_this();
    }
    ~Y() {std::cout << "~Y" << std::endl;}
};

struct S
{
    boost::shared_ptr<S> dangerous()
    {
        return boost::shared_ptr<S>(this);   // don't do this!
    }
    ~S() {std::cout << "~S" << std::endl;}
};


int main()
{
    boost::shared_ptr<Y> p(new Y);
    boost::shared_ptr<Y> q = p->f();
    assert(p == q);
    assert(!(p < q || q < p)); // p and q must share ownership

    boost::shared_ptr<S> sp1(new S);
    boost::shared_ptr<S> sp2 = sp1->dangerous();
}
