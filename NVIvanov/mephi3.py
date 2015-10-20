#!usr/bin/env python
# -*- coding: utf-8

import sys
import libxml2


def schema_validate(xml_file, xsd_file):
    ctxt = libxml2.schemaNewParserCtxt(xsd_file)
    schema = ctxt.schemaParse()
    validationCtxt = schema.schemaNewValidCtxt()
    res = validationCtxt.schemaValidateFile(xml_file, 0)
    if res != 0:
        print("VALIDATION FAILED")
    else:
        print("VALIDATED")


def main(argv):
    schema_validate(argv[1], argv[2])


if __name__ == '__main__':
    main(sys.argv)
