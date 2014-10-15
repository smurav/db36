import sys
from lxml import etree

if (len(sys.argv) ==  3):
	doc = etree.parse(sys.argv[1])
	dtd = etree.DTD(sys.argv[2])
	print(dtd.validate(doc))
else:
	print "Not enough parameters("
