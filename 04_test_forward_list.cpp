#include <forward_list>
#include <string>
#include <ctime>
#include <stdexcept>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

#include "assist.h"

using namespace std;

void test_forward_list(long& value)
{
    cout << "test_forward_list()......" << endl;
    forward_list<string> c;
    char buf[10];
    clock_t timeStart = clock();
    for(long i=0; i<value; ++i)
    {
        try{
            snprintf(buf, 10, "%d", rand() % 10000);
            c.push_front(string(buf));
        }
        catch(exception& p){
            cout << "i=" << i << p.what() << endl;
            abort();
        }
    }

    cout << "milli-seconds:" << clock() - timeStart << endl;
//    cout << "list.size()=" << c.size() << endl;
    cout << "list.max_size()=" << c.max_size() << endl;
    cout << "list.front()=" << c.front() << endl;
//    cout << "list.back()=" << c.back() << endl;

    string target = get_a_target_string();
    timeStart = clock();
    forward_list<string>::iterator pItem = ::find(c.begin(), c.end(), target);  // 调用std的find()
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
    c.sort();   // 调用list中的sort()
    cout << "c.sort(), milli-seconds:" << clock() - timeStart << endl;
}

int main()
{
    long value = 1000000;
    test_forward_list(value);

    return 0;
}
