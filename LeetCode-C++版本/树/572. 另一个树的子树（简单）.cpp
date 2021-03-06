/*
给定两个非空二叉树s和t，检验s中是否包含和t具有相同结构和节点值的子树。s的一个子树包括s的一个节点和这个节点的所有子孙。s也可以看做它自身的一棵子树。
示例1:
给定的树s:
     3
    / \
   4   5
  / \
 1   2
给定的树t：
   4 
  / \
 1   2
返回true，因为t与s的一个子树拥有相同的结构和节点值。
*/

/*
方法：递归法
先判断两棵树是否相等，再判断s的左子树是否与t相等，再判断s的右子树是否与t相等。借用到判断是否相等的函数。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s,TreeNode* t)
    {
        if(!s&&!t) return true;
        if(!s||!t) return false;
        return isSametree(s,t)||isSubtree(s->left,t)||isSubtree(s->right,t);
    }
    bool isSametree(TreeNode* s, TreeNode* t) {
        if(!s&&!t) return true;
        if(!s||!t) return false;
        return s->val==t->val&&isSametree(s->left,t->left)&&isSametree(s->right,t->right);
    }
};
