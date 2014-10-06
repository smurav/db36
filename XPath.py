#! /usr/bin/env python
#-*- coding: UTF-8 -*-
import sys, libxml2

def counter(xml_file, list_count):
	doc=libxml2.parseFile(xml_file)
	ctxt = doc.xpathNewContext()
	voo = ctxt.xpathEval(list_count)
	print
	print list_count
	print  voo
	ctxt.xpathFreeContext()
	doc.freeDoc()
  
def open(xml_file, zapros):
  doc=libxml2.parseFile(xml_file)
  ctxt = doc.xpathNewContext()
  for val in ctxt.xpathEval(zapros):
    print val.content
  ctxt.xpathFreeContext()
  doc.freeDoc()
  
def main(argv):
  zapros = [ "//kaf/@id", "//member[@enter >= 2080]", 
             "//group[./member='Рябов Петр']/attribute::name",
             "//facultet[child::kaf[@id='36']]/attribute::field"
           ]
  list_count = [ "count(//group[@name='2']/child::*)",
                 "count(//kaf[@id='36']/descendant::member)"
               ]
  if len(argv) !=2:
    sys.stderr.write("Usage : %s xml_file" % (argv[0],))
  else:
   for i in zapros:
     print 
     open(argv[1], i)
     
   for j in list_count:
     counter(argv[1], j)
    
if __name__ == '__main__':
  main(sys.argv)
