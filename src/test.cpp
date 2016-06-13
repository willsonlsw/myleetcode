#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;

int unorderedMapTest(){
	unordered_map<int, int> tmap;
	for (int i = 0; i < 10; i++){
		tmap[i] += 1;
		tmap[i] ++;
	}
	unordered_map<int, int>::iterator itr;
	for (itr = tmap.begin(); itr != tmap.end(); ++itr)
		cout << itr->first << ":" << itr->second << endl;
}

void readConfigTest(char *ipath){
	FILE *fi = fopen(ipath, "r");
	char name[256], val[256];
	while(fscanf(fi, "%s=%s", &name, &val)){
		printf("name:%s val:%s\n", name, val);
	}
	fclose(fi);
}
/*
void timeTest(){
	time_t timep;
	time(&timep);
	unsigned int ut = timep;
	cout << ut << endl;
	int count = 0;

	char timestr[] = "20160516164448\0";
	while (1){
		struct tm st;
		strptime(timestr, "%Y%m%d%H%M%s", &st);
		time_t t = mktime(&st);
		printf("%ld\n", t);
	}

	while (1){
		time_t t;
		time(&t);
		count++;
		if (count % 1000000 == 0){
			printf("\rget %d time", count);
			fflush(stdout);
		}
	}
}
*/
void randTest(){
	srand((unsigned)time(NULL));
	int count;
	while (1){
		int a = rand();
		count++;
		if (count % 100000 == 0){
			printf("\rrand %d", count);
			fflush(stdout);
		}
	}
}

void strPrintTest(){
	char str[128];
	int a = 12345;
	double b = 122.343;
	sprintf(str, "%d %f", a, b);
	printf("%s\n", str);
}

int sqrtTest(){
	int x;
	cin >> x;
	cout << (int)sqrt(x) << endl;
}

int main(int argc, char **argv){
	//unorderedMapTest();
	//readConfigTest(argv[1]);
	//timeTest();
	//randTest();
	//strPrintTest();
	sqrtTest();
	return 0;
}
