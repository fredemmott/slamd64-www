<xsl:for-each select="//x:newsItem">
	<h2><xsl:value-of select='x:title' /></h2>
	<p class='newsInfo'>
		Posted by <xsl:value-of select='x:poster' /> on <xsl:value-of select='x:posted' />
		<xsl:if test="x:editor">
			- Edited by <xsl:value-of select='x:editor' /> on <xsl:value-of select='x:edited' />
		</xsl:if>
	</p>
	<xsl:copy-of select='x:body/*' />
</xsl:for-each>
