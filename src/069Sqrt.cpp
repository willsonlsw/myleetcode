#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int mySqrt(int x){
		long long l = 0, r = x, mid;
		long long tmp;
		while (l < r){
			mid = (l + r) >> 1;
			tmp = mid * mid;
			if (tmp == x) return mid;
			else if (tmp > x) r = mid - 1;
			else l = mid + 1;
		}
		tmp = l * l;
		if (tmp > x) return l - 1;
		else return l;
	}
}; 

int main(){
	int x;
	Solution sc;
	cin >> x;
	cout << sc.mySqrt(x) << endl;
	return 0;
}