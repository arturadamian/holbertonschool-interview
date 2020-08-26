#!/usr/bin/python3


def makeChange(coins, total):
    if total < 1:
        return 0
    MAX = float('inf')
    arr = [0] + [MAX] * total

    for i in range(1, total + 1):
        for c in coins:
            if i - c >= 0:
                arr[i] = min([arr[i - c]]) + 1

    return [arr[total], -1][arr[total] == MAX]
