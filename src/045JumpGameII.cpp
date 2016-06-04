#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int jump(vector<int> &nums){
		int n = nums.size();
		vector<int> jumpn(n, 0x7fffffff);
		jumpn[0] = 0;
		int lastcover = 0;
		for (int i = 0; i < n; ++i){
			for (int j = lastcover + 1; j <= i + nums[i]; j++)
				if (j < n) jumpn[j] = min(jumpn[j], jumpn[i] + 1);
			lastcover = i + nums[i];
			//for (int j = 1; j <= nums[i]; ++j)
			//	if (i + j < n) jumpn[i+j] = min(jumpn[i+j], jumpn[i] + 1);
		}
		return jumpn[n-1];
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
	cout << sc.jump(nums) << endl;
	return 0;
}