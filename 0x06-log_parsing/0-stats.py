#!/usr/bin/python3
import fileinput
import sys
import operator
import time

"""Write a script that reads stdin line by line and computes metrics
"""


def inputMetrix():
    """
        gets data from stdin formats it
        and prints to stdout
    """

    k = 0
    fileSize = 0
    statusCodes = {}
    try:
        for line in iter(sys.stdin.readline, b''):
            k = k + 1
            fileSize += int(line.split()[-1])
            code = int(line.split()[-2])
            if code in statusCodes:
                statusCodes[code] += 1
            else:
                statusCodes[code] = 0
            if k % 10 == 0:
                printMetrix(fileSize, statusCodes)
    except KeyboardInterrupt:
        printMetrix(fileSize, statusCodes)
        pass


def printMetrix(fileSize, statusCodes):
    """
        prints the metrix
    """

    print("File size: {}".format(fileSize))
    sortedStatusCodes = sorted(statusCodes.items(), key=operator.itemgetter(0))
    for status, count in sortedStatusCodes:
        if count:
            print("{}: {}".format(status, count))

if __name__ == '__main__':
    inputMetrix()
