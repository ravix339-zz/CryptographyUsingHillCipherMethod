
#include <fstream>

using namespace std;

void write(int mat[][3], int strsize, int nums[])
{
	string file;//filename
	cout << "What do you want to name your file?\n(include filepath for a location other than the default):" << endl;
	while (1)//infinite loop
	{
		getline(cin, file);//get full line
		ofstream codeout;//create output filestream
		codeout.open(file.c_str());//open file w/ name given. makes filename a c type string, regular strings do not work
		for (int i = 0; i<3; ++i)
		for (int j = 0; j<3; ++j)
			codeout << mat[i][j] << " ";//write matrix, separated by spaces
		for (int i = 0; i < strsize; i += 3)
		{
			int r = i;
			for (int f = 0; f <3; f++)
				codeout << nums[r] * mat[f][0] + nums[r + 1] * mat[f][1] + nums[r + 2] * mat[f][2] << " ";//code writes multiplied numbers to file, in threes
		}
		if (codeout.fail())//if writing fails
		{
			cout << "Invalid filename. Try again:" << endl;//trys again with new filename
			codeout.close();
		}
		else break;//or it will break

	}
	return;
}
void read(int& numcount, int nums2[])
{
	int a[3][3];//matrix to be read
	long double inv[3][3];//inverse of matrix

	int back[3];// 3 nums read from file at a time, multiplied by inverse
	int quit = 1;// when to stop reading
	string file;//flename
	cout << "Enter the file you want to read \n(include filepath for a location other than the default)" << endl;
	while (1)//infinite loop
	{
		getline(cin, file);//get whole line
		ifstream in;//inputfilestream
		in.open(file.c_str());//open file w/ name given. makes filename a c type string, regular strings do not work
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				in >> a[i][j];//read matrix
			}
		}
		if (in.fail())//if cannot read, trys again with new filename
		{
			cout << "Invalid filename. Try again:" << endl;
			in.close();
			continue;
		}
		else//or find inverse and multiply
		{
			INVERTER(a, inv);//inverse of a comes back as inv
			while (quit)//while the numbers are not zeros
			{
				in >> back[0] >> back[1] >> back[2];//take in 3 nums
				MULTIPLY(inv, back, numcount, nums2, quit);//multiplys by inv, write to nums2, increment numcount while not zeros

			}
			in.close();
			break;//end loop
		}
	}
	return;
}
