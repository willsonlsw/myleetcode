#include <iostream>
#include <vector>
using namespace std;

int count;

bool getRes(int n, int k, int idx, int *flag) {
		if (idx == n) {
			count++;
			if (count == k) return true;
			return false;
		}
		
		for (int i = 0; i < n; ++i) 
			if (flag[i] == -1) {
				flag[i] = idx;
				if (getRes(n, k, idx+1, flag)) return true;
				flag[i] = -1;
			}
		return false;
}

char* getPermutation(int n, int k) {
		int *flag = (int*)malloc(sizeof(int) * n);
		for (int i = 0; i < n; ++i)
			flag[i] = -1;
		count = 0;
		getRes(n, k, 0, flag);
		char *str = (char*)malloc(sizeof(char) * (n + 1));
		for (int i = 0; i < n; ++i) {
			str[flag[i]] = '1' + i;
		}
		str[n] = '\0';
		return str;
}

/*
class Solution{
public:
	string getPermutation(int n, int k) {
		vector<int> flag(n, -1);
		int count = 0;
		getRes(n, k, flag, 0, count);
		string str(n, '0');
		for (int i = 0; i < n; ++i) {
			str[flag[i]] = '1' + i;
		}
		return str;
	}
	
	bool getRes(int n, int k, vector<int> &flag, int idx, int &count) {
		if (idx == n) {
			count++;
			if (count == k) return true;
			return false;
		}
		
		for (int i = 0; i < n; ++i) 
			if (flag[i] == -1) {
				flag[i] = idx;
				if (getRes(n, k, flag, idx+1, count)) return true;
				flag[i] = -1;
			}
		return false;
	}
};*/

int main(){
	int n, k;
	cin >> n >> k;
	//Solution sc;
	//cout << sc.getPermutation(n, k) << endl;
	printf("%s\n", getPermutation(n, k));
	return 0;
}