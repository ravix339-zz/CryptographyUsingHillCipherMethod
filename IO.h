#include <iostream>
#include <string>
using namespace std;

void Input(int& strsize, int nums[])
{
	string input;//input
	cout << "Enter message to encode:" << endl;
	getline(cin, input);
	strsize = input.size();//size of string
	while (strsize>5000)//if too long
	{
		cout << "Message too long. Try Again: ";
		getline(cin, input);
		strsize = input.size();
	}
	for (int i = 0; i < strsize; ++i)//convert to ints +20
		nums[i] = int(input[i]) + 20;
	nums[strsize] = 0;//adds first zero, as one is always neccesary
	++strsize;//increment size to include zero	3
	while (strsize % 3 != 0)//repeats above process to make length divisible by 3
	{
		nums[strsize] = 0;
		++strsize;
	}
	return;
}
void Output(int nums2[], int numcount)
{
	char out[5000];//char array
	for (int i = 0; i <numcount; ++i)
	{
		if (nums2[i] == 0)//stops if zero found, fail safe
			break;
		out[i] = char(nums2[i]);//cast nums to chars(already in ascii)
		cout << out[i];//display chars(decoded message)
	}
	return;
}
