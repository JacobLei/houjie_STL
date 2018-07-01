#include <unordered_set>
#include <string>
#include <ctime>
#include <stdexcept>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include "assist.h"

using namespace std;

void test_unordered_multiset(long& value)
{
    unordered_multiset<string> c;
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
    cout << "unordered_multiset.size() = " << c.size() << endl;
    cout << "unordered_multiset.max_size() = " << c.max_size() << endl;
    cout << "unordered_multiset.bucket_count() = " << c.bucket_count() << endl;
    cout << "unordered_multiset.load_factor() = " << c.load_factor() << endl;
    cout << "unordered_multiset.max_load_factor() = " << c.max_load_factor() << endl;
    cout << "unordered_multiset.max_bucket_count() = " << c.max_bucket_count() << endl;

    for(unsigned i=0; i<100; i++)
    {
        cout << "bucket #" << i << " has " << c.bucket_size(i) << endl;
    }

    string target = get_a_target_string();
    {
    timeStart = clock();
    auto pItem = ::find(c.begin(), c.end(), target);
    cout << "::find(), milli-seconds:" << clock() - timeStart << endl;
    if( pItem != c.end() )
        cout << "found , " << *pItem << endl;
    else
        cout << "not found" << endl;
    }

    {
    timeStart = clock();
    auto pItem = c.find(target);
    cout << "::find(), milli-seconds:" << clock() - timeStart << endl;
    if( pItem != c.end() )
        cout << "found , " << *pItem << endl;
    else
        cout << "not found" << endl;
    
    }
}

int main()
{
    long value = 1000000;
    test_unordered_multiset(value);
    return 0;
}
