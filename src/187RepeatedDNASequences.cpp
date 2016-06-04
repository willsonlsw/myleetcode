#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    int len = s.length();
   	int mask = 0xfffff;
  	vector<int> occn(mask, 0); 
  	int val = 0, tmp;
  	for (int i = 0; i < len; ++i){
  		switch (s[i]){
  			case 'A': tmp = 0;
  				break;
  			case 'C': tmp = 1;
  				break;
  			case 'G': tmp = 2;
  				break;
  			case 'T': tmp = 3; 				
  		}
  		val = (val << 2) + tmp;
  		if (i < 9) continue; 
  		val = mask & val;
  		occn[val]++; 
  	}
  	
  	vector<string> res;
  	for (int i = 0; i < mask; ++i)
  		if (occn[i] > 1){
  			tmp = i;
  			string str = "";
  			for (int j = 0; j < 10; j++){
  				int k = tmp & 0xc0000;
  				k = k >> 18;
  				tmp <<= 2;
  				switch (k){
  					case 0: str += 'A';
  						break;
  					case 1: str += 'C';
  						break;
  					case 2: str += 'G';
  						break;
  					case 3: str += 'T';
  				}
  			}
  			res.push_back(str);
  		}
  		
  	return res;
  }
};

int main(){
	string str;
	cin >> str;
	Solution sc;
	vector<string> res = sc.findRepeatedDnaSequences(str);
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;
	return 0;
}