program silnia;
  uses Crt;

  var n, i, wynik, wynik2: longint;

begin
  Writeln('Program liczy silnie podanej liczby.');

  repeat
    Write('Podaj n: '); Readln(n);
  until n > 0;


{-- sposób pierwszy --}
wynik := 1;
for i := 1 to n do
begin
   wynik := wynik*i;
end;
Writeln('Wynik:  ',wynik);


{-- sposób drugi --}
i := 1;
wynik2 := 1;
repeat
   i := i+1;
   wynik2 := wynik2*i;
until i = n;
Writeln('Wynik2: ',wynik2);


  Readln;
end.
