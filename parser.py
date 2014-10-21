#! /usr/bin/env python
import sys
from xml.dom.minidom import parse
def open(xml_file):
 xml = parse(xml_file)
 student = xml.getElementsByTagName('student')
 for node in student:
     print node.childNodes[0].nodeValue
def main(argv):
 if len(argv) != 2:
  sys.stderr.write("Usage : %s xml_file" % (argv[0],))
 else:
  open(argv[1])
if __name__ == '__main__': main(sys.argv)
