/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-10 19:50
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
		vector<int> getRow(int rowIndex) {
			int ans[2][rowIndex+1];
			ans[0][0] = 1;
			bool cur = 1;
			for(int i=1; i<=rowIndex; ++i) {
				for(int j=0; j<=i; ++j) {
					if(j==0 || j == i) ans[cur][j] = 1;
					else ans[cur][j] = ans[!cur][j-1] + ans[!cur][j];
				}
				cur = !cur;
			}

			return vector<int>(ans[!cur], ans[!cur] + sizeof(ans[!cur])/sizeof(ans[!cur][0]));
		}
};


int main() {
	Solution s;
	vector<int> ans = s.getRow(3);
	for(int i=0; i<ans.size(); ++i)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}
