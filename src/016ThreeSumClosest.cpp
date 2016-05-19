#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution{
public:
	int threeSumClosest(vector<int> &nums, int target){
		sort(nums.begin(), nums.end());
		int mindis = 0x7fffffff;
		int rst;
		int n = nums.size(), left, right;
		for (int i = 0; i < n - 2; ++i){
			if (i > 1 && i < n-2 && nums[i-1] == nums[i]) continue;

			left = i + 1;
			right = n - 1;
			while(left < right){
				int sum = nums[left] + nums[right] + nums[i];
				int dis = sum - target;
				if (abs(dis) < mindis){
					mindis = abs(dis);
					rst = sum;
				}
				if (dis == 0) return rst;
				else if (dis < 0){
					left++;
				}else right--;
			}
		}
		return rst;
	}
};


int main(){
	int numarray[] = {-1, 2, 1, -4};
	int target = 1;
	int size = sizeof(numarray) / sizeof(int);
	vector<int> nums(numarray, numarray + size);
	Solution sc;
	cout << sc.threeSumClosest(nums, target) << endl;
}
