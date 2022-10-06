#!/usr/bin/perl -w
##############################################################################
### This script creates a povglobe header file from a 80x40 image
### Input image should be 80x40, not compressed, no alpha channel (black
### is used for alpha)
### 
### usage: img2globe.pl image.bmp <name of array>
###
### (name of array is also the name of the output file)
### The script will also create a <name of array>out.bmp to check threshhold
### values without the globe.
###
### WARNING!
### THIS SCRIPT IS VERY QUICK&DIRTY AND MIGHT OVERWRITE DATA 
### 
### also, the cake is a lie
##############################################################################
use strict;
use warnings;
use Image::Magick;


############################################
# color thresholds from 0 to 1 (max)
my $redthreshold = 0.6;
my $greenthreshold = 0.5;
my $bluethreshold = 0.5;
############################################

open OUTFILE, ">$ARGV[1].h" or die $!;

my $image;
$image = Image::Magick->new;
$image->Read($ARGV[0]);

# blank image 
my $imageout = Image::Magick->new;
$imageout->Set(size=>'80x40');
$imageout->Read('canvas:black');

my $globeline;
my $globex;

my @pixels = (1, 1, 1);

print OUTFILE "#ifndef _$ARGV[1]_H_\n#define _$ARGV[1]_H_\n\n";
print OUTFILE "#include <avr/pgmspace.h>\n";
print OUTFILE "static const uint8_t $ARGV[1]". "[] PROGMEM = {\n";
for($globex = 0; $globex <= 79; $globex++){
	for($globeline = 0; $globeline <= 4; $globeline++){
		my ($bytered, $bytegreen, $byteblue, $curbit);
		$bytered = $bytegreen = $byteblue = $curbit = 0;
		for($curbit = 0; $curbit <= 7; $curbit++){
			my $yposition = 39 - ($globeline * 8 + $curbit);
			$image->GetPixel(geometry=>"80x40", channel=>'Red', normalize=>"true", x=>79-$globex, y=>$yposition) >= $redthreshold and 
				$bytered += 2**$curbit;
			$image->GetPixel(geometry=>"80x40", channel=>'Green', normalize=>"true", x=>79-$globex, y=>$yposition) >= $greenthreshold and 
				$bytegreen += 2** $curbit;
			$image->GetPixel(geometry=>"80x40", channel=>'Blue', normalize=>"true", x=>79-$globex, y=>$yposition) >= $bluethreshold and 
				$byteblue += 2** $curbit;
			
			$image->GetPixel(geometry=>"80x40", channel=>'Red', normalize=>"true", x=>$globex, y=>$yposition) >= $redthreshold and 
				$imageout->SetPixel(geometry=>"80x40", x=>$globex,y=>$yposition,channel=>'Red', normalize=>"true", color=>\@pixels);

			$image->GetPixel(geometry=>"80x40", channel=>'Green', normalize=>"true", x=>$globex, y=>$yposition) >= $greenthreshold and 
				$imageout->SetPixel(geometry=>"80x40", x=>$globex,y=>$yposition,channel=>'Green', normalize=>"true", color=>\@pixels);

			$image->GetPixel(geometry=>"80x40", channel=>'Blue', normalize=>"true", x=>$globex, y=>$yposition) >= $bluethreshold and 
				$imageout->SetPixel(geometry=>"80x40", x=>$globex,y=>$yposition,channel=>'Blue', normalize=>"true", color=>\@pixels);
		}
		print OUTFILE "$bytered, $bytegreen, $byteblue";
		not ($globex == 79 && $globeline == 4 ) and print OUTFILE ",";
		print OUTFILE "\n";
	}
}
$imageout->Write(filename=>"$ARGV[1]out.bmp", compression=>'None');
print OUTFILE "};\n#endif";
close OUTFILE;

