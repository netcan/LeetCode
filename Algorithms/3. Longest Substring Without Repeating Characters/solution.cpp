/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-09 11:14
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// 滑动窗口

class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			bool exist[256];
			memset(exist, 0, sizeof(exist));
			size_t i = 0, j = 0;
			int maxlen = 0;
			while(i < s.length() && j < s.length()) {
				if(exist[int(s[j])])
					exist[int(s[i++])] = false;
				else
					exist[int(s[j++])] = true;
				maxlen = max(maxlen, int(j-i));
			}
			return maxlen;
		}
};


int main() {
	Solution s;
	cout << s.lengthOfLongestSubstring("abswa") << endl;

	return 0;
}
