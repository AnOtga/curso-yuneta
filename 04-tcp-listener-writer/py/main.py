#!/usr/bin/env python

import argparse
import socket

program_version = "TCP Writer 0.0.1"

parser = argparse.ArgumentParser(
    description='Connects to a server address through the 8000 port.')
parser.add_argument("-v", "--version", help="Print program version",
                    action="version", version=program_version)
parser.add_argument(
    "--ip", "-i", help="IP to connect to", default="127.0.0.1", type=str)
parser.add_argument(
    "--port", "-p", help="Port to connect to", default=8000, type=int)
parser.add_argument(
    "MESSAGE", help="Message to send through", type=str)
args = parser.parse_args()

#######################################################
#      Main Program
#######################################################
def main():
    # Create socket and connect
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((args.ip, args.port))

    try:
        sock.sendall(args.MESSAGE)

    finally:
        #Close
        sock.close()


if __name__ == "__main__":
    main()
