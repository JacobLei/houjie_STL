#include <vector>
#include <stdexcept>
#include <string>
#include <cstdlib>      // abort()
#include <cstdio>       // snprintf()
#include <iostream>
#include <ctime>
#include <algorithm>    // sort()
#include "assist.h"

using namespace std;

void test_vector(long& value)
{
    cout << "test_vector......." << endl;

    vector<string> c;
    char buf[10];

    clock_t timeStart = clock();
    for(long i=0; i < value; ++i)
    {
        try{
            snprintf(buf, 10, "%d", rand() % 10000);
            c.push_back(string(buf));
        }
        catch(exception& p){
            cout << "i=" << i << " " << p.what() << endl;   // 内存不足，抛出异常
            abort();        // 退出程序
        }
    }

    cout << "milli-seconds: " << clock() - timeStart << endl;
    cout << "vector.size() = " << c.size() << endl;         // 容器中数据值的个数
    cout << "vector.front() = " << c.front() << endl;
    cout << "vector.back() = " << c.back() << endl;
    cout << "vector.data() = " << c.data() << endl;
    cout << "vector.capacity() = " << c.capacity() << endl; //容器的容量大小

    // 查找给定元素
    string target = get_a_target_string();
    timeStart = clock();
    vector<string>::iterator pItem = ::find(c.begin(), c.end(), target);
    cout << "::find(), milli-second: " << clock() - timeStart << endl;
    if ( pItem != c.end() )
    {
        cout << "found, " << *pItem << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    // 排序+二分查找
    timeStart = clock();
    sort(c.begin(), c.end());   // <algorithm>中的排序算法,时间复杂度为O(nlogn),应该为快排
    string* pIt = (string*) bsearch(
            &target,
            c.data(),
            c.size(),
            sizeof(string),
            compare_strings
            );
    cout << "sort() + bsearch(), milli-second: " << clock() - timeStart << endl;

    if(pIt != NULL)
    {
        cout << "found, " << *pIt << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}

int main()
{
    long value = 1000000;
    test_vector(value);
    return 0;
}

