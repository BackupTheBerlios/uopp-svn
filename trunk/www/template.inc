##
## template.inc -- uopp website template
##

#use wml::fmt::isolatin
#use wml::std::tags

<divert PORTSINDEX>
<ul>
<li><a href="<get-var ROOT />/ports/3.4.html">Browsable interface of the 3.4 ports tree</a></li>
<li><a href="<get-var ROOT />/ports/3.5.html">Browsable interface of the 3.5 ports tree</a></li>
<li><a href="<get-var ROOT />/ports/current.html">Browsable interface of the current ports tree</a></li>
<li><a href="<get-var ROOT />/ports/current/mystuff/index.html">Downloadable unoffical OpenBSD ports</a></li>
</ul>
</divert>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="en">
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
  <title><dump TITLE /> | uopp</title>
  <link rel="stylesheet" type="text/css" href="<get-var ROOT />/styles/layout.css" media='screen' />
  <link rel="shortcut icon" href="<get-var ROOT />/images/puf100X86.gif" />
  <style type="text/css">
    @import "<get-var ROOT />/styles/markup.css";
  </style>
</head>

<body>

<table class="header">
	<tr>
   <td class="logo">
   	<img width="200" height="50" alt="OpenBSD logo" src="<get-var ROOT />/images/puflogh200X50.gif" />
	</td>
   <td class="menu">
      <div class="menu_list">
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

<tr class="footer"><td class="footer">
<a href="http://developer.berlios.de">
<img src="http://developer.berlios.de/bslogo.php?group_id=2223&type=1" width="124" height="32" border="0" alt="BerliOS Logo" /></a>

</td></tr>

</table>
</body>
</html>
