#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>	// RAND_MAX

using namespace std;

// 输入最大值, RAND_MAX
long get_a_target_long()
{
	long target = 0;

	cout << "target (0~" << RAND_MAX << "):";
	cin >> target;

	return target;
}

// 将数值转化为string 
string get_a_target_string()
{
	int target = 0;
	char buf[10];

	cout << "target (0~" << RAND_MAX << "):";
	cin >> target;
	snprintf(buf, 10, "%d", target);

	return string(buf);
}

// 比较两个long是否相等
int compare_longs(const void* a, const void* b)	// 没有理解为什么return int
{
	return ( *(long*)a - *(long*)b );
}

// 比较两个字符串是否相等
int compare_strings(const void* a, const void* b)
{
	if ( *(string*)a > *(string*)b )
	{
		return 1;
	}
	else if ( *(string*)a < *(string*)b )
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
