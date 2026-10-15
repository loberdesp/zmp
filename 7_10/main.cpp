#include "stack.h"
#include <iostream>

#include <vector>
#include <deque>
#include <list>
#include <set>

#include <algorithm>

int main()
{
    // Stack<int> sint;
    // sint.push(10);
    // sint.push(20);
    // sint.push(30);

    // std::cout << sint.pop() << std::endl;
    // std::cout << sint.pop() << std::endl;
    // std::cout << sint.pop() << std::endl;

    std::vector<int> v{100, 200, 300};

    for (auto it = v.begin(); it != v.end(); ++it)
    {
        std::cout << (*it)++ << std::endl;
    }

    for (auto x : v)
    {
        std::cout << x << std::endl;
    }

    std::list<int> vc{1, 2, 3, 4, 5, 4, 6, 3, 7, 4, 2, 6, 9, 5, 2, 4, 7, 4};

    int c = std::count(vc.begin(), vc.end(), 4);

    std::cout << c << std::endl;

    std::sort(vc.begin(), vc.end());

    for (auto x : vc)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}