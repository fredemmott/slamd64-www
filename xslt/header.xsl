<?xml version="1.0"?>
<xsl:stylesheet
	version="2.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	xmlns:x="http://slamd64.com/1.0"
	xmlns="http://www.w3.org/1999/xhtml"
>
	<xsl:output method="xhtml" indent="yes" />
	<xsl:template match="/">
		<html>
			<head>
				<title>
					Slamd64
					<xsl:if test="//*:head/*:title">
						:: <xsl:value-of select='//*:head/*:title' />
					</xsl:if>
				</title>
				<link rel='stylesheet' type='text/css' href='{$root}/static/style.css' />
				<link rel="stylesheet" type="text/css" href="{$root}/static/niftyCorners.css" />
				<link rel="stylesheet" type="text/css" href="{$root}/static/niftyPrint.css" media="print" />
				<script type="text/javascript" src="{$root}/static/niftycube.js">{}</script>
				<script type="text/javascript">
					window.onload=function(){
					Nifty("ul#nav li","transparent top");
					Nifty("div#mainFrame", "tl bl br");
					Nifty("div#beg","transparent top");
					Nifty("div#externalLinks");
					Nifty("div#footer");
					}
				</script>
			</head>
			<body>
				<!--
				<div id='announce'>
					<p>
						This site is new, and we're still ironing out the bugs; if you find a problem, please <a href='/contact'>let us know</a>.
					</p>
				</div>
				-->
				<div id="menu">
					<ul id="nav">
						<li class="{if(//*:meta[@name='pageName']) then 'inactiveLink' else 'activeLink'}" >
							<div><a href="{$root}/">Home</a></div>
						</li>
						<li class="{if(//*:meta[@name='pageName' and @content='about']) then 'activeLink' else 'inactiveLink'}">
							<div><a href="{$root}/about">About</a></div>
						</li>
						<li class="{if(//*:meta[@name='pageName' and @content='download']) then 'activeLink' else 'inactiveLink'}">
							<div><a href="{$root}/download">Download</a></div>
						</li>
						<li class="{if(//*:meta[@name='pageName' and @content='support']) then 'activeLink' else 'inactiveLink'}">
							<div><a href="{$root}/support">Support</a></div>
						</li>
						<li class="{if(//*:meta[@name='pageName' and @content='thanks']) then 'activeLink' else 'inactiveLink'}">
							<div><a href="{$root}/thanks">Thanks</a></div>
						</li>
					</ul>
					<div id='beg'>
						<form action='https://www.paypal.com/cgi-bin/webscr' method='post'>
							<fieldset>
								<input type='hidden' name='cmd' value='_xclick' />
								<input type='hidden' name='business' value='sales@fredemmott.co.uk' />
								<input type='hidden' name='item_name' value='slamd64' />
								<input type='hidden' name='no_note' value='1' />
								<input type='hidden' name='currency_code' value='GBP' />
								<input type='hidden' name='tax' value='0' />
								<input type='hidden' name='bn' value='PP-DonationsBF' />
								<input type='image' src='https://www.paypal.com/en_US/i/btn/x-click-but04.gif' border='0' name='submit' alt='Donate using PayPal' id='paypalImg' />
							</fieldset>
						</form>
					</div>
				</div>
				<div id='mainFrame'>
					<div id='content'>
						<h1><a href='{$root}/'><img src='{$root}/static/slamd64.png' alt='Slamd64' /></a></h1>
						<xsl:if test="not(//*:meta[@name='pageName' and @content='download'])">
							<div id='externalLinks'>
								<h2>Related Sites:</h2>
								<dl>
									<dt>Bugtracker:</dt>
									<dd><a href='http://bugs.slamd64.com'>bugs.slamd64.com</a></dd>
									<dt>Forums:</dt>
									<dd><a href='http://forums.slamd64.com'>forums.slamd64.com</a></dd>
									<dt>Mailing Lists:</dt>
									<dd><a href='http://lists.slamd64.com'>lists.slamd64.com</a></dd>
									<dt>Extra Packages:</dt>
									<dd><a href='http://builds.slamd64.com'>builds.slamd64.com</a></dd>
								</dl>
							</div>
						</xsl:if>
						<xsl:if test="//*:head/*:title[not (@showInBody = 'false')]">
							<h2><xsl:value-of select='//*:head/*:title' /></h2>
						</xsl:if>
