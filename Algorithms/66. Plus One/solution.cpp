/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-11 16:59
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		vector<int> plusOne(vector<int>& digits) {
			vector<int> ans;
			ans = digits;
			bool shift = true;
			for(int i=ans.size()-1;shift && i>=0; --i) {
				ans[i] = (ans[i] + shift) % 10;
				shift = (ans[i] == 0);
			}
			if(shift) ans.insert(ans.begin(), 1);
			return ans;
		}

};


int main() {
	Solution s;

	return 0;
}
