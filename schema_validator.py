#! /usr/bin/env python
import sys, libxml2

def schema_validate(xml_file, xsd_file):
  ctxt = libxml2.schemaNewParserCtxt(xsd_file)
  schema = ctxt.schemaParse()
  validationCtxt = schema.schemaNewValidCtxt()
  res = validationCtxt.schemaValidateFile(xml_file, 0)
  doc = libxml2.parseFile(xml_file)
  result = validationCtxt.schemaValidateDoc(doc)
  doc.freeDoc()
  if result != 0:
    print "VALIDATION FAILED"
  else:
    print "VALIDATED"
  return result

if __name__ == ' __main__ ':
  main(sys.argv)
