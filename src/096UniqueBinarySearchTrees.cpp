#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int numTrees(int n){
		vector<int> f(n+1, 0);
		//for (int i = 0; i < f.size(); ++i) cout << f[i] << endl;
		f[0] = 1;
		f[1] = 1;
		return fcal(n, f);
	}
	
	int fcal(int n, vector<int>& f){
		if (f[n] != 0) return f[n];
		f[n] = 0;
		for (int i = 0; i < n; ++i){
			f[n] += fcal(i, f) * fcal(n-i-1, f);
		}
		return f[n];
	}
};

int main(){
	int n = 0;
	cin >> n;
	Solution sc;
	cout << sc.numTrees(n) << endl;
	return 0;
}