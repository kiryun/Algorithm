#-*- coding:utf-8 -*-
# using namespace std;

# 정수(int)가 주어지면, 팰린드롬(palindrome)인지 알아내시오. 팰린드롬이란, 앞에서부터 읽으나 뒤에서부터 읽으나 같은 단어를 말합니다.
#  단, 정수를 문자열로 바꾸면 안됩니다.
# Given an integer, check if it is a palindrome.

# 예제)
# Input: 12345
# Output: False

# Input: -101
# Output: False

# Input: 11111
# Output: True

# Input: 12421
# Output: True

def length(source):
    cnt = 0

    while source != 0:
        source /= 10
        cnt += 1
    
    return cnt-1

def soultion(source):
    answer = False
    l = length(source)
    temp = source
    mod = -1
    comp = 0
    for i in range(l, -1, -1):
        mod = temp % 10
        comp += mod * (10 ** i)
        temp /= 10

    if comp == source:
        return True

    return answer

source = 12321# int(input())

print(soultion(source))
