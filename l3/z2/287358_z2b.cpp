#include <iostream>

using namespace std;

int main()
{
	int k, size;
	cin >> size;

	int arr[size];

	for(int n = 0; n < size; n++)
		cin >> arr[n];

	cin >> k;

	for(long n = 0; n < ((long)1 << (long)size); n++) {
	    int sum = 0;
	    for(int m = n; m > 0; m >>= 1)
	        sum += m&1;
	    if(sum > k) continue;
		for(int m = 0; m < size; m++)
			if((n & (1 << m)) != 0)
				cout << arr[m] << " ";
		cout << endl;
	}
	
	return 0;
}