'''
题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）            
'''

'''
方法：建立一个辅助栈，把push序列的数字依次压入辅助栈，每次压入后，比较辅助栈的栈顶元素和pop序列的首元素是否相等，相等的话，就弹出pop序列的首元素和辅助栈的栈顶元素，若最后辅助栈为空，则push序列可以对应于pop序列。
运行时间：28ms
占用内存：5856k
'''

class Solution:
    def IsPopOrder(self, pushV, popV):
        # write code here
        if not pushV or not popV:
            return False
        #创建辅助栈
        helper=[]
        for i in range(len(pushV)):
            helper.append(pushV[i])
            while helper and helper[-1]==popV[0]:
                helper.pop()
                popV.pop(0)
        if helper:
            return False 
        else:
            return True
