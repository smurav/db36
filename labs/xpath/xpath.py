#! /usr/bin/env python
# -*- coding: utf-8 -*-
import sys, libxml2

def open(xml_file, query):  
  doc = libxml2.parseFile (xml_file) 
  ctxt = doc.xpathNewContext()
  students = ctxt.xpathEval(query)
  print students
  ctxt.xpathFreeContext()
  doc.freeDoc()

def main(argv):
  queries = ["string(/mephi/faculty[@name='K']/*/attribute::number)",
             "//group[@year>='2012']/*/attribute::*",
             "string(//group[child::student[@lastname='Разживин']]/attribute::num)",
             "count(//group[@num='1'][@year='2012']/*)",
             "count(//kafedra[@num='36']/descendant::student)",
             "string(//faculty[child::kafedra[@number='36']]/attribute::name)"]
  for s in queries:
    print s
    print
    open(argv[1], s)
    print

if __name__ == '__main__':
	main(sys.argv)
