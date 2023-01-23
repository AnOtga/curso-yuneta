import argparse
import time

parser = argparse.ArgumentParser(description='Prints a specified number of "Hello <name>" lines, where name is the required argument.')

parser.add_argument("name", help="Name to use in the output")
parser.add_argument("--lines", "-l", help="Number of lines to print, defaults to 100", default=100, type=int)
args = parser.parse_args()

st = time.time()
for i in range(args.lines):
    print("Hello {}".format(args.name))
et = time.time()

print("Time taken to execute {} prints: {}".format(args.lines, et - st))

