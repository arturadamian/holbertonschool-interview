#!/usr/bin/python3
""" Given a string s, you are allowed to convert it
    to a palindromeby adding characters in front of it.
    Find and return the shortest palindrome
    you can find by performing this transformation.
"""
def shortestPalindrom(s):
    # use Knuth–Morris–Pratt string-searching algorithm 
    revers = s[::-1]
    if s == revers:
        return s
    combo = s + '#' + revers
    kmp = [0] * len(combo)
    x, y = 0, 1
    while y < len(combo):
        if combo[y] == combo[x]:
            x += 1
            kmp[y] = x
            y += 1
        else:
            x = 0
            kmp[y] = x
            y += 1
    prefix = revers[:len(s) - kmp[-1]]
    return prefix + s

if __name__=='__main__':
    shortestPalindrom("abacrd")