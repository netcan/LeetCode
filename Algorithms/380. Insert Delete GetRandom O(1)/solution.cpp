/*************************************************************************
  > File Name: solution.cpp
  > Author: Netcan
  > Blog: http://www.netcan666.com
  > Mail: 1469709759@qq.com
  > Created Time: 2017-01-23 10:23
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet {
	public:
		/** Initialize your data structure here. */
		RandomizedSet() {

		}

		/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
		bool insert(int val) {
			if(hash.find(val) != hash.end()) return false;
			nums.push_back(val);
			hash[val] = nums.size()-1; // 记录这个数在nums的位置
			return true;
		}

		/** Removes a value from the set. Returns true if the set contained the specified element. */
		bool remove(int val) {
			if(hash.find(val) == hash.end()) return false; // 找不到
			int t = nums.back(); // 将最后一个元素移到删除的元素处
			nums[hash[val]] = t;
			hash[t] = hash[val];
			nums.pop_back();
			hash.erase(val);
			return true;
		}

		/** Get a random element from the set. */
		int getRandom() {
			return nums[random() % nums.size()];
		}
	private:
		vector<int> nums;
		unordered_map<int, int> hash;
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */


int main() {

	return 0;
}
