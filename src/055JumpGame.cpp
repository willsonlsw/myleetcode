#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	bool canJump(vector<int> &nums){
		int n = nums.size();
		vector<bool> can(nums.size(), 0);
		can[0] = 1;
		int lastcover = 0;
		for (int i = 0; i < n; ++i)
			if (!can[i]) continue;
			else if (nums[i] + i <= lastcover) continue;
			else {
				for (int j = lastcover; j <= i + nums[i]; ++j)
					can[j] = 1;
				lastcover = max(lastcover, i + nums[i]);
			}
		if (can[n-1]) return true;
		else return false;
	}
};

int main(){
	int n, x;
	vector<int> nums;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> x;
		nums.push_back(x);
	}
	Solution sc;
	if (sc.canJump(nums)) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}