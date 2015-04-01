<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="test">
  <html>
  <body>
    <h2>Результаты выполнения контрольной работы №3</h2>
    <table border="1" style="width:50%">
      <tr>
        <th style="width:10%">№</th>
        <th style="width:80%">Студент</th>
        <th>Результат</th>
      </tr>
      <xsl:apply-templates select="//group"/>
    </table>
  </body>
  </html>
</xsl:template>

<xsl:template match="group">
    <tr>
      <td colspan="3" align="center" bgcolor="#9acd32"><xsl:value-of select="@id"/></td>
      <xsl:apply-templates select="student"/>
    </tr>
</xsl:template>

<xsl:template match="student">
    <xsl:variable name="result" select="sum(task)"/>
    <xsl:variable name="bonus" select="sum(bonus)"/>
    <xsl:variable name="penalty" select="sum(penalty)"/>
    <tr>
      <td align="center"><xsl:value-of select="position()"/></td>
      <td><xsl:value-of select="@name"/></td>
      <xsl:choose>
        <xsl:when test="$result + $bonus &lt;'16' + $penalty">
          <td bgcolor="#ff0000"><xsl:value-of select="$result"/>
            <xsl:if test="bonus&gt;0">
              <xsl:text>+</xsl:text><xsl:value-of select="$bonus"/>
            </xsl:if>
            <xsl:if test="penalty&gt;0">
              <xsl:text>-</xsl:text><xsl:value-of select="$penalty"/>
            </xsl:if>
          </td>
        </xsl:when>
        <xsl:when test="$result+$bonus&gt;'19' + $penalty">
          <td bgcolor="#00ff00"><xsl:value-of select="$result"/>
            <xsl:if test="bonus&gt;0">
              <xsl:text>+</xsl:text><xsl:value-of select="$bonus"/>
            </xsl:if>
            <xsl:if test="penalty&gt;0">
              <xsl:text>-</xsl:text><xsl:value-of select="$penalty"/>
            </xsl:if>
          </td>
        </xsl:when>
        <xsl:otherwise>
          <td bgcolor="#ffff00"><xsl:value-of select="$result"/>
            <xsl:if test="bonus&gt;0">
              <xsl:text>+</xsl:text><xsl:value-of select="$bonus"/>
            </xsl:if>
            <xsl:if test="penalty&gt;0">
              <xsl:text>-</xsl:text><xsl:value-of select="$penalty"/>
            </xsl:if>
          </td>
        </xsl:otherwise>
      </xsl:choose>
    </tr>
</xsl:template>

</xsl:stylesheet>
