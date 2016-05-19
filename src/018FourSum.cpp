#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution{
public:
	vector<vector<int> > fourSum(vector<int>& nums, int target){
		sort(nums.begin(), nums.end());
		
		vector<vector<int> > rst;
		int n = nums.size(), left, right;
		for (int i = 0; i < n - 3; ++i){
			if (i > 0 && i < n - 3 && nums[i-1] == nums[i]) continue;
			int target3 = target - nums[i];
			for (int j = i + 1; j < n - 2; ++j){
				if (j > i + 1 && j < n-2 && nums[j] == nums[j-1]) continue;
				left = j + 1;
				right = n - 1;
				while (left < right){
					int sum = nums[left] + nums[right] + nums[j];
					if (sum == target3){
						vector<int> triplet;
						triplet.push_back(nums[i]);
						triplet.push_back(nums[j]);
						triplet.push_back(nums[left]);
						triplet.push_back(nums[right]);
						rst.push_back(triplet);

						while(left < right && nums[left] == nums[left+1]) left++;
						while(left < right && nums[right] == nums[right-1]) right--;
						left++;
						right--;
					}else if (sum < target3) left++;
					else right--;
				}
			}
		}
		return rst;
	}
};


int main(){
	int numarray[] = {-1,-5,-5,-3,2,5,0,4};
	int target = -7;
	int size = sizeof(numarray) / sizeof(int);
	vector<int> nums(numarray, numarray + size);
	Solution sc;
	vector<vector<int> > rst = sc.fourSum(nums, target);
	for (int i = 0; i < rst.size(); ++i){
		cout << rst[i][0] << ' ' << rst[i][1] << ' ' << rst[i][2] << ' ' << rst[i][3] <<endl; 
	}
	return 0;
}
