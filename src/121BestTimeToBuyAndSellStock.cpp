#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int maxProfit(vector<int>& prices){
		int minp = 0x7fffffff, mp = 0;
		for (int i = 0; i < prices.size(); ++i){
			minp = min(prices[i], minp);
			mp = max(prices[i] - minp, mp);
		}
		return mp;
	}
};


int main(){
}
