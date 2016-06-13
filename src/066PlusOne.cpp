#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int n = digits.size();
		digits[n - 1] += 1; 
		for (int i = n-1; i >= 0; i--){
			int tmp = digits[i] / 10;
			digits[i] %= 10;
			if (i == 0 && tmp > 0){
				digits.push_back(0);
				for (int j = n; j > 0; j--)
					digits[j] = digits[j-1];
				digits[0] = tmp;
			}else digits[i-1] += tmp;
		}
		return digits;
	}
};

int main(){
	return 0;
}