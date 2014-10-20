<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="html"/>

<xsl:template match="/">

<html>
	<head>
		<meta charset="utf-8"/>
		<title><xsl:text>Список студентов факультета К</xsl:text></title>
	</head>
	<body>
		<table border="1">
			<caption><xsl:text>Список студентов факультета К</xsl:text></caption>
			<head>
				<tr>
					<td><xsl:text>№</xsl:text></td>
					<td><xsl:text>Группа</xsl:text></td>
					<td><xsl:text>Студент</xsl:text></td>
				</tr>
			</head>
			<body>
				<xsl:for-each select="//group">
					<xsl:for-each select="./student">
						<tr>
							<td><xsl:value-of select="position()" /></td>
							<td><xsl:value-of select="concat(string(../ancestor::faculty/attribute::name), string(1+2*(2014.0-number(../attribute::year))), '-', string(../ancestor::chair/attribute::number), string(../attribute::number))" /></td>
							<td><xsl:value-of select="." /></td>
						</tr>
					</xsl:for-each>
				</xsl:for-each>
			</body>
		</table>
	</body>
</html>

</xsl:template>

</xsl:stylesheet>