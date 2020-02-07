#!/usr/bin/python3
import numpy

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
    keys = set(boxes[0])
    x = 0
    while lockers:
        if x == len(lockers):
            break
        if lockers[x] in keys:
            keys.update(boxes[lockers[x]])
            keys.remove(lockers[x])
            lockers.remove(lockers[x])
            x = 0
        else:
            x += 1
    if lockers == []:
        return True
    else:
        return False
