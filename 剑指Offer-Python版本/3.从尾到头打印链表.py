'''
题目：输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
'''

'''
方法：用insert()，一直在index=0的位置插入遍历的值
运行时间：30ms
占用内存：5708k
'''

# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        # write code here
        if not listNode:
            return []
        
        list=[]
        
        while listNode:
            list.insert(0,listNode.val)
            listNode=listNode.next
            
        return list
