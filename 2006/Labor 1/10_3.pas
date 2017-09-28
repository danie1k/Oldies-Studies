program zad_10_3;
   uses Crt;


      {funkcje pomocnicze}


function Welcome(s : string) : string;
var w : integer;
begin
   ClrScr;
   Writeln;
   w := 0; Write(' ',chr(201)); repeat Write(chr(205)); w:=w+1; until w=27; Writeln(chr(187));
   Writeln(' ',chr(186),'                           ',chr(186));
   Writeln(' ',chr(186),'  Realizacja zadania ', s ,'  ',chr(186));
   Writeln(' ',chr(186),'                           ',chr(186));
   w := 0; Write(' ',chr(200)); repeat Write(chr(205)); w:=w+1; until w=6;
   Write(' Daniel Kuruc ');
   w := 0; repeat Write(chr(205)); w:=w+1; until w=7; Writeln(chr(188));
   Writeln;
   Writeln;
end;

function PL(s : string) : string;
   var i : integer;
       c : char;
begin
   for i := 1 to length(s) do
   begin
      case s[i] of
         'π' : c := #165;
         'Ê' : c := #134;
         'Í' : c := #169;
         '≥' : c := #136;
         'Ò' : c := #228;
         'Û' : c := #162;
         'ú' : c := #152;
         'ø' : c := #190;
         'ü' : c := #171;
         '•' : c := #164;
         '∆' : c := #143;
         ' ' : c := #168;
         '£' : c := #157;
         '—' : c := #227;
         '”' : c := #224;
         'å' : c := #151;
         'Ø' : c := #189;
         'è' : c := #141;
      else
         c := s[i];
   end;
   s[i] := c;
end;
Result := s;
end;


      {g≥Ûwna czÍúÊ programu}


   var tablica: array[1..20, 1..20] of real;
       tablica_sum: array[1..2,1..10] of real;
       x, i, j, n, k: integer;

begin

     Welcome('10.3');
     Writeln('Podaj wymiary macierzy A (n-wierszy i k-kolumn): ');

REPEAT
      Write(' n: '); Readln(n);
      if n < 0 then begin Writeln(PL('    B£•D: Podana liczba musi byÊ wiÍksza od zera')); Writeln end;
UNTIL (n > 0);

REPEAT
      Write(' k: '); Readln(k);
      if k < 0 then begin Writeln(PL('    B£•D: Podana liczba musi byÊ wiÍksza od zera')); Writeln end;
UNTIL (k > 0);

Writeln;
for i := 1 to n do
begin
     for j := 1 to k do
     begin
          Write(PL('Podaj wartoúÊ elementu ['),i,',',j,']: ');
          Readln(tablica[i][j]);
      end;
end;

{sumowanie wierszy}
for i := 1 to n do
begin
     for j := 1 to k do
     begin
          tablica_sum[1,i] := tablica_sum[1,i] + tablica[i,j]
     end;
end;

{sumowanie kolumn}
for j:=1 to k do
begin
     for i:=1 to n do
     begin
          tablica_sum[2,j] := tablica_sum[2,j] + tablica[i,j]
     end;
end;


{drukowanie wpisanych wartoúci macierzy}
ClrScr;
Writeln; Writeln(' ',chr(179),' Podana macierz:'); Write(' ',chr(192)); x:=0; REPEAT Write(chr(196)); x:= x+1; UNTIL x=39; Writeln;
for i := 1 to n do
begin
     Write('   ',chr(179),' ');
     for j := 1 to k do
     begin
          Write(tablica[i,j]:3:0);
     end;
     Writeln(' ',chr(179));
end;

{drukowanie sumy wierszy}
Writeln; Writeln; Writeln(' ',chr(179),' Suma wierszy:'); Write(' ',chr(192)); x:=0; REPEAT Write(chr(196)); x:= x+1; UNTIL x=39; Writeln;
for i := 1 to n do
begin
     Writeln('   ',chr(179),' ',tablica_sum[1,i]:3:0,' ',chr(179));
end;

{drukowanie sumy kolumn}
Writeln; Writeln; Writeln(' ',chr(179),' Suma kolumn:'); Write(' ',chr(192)); x:=0; REPEAT Write(chr(196)); x:= x+1; UNTIL x=39; Writeln;
Write('   ',chr(179),' ');
for j := 1 to k do
begin
     Write(tablica_sum[2,j]:3:0,' ');
end;
Writeln(chr(179));

Readln;
end.
