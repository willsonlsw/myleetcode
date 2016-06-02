#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution{
public:
	int longestIncreasingPath(vector<vector<int> >& matrix) {
		int n = matrix.size();
		if (n == 0) return 0;
		int m = matrix[0].size(), len = n * m;
		if (m == 0) return 0;
		vector<vector<int> > graph(len);
		vector<int> inNum(len, 0);
		vector<int> distance(len, 0);
		
		int s, e, x;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j){
				s = i * m + j;
				if (i > 0 && matrix[i-1][j] > matrix[i][j]){
					e = (i-1) * m + j;
					graph[s].push_back(e);
					inNum[e]++;
				}
				if (i < n-1 && matrix[i+1][j] > matrix[i][j]){
					e = (i+1) * m + j;
					graph[s].push_back(e);
					inNum[e]++;
				}
				if (j > 0 && matrix[i][j-1] > matrix[i][j]){
					e = i * m + j - 1;
					graph[s].push_back(e);
					inNum[e]++;
				}
				if (j < m-1 && matrix[i][j+1] > matrix[i][j]){
					e = i * m + j + 1;
					graph[s].push_back(e);
					inNum[e]++;
				}
			}
		
		stack<int> stk;
		for (int i = 0; i < len; ++i)
			if (inNum[i] == 0) {
				stk.push(i);
				distance[i]++;
			}		

		while (!stk.empty()){
			x = stk.top();
			stk.pop();
			for (int i = 0; i < graph[x].size(); ++i){
				inNum[graph[x][i]]--;
				distance[graph[x][i]] = max(distance[graph[x][i]], distance[x] + 1);
				if (inNum[graph[x][i]] == 0) stk.push(graph[x][i]);
			}
		}	
		
		int res = 0;
		for (int i = 0; i < len; ++i)
			res = max(res, distance[i]);
		return res;    
	}
};

int main(){
	int n, m, x;
	cin >> n >> m;
	vector<vector<int> > matrix(n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j){
			cin >> x; 
			matrix[i].push_back(x);
		}
	Solution sc;
	int res = sc.longestIncreasingPath(matrix);
	cout << res << endl;
	return 0;
}