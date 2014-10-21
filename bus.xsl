<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="html"/>
		<xsl:template match="/">
			<xsl:for-each select="//relation/tag[@v='bus']">
				<xsl:value-of select="string(../tag[@k='ref']/@v)"/>	
				<xsl:if test="position() != last()">
					<xsl:text>&#13;</xsl:text>
				</xsl:if>
			</xsl:for-each>
		</xsl:template>
</xsl:stylesheet>
