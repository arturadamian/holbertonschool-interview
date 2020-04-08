#!/usr/bin/python3

""" UTF-8 validation
    Takes some data and
    Return: True if data is a valid UTF-8 encoding, else return False
"""


def validUTF8(data):

    countBytes = 0
    for num in data:
        binNum = format(num, '#010b')[-8:]
        if countBytes == 0:
            for bit in binNum:
                if bit == '0':
                    break
                countBytes += 1
            if countBytes == 0:
                continue
            if countBytes == 1 or countBytes > 4:
                return False
        else:
            if not (binNum[0] == '1' and binNum[1] == '0'):
                return False
        countBytes -= 1
    return countBytes == 0
