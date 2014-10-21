# -*- coding: utf-8 -*- 

from lxml import etree
import sys
import datetime, time

doc = etree.parse(sys.argv[1])

r = doc.xpath("//department/attribute::name")
print "Список кафедр:\n"
for x in r:
	print x

r = doc.xpath("//group[@year>2010]/student")
print "Список студентов поступивших после 2010 года:\n"
for x in r:
	print x.text

r = doc.xpath("//group[student='Соловьева Аня']/@number".decode('utf-8'))
print "Студент Соловьева Аня учится в группе", r[0]

r = doc.xpath("//group[@number=362]/student")
print "в группе 362", len(r),"студентов"

r = doc.xpath("//department[@number=36]/descendant::student")
print "на 36й кафедре", len(r), "студентов"

r = doc.xpath("//faculty")
amount = []
facCount = len(r)
for i in xrange(0,facCount):
	amount+=[len(doc.xpath("//faculty["+str(i+1)+"]/descendant::student"))]
maxIndex = amount.index(max(amount))
minIndex = amount.index(min(amount))
maxFac = doc.xpath("string(//faculty["+str(maxIndex+1)+"]/@name)")
print "Факультет с наибольшим количеством учащихся:", maxFac
minFac = doc.xpath("string(//faculty["+str(minIndex+1)+"]/@name)")
print "Факультет с наименьшим количеством учащихся:", minFac

r = doc.xpath("string(//department[@number=36]/parent::*/@name)")
print "Кафедра 36 является кафедрой факультета", r

numGr = 361
now_date = datetime.date.today()
cur_year = now_date.year # Год текущий
cur_month = now_date.month # Месяц текущий
startYear = doc.xpath("string(//group[@number="+str(numGr)+"]/@year)")
if cur_month > 8:
	n = (cur_year - int(startYear)) * 2 + 1
else:
	n  = (cur_year - int(startYear)) * 2 + 2
fac = doc.xpath("string(//group[@number="+str(361)+"]/../../@name)")	
print fac,n,"-",numGr
