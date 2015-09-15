#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import libxml2
import optparse


def get_property_by_name(node, name):
    for node_property in node.properties:
        if node_property.type == 'attribute' and node_property.name == name:
            return node_property.content


def validate(xml_file, dtd_file):
    doc = libxml2.parseFile(xml_file)
    dtd = libxml2.parseDTD(None, dtd_file)
    ctxt = libxml2.newValidCtxt()
    ret = doc.validateDtd(ctxt, dtd)
    dtd.freeDtd()
    doc.freeDoc()
    return ret


def parse_xml(xml_file):
    doc = libxml2.parseFile(xml_file)
    mephi = doc.getRootElement()
    faculty = mephi.children
    while faculty is not None:
        if faculty.type == "element":
            print(get_property_by_name(faculty, "name"))
            department = faculty.children
            while department is not None:
                if department.type == "element":
                    print("  " + get_property_by_name(department, "name") + "(" + get_property_by_name(department,
                                                                                                       "number") + ")")
                    group = department.children
                    while group is not None:
                        if group.type == "element":
                            print("    " + get_property_by_name(group, "name"))
                            student = group.children
                            while student is not None:
                                if student.type == "element":
                                    print("      " + get_property_by_name(student, "name"))
                                student = student.next
                        group = group.next
                department = department.next
        faculty = faculty.next
    doc.freeDoc()


def get_option_parser():
    op = optparse.OptionParser(description=U"Проверка на соответствие DTD",
                               prog="dtd", version="0.1", usage=U"%prog")
    op.add_option("-x", "--xml", dest="xml", help=U"XML документ", metavar="XML_FILE")
    op.add_option("-d", "--dtd", dest="dtd", help=U"DTD документ", metavar="DTD_FILE")
    return op


def main(argv):
    op = get_option_parser()
    options, arguments = op.parse_args()
    if options.xml and options.dtd:
        validate(options.xml, options.dtd)
        parse_xml(options.xml)
    else:
        op.print_help()


if __name__ == '__main__':
    main(sys.argv)
