#include <set>
#include <string>
#include <ctime>
#include <stdexcept>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include "assist.h"

using namespace std;

void test_multiset(long& value)
{
    multiset<string> c;
    char buf[10];
    clock_t timeStart = clock();

    for(long i=0; i<value; ++i)
    {
        try{
            snprintf(buf, 10, "%d", rand() % 10000);
            c.insert(string(buf));
        }
        catch(exception& p){
            cout << "i=" << i << " " << p.what() <<endl;
            abort();
        }
    }

    cout << "milli-seconds:" << clock() - timeStart << endl;
    cout << "multiset.size() = " << c.size() << endl;
    cout << "multiset.max_size() = " << c.max_size() << endl;

    string target = get_a_target_string();
    timeStart = clock();
    multiset<string>::iterator pItem = ::find(c.begin(), c.end(), target);
    cout << "::find(), milli-seconds:" << clock() - timeStart << endl;

    if( pItem != c.end() )
    {
        cout << "found, " << *pItem << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    timeStart = clock();
    multiset<string>::iterator pIt = c.find(target);
    cout << "find(), milli-seconds:" << clock() - timeStart << endl;

    if( pIt != c.end() )
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
    test_multiset(value);
    return 0;
}
