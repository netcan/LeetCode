/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-09 10:11
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
	public:
		int romanToInt(string s) {
			transform(s.begin(), s.end(), s.begin(), ::toupper);
			unordered_map<string, int> roman({
					{"M", 1000},
					{"CM",  900},
					{"D", 500},
					{"CD",  400},
					{"C", 100},
					{"XC",  90},
					{"L", 50},
					{"XL",  40},
					{"X", 10},
					{"IX",  9},
					{"V", 5},
					{"IV",  4},
					{"I", 1},
					});


			int i = 0;
			int sum = 0;
			while(i < s.size()) {
				string tmp(s, i, 2);
				if(roman.count(tmp)) {
					sum += roman[tmp];
					i+=2;
				}
				else {
					sum += roman[string(1, tmp[0])];
					++i;
				}
			}

			return sum;
		}

};


int main() {
	Solution s;
	cout << s.romanToInt("DCXXI") << endl;

	return 0;
}
