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
		vector<int> getNext(string needle) {
			vector<int> next(needle.length());
			int j = -1;
			next[0] = j;
			for (size_t i = 1; i < needle.length(); ++i) {
				while(j > -1 && needle[j+1] != needle[i]) j = next[j];
				if(needle[j+1] == needle[i]) ++j;
				next[i] = j;
			}
			return next;
		}
		int strStr(string haystack, string needle) {
			if(needle.empty()) return 0;
			else if(needle.length() > haystack.length()) return -1;
			vector<int> next = getNext(needle);

			int j = -1;
			for (int i = 0; i < haystack.length(); ++i) {
				while(j > -1 && needle[j+1] != haystack[i]) j = next[j];
				if(needle[j+1] == haystack[i]) ++j;
				if(j == needle.length() - 1) return i - j;
			}

			return -1;
		}

};


int main() {
	Solution s;
	cout << s.strStr("ssssa", "a") << endl;

	return 0;
}
