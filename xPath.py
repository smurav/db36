# -*- coding: utf-8 -*-
import sys
from lxml import etree

def op(xml_file): 
	doc = etree.parse(xml_file)
	return doc

def printXP(x):
	for i in x:
		print i

def maxNumOfStFac(doc, i, n):
	pass

def main(argv): 
	doc = op(argv[1])
	xp = open('xpath').read().split('\n')
	while len(xp) > 0:
		print xp.pop(0)
		if type(doc.xpath(xp[0].decode("utf-8"))) is list:
			printXP(doc.xpath(xp.pop(0).decode("utf-8")))
		else:
			print doc.xpath(xp.pop(0).decode("utf-8"))
		print 

if __name__ == '__main__':
	main(sys.argv)