/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-20 10:15
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct jumpStat {
	int pos; // 当前位置
	int step; // 当前步数
	friend bool operator<(const jumpStat&a, const jumpStat &b) {
		return a.pos < b.pos;
	}
	jumpStat(int pos, int step): pos(pos), step(step) {}
};

class Solution {
	public:
		int jump(vector<int>& nums) {
			int ans = 0;
			int N = nums.size();
			if(nums.empty()) return ans;

			priority_queue<jumpStat> q;
			q.push(jumpStat(0, 0));
			int i = 0;
			while(q.size()) {
				jumpStat p = q.top();
				q.pop();
				if(p.pos >= N - 1) return p.step;
				// printf("pos:%d step:%d\n", p.pos, p.step);
				for(; i<=p.pos; ++i) {
					q.push(jumpStat(i + nums[i], p.step + 1));
				}
			}
			return ans;
		}

};

int main() {
	Solution s;
	vector<int> nums(
			{7,8,4,2,0,6,4,1,8,7,1,7,4,1,4,1,2,8,2,7,3,7,8,2,4,4,5,3,5,6,8,5,4,4,7,4,3,4,8,1,1,9,0,8,2}
			);
	cout << s.jump(nums) << endl;

	return 0;
}
