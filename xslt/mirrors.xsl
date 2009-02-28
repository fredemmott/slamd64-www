<table id='mirrorsTable'>
	<xsl:for-each select="//x:location">
		<tr><th colspan='4' class='mirrorCountry'><xsl:value-of select='x:name' /></th></tr>
		<xsl:for-each select='x:servers/x:server'>
			<tr class='{if (position() mod 2 = 1) then "oddRow" else "evenRow"}'>
				<th class='mirrorName'><xsl:value-of select='x:name' /></th>
				<td>
					<xsl:choose>
						<xsl:when test='x:ftp'>
							<a href='{x:ftp}'>ftp</a>
						</xsl:when>
						<xsl:otherwise>
							-
						</xsl:otherwise>
					</xsl:choose>
				</td>
				<td>
					<xsl:choose>
						<xsl:when test='x:http'>
							<a href='{x:http}'>http</a>
						</xsl:when>
						<xsl:otherwise>
							-
						</xsl:otherwise>
					</xsl:choose>
				</td>
				<td>
					<xsl:choose>
						<xsl:when test='x:rsync'>
							<a href='{x:rsync}'>rsync</a>
						</xsl:when>
						<xsl:otherwise>
							-
						</xsl:otherwise>
					</xsl:choose>
				</td>
			</tr>
		</xsl:for-each>
	</xsl:for-each>
</table>
