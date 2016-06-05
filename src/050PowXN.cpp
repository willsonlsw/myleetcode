#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	double myPow(double x, int N){
		long long n = N;
		if (n == 0) return 1.0;
		if (n == 1) return x;
	
		if (n < 0) {
			x = 1.0 / x;
			n = 0 - n;
		}
		vector<double> pow2v;
		
		double powval = x, incval = x;
		long long pown = 1, incn = 1;
		pow2v.push_back(x);
		while (incn <= n) {
			incn *= 2;
			incval *= incval;
			pow2v.push_back(incval);
		}
		if (incn == n) return incval;
		incn /= 2;
		int m = pow2v.size() - 1;
		incval = pow2v[--m];
		powval = incval;
		
		pown = incn;
		while (pown != n) { 
			while (incn + pown > n) {
				incn /= 2;
				incval = pow2v[--m];
			}
			pown += incn;
			powval *= incval;
		}
		return powval;
	}
};

int main(){
	int n;
	double x;
	cin >> x >> n;
	Solution sc;
	cout << sc.myPow(x, n) << endl;
	return 0;
}