/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-09 10:11
 ************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

// Definition for an interval.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
	// 区间插入问题，需要考虑多种情况！这里直接用答案ans来判断是否插入、合并
	public:
		vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
			vector<Interval> ans;
			if(intervals.empty()) return vector<Interval>({newInterval});

			int N = intervals.size();
			if(newInterval.end < intervals[0].start) {
				ans = intervals;
				ans.insert(ans.begin(), newInterval);
				return ans;
			} else if(newInterval.start > intervals[N-1].end) {
				ans = intervals;
				ans.push_back(newInterval);
				return ans;
			}

			ans.push_back(intervals[0]);
			ans.back().start = min(newInterval.start, ans.back().start);
			if(intervals[0].end >= newInterval.start)
				ans.back().end = max(newInterval.end, ans.back().end);


			for (int i = 1; i < N; ++i) {
				Interval &I = intervals[i];
				if(I.start > ans.back().end) {
					if(newInterval.start > ans.back().end && newInterval.end < I.start)
						ans.push_back(newInterval);
					ans.push_back(I);
				} else
					ans.back().end = max(I.end, ans.back().end);


				if((newInterval.end >= I.start && newInterval.start <= I.start) || (I.end <= newInterval.end && I.end >= newInterval.start)) {
					ans.back().start = min(ans.back().start, newInterval.start);
					ans.back().end = max(ans.back().end, newInterval.end);
				}

			}

			return ans;
		}
};

int main() {
	Solution s;
	vector<Interval> intervals({
			Interval(3,5),
			Interval(12,15),
			});
	vector<Interval> ans = s.insert(intervals, Interval(6,6));
	for(int i=0; i<ans.size(); ++i) {
		printf("[%d, %d]\n", ans[i].start, ans[i].end);
	}

	return 0;
}
