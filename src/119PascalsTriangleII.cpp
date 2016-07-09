#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int C(int n, int m) {
		long long upval = 1;
		vector<bool> flag(n-m+1, true);
		for (int i = m + 1; i <= n; i++) {
			upval *= (long long)i;
			for (int j = 1; j <= n - m; ++j)
				if (flag[j] && (upval % j == 0)) {
					upval /= (long long)j;
					flag[j] = 0;
				}
		}
		return upval;
	}
	
	vector<int> getRow(int rowIndex) {
		if (rowIndex == 0) return vector<int>(1, 1);
		vector<int> res(rowIndex + 1, 0);
		for (int i = 0; i <= rowIndex; i++)
			res[i] = C(rowIndex, i);
		return res;	
	}
};

int main(){
	int n;
	cin >> n;
	Solution sc;
	vector<int> res = sc.getRow(n);
	for (int i = 0; i < res.size(); ++i) 
		cout << res[i] << " ";
	cout << endl;
	return 0;
}