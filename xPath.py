# -*- coding: utf-8 -*-

import sys
from lxml import etree

def open(xml_file): 
	doc = etree.parse(xml_file)
	return doc

def printXP(x):
	for i in x:
		print i

def main(argv): 
	xPath1 = "//faculty[@name='K']/*/attribute::number"
	xPath2 = "//group[@year>'2010']/child::student/child::text()"
	xPath3 = "//group[child::student='Артемьев Дмитрий']/attribute::name".decode('utf-8')
	xPath4 = "count(//group[@name='K05-361']/child::*)".decode('utf-8')
	xPath5 = "count(//chair[@number='36']/*/child::*)"
	xPath6 = "//university/*"

	doc = open(argv[1])
	xp = doc.xpath(xPath1)
	printXP(xp)
	xp = doc.xpath(xPath2)
	printXP(xp)
	xp = doc.xpath(xPath3)
	printXP(xp)
	xp = doc.xpath(xPath4)
	print xp
	xp = doc.xpath(xPath5)
	print xp
	xp = doc.xpath(xPath6)
	print xp


main(sys.argv)