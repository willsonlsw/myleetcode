#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	bool isHappy(int n){
		int tmp = 0, x;
		vector<bool> flag(10000, 0);
		while (1){
			tmp = 0;
			while (n > 0){
				x = n % 10;
				n /= 10;
				tmp += x * x;
			}
			if (tmp == 1) return true;
			if (flag[tmp]) return false;
			else flag[tmp] = 1;
			n = tmp;
		}
		return false;
	}
};

int main(){
	int n;
	cin >> n;
	Solution sc;
	if (sc.isHappy(n)) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}