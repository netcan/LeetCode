/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-20 11:03
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
	public:
		string addStrings(string num1, string num2) {
			int i = num1.size() - 1, j = num2.size() - 1;
			bool shift = 0;
			string ans;
			while(i>=0 || j>=0 || shift) {
				ans.push_back(((i>=0?num1[i]-'0':0) + (j>=0?num2[j]-'0':0) + shift) % 10 + '0');
				shift = ((i>=0?num1[i]-'0':0) + (j>=0?num2[j]-'0':0) + shift) / 10;
				--i, --j;
			}

			if(shift) ans.push_back(shift + '0');
			reverse(ans.begin(), ans.end());
			return ans;
		}
};


int main() {
	Solution s;

	return 0;
}
