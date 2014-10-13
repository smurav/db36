#! /usr/bin/env python
# -*- coding: utf-8 -*-

import sys, libxml2

def open(xml_file, query):
  doc = libxml2.parseFile(xml_file)
  '''
  Вывести перечень кафедр "//department/attribute::name"
  Вывести студентов всех групп "//student" 
  Вывести перечень студентов, поступивших после указанного года
    "//group[@year='2012']/student"
  for url in doc.xpathEval(query):
    print url.content
  '''
  ctxt = doc.xpathNewContext()
  students = ctxt.xpathEval(query)
  print students
  ctxt.xpathFreeContext()
  
  doc.freeDoc()


def main(argv):
  queries = [
  "string(/university/faculty[@name='K']/*/attribute::name)", #Вывести перечень кафедр
  "//group[@entryyear>='2013']/*", #Перечень студентов поступивших после указанного года
 "string(//group[child::student='Ivanov']/attribute::number)", # Перечень групп в которых есть студент с заданной фамилией
 "count(//group[@number='361'][@entryyear='2012']/*)", # Студенты из указанной группы
 "count(//department[@name='Information system and technology']/descendant::student)", #Все студенты с указанной кафедры
 "string(//faculty[child::department[@number='36']]/attribute::name)", #Вывести факультет, к которому относится кафедра №36
 "concat(string(//faculty/attribute::name),string(1+2*(2014.0-number(//group/attribute::entryyear))),'-',string(//group/attribute::number))"]
  for s in queries:
    print s
    print
    open(argv[1], s)
    print

if __name__ == '__main__':
  main(sys.argv)


