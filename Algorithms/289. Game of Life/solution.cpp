/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-18 09:56
 ************************************************************************/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
	public:
		// 生命游戏
		// mark存储下一个状态
		// 看到题解有人存储下一个状态到board的第二比特位上

		int neighbors(vector<vector<int>>& board, int &m, int &n, int x, int y) {
			int cnt = 0;
			for(int i=x-1; i<=x+1; ++i)
				for(int j=y-1; j<=y+1; ++j)
					if(i>=0 && j>=0 && i<m && j<n) {
						if((i != x || j != y)) cnt += board[i][j];
					}
			return cnt;
		}
		void gameOfLife(vector<vector<int>>& board) {
			int m = board.size();
			if(!m) return;
			int n = board[0].size();
			if(!n) return;
			vector<vector<int>> mark(board.begin(), board.end());
			for (int i = 0; i < m; ++i)
				for (int j = 0; j < n; ++j) {
					int nebs = neighbors(board, m, n, i, j);
					if(nebs < 2 || nebs > 3) mark[i][j] = 0;
					else if(nebs == 3) mark[i][j] = 1;
				}
			board = mark;
		}
};


int main() {
	Solution s;
	vector<vector<int>> board({
			{1, 1},
			{1, 0},
			});
	s.gameOfLife(board);
	return 0;
}
