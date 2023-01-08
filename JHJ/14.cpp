#include <stdio.h> 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int reverse(int x)
{
	string str = to_string(x);

	for(int i = 0; i < str.length() / 2; ++i)
	{
		swap(str[i], str[str.length()-i-1]);
	}

	return stoi(str);
}

bool isPrime(int x)
{
	for(int i = 2; i <= sqrt(x); ++i)
	{
		if(0 == x%i)
		{
			return false;
		}
	}
	return true;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	
	int n, result, temp = 0;
	vector<int> vec;
	
	cin >> n;
	vec.reserve(n);
	
	for(int i = 0; i < n; ++i)
	{
		cin >> temp;
		vec.push_back(temp);
		result = reverse(vec.back());
		
		if(result >= 2 && isPrime(result))
		{
			cout << result << endl;
		}
	}

	return 0;
}



