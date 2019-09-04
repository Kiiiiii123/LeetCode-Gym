'''
题目：输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
'''

'''
方法一：会陷入死循环，先判断该数最低位是不是1，是则count加一右移，否则直接右移，直至该数变为0 。将该数与1相与判断最低位是否为1，结果为1说明最低位为1，否则为0.这种解法有一个明显缺点：当输入为负数时，由于负数在计算机中用补码表示，最高位是符号位1，因此不断右移的过程中最高位不断补1，造成死循环。
'''

class Solution:
    def NumberOf1(self, n):
        # write code here
        count = 0
        while n:
            if n & 1:
                count += 1
            n = n >> 1
        return count
      
'''
方法二：如果一个整数不为0，那么这个整数至少有一位是1，如果把这个整数减1，那么原来处在整数最右边的1就会变为0，原来在1后面的所有的0都会变成1(如果最右边的1后面还有0的话)，其余所有位将不会受到影响。减1的结果是把最右边的一个1开始的所有位都取反了。这个时候如果再把原来的整数和减去1之后的结果做与运算，从原来整数最右边一个1那一位开始所有位都会变成0，把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0.那么一个整数的二进制有多少个1，就可以进行多少次这样的操作。
运行时间：23ms
占用内存：5860k
'''

class Solution:
    def NumberOf1(self, n):
        # write code here
        count=0
        if n<0:
            n=n&0xffffffff
        while n:
            count+=1
            n=n&(n-1)
        return count
