#! /usr/bin/env python
import sys, libxml2

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

def main(argv):
	if len(argv) != 2:
		sys.stderr.write("Usage : %s xml_file" % (argv[0],))
	else: open(argv[1])

if __name__ == '__main__':
	main(sys.argv)