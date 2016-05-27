#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
	int maxProfit(vector<int>& prices){
		int n = prices.size(), maxp = 0;
		if (n <= 1) return 0;
		for (int i = 1; i < n; ++i){
			if (prices[i] > prices[i-1]) maxp += prices[i] - prices[i-1];
		}
		return maxp;
	}
};


int main(){
	return 0;
}