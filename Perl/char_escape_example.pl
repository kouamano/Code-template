#!/usr/bin/perl

while(<>){
	push(@tmp,$_);
}

@tmp = &escape(@tmp);

foreach(@tmp2){
	print $_;
}

sub escape {
	my @all = ();
	my @out = ();
	my @sp = ();
	my $out = "";
	foreach(@_){
		@out = ();
		@sp = split(//,$_);
                foreach(@sp){
			if($_ eq '\\'){
				push(@out,"\\\\");
                        }elsif($_ eq '*'){
                                push(@out,"\\\*");
                        }elsif($_ eq '+'){
                                push(@out,"\\\+");
                        }elsif($_ eq '.'){
                                push(@out,"\\\.");
                        }elsif($_ eq '?'){
                                push(@out,"\\\?");
                        }elsif($_ eq '{'){
                                push(@out,"\\\{");
                        }elsif($_ eq '}'){
                                push(@out,"\\\}");
                        }elsif($_ eq '('){
                                push(@out,"\\\(");
                        }elsif($_ eq ')'){
                                push(@out,"\\\)");
                        }elsif($_ eq '['){
                                push(@out,"\\\[");
                        }elsif($_ eq ']'){
                                push(@out,"\\\]");
                        }elsif($_ eq '^'){
                                push(@out,"\\\^");
                        }elsif($_ eq '$'){
                                push(@out,"\\\$");
                        }elsif($_ eq '|'){
                                push(@out,"\\\|");
                        }elsif($_ eq '/'){
                                push(@out,"\\\/");
                        }else{
				push(@out,"$_");
			}
                }
		$out = join("",@out);
		push(@all,$out);
        }
	return @all;
}
