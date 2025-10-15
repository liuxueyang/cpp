my @vers = "Ocelot", "Serval", "Lynx";
my ($x, $y) = get().words>>.Str;
my ($id1, $id2);
for @vers.kv -> $id, $s {
    $id1 = $id if $s eq $x;
    $id2 = $id if $s eq $y;
}
say $id1 >= $id2 ?? "Yes" !! "No";

