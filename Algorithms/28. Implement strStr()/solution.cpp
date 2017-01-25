/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-25 10:08
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int strStr(string haystack, string needle) {
			if(needle.empty()) return 0;
			else if(needle.length() > haystack.length()) return -1;
			for (size_t s = 0; s <= haystack.length() - needle.length(); ++s) {
				size_t i = 0;
				for (i = 0; i < needle.length(); ++i)
					if(needle[i] != haystack[s + i]) break;
				if(i == needle.length()) return s;
			}
			return -1;
		}

};


int main() {
	Solution s;
	cout << s.strStr("ssssa", "a") << endl;

	return 0;
}
