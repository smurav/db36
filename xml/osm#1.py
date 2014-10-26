#! /usr/bin/env python
# -*- coding: utf-8 -*-
import sys, libxml2

def main(argv):  
  query = '//tag[@k="building"][@v="university"]/../tag[@k="name"]/attribute::v'
  doc = libxml2.parseFile ("map.osm")
  ctxt = doc.xpathNewContext()
  students = ctxt.xpathEval(query)
  for st in students:
  	print st
  	print
  ctxt.xpathFreeContext()
  doc.freeDoc()

if __name__ == '__main__':
	main(sys.argv)
