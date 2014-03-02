#!/usr/bin/perl

# vars
$help = 0;
$check = 0;
$status = 0;
$int1 = 0;
$str1 = "";
$ie = 0;

# subroutine
sub _help {
	print "USAGE:\n";
	printf " this is a template.\n"
}

sub _check {
	print "ARGS:\n";
	print " help:$help:\n";
	print " check:$check:\n";
	print " status:$status:\n";
	print " int1:$int1:\n";
	print " str1:$str1:\n";
}

sub _status {
	print "STATUS:\n";
	printf " this is a template.\n"
}

# argment analysis
foreach $l (@ARGV) {
	if($l eq "-h"){
		$help = 1;
	}elsif($l eq "-c"){
		$check = 1;
	}elsif($l eq "-s"){
		$status = 1;
	}elsif($l =~ /int1=(.*)/){
		$int1 = $1;
	}elsif($l =~ /str1=(.*)/){
		$str1 = $1;
	}else{
		print "unknown:$l:\n";
	}
}

# main
if($help == 1){
	&_help;
	$ie = 1;
}
if($check == 1){
	&_check;
	$ie = 1;
}
if($status == 1){
	&_status;
	$ie = 1;
}
if($ie == 1){
	exit(0);
}
