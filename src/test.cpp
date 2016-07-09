#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unordered_map>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdint.h>
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

string strTest(){
	string str = "";
	char num[16];
	for (int i = 0; i < 20; i++){
		memset(num, '\0', sizeof(num));
		sprintf(num, "%d", i);
		str += string(num) + " ";
	}
	cout << str << endl;
}

uint32_t hash64_32shift(uint64_t key){ 
	key = (~key) + (key << 18); // key = (key << 18) - key - 1; 
	key = key ^ (key >> 31); 
	key = key + (key << 2) + (key << 4); 
	key = key ^ (key >> 11); 
	key = key + (key << 6); 
	key = key ^ (key >> 22); 
	return (uint32_t) key; 
}

uint32_t hash32(uint64_t a){
	a = (a + 0x7ed55d16) + (a << 12);
	a = (a ^ 0xc761c23c) ^ (a >> 19);
	a = (a + 0x165667b1) + (a << 5);
	a = (a + 0xd3a2646c) ^ (a << 9);
	a = (a + 0xfd7046c5) + (a << 3);
	a = (a ^ 0xb55a4f09) ^ (a >> 16);
	return (uint32_t)(a & 0xffffffff);
}

uint64_t hash64shift(uint64_t key){
	key = (~key) + (key << 21);
	key = key ^ (key >> 24);
	key = (key +  (key << 3)) + (key << 8);
	key = key ^ (key >> 14);
	key = (key + (key << 2)) + (key << 4);
	key = key ^ (key >> 28);
	key = key + (key << 31);
	return key;
}

void hashFunTest(uint64_t n) {
	int cc = 0;
	uint64_t mask = 0x3ffffff;
	vector<uint64_t> count(n, 0);
	for (uint64_t i = 0; i < n; ++i) count[i] = 0;
	for (uint64_t i = 10000000000; i < 10100000000; ++i) {
		uint64_t key = hash64_32shift(i) % n;//hash32(i) % n;//hash64shift(i) % n;//& mask;
		//printf("%llu\n", key);
		count[key]++;

		cc++;
		if (cc % 1000000 == 0) {
			printf("\rhash %d lines", cc);
			fflush(stdout);
		}
	}
	
	vector<uint64_t> cl(20, 0);
	cout << "hash over" << endl;
	uint64_t minc = 0x7fffffff, maxc = 0; 
	for (uint64_t i = 0; i < n; ++i) {
		minc = minc < count[i] ? minc : count[i];
		maxc = maxc > count[i] ? maxc : count[i];
		cl[count[i]]++;
	}
	printf("max count: %llu\n", maxc);
	printf("min count: %llu\n", minc);
	for (int i = 0; i < 20; ++i){
		printf("cl %d: %llu\n", i, cl[i]);
	}
}

int main(int argc, char **argv){
	//unorderedMapTest();
	//readConfigTest(argv[1]);
	//timeTest();
	//randTest();
	//strPrintTest();
	//sqrtTest();
	//strTest();
	hashFunTest(0x3ffffff);
	return 0;
}
