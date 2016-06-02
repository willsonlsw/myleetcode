#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution{
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites){
		vector<vector<int> > graph(numCourses);
		vector<int> inNum(numCourses, 0);
		for (int i = 0; i < prerequisites.size(); ++i){
			graph[prerequisites[i].second].push_back(prerequisites[i].first);
			inNum[prerequisites[i].first]++;
		}
		
		stack<int> snodes;
		for (int i = 0; i < numCourses; ++i)
			if (inNum[i] == 0) snodes.push(i);
		
		int x;
		vector<int> res;
		while (!snodes.empty()){
			x = snodes.top();
			snodes.pop();
			res.push_back(x);
			for (int i = 0; i < graph[x].size(); ++i){
				inNum[graph[x][i]]--;
				if (inNum[graph[x][i]] == 0) snodes.push(graph[x][i]);
			}
		}
		
		if (res.size() != numCourses) return vector<int>();
		else return res;
	}
};


int main(){
	int n, x, y, m;
	vector<pair<int, int> > pres;
	cin >> n >> m;
	for (int i = 0; i < m; ++i){
		cin >> x >> y;
		pres.push_back(make_pair(x, y));
	}
	Solution sc;
	vector<int> res = sc.findOrder(n, pres);
	cout << "res:" << endl;
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << " ";
	cout << endl;
	return 0;
}