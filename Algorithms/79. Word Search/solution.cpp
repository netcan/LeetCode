/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-15 10:12:20
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
	public:

		// ['A','B','C','E'],
		// ['S','F','C','S'],
		// ['A','D','E','E']
		bool dfs(vector<vector<char>>& board, string word, int &M, int &N, vector<int> &dx, vector<int> &dy, vector<vector<bool>>& mark, int cur, int x, int y) {
			if(board[x][y] != word[cur] && cur != 0) return false;

			if(cur == word.size() - 1 && board[x][y] == word[cur]) // end
				return true;
			else if(cur >= word.size()) return false;
			mark[x][y] = true;

			if(word[cur] == board[x][y]) {
				for(int i=0; i<4; ++i) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if(nx >= 0 && nx < M && ny >=0 && ny < N && !mark[nx][ny]) { // 下一个状态
						mark[nx][ny] = true;
						if(dfs(board, word, M, N, dx, dy, mark, cur+1, nx, ny)) return true;
						mark[nx][ny] = false;
					}
				}
			}

			mark[x][y] = false;
			return false;
		}

		bool exist(vector<vector<char>>& board, string word) {
			// M行N列
			int M = board.size();
			if(!M) return false;
			int N = board[0].size();

			vector<int> dx = {0, 1, 0, -1}; // 右，下，左，上
			vector<int> dy = {1, 0, -1, 0};
			vector<vector<bool>> mark(M, vector<bool>(N, false));
			for(int i=0; i<M; ++i)
				for (int j = 0; j < N; ++j)
					if(word[0] == board[i][j] && dfs(board, word, M, N, dx, dy, mark, 0, i, j)) return true;
			return false;
		}

};


int main() {
	Solution s;
	vector<vector<char>> board;
	board.push_back(vector<char> {'a', 'b', 'c', 'e'});
	board.push_back(vector<char> {'s', 'e', 'c', 's'});
	board.push_back(vector<char> {'a', 'e', 'e', 'a'});
	cout << s.exist(board, "sae") << endl;

	return 0;
}
