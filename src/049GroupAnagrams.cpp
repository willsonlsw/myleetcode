#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution{
public:
	vector<vector<string> > groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string> > strmap;
    unordered_map<string, vector<string> >::iterator itr;
    for (int i = 0; i < strs.size(); ++i){
    	string tmp(strs[i]);
    	sort(tmp.begin(), tmp.end());
    	strmap[tmp].push_back(strs[i]);
    	/*
    	itr = strmap.find(tmp);
    	if (itr == strmap.end()){
    		vector<string> vec;
    		vec.push_back(strs[i]);
    		strmap[tmp] = vec;
    	}else{
    		itr->second.push_back(strs[i]);
    	}
    	*/
    }
    
    vector<vector<string> > res;
    for (itr = strmap.begin(); itr != strmap.end(); itr++){
    	res.push_back(itr->second);
    }
    return res;
  }
};

int main(){
	string str;
	vector<string> strs;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> str;
		strs.push_back(str);
	}
	Solution sc;
	vector<vector<string> > res = sc.groupAnagrams(strs);
	for (int i = 0; i < res.size(); ++i){
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}