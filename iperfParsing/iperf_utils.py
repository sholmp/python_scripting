#!/usr/bin/python
import re
import requests


class IperfServer:
   def __init__(self, hostname, port):
      self.hostname = hostname
      self.port = port


def publicIperfServers(debug=False):
   html = requests.get('https://iperf.fr/iperf-servers.php')
   htmlStr = html.text
   
   # Remove everything except from contents inside <table></table>
   tableStartIdx = htmlStr.find("<table")           
   htmlStr = htmlStr[tableStartIdx:len(htmlStr)]    
   tableEndIdx = htmlStr.find("</table")
   htmlStr = htmlStr[0:tableEndIdx] #see table.html for an example of how htmlStr looks at this point
   
   tableRows = htmlStr.split('<tr>')

   servers = []
   for row in tableRows:
      server = parseTableRow(row)
      if server:
         servers.append(server)
      if(debug):
         print("-----------\n\n", row)
   
   return servers


"""Parse a row in iperf server table into an IperfServer object
   Returns an iPerfServer object on success
   Returns None if unable to parse row"""
def parseTableRow(row):
   row = row.strip()
   lines = row.split('\n')
   if(len(lines) > 5):
      hostnameLine = lines[0]
      portLine = lines[5]
      hostnameRegex = '<strong>(\w[\w-]+\.(?:\w[\w-]+\.)?(?:\w[\w-]+\.)?(?:\w[\w-]+\.)?(?:\w[\w-]+\.)?\w+)'
      portRegex = '(\d+) TCP\/UDP'
      mHostname = re.search(hostnameRegex, hostnameLine)
      mPort = re.search(portRegex, portLine)

      hostname=""
      port=""
      if mHostname and mPort:
         port = mPort[1]
         hostname = mHostname[1]
         
         # print("{}:{}".format(hostname, port))
         return IperfServer(hostname, port)
      else:
         return None
   else:
      return None
