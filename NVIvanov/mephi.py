#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import libxml2
import optparse

def get_property_by_name(node, name):
    for node_property in node.properties:
        if node_property.type == 'attribute' and node_property.name == name:
            return node_property.content


def validate(xml_file, xsd_file):
    ctxt = libxml2.schemaNewParserCtxt(xsd_file)
    schema = ctxt.schemaParse()
    validationCtxt = schema.schemaNewValidCtxt()
    res = validationCtxt.schemaValidateFile(xml_file, 0)
    if res != 0:
        print("VALIDATION_ERROR")
    else:
        print("VALIDATED")
        parse_xml(xml_file)


def parse_xml(xml_file):
    doc = libxml2.parseFile(xml_file)
    mephi = doc.getRootElement()
    faculty = mephi.children
    while faculty is not None:
        if faculty.type == "element":
            title = faculty.children
            while title is not None:
                if title.type == "element":
                    print(title.content)
                    break
                title = title.next
            department = faculty.children
            while department is not None:
                if department.type == "element" and (department.name == "department" or department.name == "кафедра"):
                    number = department.children
                    while number is not None:
                        if number.type == "element":
                            print(number.content)
                            break
                        number = number.next
                    group = department.children
                    while group is not None:
                        if group.type == "element" and (group.name == "group" or group.name == "группа"):
                            title = group.children
                            while title is not None:
                                if title.type == "element":
                                    print(title.content)
                                    break
                                title = title.next
                            student = group.children
                            while student is not None:
                                if student.type == "element" and (student.name == "student" or student.name == "студент"):
                                    print(get_property_by_name(student, "name"))
                                student = student.next
                        group = group.next
                department = department.next
        faculty = faculty.next
    doc.freeDoc()


def get_option_parser():
    op = optparse.OptionParser(description=U"Проверка на соответствие XSD",
                               prog="dtd", version="0.1", usage=U"%prog")
    op.add_option("-x", "--xml", dest="xml", help=U"XML документ", metavar="XML_FILE")
    op.add_option("-d", "--xsd", dest="xsd", help=U"XSD документ", metavar="XSD_FILE")
    return op


def xpath(xml_file, str1):
    doc = libxml2.parseFile(xml_file)
    ctxt = doc.xpathNewContext()
    result = ctxt.xpathEval(str1)
    for item in result:
        print(item.content)
    print
    ctxt.xpathFreeContext()
    doc.freeDoc()


def main(argv):
    op = get_option_parser()
    options, arguments = op.parse_args()
    if options.xml and options.xsd:
        xpath(options.xml, "/МИФИ/факультет/кафедра/title")
        xpath(options.xml, "/МИФИ/факультет/каферда/группа/student[1]")
    else:
        op.print_help()


if __name__ == '__main__':
    main(sys.argv)
