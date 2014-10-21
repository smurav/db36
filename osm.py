# -*- coding: utf-8 -*- 

from lxml import etree
import sys

doc = etree.parse(sys.argv[1])
r = doc.xpath("//way/tag[@k='building' and @v='university']/../tag[@k='name']/@v")
for x in r:
	print x