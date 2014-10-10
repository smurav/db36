#! /usr/bin/env python
import sys, libxml2

def parse(node):
  if node.name != "group":
     if node.children is not None:  
        parse(node.children)
	while node.next is not None:
           parse(node.next)
           return
     else:
        return 
  else: 
    while node is not None:
          print node.properties
          print node.content
          node = node.next
    return
  

def main(argv):
  if len(argv) != 2:
    sys.stderr.write("Usage : %s xml_file" % (argv[0],))
  else:
    doc = libxml2.parseFile(argv[1])
    root = doc.getRootElement() 
    if root.children is not None:
       parse(root)
    doc.freeDoc()


if __name__ == '__main__':
 main (sys.argv)
