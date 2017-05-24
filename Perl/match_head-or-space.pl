#!/usr/bin/perl
#matching space or head of line
while(<>){
	$_ =~ s/([ :]|^)(a)()/${1}<${2}>${3}/g;
	print $_;
}
