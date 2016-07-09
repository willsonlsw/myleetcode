#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > res;
		if (numRows == 0) return res;
		for (int i = 0; i < numRows; i++) {
			vector<int> row;
			row.push_back(1);
			for (int j = 0; j < i; j++) {
				int x = res[i-1][j];
				if (j + 1 < res[i-1].size()) x += res[i-1][j+1];
				row.push_back(x);
			}
			res.push_back(row);
		}
		return res;
	}
};

int main(){
	int n;
	cin >> n;
	Solution sc;
	vector<vector<int> > res = sc.generate(n);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}