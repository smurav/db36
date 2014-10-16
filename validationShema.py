import sys
from lxml import etree

if (len(sys.argv) ==  3):
	print sys.argv[1] + '\n' + sys.argv[2]
	doc = etree.parse(sys.argv[1])
	schemaTree = etree.fromstring(open(sys.argv[2]).read())
	shema = etree.XMLSchema(schemaTree)
	print shema.validate(doc)
else:
	print "Not enough parameters("
