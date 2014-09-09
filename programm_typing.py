#! /usr/bin/env python
import sys, libxml2

def open(mephi_xml):
  doc = libxml2.parseFile(mephi_xml)
  doc.freeDoc()

def main(argv):
  if  len(argv) != 2:     
    sys.stderr.write("Usage : %s xml_file" % (argv[0],))
  else:
    open(argv[1])

if __name__ == '__main__':
  main(sys.argv)
