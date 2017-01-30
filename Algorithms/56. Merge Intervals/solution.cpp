/*************************************************************************
  > File Name: solution.cpp
  > Author: Netcan
  > Blog: http://www.netcan666.com
  > Mail: 1469709759@qq.com
  > Created Time: 2017-01-30 10:28
 ************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for an interval.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(const Interval &a, const Interval &b) {
	if(a.start != b.start) return a.start < b.start;
	return a.end < b.end;
}

class Solution {
	public:
		vector<Interval> merge(vector<Interval>& intervals) {
			vector<Interval> ans;
			if(intervals.size() <= 1) return intervals;
			sort(intervals.begin(), intervals.end(), cmp);
			int l = intervals[0].start, r = intervals[0].end;

			for(int i=1; i < intervals.size(); ++i) {
				if(r < intervals[i].start) {
					ans.push_back(Interval(l, r));
					l = intervals[i].start;
					r = intervals[i].end;
				} else if(r >= intervals[i].start) { // 拼接
					r = max(intervals[i].end, r);
				}
			}
			ans.push_back(Interval(l, r)); // 最后一个

			return ans;
		}
};
int main() {
	Solution s;
	return 0;
}
