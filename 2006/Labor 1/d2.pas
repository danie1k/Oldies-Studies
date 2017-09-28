program silnia2;
  uses Crt;

  function oblicz(liczba:longint):longint;
  begin
    oblicz := 2*liczba-1;
  end;

  var n, i, wynik, wynik2: longint;

begin
  Writeln('Program liczy (2n-1)! podanej liczby.');

  repeat
    Write('Podaj n: '); Readln(n);
  until n > 0;


{-- sposób pierwszy --}
wynik := 1;
for i := 1 to oblicz(n) do
begin
   wynik := wynik * i;
end;
Writeln('Wynik:  ',wynik);


{-- sposób drugi --}
i := 1;
wynik2 := 1;
repeat
   i := i+1;
   wynik2 := wynik2 * i;
until i = oblicz(n);
Writeln('Wynik2: ',wynik2);


  Readln;
end.
