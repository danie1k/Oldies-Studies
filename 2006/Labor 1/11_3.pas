program zad_11_3;
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


   var n: integer;
       Wn: real;

begin

     Welcome('11.3');

REPEAT
      Writeln(PL(' Podaj liczbÍ naturalnπ n,'));
      Write(PL(' dla ktÛrej ma zostaÊ policzona wartoúÊ wyraøenia W(n): '));
      Readln(n);
      if  (n <= 0) then
      begin
          Writeln(PL('    B£•D: Liczba muszi byÊ wiÍksza od zera!'));
          Writeln;
      end;

UNTIL n > 0;


if odd(n) then
   begin
     Wn := (n-5)*n;
     Writeln; Writeln;
     Writeln('     Podana liczba jest nieparzysta');
   end
else
   begin
     Wn := (n/2)+n*n;
     Writeln; Writeln;
     Writeln('     Podana liczba jest nieparzysta');
    end;

Writeln;
Writeln(PL('     WartoúÊ wyraøenia dla podanego n wynosi: W(n) = '),Wn:0:0);


Readln;
end.
