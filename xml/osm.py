#! /usr/bin/env python
# -*- coding: utf-8 -*-
import sys, libxml2

def open(xml_file, query):  
  doc = libxml2.parseFile (xml_file) 
  ctxt = doc.xpathNewContext()
  students = ctxt.xpathEval(query)
  for st in students:
  	print st
  	print
  ctxt.xpathFreeContext()
  doc.freeDoc()

def main(argv):
  query = '//tag[@k="building"][@v="university"]/..'
  open("map1.osm", query)

if __name__ == '__main__':
	main(sys.argv)
