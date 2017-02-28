/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int slice(int P, int Q) { // 假设[P, Q]是一个arithmetic序列
			int len = Q - P + 1;
			if(len < 3) return 0;
			else return (len-2)*(len-1)/2;
		}
		int numberOfArithmeticSlices(vector<int>& A) {
			if(A.size() < 3) return 0;
			int P = 0, ans = 0;
			while(P + 2 < A.size()) {
				if(A[P] - A[P+1] == A[P+1] - A[P+2]) {
					int Q = P+2;
					while(Q+1 < A.size() && A[P]-A[P+1] == A[Q] - A[Q+1]) ++Q;
					ans += slice(P, Q);
					P = Q + 1;
				} else ++P;
			}
			return ans;
		}

};


int main() {
	Solution s;

	return 0;
}
