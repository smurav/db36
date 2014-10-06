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
             "string(//group[child::student[@lastname='Редюк']]/attribute::grnum)",
             "count(//group[@grnum='1'][@year='2012']/*)",
             "count(//department[@number='36']/descendant::student)",
             "string(//faculty[child::department[@number='36']]/attribute::name)",
             "concat(string(//student[@firstname='Сергей'][@lastname='Редюк']/ancestor::faculty/attribute::name), string(1+2*(2014.0-number(//student[@firstname='Сергей'][@lastname='Редюк']/ancestor::group/attribute::year))), '-', string(//student[@firstname='Сергей'][@lastname='Редюк']/ancestor::department/attribute::number), string(//student[@firstname='Сергей'][@lastname='Редюк']/ancestor::group/attribute::grnum))"]
  for s in queries:
    print s
    print
    open(argv[1], s)
    print

if __name__ == '__main__':
	main(sys.argv)
