#include <ctime>
using namespace std;
void GEN(int key[][3])
{
	double det;
	srand(time(0));//seeded rand
	do
	{
		for (int i = 0; i<3; ++i)
		for (int j = 0; j<3; ++j)
			key[i][j] = rand() % 1000;//%1000 keeps numbers small enough for data types to handle
		det = (key[0][0] * key[1][1] * key[2][2])
			+ (key[0][1] * key[1][2] * key[2][0])
			+ (key[0][2] * key[1][0] * key[2][1])
			- (key[0][2] * key[1][1] * key[2][0])
			- (key[0][1] * key[1][0] * key[2][2])
			- (key[0][0] * key[1][2] * key[2][1]);//determinant, diagonals
	} while (det == 0);
	return;
}

void INVERTER(int a[][3], long double inv[][3])
{

	double det;//determinant
	det = (a[0][0] * a[1][1] * a[2][2])
		+ (a[0][1] * a[1][2] * a[2][0])
		+ (a[0][2] * a[1][0] * a[2][1])
		- (a[0][2] * a[1][1] * a[2][0])
		- (a[0][1] * a[1][0] * a[2][2])
		- (a[0][0] * a[1][2] * a[2][1]);//diagonals
	inv[0][0] = ((a[1][1] * a[2][2]) - (a[1][2] * a[2][1])) / det;
	inv[1][0] = -1 * ((a[1][0] * a[2][2]) - (a[1][2] * a[2][0])) / det;
	inv[2][0] = ((a[1][0] * a[2][1]) - (a[1][1] * a[2][0])) / det;
	inv[0][1] = -1 * ((a[0][1] * a[2][2]) - (a[0][2] * a[2][1])) / det;
	inv[1][1] = ((a[0][0] * a[2][2]) - (a[0][2] * a[2][0])) / det;
	inv[2][1] = -1 * ((a[0][0] * a[2][1]) - (a[0][1] * a[2][0])) / det;
	inv[0][2] = ((a[0][1] * a[1][2]) - (a[0][2] * a[1][1])) / det;
	inv[1][2] = -1 * ((a[0][0] * a[1][2]) - (a[0][2] * a[1][0])) / det;
	inv[2][2] = ((a[0][0] * a[1][1]) - (a[1][0] * a[0][1])) / det;//cofactors(alt negatives) stored in transpose
	return;
}

void MULTIPLY(long double key[][3], int user[3], int& numcount, int nums2[], int& quit)
{
	//take key and multiply it by the 3 by 1 vector which was entered by the user
	double temp[3] = { 0 };//multiplied nums stored here
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
			temp[i] += key[i][j] * user[j] + 0.3;//multiply, 0.3 compensates for loss of accuracy
		if (temp[i] >= -1 && temp[i] <= 8)//problem with .3, numbers will not be zero, but will be close. no nums will be between -8 and 8 in ascii
		{
			quit = 0;//if 'zero' found, tell loop in read to stop
			return;
		}
		nums2[numcount] = int(temp[i]) - 20;//make integer version of nums, and in ascii(20 was added first, when converted to ascii)
		++numcount;//increment if quit is not a zero
	}
}
