#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution{
public:
	int singleNumber(vector<int>& nums){
		int sum, val = 0;
		for (int i = 0; i < 32; ++i){
			sum = 0;
			for (int j = 0; j < nums.size(); ++j)
				if (((nums[j] >> i) & 1) > 0) sum += 1;
			if (sum % 3 == 1) val |= 1 << i;
		}
		return val;   
		/*
		int x = 1, sum, val = 0;
		for (int i = 0; i < 32; ++i){
			sum = 0;
			for (int j = 0; j < nums.size(); ++j)
				if ((nums[j] & x) > 0) sum += 1;
			if (sum % 3 == 1) val += x;
			x <<= 1;
		}
		return val;
		*/
	}
};
 

int main(){
	int n, x;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; ++i){
		cin >> x;
		nums.push_back(x);
	}
	Solution sc;
	cout << sc.singleNumber(nums) << endl;
	return 0;
}