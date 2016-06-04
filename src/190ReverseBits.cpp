#include <iostream>
#include <string>
#include <cstdlib>
#include <stdint.h>
using namespace std;

class Solution{
public:
	uint32_t reverseBits(uint32_t n){
		uint32_t m = 0;
		for (int i = 31; i >= 0; i--){
			uint32_t x = 1 & n;
			n >>= 1;
			m = (m << 1) + x;
		}
		return m;
	}
};


void outputBit(uint32_t n){
	string str = "";
	for (int i = 0; i < 32; ++i){
		cout << char('0' + (n&1));
		n >>= 1;
	}
	cout << endl;
}


int main(){
	int n, m;
	cin >> n;
	Solution sc;
	outputBit(n);
	outputBit(sc.reverseBits(n));
	return 0;
}