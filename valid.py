#!/usr/bin/python
#-*- coding: UTF-8 -*-

import optparse, libxml2, sys

def schema_validate(xml_file, xsd_file):
  ctxt = libxml2.schemaNewParserCtxt(xsd_file)
  schema = ctxt.schemaParse()
  validationCtxt = schema.schemaNewValidCtxt()
  res = validationCtxt.schemaValidateFile(xml_file, 0)
  if res != 0:
    print "VALIDATION FAILED"
  else:
    print "VALIDATED"
  return res

def main(argv):
  op = optparse.OptionParser(description = U"�������� �� ������������ XSD", prog="xsd", version="0.1", usage=U"%prog")
  op.add_option("-x", "--xml", dest="xml", help=U"XML ��������", metavar="XML_FILE")
  op.add_option("-s", "--xsd", dest="dtd", help=U"XSD ��������", metavar="XSD_FILE")

  options, arguments = op.parse_args()
  if options.xml and options.dtd:
    validate(options.xml, options.xsd):
  else:
    op.print_help()
if __name__=='__main__':
  main(sys.argv)
