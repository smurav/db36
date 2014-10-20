# -*- coding: utf-8 -*-
import sys
from lxml import etree
def op(xml_file): 
	doc = etree.parse(xml_file)
	return doc

def main(argv): 
	doc = op(argv[1])
	xsl = op(argv[2])
	transform = etree.XSLT(xsl)
	result = transform(doc)
	f = open(argv[3], 'w')
	f.write(str(result))
	f.close()

if __name__ == '__main__':
	if(len(sys.argv) != 4):
		print "Bad number of parametrs"
	else:
		main(sys.argv)