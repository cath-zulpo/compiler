program exemplo75 (input, output);
var x :  integer;
	function f(x:integer) : integer;
	begin
		if x = 0 then
			f := 0
		else if x = 1 then
			f := 1
		else
			f := f(x-1)+f(x-2)
	end;
begin
	read(x);

	writeln(f(x));
end.
