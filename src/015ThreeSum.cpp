#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution{
public:
	vector<vector<int> > threeSum(vector<int>& nums){
		sort(nums.begin(), nums.end());
		vector<vector<int> > rst;
		int n = nums.size();
		
		int i = 0;
		int left, right;
		while (i < n){
			int sum2 = 0 - nums[i];
			left = i + 1;
			right = n - 1;

			while (left < right){
				int target = nums[left] + nums[right];
				if (target == sum2){
					vector<int> triplet;
					triplet.push_back(nums[i]);
					triplet.push_back(nums[left]);
					triplet.push_back(nums[right]);
					rst.push_back(triplet);
					while (left < right && nums[left] == nums[left + 1]) left++;
					while (left < right && nums[right] == nums[right - 1]) right--;
					left++;
					right--;
				}else if (target < sum2) left += 1;
				else right -= 1;
			}

			int ival = nums[i];
			while (i < n && nums[i] == ival) i++;
		}
		return rst;
	}
};


int main(){
	int n, x;
	int numarray[]={7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	int size = sizeof(numarray) / sizeof(int);
	vector<int> nums(numarray, numarray + size);
	/*
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x;
		nums.push_back(x);
	}*/
	Solution sc;
	vector<vector<int> > rst = sc.threeSum(nums);
	for (int i = 0; i < rst.size(); ++i){
		cout << rst[i][0] << ' ' << rst[i][1] << ' ' << rst[i][2] << endl;
	}
	return 0;
}
