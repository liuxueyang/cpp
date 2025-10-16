my @tokens = $*IN.slurp.words>>.Int;
my $idx = 0;
my $n = @tokens[$idx++];
my Int (@a, @p);
my %mp;
@a[1..$n] = @tokens[$idx..^$idx + $n];

my Bool $ok = True;
for @a[1..$n] -> $i {
    next if $i < 0;
    if %mp{$i}:exists {
        $ok = False;
        last;
    }
    %mp{$i} = 1;
}

if $ok {
    my $j = 1;
    for @a[1..$n] -> $i {
        if $i < 0 {
            while %mp{$j}:exists {
                $j++;
            }
            @p.push($j++);
        } else {
            @p.push($i);
        }
    }
    say "Yes\n", @p.join(" ");
} else {
    say "No";
}
