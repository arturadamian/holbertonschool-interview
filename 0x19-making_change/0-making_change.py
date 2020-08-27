#!/usr/bin/python3
"""
    Given a pile of coins of different values,
    determine the fewest number of coins needed
    to meet a given amount total
"""


def makeChange(coins, total):
    """
        return the fewest number of coins
        0 if total less than 1
        or -1 if it is impossible
    """
    if total < 1:
        return 0
    MAX = float('inf')
    arr = [0] + [MAX] * total

    for i in range(1, total + 1):
        for c in coins:
            if c <= i:
                arr[i] = min(arr[i], arr[i - c] + 1)

    return arr[i] if arr[i] != MAX else -1
