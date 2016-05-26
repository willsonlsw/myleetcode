#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
	int maxProfit(vector<int>& prices){
		if (prices.size() <= 1) return 0;
		
		int n = prices.size();
		int lmin = prices[0], rmax = prices[n-1], maxsum=0;
		vector<int> lv(n, 0), rv(n, 0);
		
		for (int i = 1; i < n; ++i){
			lmin = min(prices[i], lmin);
			lv[i] = max(lv[i-1], prices[i]-min);
		}
		for (int j = n-2; j >= 0; --j){
			rmax = max(prices[j], max);
			rv[j] = max(rv[j+1], rmax - prices[j]);
		}
			
		for (int i = 0; i < n; ++i)
			maxsum = max(maxsum, lv[i] + rv[i]);
		
		/*for (int i = 1; i < prices.size(); ++i){
			lmin = min(lmin, prices[i]);
			lsum = max(lsum, prices[i] - lmin);
			
			rmin = prices[i];
			rsum = 0;
			for (int j = i; j < prices.size(); ++j){
				rmin = min(rmin, prices[j]);
				rsum = max(rsum, prices[j] - rmin);
			}
				
			maxsum = max(maxsum, rsum + lsum);
		}*/
		
		return maxsum;
	}
}


int main(){
	int num[] = 
	vector<int> prices
	return 0;
}