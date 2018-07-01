#include <map>
#include <string>
#include <ctime>
#include <stdexcept>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include "assist.h"

using namespace std;

void test_multimap(long& value)
{
    multimap<long, string> c;
    char buf[10];
    clock_t timeStart = clock();

    for(long i=0; i<value; ++i)
    {
        try{
            snprintf(buf, 10, "%d", rand() % 10000);
            c.insert(pair<long, string>(i, buf));   // 
        }
        catch(exception& p){
            cout << "i=" << i << " " << p.what() <<endl;
            abort();
        }
    }

    cout << "milli-seconds:" << clock() - timeStart << endl;
    cout << "multimap.size() = " << c.size() << endl;
    cout << "multimap.max_size() = " << c.max_size() << endl;

    long target = get_a_target_long();
    timeStart = clock();
    auto pIt = c.find(target);
    cout << "find(), milli-seconds:" << clock() - timeStart << endl;

    if( pIt != c.end() )
    {
        cout << "found, " << (*pIt).second << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}

int main()
{
    long value = 1000000;
    test_multimap(value);
    return 0;
}
