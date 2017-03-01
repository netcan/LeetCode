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
		// 利用堆求第k大的元素
		void buildHeap(vector<int> & nums) {
			size_t N = nums.size();
			for(int parent = (N-1)>>1; parent >=0; --parent) {
				int x = nums[parent];
				for(size_t child = parent*2 + 1; child < N; child = parent * 2 + 1 ) { // child默认左结点
					if(child + 1 < N && nums[child + 1] > nums[child]) ++child; // 使得child指向最大节点
					if(x >= nums[child]) break;
					nums[parent] = nums[child];
					parent = child;
				}
				nums[parent] = x;
			}
		}

		int popHeap(vector<int> &nums) {
			if(nums.empty()) return -1;
			int x = nums.back(); nums.pop_back();
			size_t N = nums.size();
			int max = nums[0];
			int parent = 0;

			for(size_t child = parent*2 + 1; child < N; child = parent * 2 + 1 ) { // child默认左结点
				if(child + 1 < N && nums[child + 1] > nums[child]) ++child; // 使得child指向最大节点
				if(x >= nums[child]) break;
				nums[parent] = nums[child];
				parent = child;
			}

			nums[parent] = x;
			return max;
		}

		int findKthLargest(vector<int>& nums, int k) {
			if(nums.empty()) return -1;
			buildHeap(nums);
			int ans = nums[0];
			for(int i=0; i<k; ++i)
				ans = popHeap(nums);
			return ans;
		}

};


int main() {
	Solution s;
	vector<int> nums = {
		1,2,3
	};
	cout << s.findKthLargest(nums, 3) << endl;

	return 0;
}
