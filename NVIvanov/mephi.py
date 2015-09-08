#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import libxml2


def get_property_by_name(node, name):
    for node_property in node.properties:
        if node_property.type == 'attribute' and node_property.name == name:
            return node_property.content


def main(argv):
    if len(argv) != 2:
        sys.stderr.write("Usage : %s xml_file" % (argv[0],))
    else:
        doc = libxml2.parseFile(argv[1])
        university = doc.getRootElement()
        print(get_property_by_name(university, "name"))
        department = university.children.next.next.next.children.next.next.next
        while department is not None:
            if department.type == 'element':
                print("  Кафедра №" + get_property_by_name(department, "number"))
                group = department.children.next.next.next
                while group is not None:
                    if group.type == 'element':
                        print("    " + get_property_by_name(group, "name"))
                        for student in group.children:
                            if student.type == 'element':
                                print("      %s) " % get_property_by_name(student, "number") +
                                      get_property_by_name(student, "name"))
                    group = group.next
            department = department.next


if __name__ == '__main__':
    main(sys.argv)
