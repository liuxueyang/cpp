my $s = get().words.Str;
my %mp;
for 0..^($s.chars) -> $i {
    my $ch = $s.substr($i, 1);
    %mp{$ch}++;
}
for %mp.kv -> $key, $value {
    say $key if $value == 1;
}
