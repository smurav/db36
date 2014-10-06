#!/usr/bin/python
#-*- coding: UTF-8 -*-

import optparse, libxml2, sys

def print_department_list(xml_file):
  print "\nПеречень кафедр факультета КиБ:"
  doc = libxml2.parseFile (xml_file)
  ctxt = doc.xpathNewContext()
  data = ctxt.xpathEval("//faculty[@name='КиБ']/department/@name")
  for node in data:
    print node.content
  ctxt.xpathFreeContext ()
  doc.freeDoc ()

def print_student_list_after_year(xml_file):
  print "\nПеречень студентов, поступивших после указанного года:"
  doc = libxml2.parseFile (xml_file)
  ctxt = doc.xpathNewContext()
  data = ctxt.xpathEval("//group[@date>=2012]/student")
  for node in data:
    print node.content
  ctxt.xpathFreeContext ()
  doc.freeDoc ()

def print_group_list_with_this_student(xml_file):
  print "\nПеречень групп, в которых есть студент с фамилией Заманов:"
  doc = libxml2.parseFile (xml_file)
  ctxt = doc.xpathNewContext()
  data = ctxt.xpathEval("//group[student='Заманов']/@name")
  for node in data:
    print node.content
  ctxt.xpathFreeContext ()
  doc.freeDoc ()

def number_of_students_group(xml_file):
  print "\nЧисло студентов в группе К5-361:"
  doc = libxml2.parseFile (xml_file)
  ctxt = doc.xpathNewContext()
  data = ctxt.xpathEval("count(//group[@name='К5-361']/student)")
  print int(data)
  ctxt.xpathFreeContext ()
  doc.freeDoc ()

def number_of_students(xml_file):
  print "\nОбщее число студентов на 36 кафедре:"
  doc = libxml2.parseFile (xml_file)
  ctxt = doc.xpathNewContext()
  x=36
  data = ctxt.xpathEval("count(//department[@number=36]/group/student)")
  print int(data)
  ctxt.xpathFreeContext ()
  doc.freeDoc ()

def find_faculty(xml_file):
  print "\nФакультет с наименьшим и наибольшим количеством студентов:"
  doc = libxml2.parseFile (xml_file)
  ctxt = doc.xpathNewContext()
  data = ctxt.xpathEval("count(//faculty)")
    /university/faculty[count(./department/group/student)>count(following-sibling::department/group/student) and count(./department/group/student)>count(preceding-sibling::department/group/student)]/@name
  ctxt.xpathFreeContext ()
  doc.freeDoc ()

def print_faculty(xml_file):
  print "\nФакультет, к которому относится кафедра No36:"
  doc = libxml2.parseFile (xml_file)
  ctxt = doc.xpathNewContext()
  data = ctxt.xpathEval("/university/faculty/department[@number=36]/parent::*/@name")
  for node in data:
    print node.content
  ctxt.xpathFreeContext ()
  doc.freeDoc ()

def print_full_name(xml_file,year,month):
  print "\nПолное имя 1-ой группы:"
  doc = libxml2.parseFile (xml_file)
  ctxt = doc.xpathNewContext()
  number3 = ctxt.xpathEval("//group[@name='К5-361']/@number")
  number2 = ctxt.xpathEval("//group[@name='К5-361']/parent::*/@number")
  number1 = ctxt.xpathEval("//group[@name='К5-361']/@date ")
  letter = ctxt.xpathEval("//group[@name='К5-361']/parent::*/@tag")
  for node in number1:
    data1 = node.content
  for node in number2:
    data2 = node.content
  for node in number3:
    data3 = node.content
  for node in letter:
    letter = node.content 
  if month>8:
    date=(year-int(data1))*2+1
  else:
    date=(year-int(data1))*2
  name=letter+str(date)+'-'+data2+data3
  print name
  ctxt.xpathFreeContext ()
  doc.freeDoc ()


def main(argv):
  op = optparse.OptionParser(description = U"XPath запросы", prog="xpath", version="0.1", usage=U"%prog")
  op.add_option("-x", "--xml", dest="xml", help=U"XML документ", metavar="XML_FILE")
  options, arguments = op.parse_args()
  month=10
  year=2014
  if options.xml:
    print_department_list(options.xml)
    print_student_list_after_year(options.xml)
    print_group_list_with_this_student(options.xml)
    number_of_students_group(options.xml)
    number_of_students(options.xml)
    find_faculty(options.xml)
    print_faculty(options.xml)
    print_full_name(options.xml,year,month)
  else:
    op.print_help()

if __name__=='__main__':
  main(sys.argv)
