#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
void Print(int** a, const int rowCount, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& min);
void Delete(int** a, int rowCount);
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void rowmem(int** a, const int rowCount, const int colCount);

int main()
{
	srand((unsigned)time(NULL));

	int k;
	int	n;
	int minmax;
	cout << "Input k: ";
	cin >> k;
	cout << "Input n: ";
	cin >> n;
	int low = -5;
	int high = 5;
	int** a = new int* [k];

	rowmem(a, k, n);

	Create(a, k, n, low, high);

	Print(a, k, n);

	Calc(a, k, n,minmax);

	cout <<"Minmax :" << minmax << endl;

	return 0;
}
void rowmem(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
}
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void Calc(int** a, const int rowCount, const int colCount , int& max )
{
	int min;
	for (int  j = 1; j < colCount; j += 2)
	{
		min = a[0][j];
		for (int i = 1; i < rowCount; i++)
		{
				if (a[i][j] < min)
					min = a[i][j];
		}
		if (j == 1)
			max = min;
		if (min > max)
			max = min;
	}
}

void Delete(int** a, int rowCount)
{
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
}
