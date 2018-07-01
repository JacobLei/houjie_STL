#include <unordered_map>
#include <string>
#include <ctime>
#include <stdexcept>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include "assist.h"

using namespace std;

void test_unordered_multimap(long& value)
{
    unordered_multimap<long, string> c;
    char buf[10];
    clock_t timeStart = clock();

    for(long i=0; i<value; ++i)
    {
        try{
            snprintf(buf, 10, "%d", rand() % 10000);
            c.insert(pair<long, string>(i, buf));
        }
        catch(exception& p){
            cout << "i=" << i << " " << p.what() <<endl;
            abort();
        }
    }

    cout << "milli-seconds:" << clock() - timeStart << endl;
    cout << "unordered_multimap.size() = " << c.size() << endl;
    cout << "unordered_multimap.max_size() = " << c.max_size() << endl;

    long target = get_a_target_long();
    {
    timeStart = clock();
    auto pItem = c.find(target);
    cout << "::find(), milli-seconds:" << clock() - timeStart << endl;
    if( pItem != c.end() )
        cout << "found , " << (*pItem).second << endl;
    else
        cout << "not found" << endl;
    
    }
}

int main()
{
    long value = 1000000;
    test_unordered_multimap(value);
    return 0;
}
