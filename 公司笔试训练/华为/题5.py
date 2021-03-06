'''
题目：给一组正整数（小于100个），从第一个数开始，可以走1<=step<=len/2步，从第二步开始，必须走该位置所对应的数的步长，问最少几步可以走到最后一个位置，如果不能输出-1.
示例：输入：7 5 9 4 2 6 8 3 5 4 3 9 输出：2，第一步可以走步长2，走到位置arr[2]=9,然后走了9步，到达最后一个位置。
'''

'''
方法： 直接暴力法，可能不是最优的解法。
'''

if __name__=="__main__":
  list=input()
  maxstep=101
  
  for i in range(len(list)/2):
    pos=i
    step=1
    while pos<len(list)-1:
      pos+=list[i]
      step+=1
    if pos==len(list)-1:
      if maxstep>step:
        maxstep=step
  if maxstep==101:
    print(-1)
  else:
    print(maxstep)
  
  
