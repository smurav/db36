#! /usr/bin/env python
import sys
from lxml import etree

def open(xml_file): 
	doc = etree.parse(xml_file)
	return doc

def printStudents(g):
	i = 1
	print g.get("name")
	for s in g.getchildren():
		print str(i) + ") " + s.text
		i+=1

def main(argv): 
	if len(argv) != 2: 
		sys.stderr.write("Usage : %s xml_file" % (argv[0],)) 
	else: 
		doc = open(argv[1])
		university = doc.getroot()
		t = university.getchildren().pop()
		x = t.getchildren().pop()
		g1 = x.getchildren()[0]
		g2 = x.getchildren()[1]
		printStudents(g1)
		printStudents(g2)
		


main(sys.argv)