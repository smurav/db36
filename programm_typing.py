#! /usr/bin/env python
import sys, libxml2

def open(mephi_xml):
  doc = libxml2.parseFile(mephi_xml)
  doc.freeDoc()

def main(argv):
  open(argv[1])
  from xml.dom.minidom import *

  xml = parse('mephi.xml')
  name = xml.getElementsByTagName('student')

for node in name:
  print node.childNodes[0].nodeValue


if __name__ == '__main__':
  main(sys.argv)
