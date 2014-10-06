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
  queries = ["string(/university/faculty[@name='K']/*/attribute::name)",
             "//group[@entryyear>='2012']/*",
             "string(//group[child::student='Sidorova Liubov']/attribute::name)",
             "count(//group[@name='361'][@entryyear='2012']/*)",
             "count(//department[@name='Information tehnology']/descendant::student)",
             "string(//faculty[child::department[@name='361']]/attribute::name)",
             "concat(string(//faculty/attribute::name),string(1+2*(2014.0-number(//group/attribute::entryyear))),'-',string(//group/attribute::name))"]
  for s in queries:
    print s
    print
    open(argv[1], s)
    print

if __name__ == '__main__':
    main(sys.argv)
