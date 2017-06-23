// https://theboostcpplibraries.com/boost.thread-futures-and-promises

#define BOOST_THREAD_PROVIDES_FUTURE
#include <boost/thread.hpp>
#include <boost/thread/future.hpp>
#include <functional>
#include <iostream>

void accumulate(boost::promise<int> &p)
{
  int sum = 0;
  for (int i = 0; i < 5; ++i)
    sum += i;
  p.set_value(sum);
}

int accumulate_no_args()
{
  int sum = 0;
  for (int i = 0; i < 5; ++i)
    sum += i;
  return sum;
}

int main()
{
  // 1. Using boost::future and boost::promise

  boost::promise<int> p;
  boost::future<int> f = p.get_future();
  boost::thread t{accumulate, std::ref(p)};
  std::cout << f.get() << '\n';

  // 2. Using boost::packaged_task

  boost::packaged_task<int> task{accumulate_no_args};
  boost::future<int> ff = task.get_future();
  boost::thread t2{std::move(task)};
  std::cout << ff.get() << '\n';

  // 3. Using boost::async()
  boost::future<int> fff = boost::async(accumulate_no_args);
  std::cout << fff.get() << '\n';

  return 0;
}
