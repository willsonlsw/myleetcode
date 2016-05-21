#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
	int removeDuplicates(vector<int>& nums){
		int n = nums.size();
		if (n == 0) return 0;
		
		int lastNum = nums[0], len = 1;
		for (int i = 1; i < n; ++i) {
			if (nums[i] == lastNum){
				continue;
			}else{
				lastNum = nums[i];
				nums[len] = nums[i];
				len++;
			}
		}
		
		return len;
	}
};


int main(){
	return 0;
}