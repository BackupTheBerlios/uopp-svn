##
##  wml::fmt::isolatin - ISO-Latin-1 to HTML Entity Conversion
##  Copyright (c) 1997-2001 Ralf S. Engelschall, All Rights Reserved. 
##

#   the container tag itself
<define-tag isolatin endtag=required>
{:\
    [[s| |&nbsp;|g]]\
    [[s|¡|&iexcl;|g]]\
    [[s|¢|&cent;|g]]\
    [[s|£|&pound;|g]]\
    [[s|¤|&curren;|g]]\
    [[s|¥|&yen;|g]]\
    [[s|¦|&brvbar;|g]]\
    [[s|§|&sect;|g]]\
    [[s|¨|&uml;|g]]\
    [[s|©|&copy;|g]]\
    [[s|ª|&ordf;|g]]\
    [[s|«|&laquo;|g]]\
    [[s|¬|&not;|g]]\
    [[s|­|&shy;|g]]\
    [[s|®|&reg;|g]]\
    [[s|¯|&macr;|g]]\
    [[s|°|&deg;|g]]\
    [[s|±|&plusmn;|g]]\
    [[s|²|&sup2;|g]]\
    [[s|³|&sup3;|g]]\
    [[s|´|&acute;|g]]\
    [[s|µ|&micro;|g]]\
    [[s|¶|&para;|g]]\
    [[s|·|&middot;|g]]\
    [[s|¸|&cedil;|g]]\
    [[s|¹|&sup1;|g]]\
    [[s|º|&ordm;|g]]\
    [[s|»|&raquo;|g]]\
    [[s|¼|&frac14;|g]]\
    [[s|½|&frac12;|g]]\
    [[s|¾|&frac34;|g]]\
    [[s|¿|&iquest;|g]]\
    [[s|À|&Agrave;|g]]\
    [[s|Á|&Aacute;|g]]\
    [[s|Â|&Acirc;|g]]\
    [[s|Ã|&Atilde;|g]]\
    [[s|Ä|&Auml;|g]]\
    [[s|Å|&Aring;|g]]\
    [[s|Æ|&AElig;|g]]\
    [[s|Ç|&Ccedil;|g]]\
    [[s|È|&Egrave;|g]]\
    [[s|É|&Eacute;|g]]\
    [[s|Ê|&Ecirc;|g]]\
    [[s|Ë|&Euml;|g]]\
    [[s|Ì|&Igrave;|g]]\
    [[s|Í|&Iacute;|g]]\
    [[s|Î|&Icirc;|g]]\
    [[s|Ï|&Iuml;|g]]\
    [[s|Ð|&ETH;|g]]\
    [[s|Ñ|&Ntilde;|g]]\
    [[s|Ò|&Ograve;|g]]\
    [[s|Ó|&Oacute;|g]]\
    [[s|Ô|&Ocirc;|g]]\
    [[s|Õ|&Otilde;|g]]\
    [[s|Ö|&Ouml;|g]]\
    [[s|×|&times;|g]]\
    [[s|Ø|&Oslash;|g]]\
    [[s|Ù|&Ugrave;|g]]\
    [[s|Ú|&Uacute;|g]]\
    [[s|Û|&Ucirc;|g]]\
    [[s|Ü|&Uuml;|g]]\
    [[s|Ý|&Yacute;|g]]\
    [[s|Þ|&THORN;|g]]\
    [[s|ß|&szlig;|g]]\
    [[s|à|&agrave;|g]]\
    [[s|á|&aacute;|g]]\
    [[s|â|&acirc;|g]]\
    [[s|ã|&atilde;|g]]\
    [[s|ä|&auml;|g]]\
    [[s|å|&aring;|g]]\
    [[s|æ|&aelig;|g]]\
    [[s|ç|&ccedil;|g]]\
    [[s|è|&egrave;|g]]\
    [[s|é|&eacute;|g]]\
    [[s|ê|&ecirc;|g]]\
    [[s|ë|&euml;|g]]\
    [[s|ì|&igrave;|g]]\
    [[s|í|&iacute;|g]]\
    [[s|î|&icirc;|g]]\
    [[s|ï|&iuml;|g]]\
    [[s|ð|&eth;|g]]\
    [[s|ñ|&ntilde;|g]]\
    [[s|ò|&ograve;|g]]\
    [[s|ó|&oacute;|g]]\
    [[s|ô|&ocirc;|g]]\
    [[s|õ|&otilde;|g]]\
    [[s|ö|&ouml;|g]]\
    [[s|÷|&divide;|g]]\
    [[s|ø|&oslash;|g]]\
    [[s|ù|&ugrave;|g]]\
    [[s|ú|&uacute;|g]]\
    [[s|û|&ucirc;|g]]\
    [[s|ü|&uuml;|g]]\
    [[s|ý|&yacute;|g]]\
    [[s|þ|&thorn;|g]]\
    [[s|ÿ|&yuml;|g]]\
    [[s|& |&amp; |g]]\
    %body\
:}\
</define-tag>

#   the "#include ... global" support
<if "$(global)" <group
<isolatin>
{#ISOLATIN_GLOBAL#}
</isolatin>
{#ISOLATIN_GLOBAL#:
/>/>

##EOF##
