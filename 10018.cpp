#include <bits/stdc++.h>

using namespace std;

unsigned long reverse(unsigned long n)
{
	unsigned long rev_n = 0;
	while (n != 0)
	{
		rev_n = (rev_n * 10) + n % 10;
		n /= 10;
	}
	return rev_n;
}

inline int is_palindrome(unsigned long n)
{
	return n == reverse(n);
}

int reverse_and_add(unsigned long num, unsigned long &result)
{
	int counter = 0;
	do
	{
		num += reverse(num);
		counter++;
	} while (!is_palindrome(num));
	result = num;
	return counter;
}

int main()
{
	int numOfCase;
	scanf("%d", &numOfCase);
	while (numOfCase--)
	{
		unsigned long num;
		scanf("%lu", &num);
		int iteration;			  // #iteration
		unsigned long result; // final palindrome, like 9339
		iteration = reverse_and_add(num, result);
		printf("%d %lu\n", iteration, result);
	}
	return 0;
}
