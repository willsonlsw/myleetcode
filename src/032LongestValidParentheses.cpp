#include <iostream>
#include <stack>
#include <string>
using namespace std;


class Solution {
public:
  int longestValidParentheses(string s) {
    stack<int> stk;
    int n = s.length();
    int maxlen = 0;
    for (int i = 0; i < n; ++i)
    	if (s[i] == '(') stk.push(i);
    	else if(!stk.empty() && s[stk.top()] == '(' && s[i] == ')'){
    		stk.pop();
    		int len;
    		if (stk.empty()) len = i + 1; else len = i - stk.top();
    		maxlen = max(len, maxlen);
    	}else stk.push(i);
    return maxlen;
  }
};


int main(){
	return 0;
}