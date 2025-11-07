program exemplo75 (input, output);
var x :  integer;
	procedure p1(var y : integer);
		function f1(var z : integer) : integer;
			procedure p2(var w : integer);
			begin
				w := 5;
			end;
		begin
			f1 := z+1;
			p2(z);
		end;
	begin
			y := f1(y)+y;
	end;
begin
	read(x);

	p1(x);

	writeln(x);
end.
