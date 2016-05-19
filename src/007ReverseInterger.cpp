#include <cstdio>

int reverse(int x){
	int MAXINT = ((unsigned)(-1)) >> 1;
	bool flag;
	if (x >= 0) flag = true;
	else{
		x = 0 - x;
		flag = false;
	}
	int rx = 0, y;
	while(x > 0){
		if (rx > MAXINT / 10) return 0;
		y = x % 10;
		rx = rx * 10 + y;
		x /= 10;
	}
	
	if (flag) return rx;
	else return 0 - rx;
}

int main(){
	int x;
	while(scanf("%d", &x) != EOF){
		printf("reverse:%d\n", reverse(x));
	}
	return 0;
}
