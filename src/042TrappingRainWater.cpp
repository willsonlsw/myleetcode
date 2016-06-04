#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
	int trap(vector<int> &height){
		stack<int> stk;
		int n = height.size();
		if (n <= 1) return 0;
		stk.push(0);
		int ares=0, lasth;
		for (int i = 1; i < n; ++i){
			if (height[i] == 0) continue;
			lasth = 0;
			while (!stk.empty() && height[stk.top()] <= height[i]){
				ares += (height[stk.top()] - lasth) * (i - stk.top() - 1);
				lasth = height[stk.top()];
				stk.pop();
			}
			if (!stk.empty()) ares += (height[i] - lasth) * (i - stk.top() - 1);
			stk.push(i);
		}
		return ares;
	}
};

int main(){
	int n, x;
	vector<int> height;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> x;
		height.push_back(x);
	}
	Solution sc;
	cout << sc.trap(height) << endl;
	return 0;
}