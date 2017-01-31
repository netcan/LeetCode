/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-29 10:54
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int findPoisonedDuration(vector<int>& timeSeries, int duration) {
			int ans = 0;
			if(timeSeries.empty() || duration == 0) return ans;
			int d = 0;
			for (int i = 0; i < timeSeries.size(); ++i) {
				d = timeSeries[i] + duration - 1;
				if(i+1 < timeSeries.size()) {
					if(d < timeSeries[i+1])
						ans += duration;
					else
						ans += timeSeries[i+1] - timeSeries[i];
				} else
					ans += duration;
			}
			return ans;
		}

};


int main() {
	Solution s;
	vector<int>timeSeries({1,4});

	return 0;
}
