#! usr/bin/env python
import sys, libxml2
	
def open(xml_file):
	doc = libxml2.parseFile(xml_file)
	root = doc.getRootElement()
	print root.name
	child = root.children
	while child is not None:
		if child.type == 'element':
			print child.name + ' ' + child.content
		child = child.next
	doc.freeDoc()
def main(argv):
	if len(argv) != 2:
		sys.stderr.write("Usage : %s xml_file" % (argv[0],))
	else:
		open(argv[1])
if __name__ == "__main__":
	main(sys.argv)
