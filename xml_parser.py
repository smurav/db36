#! /usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import libxml2

def getPropValue(node,name):
  for prop in node.properties:
    if prop.type == 'attribute' and prop.name == 'name':
      return prop.content  

def main(argv):
  if len(argv) != 2:
    sys.stderr.write("Usage : %s xml_file" % (argv[0],))
  else:
    doc = libxml2.parseFile(argv[1])
    university = doc.getRootElement()
    print(getPropValue(university,'name'))
    faculty = university.children
    while faculty is not None:
      if faculty.type == 'element':
        print("  Факультет: " + getPropValue(faculty,'name'))
        group = faculty.children
        while department is not None:
          if department.type == 'element':
            print("    Кафедра №" + getPropValue(department,'name'))
            group = department.children
            while geoup is not None:
              if group.type == 'element':
                print("      Группа " + getPropValue(group,'name'))
                student = group.children
                while student is not None:
                  if student.type == 'element':
                    print("        " + getPropValue(student,'name'))
                  student = student.next
              group = group.next
          department = department.next
      faculty = faculty.next
  doc.freeDoc()
     
if __name__ == ' __main__ ':
  main(sys.argv)
