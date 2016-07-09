#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution{
public:
	int longestConsecutive(vector<int> &num) {
		vector<long long> nums;
		for (int i = 0; i < num.size(); ++i)
			nums.push_back((long long)num[i]);
			
		unordered_map<long long, int> nmap;
		for (int i = 0; i < nums.size(); ++i)
			nmap[nums[i]] = 1;
		for (int i = 0; i < nums.size(); ++i) {
			if (nmap[nums[i]-1] > 0) nmap[nums[i]] |= 2;
			if (nmap[nums[i]+1] > 0) nmap[nums[i]] |= 4;
		}
		for (int i = nums.size() - 1; i >= 0; --i) {
			if (nmap[nums[i]-1] > 0) nmap[nums[i]] |= 2;
			if (nmap[nums[i]+1] > 0) nmap[nums[i]] |= 4;
		}
		
		long long x, y;
		stack<long long> stk;
		unordered_map<long long, int> leftm, rightm;
		for (int i = 0; i < nums.size(); ++i) {
			auto itr = leftm.find(nums[i]);
			if (itr == leftm.end()) {
				x = nums[i];
				while (nmap[x] & 2 > 0 && leftm[x] == 0) stk.push(x--);
				if (nmap[x] == 0 && !stk.empty()) {
					x = stk.top();
					stk.pop();
				}
				while (!stk.empty()) {
					y = stk.top();
					stk.pop();
					leftm[y] = leftm[x] + 1;
					x = y; 
				}
			}
			itr = rightm.find(nums[i]);
			if (itr == rightm.end()) {
				x = nums[i];
				while (nmap[x] & 4 > 0 && rightm[x] == 0) stk.push(x++);
				if (nmap[x] == 0 && !stk.empty()) {
					x = stk.top();
					stk.pop();
				}
				while (!stk.empty()) {
					y = stk.top();
					stk.pop();
					rightm[y] = rightm[x] + 1;
					x = y;
				}
			}
		}
		
		int maxlen = 0;
		for (int i = 0; i < nums.size(); ++i) {
			int len = leftm[nums[i]] + rightm[nums[i]] + 1;
			maxlen = maxlen > len ? maxlen : len; 
		}
		return maxlen;
	}
};

int main(){
	int n, x;
	vector<int> nums;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		nums.push_back(x);
	}
	Solution sc;
	cout << "maxlen: " << sc.longestConsecutive(nums) << endl;	
	return 0;
}