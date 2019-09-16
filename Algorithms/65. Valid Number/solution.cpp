/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2019-09-16 22:38
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 1. [+-]?.[0-9]+
    // 2. [+-]?[0-9]+(.[0-9]*)?
    // (1 or 2)e[+-]?[0-9]+
    bool isNumber(string s) {
        // trim
        while (! s.empty() && s.front() == ' ') s.erase(s.begin());
        while (! s.empty() && s.back() == ' ')  s.pop_back();
        if(s.empty()) return false;

        const char* p = s.c_str();

        if(*p == '+' || *p == '-') ++p;
        if(*p == 0) return false;

        if(*p == '.') {
            ++p; // skip '.'
            if(*p == 0 || !isdigit(*p++)) return false;
            while(*p != 0 && isdigit(*p)) ++p;
        } else {
            if(! isdigit(*p++)) return false;
            while(*p != 0 && isdigit(*p)) ++p;
            if(*p != 0 && *p == '.') {
                ++p; // skip '.'
                while(*p != 0 && isdigit(*p)) ++p;
            }
        }
        if(*p == 0) return true;

        if(*p == 'e') { // match e
            ++p; // skip 'e'
            if(*p == 0) return false;

            if(*p == '+' || *p == '-') ++p;
            if(*p == 0 || ! isdigit(*p++)) return false;

            while(*p != 0 && isdigit(*p)) ++p;
        }

        if(*p == 0) return true;

        return false;
    }

};


int main() {
	Solution s;
    printf("%d\n", s.isNumber("-5.e+2"));

	return 0;
}
