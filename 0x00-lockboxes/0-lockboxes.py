#!/usr/bin/python3

""" You have n number of locked boxes in front of you.
    Each box is numbered sequentially from 0 to n - 1 and
    each box may contain keys to the other boxes.
    Write a method that determines if all the boxes can be opened.

    Prototype: def canUnlockAll(boxes)
    boxes is a list of lists
    A s with the same number as a box opens that box
    You can assume all keys will be positive integers
    The first box boxes[0] is unlocked
    Return True if all boxes can be opened, else return False
"""


def canUnlockAll(boxes):
    if len(boxes) == 0:
        return True
    lockers = list(range(1, len(boxes)))
    print(boxes)
    print(lockers)
    keys = boxes[0]
    print(keys)
    x = 0
    while x < len(keys):
        if keys[x] in lockers:
            lockers.remove(keys[x])
            keys.extend(boxes[keys[x]])
            keys.remove(keys[x])
            x = 0
            if lockers == []:
                return True
        else:
            x += 1
    return False
