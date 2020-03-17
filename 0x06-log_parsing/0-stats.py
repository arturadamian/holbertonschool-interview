#!/usr/bin/python3
""" Write a script that reads stdin
    line by line and computes metrics
"""

if __name__ == '__main__':

    import sys
    
    def printMetrix(fileSize, statusCodes):
        """
            prints the metrix
        """

        print("File size: {}".format(fileSize))
        for status, count in sorted(statusCodes.items()):
            if count:
                print("{}: {}".format(status, count))

    k = 0
    fileSize = 0
    statusCodes = {}
    try:
        for line in sys.stdin:
            k += 1
            data = line.split()
            try:
                fileSize += int(data[-1])
                code = data[-2]
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
