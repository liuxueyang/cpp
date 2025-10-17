sub f(Str $n) {
    my $res = 0;
    for 0..^$n.chars -> $i {
        $res += $n.substr($i, 1) - '0';
    }
    return $res;
}

for $*IN.lines -> $line {
    my $n = $line.Int;
    my $res = 1;
    for 1..($n - 1) {
        $res = $res + f($res.Str);
    }
    say $res;
}
