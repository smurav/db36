<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="xml"/>
<xsl:template match="/">
          <xsl:attribute name="FullGroupName">
<xsl:for-each select="//facultet[@field='K']/kaf/group[@name=1]">
           <xsl:value-of select="concat(string(//facultet/@field),string(1+2*(2014.0-number(ancestor::group/attribute::year))),'-', string(number(ancestor::kaf/attribute::id)), string(ancestor::group/@name))"/>
	</xsl:for-each>
	  </xsl:attribute>
</xsl:template>
</xsl:stylesheet>
