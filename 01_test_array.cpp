#include <array>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "assist.h"

using namespace std;
const long ASIZE = 500000;

void test_array()
{
	cout << "test_array()............" << endl;

	array<long, ASIZE> c;
	clock_t timeStart = clock();

	for(long i=0; i<ASIZE; ++i)
	{
		c[i] = rand() % 100000;
	}

	cout << "milli-seconds: " << (clock() - timeStart) << endl;	// 赋值500000数据所用时间
	cout << "array.size() = " << c.size() << endl;	 
	cout << "array.front() = " << c.front() << endl; //Returns a reference to the first element in the array container
	cout << "array.back() = " << c.back() << endl;	// Returns a reference to the last element in the array container
	cout << "array.data() = " << c.data() << endl;	// Returns a pointer to the first element in the array object
	
	long target = get_a_target_long();	// 输入一个目标数据
	timeStart = clock();
	qsort(c.data(), ASIZE, sizeof(long), compare_longs); // 快排 
	long *pItem = (long*) bsearch(                       // 二分查找
            &target, 
            c.data(), 
            ASIZE, 
            sizeof(long), 
            compare_longs
            );
    cout << "qsort()+bsearch(), milli-seconds: "
        << clock() - timeStart
        << endl;

    if (pItem != NULL)
    {
        cout << "found, " << *pItem << endl;
    }
    else
    {
        cout << "not found" << endl;
    }


}

int main()
{
	test_array();

	return 0;
}
