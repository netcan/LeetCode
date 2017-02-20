/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-02-20 08:58
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
	public:
		unordered_map<int, bool> hash; // 判断数字是否重复
		bool isHappy(int n) {
			if(n == 1) return true;
			else if(hash[n]) return false;
			hash[n] = true;
			int sum = 0;
			while(n) {
				sum += (n%10) * (n%10);
				n /= 10;
			}
			return isHappy(sum);
		}
};


int main() {
	Solution s;
	cout << s.isHappy(18) << endl;

	return 0;
}
