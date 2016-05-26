#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
	void sortColors(vector<int>& nums){
    int l = 0, r = nums.size() - 1, tmp; 
		for (int i = 0; i <= r; ++i){
			if (nums[i] == 0){
        tmp = nums[i];
        nums[i] = nums[l];
        nums[l] = tmp;
				l++;
			}else if (nums[i] == 2){
			  tmp = nums[i];
			  nums[i] = nums[r];
			  nums[r] = tmp;
				r--;
				i--;
			}
		}
	}
}


int main(){

	return 0;
}