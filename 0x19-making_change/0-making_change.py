#!/usr/bin/python3


def makeChange(coins, total):
    if total < 1:
        return 0
    MAX = float('inf')
    arr = [0] + [MAX] * total

    for i in range(1, total + 1):
        for c in coins:
            if c <= i:
                arr[i] = min(arr[i], arr[i - c] + 1)

    return arr[i] if arr[i] != MAX else -1

# if __name__=='__main__':
#     print(makeChange([1, 2, 25], 37))
#     print(makeChange([1256, 54, 48, 16, 102], 1453))
