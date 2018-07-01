#include <deque>
#include <string>
#include <ctime>
#include <stdexcept>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

#include "assist.h"

using namespace std;

void test_deque(long& value)
{
    cout << "test_deque()......" << endl;
    deque<string> c;
    char buf[10];
    clock_t timeStart = clock();
    for(long i=0; i<value; ++i)
    {
        try{
            snprintf(buf, 10, "%d", rand() % 10000);
            c.push_back(string(buf));
        }
        catch(exception& p){
            cout << "i=" << i << p.what() << endl;
            abort();
        }
    }

    cout << "milli-seconds:" << clock() - timeStart << endl;
    cout << "deque.size()=" << c.size() << endl;
    cout << "deque.max_size()=" << c.max_size() << endl;
    cout << "deque.front()=" << c.front() << endl;
    cout << "deque.back()=" << c.back() << endl;

    string target = get_a_target_string();
    timeStart = clock();
    deque<string>::iterator pItem = ::find(c.begin(), c.end(), target);  // 调用std的find()
    cout << "::find(), milli-seconds:" << clock() - timeStart << endl;
    if(pItem != c.end())
    {
        cout << "found, " << *pItem << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    timeStart = clock();
    ::sort(c.begin(), c.end());   // 调用std中的sort()
    cout << "c.sort(), milli-seconds:" << clock() - timeStart << endl;
}

int main()
{
    long value = 1000000;
    test_deque(value);

    return 0;
}
