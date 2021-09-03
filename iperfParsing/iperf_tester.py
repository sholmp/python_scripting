#!/usr/bin/python
import iperf_utils as iu
import os

if __name__ == "__main__":
    servers = iu.publicIperfServers()

    print("-"*20)
    for s in servers[1:2]:
        print("{}:{}".format(s.hostname, s.port))

        os.system("iperf3 -c {} -p {}".format(s.hostname, s.port))

