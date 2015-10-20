#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import libxml2


def parse_students(doc):
    mephi = doc.getRootElement()
    faculty = mephi.children
    while faculty is not None:
        if faculty.type == 'element':
            department = faculty.children
            while department is not None:
                if department.type == 'element':
                    group = department.children
                    while group is not None:
                        if group.type == 'element':
                            student = group.children
                            while student is not None:
                                if student.type == 'element':
                                    print(student.prop("name"))
                                student = student.next
                        group = group.next
                department = department.next
        faculty = faculty.next


def main(argv):
    doc = libxml2.parseFile(argv[1])
    parse_students(doc)
    doc.freeDoc()

if __name__ == '__main__':
    main(sys.argv)
