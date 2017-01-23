/*************************************************************************
  > File Name: solution.cpp
  > Author: Netcan
  > Blog: http://www.netcan666.com
  > Mail: 1469709759@qq.com
  > Created Time: 2017-01-23 16:56
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class RandomizedCollection {
	public:
		/** Initialize your data structure here. */
		RandomizedCollection() {
		}
		/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
		bool insert(int val) {
			bool ret = (hash.find(val) == hash.end()); // 判断找不找得到
			nums.push_back(val);
			if(ret)
				hash[val] = vector<int>({int(nums.size() - 1)});
			else hash[val].push_back(nums.size() - 1);

			return ret;
		}
		/** Removes a value from the collection. Returns true if the collection contained the specified element. */
		bool remove(int val) {
			if(hash.find(val) == hash.end())  return false; // 判断找不找得到
			int t = nums.back(); // 将最后一个元素挪到前面
			int pos = hash[val].back();
			hash[val].pop_back();
			nums[pos] = t;
			for(auto &i: hash[t])
				if(i == nums.size() - 1) {
					i = pos;
					break;
				}
			nums.pop_back();
			if(hash[val].empty()) hash.erase(val);

			return true;
		}
		/** Get a random element from the collection. */
		int getRandom() {
			return nums[random() % nums.size()];
		}
	private:
		unordered_map<int, vector<int>> hash; // 记录元素的位置
		vector<int> nums; // 存储元素

};
/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
int main() {

	return 0;
}
