<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <head>
                <meta charset="utf-8"/>
            </head>
            <body>
                <h2>Студенты</h2>
                <table border="1">
                    <tr>
                        <th>Имя</th>
                        <th>Группа</th>
                    </tr>
                    <xsl:for-each select="//group">
                        <tr>
                        <td><xsl:value-of select="./student/@name"/></td>
                        <td><xsl:value-of select="./student/parent::group/@name"/></td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>