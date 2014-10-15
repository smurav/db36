import sys
from lxml import etree

if (len(sys.argv) ==  3):
	doc = etree.parse(sys.argv[1])
	shema = etree.XMLSchema(sys.argv[2])
	print(shema.validate(doc))
else:
	print "Not enough parameters("
