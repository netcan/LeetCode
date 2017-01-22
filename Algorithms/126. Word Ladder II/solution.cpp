/*************************************************************************
	> File Name: solution.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2017-01-09 10:11
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;


class Solution {
	public:
		void dfs(unordered_map<string, vector<string>>& graph, string &endWord, vector<vector<string>>& ans, vector<string>& path, int &minStep, int curStep) {
			if(curStep >= minStep) return;
			else if(path.back() == endWord) {
				ans.push_back(path);
				return;
			}
			for(auto &p: graph[path.back()]) {
				path.push_back(p);
				dfs(graph, endWord, ans, path, minStep, curStep + 1);
				path.pop_back();
			}
		}

		vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
			vector<vector<string>> ans;
			queue<string> que;
			unordered_map<string, int> wordStep;
			unordered_map<string, vector<string>> graph; // 邻接图
			vector<string> path; // 一条路径
			path.push_back(beginWord);
			int minStep = numeric_limits<int>::max();
			for(auto& s: wordList) wordStep[s] = minStep;
			que.push(beginWord); wordStep[beginWord] = 0;

			while(que.size()) {
				string q = que.front(); que.pop();
				int step = wordStep[q];
				if(step > minStep) break; // 大于最小步数，无需继续查找
				for (int i = 0; i < q.length(); ++i) {
					for(char ch='a'; ch <='z'; ++ch) {
						string newWord = q;
						newWord[i] = ch; // 新单词
						if(wordStep.count(newWord)) { // 字典中有该单词
							if(step + 1 < wordStep[newWord]) {
								wordStep[newWord] = step + 1;
								que.push(newWord);
								graph[q].push_back(newWord);
							} else if(step + 1 == wordStep[newWord]) // 说明队列中已有该单词，无需插入
								graph[q].push_back(newWord);

							if(newWord == endWord) minStep = step+1;
						}
					}
				}
			}

			dfs(graph, endWord, ans, path, minStep, 0);

			return ans;
		}
};


int main() {
	Solution s;
	vector<string> wordList(
			{"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"}
			);
	vector<vector<string>> ans =
		s.findLadders("qa", "sq", wordList);

	for(auto &s: ans) {
		for(auto &ss: s) {
			printf("%s ", ss.c_str());
		}
		puts("");
	}
	return 0;
}
