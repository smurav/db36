<?xml version="1.0"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
  <html>
  <h2>Group K05-361</h2>
    <table border="1">
      <tr bgcolor="#9acd32">
        <th style="text-align:left">Number</th>
        <th style="text-align:left">Group</th>
        <th style="text-align:left">Name</th>
      </tr>
      <xsl:for-each select="//student">
      <tr>
        <td><xsl:value-of select="./attribute::number"/></td>
        <td><xsl:value-of select="concat(string(ancestor::faculty/attribute::name), string(1+2*(2014.0-number(ancestor::group/attribute::entryyear))), '-', string(ancestor::group/attribute::name))"/></td>
        <td><xsl:value-of select="current()"/></td>
      </tr>
      </xsl:for-each>
    </table>
  </html>
</xsl:template>
</xsl:stylesheet>
