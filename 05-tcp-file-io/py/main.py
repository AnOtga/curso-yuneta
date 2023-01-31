#!/usr/bin/env python

import argparse
import socket

program_version = "TCP File Writer 0.0.1"

parser = argparse.ArgumentParser(description='Connects to a server address through the 8000 port.')
parser.add_argument("-v", "--version", help="Print program version", action="version", version=program_version)
parser.add_argument("--ip", "-i", help="IP to connect to", default="127.0.0.1", type=str)
parser.add_argument("--port", "-p", help="Port to connect to", default=8000, type=int)
parser.add_argument("FILEPATH", help="Path to the file that will be sent through the port", type=str)
args = parser.parse_args()

#######################################################
#      Main Program
#######################################################
def main():
    # Create socket and connect
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print("Connecting to {}:{} ".format(args.ip, args.port))
    sock.connect((args.ip, args.port))

    try:
        # Open file
        with open(args.FILEPATH, "r") as file:
            # Read the file, and send it encoded
            content = file.read()

            print("-- Sending file --\n{}".format(content))
            sock.sendall(content.encode())

    finally:
        #Close
        print("-- Closing socket --")
        sock.close()


if __name__ == "__main__":
    main()