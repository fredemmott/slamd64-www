<?xml version="1.0"?>
<xsl:stylesheet version="2.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:output method="xhtml" indent="yes" />
	<xsl:template match="/">
		<html>
			<head>
				<title>Slamd64Builds :: <xsl:value-of select="//redirect/title" /></title>
			</head>
			<body>
				<h1><xsl:value-of select="//redirect/title" /></h1>
				<p>The package you were looking for couldn't be found - did you mean <a href='{$root}/{//redirect/target}'><xsl:value-of select="//redirect/target" /></a>?</p>
			</body>
		</html>
	</xsl:template>
</xsl:stylesheet>
