<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
	<head>
		<meta charset="utf-8"/>
		<title><xsl:text>Список студентов факультета К</xsl:text></title>
	</head>
  <body>
    <table border="1">
      <tr bgcolor="#9acd32">
        <th style="text-align:left">Порядковый номер</th>
        <th style="text-align:left">ФИО</th>
        <th style="text-align:left">Группа</th>
      </tr>
      <xsl:for-each select="//faculty[@name='K']/descendant::student">
      		<tr>
       		 <td><xsl:value-of select="position()"/></td>
       		 <td><xsl:value-of select="."/></td>
       		 <td><xsl:value-of select="concat(string(./ancestor::faculty/@name), 
       		 	string(2014 - number(./ancestor::group/@year)), '-', string(./parent::*/@number))"/></td>
      		</tr>
      </xsl:for-each>
    </table>
  </body>
  </html>
</xsl:template>
</xsl:stylesheet>