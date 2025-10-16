my @tokens = $*IN.slurp.words>>.Int;
my $n = @tokens[0];
my $res = 0;
for 1..$n -> $i {
    $res += ($i +& 1 ?? -1 !! 1) * ($i ** 3);
}
say $res;
