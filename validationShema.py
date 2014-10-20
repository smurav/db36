import sys
from lxml import etree

if (len(sys.argv) ==  3):
	doc = etree.parse(sys.argv[1])
	schemaTree = etree.fromstring(open(sys.argv[2]).read())
	shema = etree.XMLSchema(schemaTree)
	if shema.validate(doc):
		print "Validation is success"
	else: 
		print shema.assertValid(doc)
else:
	print "Not enough parameters("
