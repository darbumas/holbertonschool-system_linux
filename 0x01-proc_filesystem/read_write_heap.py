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
    
    mapsFile = "/proc/{}/maps".format(pid)
    memFile = "/proc/{}/mem".format(pid)

    heap = {
        "start": '',
        "end": '',
        "mode": '',
        "mem": ''
    }
    with open(mapsFile) as maps:
        for line in maps:
            if "[heap]" in line:
                s = line.split()
                s[0] = s[0].split('-')
                s[0] = list(map(lambda x: int('0x' + x, 16), s[0]))
                [heap['start'], heap['end']] = s[0]
                heap['mode'] = s[1]
                break
    if heap['start'] == '':
        print("Missing heap")
        exit(2)

    with open(memFile, 'rb+') as mem:
        mem.seek(heap['start'])
        heap['mem'] = mem.read(heap['end'] - heap['start'])
        try:
            i = heap['mem'].index(bytes(searchStr, "ASCII"))
        except ValueError:
            print("Not matching string")
            exit(3)
        mem.seek(heap['start'] + i)
        mem.write(bytes(replaceStr, "ASCII"))

if __name__ == "__main__":
    main()
