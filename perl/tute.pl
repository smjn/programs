#!/usr/bin/env perl

use strict;
use warnings;
use diagnostics;

use feature "say";	#println
use feature "switch"; #switch case

say "hello world";

#data types - scalars, arrays and hash
#scalars
my $name = "Sushant";
my ($num1, $addr1) = (1, "Tagore Garden");
my $my_info = "$name lives on $addr1\n";
print $my_info;
$my_info = qq{$name lives on "$addr1"\n};
print $my_info;

#here line
my $big_line = << "END";
this is a big line
doesn't need to be
but it is
END

say $big_line;

printf("%u \n", $num1 + 1);

my $first = 1;
my $second = 2;

($first, $second) = ($second, $first);
print $first, $second,"\n";

print rand 11
