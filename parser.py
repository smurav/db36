#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import libxml2

#function prints a list of names
def printing(root):
	child = root.children
	while child.next is not None:
		if child.type == "element":
			printing(child)
		child = child.next
	sys.stdout.write(child.content)
	print	

#open file to work with it
def open(xml_file):
	doc = libxml2.parseFile(xml_file)
	root = doc.getRootElement()
	printing(root)
	doc.freeDoc()

def main(argv):
	if len(argv) !=2:
		sys.stdout.write("Usage: %s xml_file" % (argv[0],))
	else:
		open(argv[1])

if __name__ == '__main__':
	main(sys.argv)
