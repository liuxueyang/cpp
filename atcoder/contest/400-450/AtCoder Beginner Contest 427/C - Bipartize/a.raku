my ($n, $m) = get().words>>.Int;
my @edges;
for ^$m {
    my ($u, $v) = get().words>>.Int;
    $u--, $v--;
    @edges.push: [$u, $v];
}

my $res = $m + 10000;
for 0..^(2 ** $n) -> $s {
    my $tmp = 0;
    for @edges -> ($u, $v) {
        my $color1 = ($s +> $u) +& 1;
        my $color2 = ($s +> $v) +& 1;
        $tmp++ if $color1 == $color2;
    }
    $res = min($res, $tmp);
}
say $res;
