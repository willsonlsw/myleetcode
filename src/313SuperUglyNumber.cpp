#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
	        vector<int> vals(primes);
        //for (int i = 0; i < vals.size(); ++i) cout << vals[i] << endl;
        vector<int> idx(primes.size(), 0);
        vector<int> uglys(n+1, 0x7fffffff);
        uglys[0] = 1;
        int m = primes.size(); 
        for (int i = 1; i < n; ++i){
            for (int j = 0; j < m; ++j) uglys[i] = min(uglys[i], vals[j]);
            for (int j = 0; j < m; ++j) 
                if (uglys[i] == vals[j]) {
                    vals[j] = uglys[++idx[j]] * primes[j];
                }
        }
        return uglys[n-1];
};


int main(){
	return 0;
}