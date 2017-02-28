/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-09 10:11
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		vector<int> factor = {2, 3, 5};
		bool isUgly(int num) {
			if(num <= 0) return false;
			else if(num == 1 || num == 2 || num == 3 || num == 5) return true;
			for(int i=0; i < factor.size(); ++i)
				if(num % factor[i] == 0) return isUgly(num /= factor[i]);
			return false;
		}
};


int main() {
	Solution s;

	return 0;
}
