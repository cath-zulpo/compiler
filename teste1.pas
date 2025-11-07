program exemplo75 (input, output);
var i,m,n,k :  integer;
begin
	i := 1;
	m := 2;
	n := 3;
	k := 4;

	while i < 5 do
	begin
		writeln(i);
		i := i+1;
	end;

	writeln((5+m)*-n, k);
end.
