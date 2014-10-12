#! /usr/bin/env python
# -*- coding: utf-8 -*-
import sys, libxml2
import libxslt

def transform(xml_file, xsl_file, out_file):
	xml_doc = libxml2.parseFile(xml_file)
	xsl_doc = libxml2.parseFile(xsl_file)
	xsl = libxslt.parseStylesheetDoc(xsl_doc)
	out_doc = xsl.applyStylesheet(xml_doc ,None)
	xsl.saveResultToFilename(out_file, out_doc, 0)
	xsl.freeStylesheet()
	out_doc.freeDoc()
	xml_doc.freeDoc()

def main(argv):
 transform(argv[1], argv[2], argv[3])

if __name__ == '__main__':
    main(sys.argv)   
