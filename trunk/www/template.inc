##
## template.inc -- uopp website template
##

#include "grid.inc"

#use wml::fmt::isolatin
#use wml::std::tags
#use wml::fmt::url

<divert PORTSINDEX>
<ul>
<li><a href="<get-var ROOT />/ports/3.4/index.html">Browsable interface of the 3.4 ports tree</a></li>
<li><a href="<get-var ROOT />/ports/3.5/index.html">Browsable interface of the 3.5 ports tree</a></li>
<li><a href="<get-var ROOT />/ports/3.6/index.html">Browsable interface of the 3.6 ports tree</a></li>
<li><a href="<get-var ROOT />/ports/current/index.html">Browsable interface of the current ports tree</a></li>
<li><a href="<get-var ROOT />/ports/current/mystuff/index.html">Downloadable unofficial OpenBSD ports</a></li>
</ul>
</divert>

<divert CODEINDEX>
<ul>
<li><a href="<get-var ROOT />/code/p2w.html">Code for generating a web-interface from the ports tree</a></li>
</ul>
</divert>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="en">
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
  <title><dump TITLE /> | uopp</title>
  <link rel="stylesheet" type="text/css" href="<get-var ROOT />/styles/layout.css" media="screen" />
  <link rel="shortcut icon" href="<get-var ROOT />/images/puf100X86.gif" />
  <style type="text/css">
    @import "<get-var ROOT />/styles/markup.css";
  </style>
</head>

<body>

<table class="header">
	<tr class="header">
   <td class="logo">
   	<img class="logo" width="200" height="50" alt="OpenBSD logo" src="<get-var ROOT />/images/puflogh200X50.gif" />
	</td>
   <td class="menu">
      <div class="menu">
	<a class="menu_item" href="<get-var ROOT />/index.html">Home</a> | 
	<a class="menu_item" href="<get-var ROOT />/ports.html">Ports</a> |
	<a class="menu_item" href="<get-var ROOT />/docs.html">Documentation</a> | 
	<a class="menu_item" href="<get-var ROOT />/code.html">Code</a> | 
	<a class="menu_item" href="<get-var ROOT />/links.html">Links</a> | 
	<a class="menu_item" href="<get-var ROOT />/about.html">About</a></div>
   </td>
   </tr>
</table>

<table class="body"><tr class="body"><td class="body">

<isolatin>
<dump BODY />
</isolatin>
</td>
</tr>
</table>

<div class="footer">

<p class="footer">
 
<a class="footer" href="http://validator.w3.org/check?uri=referer">
<img class="footer" src="http://www.w3.org/Icons/valid-xhtml10"
          alt="Valid XHTML 1.0!" height="31" width="88" />
</a>

<a class="footer" href="http://jigsaw.w3.org/css-validator/">
<img class="footer" src="http://jigsaw.w3.org/css-validator/images/vcss"
	  alt="Valid CSS!" height="31" width="88" />
 </a>

<a class="footer" href="http://developer.berlios.de/projects/uopp/">
<img class="footer" src="http://developer.berlios.de/bslogo.php?group_id=2223&amp;type=1" 
	  alt="BerliOS Logo" height="32" width="124" />
</a>

</p>

<p class="copyright">
Created by <a class="copyright" href="http://thomas.delaet.org">Thomas Delaet</a>
</p>

</div>

</body>
</html>
