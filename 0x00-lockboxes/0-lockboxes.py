#!/usr/bin/python3

""" You have n number of locked boxes in front of you.
    Each box is numbered sequentially from 0 to n - 1 and
    each box may contain keys to the other boxes.
    Write a method that determines if all the boxes can be opened.

    Prototype: def canUnlockAll(boxes)
    boxes is a list of lists
    A key with the same number as a box opens that box
    You can assume all keys will be positive integers
    The first box boxes[0] is unlocked
    Return True if all boxes can be opened, else return False
"""

def canUnlockAll(boxes):
    if (len(boxes) == 0) or (len(boxes) == 1 and len(boxes[0]) == 0):
        return True
    index = 0
    keys = list(range(1,len(boxes)))
    shared_box = []
    return canUnlock(boxes, index, keys, shared_box)

def canUnlock(boxes, index, keys, shared_box):
    if keys == []:
        return True
    shared_box.extend(set(boxes[index]))
    for key in range(len(shared_box)):
        if shared_box[key] in keys:
            index = shared_box[key]
            shared_box.remove(index)
            keys.remove(index)
            break
        if key == len(shared_box) - 1:
            return False
    return canUnlock(boxes, index, keys, shared_box)

