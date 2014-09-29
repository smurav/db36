#! /usr/bin/env python
import sys, libxml2
def open(xml_file): 
 doc = libxml2.parseFile(xml_file)  
 doc.freeDoc()

def main(argv):
 open(argv[1])
from xml.dom.minidom import *

xml = parse('KiBmephi.xml')
name = xml.getElementsByTagName('student')

for node in name:
	print node.childNodes[0].nodeValue