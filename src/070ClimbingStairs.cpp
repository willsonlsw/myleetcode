#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
    		int f1=1, f2=0, rst=0;
        for (int i = 0; i < n; ++i){
        		rst = f1 + f2;
        		f2 = f1;
        		f1 = rst;
        }
				return rst;
    }
};

int main(){
	int n;
	Solution sc;
	while(cin >> n) cout << sc.climbStairs(n) << endl;
	return 0;
}