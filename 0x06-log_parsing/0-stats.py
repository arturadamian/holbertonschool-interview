#!/usr/bin/python3
import fileinput
import sys
import operator


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
        for line in sys.stdin:
            k += 1
            data = line.split()
            try:
                fileSize += int(data[-1])
                code = int(data[-2])
                if code in statusCodes:
                    statusCodes[code] += 1
                else:
                    statusCodes[code] = 0
            except BaseException:
                pass
            if k % 10 == 0:
                printMetrix(fileSize, statusCodes)
        printMetrix(fileSize, statusCodes)
    except KeyboardInterrupt:
        printMetrix(fileSize, statusCodes)
        raise


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
