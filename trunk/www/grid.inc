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
<preserve layout align valign width padding spacing border
          bgcolor color summary class />
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
    my $align   = '<get-var align />';
    my $valign  = '<get-var valign />';
    my $width   = '<get-var width />';
    my $spacing = '<get-var spacing />';
    my $padding = '<get-var padding />';
    my $border  = '<get-var border />';
    my $bgcolor = '<get-var bgcolor />';
    my $color   = '<get-var color />';
    my $class	= '<get-var class />';
    my $summary = qq|<get-var summary />|;
    my $height;
    #    set defaults for attributes
    $layout  = "1x$NCELL"                  if ($layout  eq '');
    ($xsize, $ysize) = ($layout =~ m|^(\d+)x(\d+)$|);
    $align   = 'l' x $xsize                if ($align   eq '');
    @ALIGNS  = split("", $align);
    $valign  = 't' x $ysize                if ($valign  eq '');
    @VALIGNS = split("", $valign);
    $width   = " width=\"$width\""         if ($width   ne '');
    $spacing = '0'                         if ($spacing eq '');
    $spacing = " cellspacing=\"$spacing\"" if ($spacing ne '');
    $padding = '0'                         if ($padding eq '');
    $padding = " cellpadding=\"$padding\"" if ($padding ne '');
    $border  = '0'                         if ($border  eq '');
    $border  = " border=\"$border\""       if ($border  ne '');
    $bgcolor = " bgcolor=\"$bgcolor\""     if ($bgcolor ne '');
    $summary = " summary=\"$summary\""     if ($summary ne '');
    $class   = " class=\"$class\""	   if ($class ne '');

    #   some more setups
    my $pad = '    ' x ($GRIDLEVEL-1);
    my $globalcolor = $color;
    my %ALIGNTEXT = ( 'l' => 'left', 'c' => 'center', 'r' => 'right',
                      't' => 'top',  'm' => 'middle', 'b' => 'bottom' );

    #   create table container
    <perl:print>\
       $pad<table*$width$border$spacing$padding$bgcolor$summary$class>
</perl:print>

    #   create cell entries
    my %SPAN = ();
    my $n = 0;
    my ($y, $x, $body, $attr, $i);
    for ($y = 0; $y < $ysize; $y++) {
        #   start of a row
        <perl:print>$pad  <tr*>
</perl:print>

        #   create cells in a row
        for ($x = 0; $x < $xsize; $x++) {

            #   skip current grid position if spanning is active
            next if ($SPAN{$y*$xsize+$x});

            #   get the next cell info
            $body = $CELL_BODY{$n};
            $attr = $CELL_ATTR{$n};
            ($align, $valign, $bgcolor, $color, $rowspan, $colspan, $width, $height) = split(':', $attr);

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
            $align   = "$ALIGNTEXT{$ALIGNS[$x]}"  if ($align eq '');
            $align   = " align=\"$align\"";
            $valign  = "$ALIGNTEXT{$VALIGNS[$y]}" if ($valign eq '');
            $valign  = " valign=\"$valign\"";
            $bgcolor = " bgcolor=\"$bgcolor\""    if ($bgcolor ne '');
            $color   = $globalcolor if ($globalcolor ne '' and $color eq '');
            $body    = "<"."font color=\"$color\">".$body."<*/font>" if ($color ne '');
            $rowspan = " rowspan=\"$rowspan\""    if ($rowspan ne '');
            $colspan = " colspan=\"$colspan\""    if ($colspan ne '');
            $width   = " width=\"$width\""        if ($width ne '');
            $height  = " height=\"$height\""      if ($height ne '');

            #   insert cell
            <perl:print>\
               $pad    <td$align$valign$bgcolor$rowspan$colspan$width$height>\
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
<restore  layout align valign width padding spacing border
          bgcolor color summary class />
</define-tag>

#
#   THE CELL ELEMENT TAG
#
<define-tag cell endtag=required>
<preserve align valign bgcolor color rowspan colspan width height />
<set-var %attributes />
<perl>
    #   set the information for the surrounding grid container
    $div = "GRID${ngrid}_CELL${NCELL}";
    $CELL_BODY{$NCELL} = "{#${div}#}";
    $CELL_ATTR{$NCELL} = '<get-var align />:<get-var valign />:<get-var bgcolor />:<get-var color />:<get-var rowspan />:<get-var colspan />:<get-var width />:<get-var height />';
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
<restore  align valign bgcolor color rowspan colspan width height />
</define-tag>

##EOF##
