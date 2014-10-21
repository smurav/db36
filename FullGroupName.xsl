<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output encoding="UTF-8" method="xml"/>
<xsl:template match="*">
	<xsl:element name="{local-name()}">
		<xsl:copy-of select="@*"/>
		<xsl:if test="local-name() = 'group'">
			<xsl:attribute name="fullname">
				<xsl:value-of select="concat(string(./ancestor::faculty/attribute::name), string(1+2*(2014.0-number(./attribute::year))), '-', string(./ancestor::chair/attribute::number), string(./attribute::number))"/>
      	</xsl:attribute>
      </xsl:if> 
      <xsl:apply-templates/>
    </xsl:element>
</xsl:template>

<xsl:template match="/">
    <xsl:apply-templates/>
</xsl:template>

</xsl:stylesheet>
