#include "Matrix.h"
#include "IO.h"
#include "Fileio.h"

void ENCODE()
{

	int mat[3][3], nums[5001], strsize;//matrix key, number versions of input, number of characters
	Input(strsize, nums);//gets input, makes it divisible by 33 by adding zeros
	GEN(mat);//generate matrix
	write(mat, strsize, nums);// write the matrix and multiplied numbers to file
	return;
}
void DECODE()
{
	int nums2[5000];//numbers to be converted to chars
	int numcount = 0;//incremented while nums2 is not zero, length of string
	read(numcount, nums2);//read out numbers, multiply them by inverse
	Output(nums2, numcount);//display chars
	cout << endl;
	return;
}
