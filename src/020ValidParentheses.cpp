#include <iostream>
#include <string>
#include <stack>
using namespace std;


class Solution{
public:
	bool isValid(string s){
		stack<char> stk;
		for (int i = 0; i < s.size(); ++i){
			switch(s[i]){
				case '(':
				case '[':
				case '{':
					stk.push(s[i]);
					break;
				case ')':
					if (stk.empty() || stk.top() != '(') return false;
					else stk.pop();
					break;
				case ']':
					if (stk.empty() || stk.top() != '[') return false;
					else stk.pop();
					break;
				case '}':
					if (stk.empty() || stk.top() != '{') return false;
					else stk.pop();
			}
		}
		if (stk.empty()) return true;
		else return false;
	}
};


int main(){
	string s = "()(){}[{{}]";
	Solution sc;
	if (sc.isValid(s)) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}
