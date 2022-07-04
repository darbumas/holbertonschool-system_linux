#!/usr/bin/python3
"""
Locates and replaces a string in the heap of a running process
"""
import sys


def main():
    """find and replace string"""
    if len(sys.argv) != 4:
        print("Usage: read_write_heap.py pid search_string replace_string")
        exit(1)
    pid = sys.argv[1]
    searchStr = sys.argv[2]
    replaceStr = sys.argv[3]

    if len(replaceStr) > len(searchStr):
        exit(1)

    try:
        mapsFile = open("proc/{}/maps".format(pid), 'r')
    except Exception as e:
        print(e)
        exit(1)

    try:
        memFile = open("proc/{}/mem".format(pid), 'r+b', 0)
    except Exception as e:
        mapsFile.close()
        print(e)
        exit(1)

    heap = False
    for line in mapsFile.readlines():
        strLine = line.split()
        if strLine[len(strLine) - 1] == "[heap]":
            heap = True
            rangeMem = strLine[0].split('-')
            strart = int(rangeMem[0], 16)
            end = int(rangeMem[1], 16)
            memFile.seek(start)
            s = memFile.read(end - start)
            idx = s.find(bytes(searchStr, 'utf-8'))

            if idx == -1:
                break

            memFile.seek(start + idx)
            memFile.write(bytes(replaceStr, 'utf-8') +b'\x00')
            break

    mapsFile.close()
    memFile.close()

    if idx == -1:
        exit(1)

    if not heap:
        exit(1)

    print("replacing string in memory: /proc/{}/mem".format(pid))

if __name__ == "__main__":
    main()
