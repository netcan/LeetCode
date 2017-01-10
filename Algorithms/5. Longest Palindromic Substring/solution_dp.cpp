/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-10 09:34
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Solution {
	public:
		string longestPalindrome(string s) {
			// 动态规划算法
			// dp[i][j]表示s[i,j]为回文串
			// dp[i][j] == (dp[i+1][j-1] && s[i] == s[j])
			// dp[i][i] = true, dp[i][i+1] = true if s[i] = s[i+1]
			bool dp[1000+1][1000+1];
			int maxlen = 1, index = 0;
			for(int i=s.length() - 2; i>=0; --i) {
				for(int j=i; j<s.length(); ++j) {
					if(i == j || (j-i == 1 && s[i] == s[j])) dp[i][j] = true;
					else
						dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);

					if(dp[i][j] && j-i+1 > maxlen) {
						maxlen = j-i+1;
						index = i;
					}
				}
			}
			return s.substr(index, maxlen);
		}
};


int main() {
	Solution s;
	cout << s.longestPalindrome("ab") << endl;
	return 0;
}
