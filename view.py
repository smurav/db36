#! /usr/bin/env python
import sys, libxml2

def list(cell):
  print
  child = cell.children
  while child.next is not None:
    if child.type == "element":
      list(child)
    child = child.next
  sys.stdout.write(child.content)

def open(xml_file):
  doc=libxml2.parseFile(xml_file)
  root = doc.getRootElement()
  list(root)
  doc.freeDoc()

def main(argv):
  if len(argv) !=2:
    sys.stderr.write("Usage : %s xml_file" % (argv[0],))
  else:
    open(argv[1])

if __name__ == '__main__':
  main(sys.argv)
