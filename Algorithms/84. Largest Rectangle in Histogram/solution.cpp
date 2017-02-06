/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-06 10:19
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
	// 最大直方图
	// 栈维护一个升序序列
	public:
		int largestRectangleArea(vector<int>& heights) {
			if(heights.empty()) return 0;
			int ans = 0;
			heights.push_back(0); // 哨兵元素
			stack<int> s;
			for (int i = 0; i < heights.size(); ++i) {
				while(s.size() && heights[s.top()] >= heights[i]) {
					int h = heights[s.top()];
					s.pop();
					int d = s.empty()?i:i-1-s.top();
					ans = max(ans, d*h);
				}
				s.push(i);
			}
			return ans;
		}
};


int main() {
	Solution s;
	vector<int> heights( {
			2,0,2
			});
	cout << s.largestRectangleArea(heights) << endl;

	return 0;
}
