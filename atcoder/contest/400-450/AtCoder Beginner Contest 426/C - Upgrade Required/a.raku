my $input = $*IN.slurp;
my int @tokens = $input.words>>.Int;
my $idx = 0;

my $n = @tokens[$idx++];
my $q = @tokens[$idx++];
my int @arr = 1 xx ($n + 1);
my @ans;
for ^$q {
    my $x = @tokens[$idx++];
    my $y = @tokens[$idx++];
    my $res = 0;
    for reverse(1..$x) -> $i {
        if (!@arr[$i]) {
            last;
        }
        $res += @arr[$i];
        @arr[$i] = 0;
    }
    @arr[$y] += $res;

    @ans.push($res);
}
say @ans.join("\n");
