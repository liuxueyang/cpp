for $*IN.lines -> $line {
    my $len = $line.chars;
    for 0..^$len -> $i {
        print $line.substr($i, 1) if $i != ($len div 2);
    }
    say '';
}
