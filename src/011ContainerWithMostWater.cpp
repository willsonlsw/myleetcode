#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	bool cmp(pair<int, int> &a, pair<int, int> &b) {
		return a.first < b.first;
	}

	int maxArea(vector<int>& height) {
		vector<pair<int, int> > ps;
		for (int i = 0; i < height.size(); ++i) {
			pair<int, int> p(height[i], i);
			ps.push_back(p);
		}
		sort(ps.begin(), ps.end(), cmp);
		int area = 0, i = 0, re = -1, le = 0x7fffffff;
		while (i < ps.size()) {
			int h = ps[i].first;
			while (i < ps.size() && ps[i].first == h) {
				le = ps[i].second < le ? ps[i].second : le;
				re = ps[i].second < le ? le : ps[i].second;
				i += 1;
			}
			int tmparea = (re - le) * h;
			area = area > tmparea ? area : tmparea;
			if (ps[i].first == h) i++;
		}
		return area;
	}
};


int main()
{
	vector<int> a;
	int x;
	for (int i = 0; i < 10; ++i) {
		cin >> x;
		a.push_back(x);
	}
	Solution sc;
	cout << "area:" << sc.maxArea(a) << endl;
	return 0;
}