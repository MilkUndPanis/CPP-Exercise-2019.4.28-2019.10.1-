//1.1
#include<stdlib.h>
//确定n个元素中的第k=n/2个最大者，排序为递减
template<typename T>
T findmax(T * ar, int n)
{
	int k = n / 2;
	T* ar_temp = new T[k];
	for (int i = 0; i < k; i++)
		ar_temp[i] = ar[i];
	for (int i = 0; i < k - 1; i++)
		for (int j = i; j < k; j++)
			if (ar_temp[i] < ar_temp[j])
			{
				T temp = ar_temp[i];
				ar_temp[i] = ar_temp[j];
				ar_temp[j] = temp;
			}
	for (int i = k; i < n; i++)
		if (ar[i] > ar_temp[k - 1])
		{
			int j;
			for (j = k - 2; j >= 0; j--)
				if (!(ar[i] > ar_temp[j]))
					break;
			j++;//该元素必须放在判断表达式右端元素之后
			T* temp = new T[k - j];
			for (int t = 0; t < k - j; t++)
				temp[t] = ar_temp[j + t];
			ar_temp[j] = ar[i];
			for (int u = 1; u < k - j; u++)
				ar_temp[j + u] = temp[u - 1];
			delete[] temp;
		}
	T result = ar_temp[k - 1];
	delete[] ar_temp;
	return result;
}
//1.2
#include<iostream>
int main()
{
	using std::cout;
	using std::endl;
	char wordlist[4][4] = { {'t','h','i','s'},
							{'w','a','t','s'},
							{'o','a','h','g'},
							{'f','g','d','t'} };
	const char* word[4] = { "this","two","fat","that" };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int pair[2] = {};
			for (int k = 0; k < 4; k++)
				for (int l = 0; l < 4; l++)
					if (word[i][j] == wordlist[k][l])
					{
						pair[0] = k;
						pair[1] = l;
						cout << "(" << k << "," << l << ")";
						if (word[i][j + 1] == '\0')
						{
							cout << word[i] << endl;
							goto flag;
						}
						else goto flag;
					}
		flag:continue;
		}
	}
	return 0;
}
//1.3
#include<stdio.h>
void PrintDigit(int N)
{
	printf("%d", N);
}
void PrintReal(double N, int dec = 10)
{
	if (N < 0)
	{
		putchar('-');
		N = -N;
	}
	double base = 1;
	for (int i = 0; i < dec; i++)
		base /= 10;
	N += base;
	int adigit = (int)N;
	double frac = N - adigit;
	PrintDigit(adigit);
	if (dec > 0)
		putchar('.');
	for (int i = 0; i < dec; i++)
	{
		frac *= 10;
		PrintDigit((int)frac);
		frac -= int(frac);
	}
}
//1.4.
#include<fstream>
#include<iostream>
void PrintFile(const char* Filename)
{
	using namespace std;
	fstream file(Filename, ios_base::in | ios_base::binary);
	file.seekp(0);
	char ch;
	while ((ch = file.get()) != EOF)
	{
		cout.put(ch);
		if (ch == '#')
		{
			string str;
			str.push_back(ch);
			for (int i = 0; i < 7; i++)
			{
				ch = file.get();
				cout.put(ch);
				str.push_back(ch);
			}
			if (str == "#include")
			{
				string filename;
				if (file.peek() == ' ')
				{
					cout.put(' ');
					file.get();
				}
				file >> filename;
				PrintFile(filename.c_str());
			}
		}
	}
}
//2.7.
#include<iostream>
#include<ctime>
#include<cstdlib>
template<typename T>
void Swap(T & a, T & b)
{
	T temp = a;
	a = b;
	b = temp;
}
void Put(int A[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << A[i] << " ";
}
int RandInt(int i, int j)
{
	srand(time(0));
	int randn = rand();
	while ((randn < i) || (randn >= j))
		randn = rand();
	return randn;
}
//Algorithms
void Set1(int A[], int n)//O(N^2logN)
{
	A[0] = RandInt(1, n + 1);
	for (int k = 1; k < n; k++)
	{
	flag:int r = RandInt(1, n + 1);
		for (int p = 0; p < k; p++)
			if (r != A[p])
				continue;
			else goto flag;
		A[k] = r;
	}
}
void Set2(int A[], int n)//O(NlogN)
{
	int* Used = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
		Used[i] = 0;
	A[0] = RandInt(1, n + 1);
	Used[A[0]] = 1;
	for (int i = 1; i < n; i++)
	{
	flag:int r = RandInt(1, n + 1);
		if (Used[r])
			goto flag;
		A[i] = r;
		Used[r] = 1;
	}
	delete[] Used;
}
void Set3(int A[], int n)//O(N)
{
	for (int i = 0; i < n; i++)
		A[i] = i + 1;
	for (int i = 1; i < n; i++)
		Swap(A[i], A[RandInt(0, i)]);
}
//2.9.
long int Pow1(long int X, unsigned int N)//O(N)
{
	long int r = 1;
	for (int i = 0; i < N; i++)
		r *= X;
	return r;
}
long int Pow2(long int X, unsigned int N)//O(logN)
{
	if (N == 0)
		return 1;
	if (N % 2 == 0)
		return Pow2(X * X, N / 2);
	else return Pow2(X * X, N / 2) * X;
}
long int Fx1(long int A[], int X, int N)//T(N)=O(N)*O(N)=0(N^2)
{
	long int sum = 0;
	for (int i = 0; i < N; i++)//O(N)
	{
		sum += A[i] * Pow1(X, i);//O(N)
	}
}
long int Fx2(long int A[], int X, int N)//T(N)=O(N)*O(logN)=O(NlogN)
{
	long int sum = 0;
	for (int i = 0; i < N; i++)//O(N)
	{
		sum += A[i] * Pow2(X, i);//O(logN)
	}
}
//2.11
int Findi(const int A[], int n, int i)//binary search,T(N)=O(logN)
{
	int left, right, center;
	left = 0;
	right = n - 1;
	center = (left + right) / 2;
	while (left <= right)
	{
		if (A[center] == i)
			return center;
		if (A[center] < i)
		{
			left = center + 1;
			center = (left + right) / 2;
		}
		else
		{
			right = center - 1;
			center = (left + right) / 2;
		}
	}
	return -1;
}
//2.12
//a.
long int FindMinSequenceSum(const int A[], int left, int right)
{
	long int MinLeftSum, MinRightSum;
	long int MinLeftBorderSum, MinRightBorderSum;
	long int LeftBorderSum, RightBorderSum;
	int Center;
	if (left == right)
		return A[left];
	Center = (left + right) / 2;
	MinLeftSum = FindMinSequenceSum(A, left, Center);
	MinRightSum = FindMinSequenceSum(A, Center + 1, right);
	MinLeftBorderSum = LeftBorderSum = 0;
	for (int i = left; i <= Center; i++)
	{
		LeftBorderSum += A[i];
		if (MinLeftBorderSum > LeftBorderSum)
			MinLeftBorderSum = LeftBorderSum;
	}
	MinRightBorderSum = RightBorderSum = 0;
	for (int i = Center + 1; i <= right; i++)
	{
		RightBorderSum += A[i];
		if (MinRightBorderSum > RightBorderSum)
			MinRightBorderSum = RightBorderSum;
	}
	return Min_3(MinLeftSum, MinRightSum, MinLeftBorderSum + MinRightBorderSum);
}
long int MinSequenceSum(const int A[], int n)
{
	return FindMinSequenceSum(A, 0, n - 1);
}
//b. 
long int FindMinSequenceSum(const int A[], int n)
{
	int ThisSum, MinSum, i;
	ThisSum = MinSum = 0;
	for (i = 0; i < n; i++)
	{
		ThisSum += A[i];
		if (ThisSum < MinSum)
		{
			MinSum = ThisSum;
		}
		else if (ThisSum > 0)
			ThisSum = 0;
	}
	return MinSum;
}
//c.
long int maxSubsequenceMul(const int A[], int n)//Dynamic Planning
{
	int maxA[1000];
	int minA[1000];
	maxA[0] = minA[0] = A[0];
	int ans = A[0];
	for (int i = 1; i < n; i++)
	{
		maxA[i] = max(max(A[i], minA[i - 1] * A[i]), maxA[i - 1] * A[i]);
		minA[i] = min(min(A[i], minA[i - 1] * A[i]), maxA[i - 1] * A[i]);
		ans = max(ans, maxA[i]);
	}
	return ans;
}
//2.13.
//a.
bool isPrime(int N)//T(N)=O(N^0.5)
{
	if (N <= 1)
		return false;
	if ((N == 2) || (N == 3))
		return true;
	for (int i = 2; i * i <= N; i++)
	{
		if (N % i == 0)
			return false;
	}
	return true;
}
//2.14.
#include<iostream>
void Eratosthenes(int N)//T(N)=O(N)
{
	int i, j;
	bool* sel = new bool[N + 1];
	sel[0] = sel[1] = false;
	for (i = 2; i <= N; i++)
		sel[i] = true;
	i = 2;
	while (i <= N)
	{
		while (sel[i++])//i++等于i原值，而i已经自增，故j=i-1求i原值
		{
			j = i - 1;
			break;
		}
		for (int k = 2; j * k <= N; ++k)
		{
			sel[j * k] = false;
		}
	}
	for (int i = 0; i <= N; i++)
		if (sel[i])
			std::cout << i << " ";
}
//2.16.
long int Pow(int x, int n)
{
	long int result = 1;
	while (n)
	{
		if (n % 2 != 0)
			result *= x;
		n /= 2;
		x *= x;
	}
	return result;
}
//2.19
#include<iostream>
#include<cmath>
using namespace std;
#define MAXN 1000
int a[MAXN], b[MAXN];
bool IsMainCell(int* a, int n, int probable)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == probable)
			cnt++;
	if (cnt > n / 2)
		return true;
	else
		return false;
}
int FindMainCell(int a[], int b[], int n, int n2)
{
	if (n == 0)
		return -1;
	if (n == 1)
		if (IsMainCell(b, n2, a[0]))
			return a[0];
		else
			return -1;
	int cnt = 0;
	for (int i = 0; i + 1 < n; i++) {
		if (a[i] == a[i + 1]) {
			b[cnt++] = a[i];
		}
	}
	int res = FindMainCell(b, a, cnt, n);
	if (res == -1 && n % 2 == 1 && IsMainCell(a, n, a[n - 1]))
		return a[n - 1];
	else
		return res;
}
//2.23
int BinarySearch(const int A[], int n, int x)
{
	int low, mid, high;
	low = 0; high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (A[mid] == x)
			return mid;
		if (A[mid] < x)
			low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}
