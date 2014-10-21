import sys
from lxml import etree
if (len(sys.argv) == 3):
	doc = etree.parse(sys.argv[1])
	schemaTree = etree.fromstring(open(sys.argv[2]).read())
	schema = etree.XMLSchema(schemaTree)
	if schema.validate(doc):
		print "Validated"
	else: 
		print "Not validated"
		print schema.assertValid(doc)
else:
	print "Incorrect number of parameters" 
