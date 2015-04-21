#!/usr/bin/perl

use Parallel::ForkManager;

my $pm = Parallel::ForkManager->new(8);

my @list = (1,2,3,4,5,6,7,8);
foreach(@list){
	$pm->start and next;
	print $_;
	$pm->finish;
}
$pm->wait_all_children;
