#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
	string simplifyPath(string path){
		vector<string> list;
		int idx = -1, i;
		while (i < path.size()){
			while (i < path.size() && path[i] == '/') i++;
			if (i >= path.size()) continue;
			string str="";
			while (i < path.size() && path[i] != '/')
				str += path[i++];
			if (str == "..") {
				idx--;
				if (idx < -1) idx = -1;
			}
			else if (str != "."){
					if (idx + 1 >= list.size()) {
						list.push_back(str);
						idx++;
					}else{
						list[++idx] = str;
					}
			}
		}
		string res = "";
		for(i = 0; i <= idx; i++)
			res += "/" + list[i];
		if (res.size() == 0 && path[0] == '/') res += "/"; 
		return res;
	}
};

int main(){
	string str;
	Solution sc;
	cin >> str;
	cout << sc.simplifyPath(str) << endl;
	return 0;
}