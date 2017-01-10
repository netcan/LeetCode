/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-10 10:28
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Solution {
	public:
		string convert(string s, int numRows) {
			if(numRows == 1) return s;
			char ans[s.length()];
			char zigzag[numRows][s.length()];
			memset(zigzag, 0, sizeof(zigzag));

			int x = 0, y = 0;
			bool corner = false;
			size_t index = 0;
			while(index < s.length()) {
				// printf("x=%d, y=%d, c=%c\n", x, y, s[index]);
				if(corner) {
					zigzag[x][y] = s[index++];
					++y;
					--x;
					if(x == 0) corner = false;
				}
				else {
					zigzag[x][y] = s[index++];
					++x;
					if(x >= numRows - 1) corner = true;
				}
			}

			index = 0;
			for(int i=0; i<numRows; ++i)
				for(int j=0; j<=y; ++j)
					if(zigzag[i][j]) ans[index++] = zigzag[i][j];
			ans[index] = 0;
			return string(ans);
		}
};


int main() {
	Solution s;
	cout << s.convert("123456", 2) << endl;
	return 0;
}
