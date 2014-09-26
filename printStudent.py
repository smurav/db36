#! /usr/bin/env python
import sys, libxml2
from xml.dom.minidom import parse
def open(xml_file): 
  doc = libxml2.parseFile(xml_file) 
  doc.freeDoc()

def main(argv):
  open(argv[1])

xml = parse('mephi_dtd.xml')
name = xml.getElementsByTagName('student')

for node in name:
  print node.childNodes[0].nodeValue
