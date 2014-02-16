#!/usr/bin/perl

use strict;
use warnings;

open FILE, "</dev/ttyACM0";
while (1) {
	while (<FILE>) {
		print $_;
	}
}
