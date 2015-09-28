#! /usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import libxml2
import optparse  

def validate(xml_file, dtd_file):
  doc = libxml2.parseFile(xml_file)
  dtd = libxml2.parseDTD(None, dtd_file)
  ctxt = libxml2.newValidCtxt()
  ret = doc.validateDtd(ctxt, dtd)
  dtd.freeDtd()
  doc.freeDoc()
  return ret

def main():
  op = optparse.OptionParser(description = U"Проверка на соответствие DTD",
                             prog="dtd", version="0.1", usage=U"%prog")
  op.add_option("-x", "--xml", dest="xml", help=U"XML документ", metavar="XML_FILE")
  op.add_option("-d", "--dtd", dest="dtd", help=U"DTD документ", metavar="DTD_FILE")
  
  options, arguments = op.parse_args()
  if options.xml and options.dtd:
    validate(options.xml, options.dtd)
  else:
    op.print_help()
     
if __name__ == ' __main__ ':
  main()
