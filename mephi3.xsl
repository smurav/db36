<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
  <html xmlns="http://www.w3.org/1999/xhtml" lang="ru-RU" xml:lang="ru-RU">
  <head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
  <title>Задание №3</title>
  </head>
  <body>
  <h2>Все студенты факультета КиБ</h2>
    <table border="1">
      <tr bgcolor="#9acd32">
        <th style="text-align:left">Номер</th>
        <th style="text-align:left">Студент</th>
        <th style="text-align:left">Группа</th>
      </tr>
      <xsl:for-each select="//student[ancestor::faculty/@name='КиБ']">
      <tr>
        <td><xsl:value-of select="position()"/></td>
        <td><xsl:value-of select="self::student"/></td>
        <td><xsl:value-of select="concat(string(ancestor::department/@tag),string(2*(2014.0-number(parent::group/@date))+1),'-',string(ancestor::department/@number),string(parent::group/@number))"/></td>
      </tr>
      </xsl:for-each>
    </table>
  </body>
  </html>
</xsl:template>
</xsl:stylesheet>


