[Next Permutation](https://leetcode.com/problems/next-permutation/)

意思就是给定一个序列，求下一个排列数。下一个排列数是指重排序列，使得下一个序列的字典序比当前序列要大，如果找不到，就返回最小字典序的那个序列。

要求是一步到位，不能分配多余的内存。

这个题貌似是要求实现C++的`next_permutation`函数，然后去瞄了一眼其实现：

```cpp
template<class BidirIt>
bool next_permutation(BidirIt first, BidirIt last)
{
    if (first == last) return false;
    BidirIt i = last;
    if (first == --i) return false;

    while (true) {
        BidirIt i1, i2;

        i1 = i;
        if (*--i < *i1) {
            i2 = last;
            while (!(*i < *--i2))
                ;
            std::iter_swap(i, i2);
            std::reverse(i1, last);
            return true;
        }
        if (i == first) {
            std::reverse(first, last);
            return false;
        }
    }
}
```

看了代码貌似很简单，都能口算下一个排列数了= =

思路很简单，就是

1. 从后往前找，如果找到一个数`x[i]`，使得`x[i] < x[i+1]`，记下这个下标`i`
2. 如果`i==0`，并且`x[0] >= x[1]`，那么说明没有下一个排列数，即**降序**，那么就将其逆序得到升序序列，使得字典序最小。否则进入3
3. 然后又从后往前找，使得`x[i] < x[j]`，记下这个下标`j`，交换`x[i]`与`x[j]`，并将`i`后面的数逆序。

简要说明下，第一步是找出第一个可交换的位置`i`，第二步判断有没有下一个排列数。

那么说明`i`后面的数都是**降序**的， 然后又从后往前找，找到一个数`x[j]`使得`x[i] < x[j]`，这个`x[j]`即是`i`后面最小的一个大于`x[i]`的数。

交换`x[i]`与`x[j]`，那么字典序会变大，因为`i`后面的数都是**降序**的，那么将其逆序得到升序，那么使得字典序最小，总而言之，就是求出一个最小的变大字典序序列。

最后给出`AC`代码：

```cpp
class Solution {
	public:
		void nextPermutation(vector<int>& nums) {
			int N = nums.size();
			if(!N || N == 1) return;
			int i = N - 2, j = N-1;
			while(i>0 && !(nums[i] < nums[i+1])) --i; // 步骤1

			if(i == 0 && !(nums[i] < nums[i+1])) reverse(nums.begin(), nums.end()); // 步骤2
			else {
				while(j > i && !(nums[i] < nums[j])) --j; // 步骤3
				swap(nums[i], nums[j]);
				reverse(nums.begin()+i+1, nums.end());
			}
		}
};
```
