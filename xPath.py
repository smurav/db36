# -*- coding: utf-8 -*-
import sys
from lxml import etree

def op(xml_file): 
	doc = etree.parse(xml_file)
	return doc

def printXP(x):
	for i in x:
		print i

def maxNumOfStFac(doc):
	cnt = int(doc.xpath("count(//faculty)"))
	print cnt
	l = list()
	k = list()
	for i in xrange(1, cnt+1):
		l.append(doc.xpath("count(//faculty["+str(i)+"]//child::student)"))
		k.append(doc.xpath("string(//faculty["+str(i)+"]/attribute::name)"))
	print "Faculty has max count of students is: " + k[l.index(max(l))]
	print "Faculty has min count of students is: " + k[l.index(min(l))]


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
	maxNumOfStFac(doc)

if __name__ == '__main__':
	main(sys.argv)