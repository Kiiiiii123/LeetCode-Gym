/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。你可以假设数组中无重复元素。
示例１：输入：[1,3,5,6], 5　输出：２
示例２：输入：[1,3,5,6], 2　输出：１
*/

/*方法：二分查找
如果该题目暴力解决的话需要Ｏ(n)的时间复杂度，但是如果二分的话则可以降到Ｏ(logn)的时间复杂度，整体思路和普通的二分查找几乎没有区别，先设定左侧下标left和右侧下标right，在计算中间下标mid,每次根据nums[mid]和target之间的大小进行判断，相等则直接返回下标，nums[mid]<target则left右移，nums[mid]>target则right左移，查找结束如果没有相等值则返回left，该值为插入位置。二分查找的思路不难理解，但是边界条件容易出错，比如循环结束条件中left和right的关系，更新left和right的位置时要不要加１减１。
时间复杂度：Ｏ(logn)
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left =0;
        int right = nums.size()-1;
        while( left <= right )  /*注意边界*/
        {
            int mid = ( left + right )/2;
            if( nums[mid] == target )
                return mid;
            else if( nums[mid] > target )
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return left;
    }
};
