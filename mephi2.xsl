<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">

<university name="МИФИ" city="Москва" metro="Каширская">
	
<faculty name="КиБ" dean="Евсеев">
		<department tag="K" name="Информационные системы и технологии" number="36">
			<group name="К5-361" number="1" amount="13" date="2012">
	<xsl:attribute name="fullname">	
<xsl:for-each select="//group[@name='К5-361']">		
	<xsl:value-of select="concat(string(ancestor::department/@tag),string(2*(2014.0-number(@date))+1),'-',string(ancestor::department/@number),string(@number))"/>
</xsl:for-each>
	</xsl:attribute>

				<student>Анисимова</student>
				<student>Артемьев</student>
				<student>Бубенко</student>
				<student>Джелоухова</student>
				<student>Заманов</student>
				<student>Михеев</student>
				<student>Пивоваров</student>
				<student>Самсонов</student>
				<student>Сидорова</student>
				<student>Соловьёва</student>
				<student>Тармазаков</student>
				<student>Титоренко</student>
				<student>Штанько</student>
			</group>
			<group name="К5-362" number="2" amount="17" date="2012">
<xsl:attribute name="fullname">	
<xsl:for-each select="//group[@name='К5-362']">		
	<xsl:value-of select="concat(string(ancestor::department/@tag),string(2*(2014.0-number(@date))+1),'-',string(ancestor::department/@number),string(@number))"/>
</xsl:for-each>
	</xsl:attribute>
				<student>Ахметсафин</student>
       				<student>Галкин</student>
  			        <student>Головко</student>
   			        <student>Джумайло</student>
    		   	        <student>Ерохин</student>
        			<student>Каталкина</student>
        			<student>Левин</student>
        			<student>Молочков</student>
        			<student>Моряшова</student>
        			<student>Полстянкин</student>
        			<student>Пурик</student>
        			<student>Разживин</student>
        			<student>Редюк</student>
       				<student>Рябов</student>
        			<student>Скок</student>
        			<student>Стрекалов</student>
        			<student>Чайковская</student>
			</group>
		</department>
		<department tag="K" name="Программная инженерия" number="22">
			<group name="К5-221" number="1" amount="1" date="2012">
<xsl:attribute name="fullname">	
<xsl:for-each select="//group[@name='К5-221']">		
	<xsl:value-of select="concat(string(ancestor::department/@tag),string(2*(2014.0-number(@date))+1),'-',string(ancestor::department/@number),string(@number))"/>
</xsl:for-each>
	</xsl:attribute>
				<student>Седова</student>
			</group>
		</department>
		<department tag="K" name="Математическое обеспечение систем" number="33">
			<group name="К5-331" number="1" amount="1" date="2012">
<xsl:attribute name="fullname">	
<xsl:for-each select="//group[@name='К5-331']">		
	<xsl:value-of select="concat(string(ancestor::department/@tag),string(2*(2014.0-number(@date))+1),'-',string(ancestor::department/@number),string(@number))"/>
</xsl:for-each>
	</xsl:attribute>
				<student>Хузин</student>
			</group>
		</department>
		<department tag="K" name="Информационные технологии в социальных системах" number="68">
			<group name="К5-682" number="2" amount="1" date="2012">
<xsl:attribute name="fullname">	
<xsl:for-each select="//group[@name='К5-682']">		
	<xsl:value-of select="concat(string(ancestor::department/@tag),string(2*(2014.0-number(@date))+1),'-',string(ancestor::department/@number),string(@number))"/>
</xsl:for-each>
	</xsl:attribute>
				<student>Маляр</student>
			</group>
		</department>	
	</faculty>
	<faculty name="Т">
		<department tag="Т" name="Кафедра молекулярной физики" number="10">
			<group name="Т3-101" number="1" amount="2" date="2013">
<xsl:attribute name="fullname">	
<xsl:for-each select="//group[@name='Т3-101']">		
	<xsl:value-of select="concat(string(ancestor::department/@tag),string(2*(2014.0-number(@date))+1),'-',string(ancestor::department/@number),string(@number))"/>
</xsl:for-each>
	</xsl:attribute>
				<student>Иванов</student>
       				<student>Петров</student>
  			        <student>Сидоров</student>   			      
			</group>
		</department>
	</faculty>

</university>

</xsl:template>
</xsl:stylesheet>

