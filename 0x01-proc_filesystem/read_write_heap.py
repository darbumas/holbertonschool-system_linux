#!/usr/bin/python3
"""
Locates and replaces a string in the heap of a running process
"""
from sys import argv


def read_mapsFile(pid):
    """returns address range of process running"""
    start = None
    stop = None
    try:
        with open("/proc/{:d}/maps".format(pid), "r") as maps:
            for line in maps:
                if line.endswith("[heap]\n"):
                    start, stop = \
                        [int(x, 16) for x in line.split(" ")[0].split("-")]
    except Exception as e:
        print(e)
        exit(1)
    if not start or not stop:
        print("[ERROR] Heap address not found.") or exit(1)
    print("[*] Heap starts at {:02X}".format(start))
    return start, stop


def read_write_memFile(pid, searchStr, replaceStr, start, stop):
    """locates string in proc/[pid]/mem and overwrites it"""
    try:
        with open("/proc/{:d}/mem".format(pid), "r+b") as mem:
            mem.seek(start)
            data = mem.read(stop - start)
            print("[*] Read {:d} bytes".format(stop - start))
            s = data.find(searchStr.encode())
            if s > -1:
                print("[*] String found at {:02X}"
                      .format(start + s))
                mem.seek(start + s)
                r = mem.write(replaceStr.encode() + b'\x00')
                print("[*] {:d} bytes written!".format(r))
            else:
                print(
                    "[ERROR] String '{:s}' not found in heap."
                    .format(searchStr))
                exit(1)
    except Exception as e:
        print(e)
        exit(1)


if __name__ == "__main__":
    if len(argv) < 4 or len(argv[2]) < len(argv[3]):
        print("Usage: {} pid search_string replace_string".format(argv[0]))
        exit(1)
    start, stop = read_mapsFile(int(argv[1]))
    read_write_memFile(int(argv[1]), argv[2], argv[3], start, stop)
