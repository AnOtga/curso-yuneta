#!/usr/bin/env python3

import argparse
import socket

program_version = "TCP File Writer 0.0.1"

parser = argparse.ArgumentParser(description='Connects to a server address through the 8000 port.')
parser.add_argument("-v", "--version", help="Print program version", action="version", version=program_version)
parser.add_argument("--ip", "-i", help="IP to connect to", default="127.0.0.1", type=str)
parser.add_argument("--port", "-p", help="Port to connect to", default=8000, type=int)
parser.add_argument("--repeat", "-r", help="Times to send the file", default=2, type=int)
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
    print("Connection has been established to {} through {} ".format(sock.getpeername(), sock.getsockname()))

    try:
        print(f'Sending file: {args.FILEPATH} {args.repeat} times.\n')
        nLoop = 0
        while nLoop < args.repeat:
            pathLen = len(args.FILEPATH)
            #We aren't going to send a file yet, so we need to encode things manually
            #Send path length in the first four bytes, as if it were the file size.
            sock.sendall(pathLen.to_bytes(4, byteorder='big'))
            sock.sendall(args.FILEPATH.encode())

            netMsg = sock.recv(1024)
            print(f'File status: {netMsg.decode()}\n') 
            with open(args.FILEPATH, 'rb') as f:
                sock.sendall(f.read())

            netMsg = sock.recv(1024)
            print(f'Received: {netMsg.decode()}\n')
            nLoop += 1

    finally:
        #Close
        print("-- Closing socket --")
        sock.close()


if __name__ == "__main__":
    main()
