#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
	int maximalRectangle(vector<vector<char> >& matrix){
		if(matrix.size() <= 0 || matrix[0].size() <= 0) return 0;
			
		int m = matrix.size(), n = matrix[0].size();
		vector<int> heights(n, 0);
		
		int maxarea = 0;
		for (int r = 0; r < m; ++r){
			for (int i = 0; i < n; ++i)
				if (matrix[r][i] == '1') heights[i] += 1;
				else heights[i] = 0;
			maxarea = max(maxarea, maxRecArea(heights));		
		}
		return maxarea;
	}
	
	int maxRecArea(vector<int>& heights){
		int n = heights.size(), idx;
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    
    stack<int> stk;
    for (int i = 0; i < n; ++i){
    	while(!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
    	if (stk.empty()) left[i] = -1;
    	else left[i] = stk.top();
    	stk.push(i);
    }
    
    while(!stk.empty()) stk.pop();
    for (int i = n - 1; i >= 0; --i){
    	while(!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
    	if (stk.empty()) right[i] = n;
    	else right[i] = stk.top();
    	stk.push(i);
    }
    
    int maxarea = 0, area;
    for (int i = 0; i < n; ++i){
    	area = heights[i] * (right[i] - left[i] - 1);
    	maxarea = max(maxarea, area);
    }
    return maxarea;
	}
};


int main(){
	return 0;
}