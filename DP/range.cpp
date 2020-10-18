#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
#include <algorithm>



class range
{
public:
    range(int end) : _end(end), _begin(0), _step(1) {}
    range(int begin, int end, int step=1) : _begin(begin), _end(end), _step(step) {
        if (!_step) // 步长为0, 设为默认值1
            _step = 1;
    }


    class iterator
    {
    public:
        iterator(int x, int s=1) : n(x), step(s) {}
        ~iterator() = default;

        iterator &operator++() {
            n += step;
            return *this;
        }

        bool operator!=(const iterator &x) {
            return (step>0)? n<x.n : n>x.n;
        }

        int &operator*() {
            return n;
        }

    private:
        int n, step;
    };

    iterator begin()
    {
        return iterator(_begin, _step);
    }
    iterator end()
    {
        return iterator(_end, _step);
    }

private:
    int _begin, _end, _step;
};



// for(auto &p : obj) 实际上会被展开为
// for(auto it=obj.begin(); it!=obj.end(); ++it)
// 对于一个obj，其可以使用 range for 的条件是，obj 有至少有两个函数，obj.begin() 和 obj.end()。
// 这两个函数返回相同的类型，这个返回类型我们称为 obj 的迭代器
// 除了 obj 满足有这两个函数之外，还要求 obj 的迭代器满足下列三个条件
// 有前置++算符，（展开中的 ++it 要用）
// 有不等于判断算符，（终止条件是用不等于算符判断的）
// 有解应用算符，因为 range for 得到的是迭代器的解引用
int main(int argc, char const *argv[])
{


    for(auto i: range(10))
    std::cout << i << std::endl;

    for(auto i: range(10, 100))
        std::cout << i << std::endl;

    for(auto i: range(10, 100, 2))
        std::cout << i << std::endl;

    for(auto i: range(100, 10, -2))
        std::cout << i << std::endl;
    return 0;
}
