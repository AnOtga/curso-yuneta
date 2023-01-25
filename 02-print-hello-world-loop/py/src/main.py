#!/usr/bin/env python

import argparse
import time

program_version = "Hello World Loop 0.0.1"

#######################################################
#      Main Program
#######################################################
def main():
    parser = argparse.ArgumentParser(description='Prints a specified number of "Hello World" lines.')
    parser.add_argument("-v", "--version", help="Print program version", action="version", version=program_version)
    parser.add_argument("--lines", "-l", help="Number of lines to print, defaults to 100", default=100, type=int)
    args = parser.parse_args()

    st = time.time()
    for i in range(args.lines):
        print("Hello World")
    et = time.time()

    print("Time taken to execute {} prints: {}".format(args.lines, et - st))

if __name__ == "__main__":
    main()