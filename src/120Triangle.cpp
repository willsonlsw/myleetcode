#include <iostream>
#include <vector>
using namespace std;

#define min(a,b) a<b?a:b
#define max(a,b) a<b?b:a


class Solution{
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		if (n == 1) return triangle[0][0];
			
    vector<vector<int> > f;
    for (int i = 0; i < n; ++i){
    	vector<int> tmp(triangle[i].size(), 0x3fffffff);
    	f.push_back(tmp);    
    }
    
    f[0][0] = triangle[0][0];
    for (int i = 1; i < n; ++i)
    	for (int j = 0; j < triangle[i].size(); ++j){
    		if (j>0) f[i][j] = min(f[i][j], f[i-1][j-1] + triangle[i][j]);
    		if (j<triangle[i-1].size()) f[i][j] = min(f[i][j], f[i-1][j] + triangle[i][j]);
    	}
    
    int sum = 0x7fffffff;
    for (int i = 0; i < n; ++i)
    	sum = min(f[n-1][i], sum);
    return sum;
  }
};


int main(){
	return 0;
}