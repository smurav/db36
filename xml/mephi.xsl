<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
  <html>
  <body>
  <h2>Table of Students</h2>
    <table border="1">
      <tr bgcolor="#9acd32">
        <th style="text-align:left">Student</th>
        <th style="text-align:left">Group</th>
      </tr>
      <xsl:for-each select="//student">
      <tr>
        <td><xsl:value-of select="concat(string(@firstname), ' ', string(@lastname))"/></td>
        <td><xsl:value-of select="concat(string(ancestor::faculty/attribute::name), string(1+2*(2014.0-number(ancestor::group/attribute::year))), '-', string(ancestor::department/attribute::number), string(ancestor::group/attribute::grnum))"/></td>
      </tr>
      </xsl:for-each>
    </table>
  </body>
  </html>
</xsl:template>
</xsl:stylesheet>

