#include <assert.h>

#include <iostream>
#include <memory>
#include <string>
using namespace std;

int main()
{
    shared_ptr<int> sp(new int(10));
    assert(sp.use_count() == 1);
    weak_ptr<int> wp(sp); //从shared_ptr创建weak_ptr
    assert(wp.use_count() == 1);
    if (!wp.expired()) //判断weak_ptr观察的对象是否失效
    {
        shared_ptr<int> sp2 = wp.lock(); //获得一个shared_ptr
        *sp2 = 100;

        cout << "int sp2:" << *sp2 << endl;
        assert(wp.use_count() == 2);
    }
    assert(wp.use_count() == 1);
    cout << "int:" << *sp << endl;
    return 0;
}