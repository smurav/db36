#!/usr/bin/python
#-*- coding: UTF-8 -*-
import optparse, libxml2, sys, libxslt

def transform(xml_file, xsl_file, out_file):
  xml_doc = libxml2.parseFile(xml_file)
  xsl_doc = libxml2.parseFile(xsl_file)
  xsl = libxslt.parseStylesheetDoc(xsl_doc)
  out_doc = xsl.applyStylesheet(xml_doc ,None)
  print out_doc
  xsl.saveResultToFilename(out_file, out_doc, 0)
  xsl.freeStylesheet()
  out_doc.freeDoc()
  xml_doc.freeDoc()

def main(argv):
  op = optparse.OptionParser(description = U"XSLT-преобразования", prog="xslt", version="0.1", usage=U"%prog")
  op.add_option("-x", "--xml", dest="xml", help=U"XML документ", metavar="XML_FILE")
  op.add_option("-s", "--xsl", dest="xsl", help=U"XSL документ", metavar="XSL_FILE")
  op.add_option("-o", "--out", dest="out", help=U"Выходной документ", metavar="OUT_FILE")
  options, arguments = op.parse_args()
  if options.xml and options.xsl and options.out:
    transform(options.xml, options.xsl, options.out)
  else:
    op.print_help()

if __name__=='__main__':
  main(sys.argv)
