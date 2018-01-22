#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#author: 金泽文 - King Zevin
#

from collections import deque

s0 = 0
s1 = 1
s2 = 2
s3 = 3
s4 = 4

def s0to1(dq, alpha):
    return dq[-1] == s0 
def s1to2(dq, alpha):
    return dq[-1] == s1 and alpha == 'a'
def s2to2(dq, alpha):
    return dq[-1] == s2 and alpha == 'a'
def s0to3(dq, alpha):
    return dq[-1] == s0 
def s3to4(dq, alpha):
    return dq[-1] == s3 and alpha == 'b'
def s4to4(dq, alpha):
    return dq[-1] == s4 and alpha == 'b'

def nfa(word):
    dq=deque()
    dq.append(s0)
    cursor = 0 
    length = len(word)
    fail = False
    last = -1

    while cursor != length:
        if not(fail and last == s1) and s0to1(dq, word[cursor]):
            dq.append(s1)
            # print(cursor, word[cursor], 36)
        elif not(fail and last == s2) and s1to2(dq, word[cursor]):
            dq.append(s2)
            # print(cursor, word[cursor], 39)
            cursor = cursor + 1
        elif not(fail and last == s2) and s2to2(dq, word[cursor]):
            dq.append(s2)
            # print(cursor, word[cursor], 43)
            cursor = cursor + 1
        elif not(fail and last == s3) and s0to3(dq, word[cursor]):
            dq.append(s3)
            # print(cursor, word[cursor], 47)
        elif not(fail and last == s4) and s3to4(dq, word[cursor]):
            dq.append(s4)
            # print(cursor, word[cursor], 50)
            cursor = cursor + 1
        elif not(fail and last == s4) and s4to4(dq, word[cursor]):
            dq.append(s4)
            # print(cursor, word[cursor], 54)
            cursor = cursor + 1
        else:
            last = dq.pop()
            fail = True
            # print(cursor, word[cursor], 59)
            if cursor == 0 and last == s3:
                return False
            cursor = cursor - 1
            if cursor < 0:
                cursor = 0
            
            continue
        fail = False
    return cursor == length

# def notin(token, tokens):
#     for i in tokens:
#         if token in i:
#             return False
#     return True

string = input('Please input the string you want to recognize: ')
# tokens=[]

for i in range(0, len(string)):
    flag = True
    j = len(string)
    while flag:
        if nfa(string[i:j]):
            # if notin(string[i:j], tokens):
                # tokens.append(string[i:j])
                # print(string[i:j])
            print(string[i:j])
            flag = False
        j = j - 1
