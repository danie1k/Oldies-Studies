program zad_11_5;
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


   var strona, y, i, n, bin: integer;
       liczby: array[1..100,1..2] of integer;
       binarna: string;

procedure stronicowanie;
begin
     if (i mod 16 = 0) and (i <> n)then
     begin
          Writeln('              ',chr(192),'----',chr(193),'----------------------',chr(193),'----------------------',chr(217));
          Writeln;
          Write(PL('Naciúnij klawisz Enter, aby kontynuowaÊ...'));
          Readln;
          ClrScr;

          strona:=strona+1;
          Writeln('    ',PL('Ciπg ma '),n,PL(' elementÛw')); y:=0; REPEAT Write(chr(196)); y:=y+1; UNTIL y=80; Writeln('Strona: ',strona);

          Writeln('              ',chr(218),'----',chr(194),'----------------------',chr(194),'----------------------',chr(191));
          Writeln('              ',chr(179),' lp ',chr(179),PL('    liczba dziesiÍtna '),chr(179),PL('       liczba binarna '),chr(179));
          Writeln('              ',chr(195),'----',chr(197),'----------------------',chr(197),'----------------------',chr(180));
      end;
end;

procedure DecBin(x: integer);
begin
     binarna := '';
     REPEAT
           if (x mod 2) = 1 then binarna := '1' + binarna
           else
               if (x mod 2) = 0 then binarna := '0' + binarna;

           x := (x div 2);
     UNTIL x = 0;
     val(binarna, bin);
end;


begin

     Welcome('11.5');

REPEAT
      Write(PL('   Podaj iloúÊ elementÛw ciπgu (n): ')); Readln(n);
      if (n <= 0) then
      begin
           Writeln(PL('    B£•D: Pusi byÊ przynajmniej jeden element do przeliczenia :)'));
           Writeln
      end
      else
          if (n > 100) then
          begin
             Writeln(PL('    B£•D: Maksymalna iloúÊ elementÛw to 100'));
             Writeln
          end;


UNTIL (n > 0) and (n <= 100);

Writeln; Writeln;

for i := 1 to n do
begin
     REPEAT
          Write('Podaj ',i,PL(' element ciπgu: ')); Readln(liczby[i,1]);
          if (n <= 0) then
          begin
               Writeln(PL('    B£•D: Liczba musi byÊ >= 0'));
               Writeln
          end
     UNTIL (liczby[i,1] >= 0);

     DecBin(liczby[i,1]);
     liczby[i,2] := bin;
end;


ClrScr;

strona := 1;
Writeln('    ',PL('Ciπg ma '),n,PL(' elementÛw')); y:=0; REPEAT Write(chr(196)); y:=y+1; UNTIL y=80; Writeln('Strona: ',strona);

Writeln('              ',chr(218),'----',chr(194),'----------------------',chr(194),'----------------------',chr(191));
Writeln('              ',chr(179),' lp ',chr(179),PL('    liczba dziesiÍtna '),chr(179),PL('       liczba binarna '),chr(179));
Writeln('              ',chr(195),'----',chr(197),'----------------------',chr(197),'----------------------',chr(180));

for i := 1 to n do
begin
     Writeln('              ',chr(179),' ',i:2,' ',chr(179),' ',liczby[i,1]:20,' ',chr(179),' ',liczby[i,2]:20,' ',chr(179));
     stronicowanie;
end;

Writeln('              ',chr(192),'----',chr(193),'----------------------',chr(193),'----------------------',chr(217));
GotoXY(1,25); Write('Koniec.');

Readln;
end.
