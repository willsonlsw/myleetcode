#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	int myAtoi(string str){
		int MAXINT = ((unsigned)(-1)) >> 1;

		string str2 = "";
		int j = 0; 
		while(str[j] == ' ') j += 1;
		if (!(str[j] == '+' or str[j] == '-' or '0' <= str[j] && str[j] <= '9')) return 0;

		bool flag = 1;
		if (str[j] == '-') {
			flag = 0; 
			j += 1;
		}else if (str[j] == '+'){
			flag = 1;
			j += 1;
		}

		while ( '0' <= str[j] && str[j] <= '9'){
			str2 += str[j];
			j += 1;
		}
		if (str2.size() <= 0) return 0;

		long long tmp = 0;
		for(int i=0; i < str2.size(); ++i){
			tmp = tmp * 10 +  str2[i] - '0';
			if (tmp > MAXINT) break;
		}

		if (flag == 0) tmp = 0 - tmp;
		if (tmp > MAXINT) return MAXINT;
		else if (tmp < 0 - MAXINT - 1) return 0 - MAXINT -1;
		else return (int)tmp;
	}
};

int main(){
	string x;
	Solution sc;
	while(cin >> x){
		cout << "the num:" << sc.myAtoi(x) << endl;
	}
	return 0;
}
