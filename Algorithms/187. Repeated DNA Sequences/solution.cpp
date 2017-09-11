/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-09-11 Mon 20:24:01 CST
 ************************************************************************/

#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
		vector<string> ret;
		if(s.size() < 10) return {};
		unordered_map<string, bool> seen, repeated;

		for(size_t i = 0; i + 10 <= s.size(); ++i) {
			string curS = s.substr(i, 10);
			//printf("curS: %s\n", curS.c_str());
			if(seen.find(curS) == seen.end())
				seen.insert(make_pair(curS, true));
			else repeated.insert(make_pair(curS, true));
		}

		for(auto &strPair: repeated)
			ret.push_back(strPair.first);

		return ret;
    }
};

int main(void) {
	Solution s;
	vector<string> v = s.findRepeatedDnaSequences("AAAAAAAAAAA");
	for(auto ss: v)
		cout << ss << endl;

	return 0;
}
