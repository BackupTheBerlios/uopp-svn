##
##  wml::std::grid - Layout Grid
##  Copyright (c) 1997-2001 Ralf S. Engelschall, All Rights Reserved. 
##

#  The <preserve>/<restore> tags with multiple arguments require WML 2.0.3
#use wml::mod::version
<require 2.0.3 />

#use wml::std::tags

<: 
#   top-level globals
$NGRID     = 0;
$GRIDLEVEL = 0;
:>

#
#   THE GRID CONTAINER TAG
#
<define-tag grid endtag=required>
<preserve layout class />
<set-var %attributes />
<perl>
{
    $GRIDLEVEL++;

    #  grid globals
    my $ngrid = $NGRID++;
    my $NCELL = 0;
    my %CELL_ATTR = ();
    my %CELL_BODY = ();

    #   import cell specs... 
    my $div;
</perl>\
%body
<perl>
    #   then import attributes to ePerl 
    my $layout  = '<get-var layout />';
    my $class	= '<get-var class />';

    #    set defaults for attributes
    $layout  = "1x$NCELL"                  if ($layout  eq '');
    ($xsize, $ysize) = ($layout =~ m|^(\d+)x(\d+)$|);
    $class   = " class=\"$class\""	   if ($class ne '');

    #   some more setups
    my $pad = '    ' x ($GRIDLEVEL-1);
    #   create table container
    <perl:print>\
       $pad<table*$class>
</perl:print>

    #   create cell entries
    my %SPAN = ();
    my $n = 0;
    my ($y, $x, $body, $attr, $i);
    for ($y = 0; $y < $ysize; $y++) {
        #   start of a row
        <perl:print>$pad  <tr$class*>
</perl:print>

        #   create cells in a row
        for ($x = 0; $x < $xsize; $x++) {

            #   skip current grid position if spanning is active
            next if ($SPAN{$y*$xsize+$x});

            #   get the next cell info
            $body = $CELL_BODY{$n};
            $attr = $CELL_ATTR{$n};
            (class) = split(':', $attr);

            #   remember row spanning (current one can be ignored)
            if ($rowspan ne '') {
                for ($i = 1; $i < $rowspan; $i++) {
                    $SPAN{$y*$xsize+$x + $xsize*$i} = 1;
                }
            }
            #   remember column spanning (current one can be ignored)
            if ($colspan ne '') {
                for ($i = 1; $i < $colspan; $i++) {
                    $SPAN{$y*$xsize+$x + $i} = 1;
                }
            }

            #   complete the info
            $class  = " class=\"$class\""      if ($class ne '');

            #   insert cell
            <perl:print>\
               $pad    <td$class>\
               $body</td>
</perl:print>

            #   increase cell counter
            $n++;
        }

        #   end of a row
        <perl:print>$pad  </tr*>
</perl:print>
    }

    #   end of the table
    <perl:print>$pad</table*>
</perl:print>

    $GRIDLEVEL--;
}
</perl>\
<restore  layout class />
</define-tag>

#
#   THE CELL ELEMENT TAG
#
<define-tag cell endtag=required>
<preserve class />
<set-var %attributes />
<perl>
    #   set the information for the surrounding grid container
    $div = "GRID${ngrid}_CELL${NCELL}";
    $CELL_BODY{$NCELL} = "{#${div}#}";
    $CELL_ATTR{$NCELL} = '<get-var class />';
    $NCELL++;

    #   now finally inline the body via divertions
    #   (we could put the body tag directly above
    #   but then this will limit the usage dramatically!)
    <perl:print>{#${div}#:</perl:print>
</perl>\
%body\
<perl>
    <perl:print>:#${div}#}</perl:print>
</perl>\
<restore  class />
</define-tag>

##EOF##
