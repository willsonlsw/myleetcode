#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int removeDuplicates(vector<int> &nums){
		int slowidx = 0, count = 0, last;
		last = nums[0];
		count = 0;
		for (int i = 0; i < nums.size(); ++i){
			if (nums[i] == last) {
				count++;
				if (count <= 2) nums[slowidx++] = nums[i];
			}else{
				last = nums[i];
				count = 1;
				nums[slowidx++] = nums[i];
			}
		}
		return slowidx;
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
	cout << sc.removeDuplicates(nums) << endl;
	return 0;
}
