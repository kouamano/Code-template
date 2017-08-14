#!/usr/bin/perl

while(<>){
	%hs = ();
	chomp;
	print "$_\t";

	while($_ =~ /(<ORG)/g){
	$pos = pos($_);
	#print "$1:$pos";
	$hs{$pos} = "<ORG"; }

	pos($_) = 0;

	while($_ =~ /(<RES)/g){
	$pos = pos($_);
	#print "$1:$pos";
	$hs{$pos} = "<RES"; }

	for my $key (sort{$a <=> $b} keys %hs) {
		print ":$key$hs{$key}"
	}
	print "\n";
}
