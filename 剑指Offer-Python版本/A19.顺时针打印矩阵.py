'''
题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.                      
'''

'''
方法：模拟魔方逆时针旋转的方法
运行时间：24ms
占用内存：5844k
'''

class Solution:
    # matrix类型为二维列表，需要返回列表
    def printMatrix(self, matrix):
        # write code here
        result=[]
        while matrix:
            result+=matrix.pop(0)
            #matrix[0]防止测试用例pop(0)到最后只剩一个元素出错
            if not matrix or not matrix[0]:
                break
            matrix=self.turn(matrix)
        return result
    
    def turn(self,matrix):
        newMat1=[]
        num_row=len(matrix)
        num_colum=len(matrix[0])
        for i in range(num_colum):
            newMat2=[]
            for j in range(num_row):
                newMat2.append(matrix[j][i])
            newMat1.append(newMat2)
        newMat1.reverse()   
        return newMat1
