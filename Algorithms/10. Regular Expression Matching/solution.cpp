/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2019-09-11 21:49
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
// .*a
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
        return isMatch(s.c_str(), 0, p.c_str(), 0, dp);
    }
    bool isMatch(const char* s, int si, const char *p, int pi, vector<vector<int>> &dp) {
        if(dp[si][pi] != -1) return dp[si][pi];
        if(strlen(p) == pi) return strlen(s) == si;
        bool firstMatch = strlen(s) > si && (s[si] == p[pi] || p[pi] == '.');

        bool match;
        if(strlen(p) > pi + 1 && p[pi + 1] == '*')
            match = isMatch(s, si, p, pi + 2, dp) || (firstMatch && isMatch(s, si + 1, p, pi, dp));
        else match = firstMatch && isMatch(s, si + 1, p, pi + 1, dp);
        return dp[si][pi] = match;
    }

};

int main() {
    Solution s;
    assert(s.isMatch("abc", "abc") == true);
    assert(s.isMatch("ab", "abc") == false);
    assert(s.isMatch("abc", "ab") == false);
    assert(s.isMatch("abc", "ab.") == true);
    assert(s.isMatch("abc", "ab.*") == true);

}
