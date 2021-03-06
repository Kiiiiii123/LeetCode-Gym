/*
给定一个整数数组nums和一个目标值target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
示例：给定nums = [2,7,11,15],target = 9，因为nums[0] + nums[1] = 2 + 7 = 9,所以返回[0,1]
*/

/*方法一：暴力法
遍历每个元素x，并查找是否存在一个值与target-x相等的目标元素。
时间复杂度：O(n^2) 对于每个元素，我们试图通过遍历数组的其余部分来寻找它所对应的目标元素，这将耗费O(n)的时间。因此时间复杂度为O(n^2)。
空间复杂度：O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        for(i = 0 ;i<nums.size()-1;i++)
        {
            for(j = i+1;j<nums.size();j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    return {i,j};
                }
            }
        }
        return {i,j};
    }
};

/*方法二：两遍哈希表
为了对运行时间复杂度进行优化，我们需要一种更有效的方法来检查数组中是否存在目标元素。如果存在，我们需要找出它的索引。保持数组中的每个元素与其索引相互对应的最好方法是什么？哈希表。
通过以空间换取速度的方式，我们可以将查找时间从O(n)降低到O(1)。哈希表正是为此目的而构建的，它支持以近似恒定的时间进行快速查找。用“近似”来描述，是因为一旦出现冲突，查找用时可能会退化到O(n^2)。但只要仔细地挑选哈希函数，在哈希表中进行查找的用时应当被摊销为O(1)。
一个简单的实现使用了两次迭代。在第一次迭代中，我们将每个元素的值和它的索引添加到表中。然后，在第二次迭代中，我们将检查每个元素所对应的目标元素（target−nums[i]）是否存在于表中。注意，该目标元素不能是nums[i]本身！
时间复杂度：O(n) 我们把包含有n个元素的列表遍历两次。由于哈希表将查找时间缩短到O(1)，所以时间复杂度为O(n)。
空间复杂度：O(n) 所需的额外空间取决于哈希表中存储的元素数量，该表中存储了n个元素。
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> a;  /*map是STL的一个关联容器，它提供一对一（其中第一个可以称为关键字，每个关键字只能在map中出现一次，第二个可能称为该关键字的值）的数据处理能力*/
        vector<int> b(2,-1);  
        for(int i=0;i<nums.size();i++)
            a.insert(map<int,int>::value_type(nums[i],i));
        for(int i=0;i<nums.size();i++)
        {
            if(a.count(target-nums[i])>0 && a[target-nums[i]]!=i)
            {
                b[0] = i;
                b[1] = a[target-nums[i]];
                break;
            }
        }
        return b ;
    }
};

/*方法三：一遍哈希表
在进行迭代并将元素插入到表中的同时，我们还会回过头来检查表中是否已经存在当前元素所对应的目标元素。如果它存在，那我们已经找到了对应解，并立即将其返回。
时间复杂度：O(n) 我们只遍历了包含有n个元素的列表一次。在表中进行的每次查找只花费O(1)的时间。
空间复杂度：O(n) 所需的额外空间取决于哈希表中存储的元素数量，该表最多需要存储n个元素。
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> a;
        vector<int> b(2,-1);
        for(int i=0;i<nums.size();i++)
        {
            if(a.count(target-nums[i])>0 && a[target-nums[i]]!=i)
            {
                b[0] = i;
                b[1] =a[target-nums[i]];
                break;
            }
            a[nums[i]] = i;
        }
        return b;
    }
};

