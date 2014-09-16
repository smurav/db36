#! /usr/bin/env python
#-*- coding: UTF-8 -*-
import sys, libxml2, optparse

def space(dep):
	for i in range(0, dep):
		sys.stdout.write(" ")

depth = 0
def view(node):
	global depth
	print
	space(depth)
	sys.stdout.write(node.name+" ")
	if node.properties is not None:
		for _property in node.properties:
			if _property.type == "attribute":
				#print _property.name
				sys.stdout.write(_property.content+" ")
	child = node.children
	depth = depth+1
	while child.next is not None:
		if child.type == "element":
			view(child)
		child = child.next
	depth = depth-1
	sys.stdout.write(child.content)

def open(xml_file):
	doc = libxml2.parseFile(xml_file)
	root = doc.getRootElement()
	#print root.name
	#print root.content
	view(root)
 	doc.freeDoc()

def validate(xml_file, dtd_file):
	doc = libxml2.parseFile(xml_file)
	dtd = libxml2.parseDTD(None, dtd_file)
	ctxt = libxml2.newValidCtxt()
	ret = doc.validateDtd(ctxt, dtd)
	dtd.freeDtd()
	doc.freeDoc()
	return ret

def main(argv):
	op = optparse.OptionParser(description = U"Проверка на соответствие DTD", prog="dtd", version="0.1", usage=U"%prog")
	op.add_option("-x", "--xml", dest="xml", help=U"XML документ", metavar="XML_FILE")
	op.add_option("-d", "--dtd", dest="dtd", help=U"DTD документ", metavar="DTD_FILE")
	options, arguments = op.parse_args()
	if options.xml and options.dtd:
		open(options.xml)
		validate(options.xml, options.dtd)
	else: op.print_help()

if __name__ == '__main__':
	main(sys.argv)