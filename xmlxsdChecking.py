#!/usr/bin/env python
#-*- coding=UTF-8 -*-

import sys, optparse, libxml2

def schema_validate(xml_file, xsd_file):
  ctxt = libxml2.schemaNewParserCtxt(xsd_file)  
  schema = ctxt.schemaParse()  
  validationCtxt = schema.schemaNewValidCtxt()  
  res = validationCtxt.schemaValidateFile(xml_file, 0)  
  return res

def main():
  op = optparse.OptionParser(description = U"Проверка на соответствие XSD", prog="xsd", version="0.1", usage=U"%prog")
  op.add_option("-x", "--xml", dest="xml", help=U"XML документ", metavar="XML_FILE")
  op.add_option("-s", "--xsd", dest="xsd", help=U"XSD документ", metavar="XSD_FILE")

  options, arguments = op.parse_args()
  if options.xml and options.xsd:
    try:
      if schema_validate(options.xml, options.xsd):
        print 'XML документ неправильный'
      else:
        print 'XML документ правильный'
    except:
      print 'Что-то пошло не так, программа остановлена'
  else:
    op.print_help()

if __name__=='__main__':
  main()
