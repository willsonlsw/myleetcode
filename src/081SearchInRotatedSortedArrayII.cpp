#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	bool search(vector<int> &nums, int target){
		int l = 0, r = nums.size() - 1, mid;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (nums[mid] == target) return true;
			if (nums[l] < nums[mid]) {
				if (nums[l] <= target && target <= nums[mid]) r = mid - 1;
				else l = mid + 1;
			}else if (nums[mid] < nums[r]) {
				if (nums[mid] <= target && target <= nums[r]) l = mid + 1;
				else r = mid - 1;
			}else {
				if (nums[l] == target) return true;
				else l += 1;
			}
		}
		return false;
	}
};

int main(){
	int n, x, target;
	vector<int> nums;
	cin >> n >> target;
	for (int i = 0; i < n; ++i){
		cin >> x;
		nums.push_back(x);
	}
	Solution sc;
	if (sc.search(nums, target)) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}