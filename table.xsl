<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="html"/>
<xsl:template match="/">
  <html>
    <body>
     <h3> There are such students </h3>
        <table border="2">
		<tr bgcolor="#55AACC">
                <th style="float: center">Student</th>
                <th style="float: center">Group</th>
                 </tr>
          <xsl:for-each select="//facultet[@field='K']/kaf/group/member">
           <tr>
		<td><xsl:value-of select="./self::*" /></td>
	        <td><xsl:value-of select="concat(string(//facultet/@field),string(1+2*(2014.0-number(ancestor::group/attribute::year))),'-', string(number(ancestor::kaf/attribute::id)), string(ancestor::group/@name))"/>
</td>
	   </tr>
	  </xsl:for-each>
    </table>
    </body>
  </html>
</xsl:template>
</xsl:stylesheet>
