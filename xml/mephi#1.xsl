<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
	<xsl:for-each select="//faculty[@name='K']/*">department #<xsl:value-of select="./attribute::number"/>, </xsl:for-each>
</xsl:template>
</xsl:stylesheet>

