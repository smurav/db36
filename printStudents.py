#! /usr/bin/env python
# coding=UTF-8

# К5-361 Штанько Александр

import sys, libxml2

def open(xml_file):
  doc = libxml2.parseFile(xml_file)
  ctxt =  doc.xpathNewContext()
  students = ctxt.xpathEval('/university/faculty/department/group/student')
  for node in students:
    print node.content
  doc.freeDoc()
  ctxt.xpathFreeContext()

def main(argv):
  if len(argv) != 2:
    sys.stdout.write("Usage : %s xml_file" % (argv[0],))
  else:
    open(argv[1])

if __name__ == '__main__':
  main(sys.argv)
