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
	
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		sort(intervals.begin(), intervals.end(), cmp);
		int n = intervals.size();
		vector<Interval> res;
		int i = 0;
		while (i < n && intervals[i].end < newInterval.start) res.push_back(intervals[i++]);
		if (i < n && intervals[i].start <= newInterval.end) {
			int ints = min(intervals[i].start, newInterval.start);
			int inte = max(intervals[i].end, newInterval.end);
			while (i < n && intervals[i].start <= inte){
				inte = max(inte, intervals[i].end);
				i++;
			}
			Interval tmp(ints, inte);
			res.push_back(tmp);
		}else{
		    res.push_back(newInterval);
		}
		while (i < n) res.push_back(intervals[i++]);
		return res;
	}
};

int main(){
	int n, s, e; 
	vector<Interval> intervals;
	cin >> n >> s >> e;
	Interval newInterval(s, e);
	for (int i = 0; i < n; ++i){
		cin >> s >> e;
		Interval interval(s, e);
		intervals.push_back(interval);
	}
	Solution sc;
	vector<Interval> res = sc.insert(intervals, newInterval);
	for (int i = 0; i < res.size(); ++i){
		cout << res[i].start << " " << res[i].end << endl;
	}
	return 0;
}