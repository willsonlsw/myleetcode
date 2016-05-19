#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


class Solution{
public:
	int maxSubArray(vector<int>& nums){
		int n = nums.size(), rst = 0 - 0x7fffffff;
		int *f = (int*)malloc(sizeof(int) * n);
		f[0] = nums[0];
		for (int i = 1; i < n; ++i){
			if (f[i - 1] > 0) f[i] = f[i - 1] + nums[i];
			else f[i] = nums[i];
			if (f[i] > rst) rst = f[i];
		}
		free(f);
		return rst;
	}
};


int main(){
	int numsarray[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(numsarray) / sizeof(int);
	vector<int> nums(numsarray, numsarray + n);
	Solution sc;
	cout << sc.maxSubArray(nums) << endl;
	return 0;
}
