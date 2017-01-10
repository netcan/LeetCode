/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-09 22:19
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
		string longestPalindrome(string s) {
			string ans = s.substr(0, 1);
			// 以mid为中心，两边查找
			for(double mid=0.5; mid<s.length(); mid += 0.5) {
				double d = (mid - int(mid) == 0 ?1:0.5);
				while(mid - d >= 0 && mid + d < s.length()) {
					if(s[mid - d] != s[mid + d]) break;
					++d;
				}
				if(mid - d + 1 >= 0) {
					string sub = s.substr(mid - d + 1, 2*d-1);
					if(ans.length() < sub.length()) ans = sub;
				}
			}

			return ans;
		}
};


int main() {
	Solution s;
	cout << s.longestPalindrome("cbbd") << endl;
	return 0;
}
