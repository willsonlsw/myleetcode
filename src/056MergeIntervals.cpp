#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution{
public:
	static bool cmp(Interval i1, Interval i2){
		return i1.start < i2.start;
	}
	
	vector<Interval> merge(vector<Interval>& intervals){
		if (intervals.size() == 0) return intervals;
		sort(intervals.begin(), intervals.end(), cmp);
		int n = intervals.size();
		int s = intervals[0].start, e = intervals[0].end;
		vector<Interval> res;
		for (int i = 0; i < n; ++i){
			if (intervals[i].start <= e) e = max(e, intervals[i].end);
			else {
				Interval interval(s, e);
				res.push_back(interval);
				s = intervals[i].start;
				e = intervals[i].end;
			}
		}
		Interval interval(s, e);
		res.push_back(interval);
		return res;
	}
};

int main(){
	int n, s, e;
	vector<Interval> intervals;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> s >> e;
		Interval interval(s, e);
		intervals.push_back(interval);
	}
	Solution sc;
	vector<Interval> res = sc.merge(intervals);
	for (int i = 0; i < res.size(); ++i){
		cout << res[i].start << " " << res[i].end << endl;
 	}
	return 0;
}