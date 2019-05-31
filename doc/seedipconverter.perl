#!/usr/bin/perl
# run:  perl seedipconverter.perl (input ip4 address)

my $ip;
if (@ARGV){
	$ip = shift @ARGV;
}else{
	print "Enter an (dotted quad) ip address: ";
	chomp( $ip = <STDIN> );
}

printf "0x%08x\n \n", unpack 'N', pack 'C4', reverse split '\.', $ip;
print "chainseeds hex ip example----------> 0xb6a15c56 -----------> 0xb6   a1   5c   56\n";
print "{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xb6,0xa1,0x5c,0x56}\n ";
