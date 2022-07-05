#!/usr/bin/python3
"""
Locates and replaces a string in the heap of a running process
"""
from sys import argv, exit


def main():
    """find and replace string"""
    if len(argv) != 4:
        print("Usage: {} pid search_string replace_string".format(argv[0]))
        exit(1)
    pid = argv[1]
    searchStr = argv[2]
    replaceStr = argv[3]
    if "" in [pid, searchStr]:
        print("Missing [pid] and/or [search string]")
    elif replaceStr == '':
        replaceStr = ' ' * len(searchStr)

    if len(replaceStr) > len(searchStr):
        exit(1)
    try:
        mapsFile = open("/proc/{}/maps".format(pid), 'r')
    except OSError as e:
        print("Unable to open file proc/{}/maps\nOSError : {}".format(pid, e))
        exit(1)

    print("[*] maps: /proc/{}/maps".format(pid))
    print("[*] mem: /proc/{}/mem".format(pid))

    heapFound = None
    for line in mapsFile:
        if "heap" in line:
            heapFound = line.split()
    mapsFile.close()

    if heapFound is None:
        print("No heap found!")
        exit(1)
    else:
        print('\n'.join(("[*] Found: {}".format(heapFound[-1]),
                         "\tpathname = {}".format(heapFound[-1]),
                         "\taddr range = {}".format(heapFound[0]),
                         "\tperm = {}".format(heapFound[1]),
                         "\toffset (in bytes) = {}".format(heapFound[2]),
                         "\tinode = {}".format(heapFound[4]))))
    addr = heapFound[0].split('-')
    print("[*] Addresses start [{}] | end [{}]".format(addr[0].lstrip('0'),
                                                       addr[1].lstrip('0')))

    perms = heapFound[1]
    if 'r' not in perms:
        print("Heap does not have read permission")
        exit(0)
    if 'w' not in perms:
        print("Heap does not have write permission")
        exit(0)

    try:
        memFile = open("/proc/{}/mem".format(pid), 'rb+')
    except OSError as e:
        print("Can't open file /proc/{}/mem: OSError: {}".format(pid, e))
        exit(1)

    heapStart = int(addr[0], 16)
    heapEnd = int(addr[1], 16)
    memFile.seek(heapStart)
    heap = memFile.read(heapEnd - heapStart)
    offset = heap.find(bytes(searchStr, "ASCII"))
    if offset == -1:
        print("can't find {} in /proc/{}/mem".format(searchStr, pid))
        exit(1)
    else:
        print("[*] Writing '{}' at {}".format(replaceStr,
                                              hex(heapStart + offset)[2:]))


if __name__ == "__main__":
    main()
