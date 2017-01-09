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

class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			bool exist[256];
			int maxlen = 0;
			for(size_t i = 0; i<s.length(); ++i) {
				memset(exist, 0, sizeof(exist));
				exist[int(s[i])] = true;
				size_t j;
				for(j = i+1; j<s.length(); ++j) {
					if(exist[int(s[j])]) {
						maxlen = max(maxlen, int(j-i));
						break;
					}
					exist[int(s[j])] = true;
				}
				if(j == s.length())
					maxlen = max(maxlen, int(j-i));
			}
			return maxlen;
		}
};


int main() {
	Solution s;
	cout << s.lengthOfLongestSubstring("au") << endl;

	return 0;
}
