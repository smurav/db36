<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:template match="/">
		<html>
			<head>
				<meta charset="utf-8"/>
				<title><xsl:text>Остановки троллейбуса №11</xsl:text></title>
			</head>
		<body>
			<table border="1">
				<tr>
					<th style="text-align:left">Порядковый номер</th>
					<th style="text-align:left">id</th>
				</tr>
				<xsl:for-each select="//relation/tag[@v=11]/../tag[@v='trolleybus']/..">
					<xsl:for-each select="./member[@role='platform']">
				<tr>
					<td><xsl:value-of select="position()"/></td>
       		 		<td><xsl:value-of select="./@ref"/></td>
       			</tr>
       		</xsl:for-each>
       		</xsl:for-each>

			</table>
		</body>
	</html>
	</xsl:template>
</xsl:stylesheet>