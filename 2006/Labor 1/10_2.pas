program zad_10_2;
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


   var x, strona, ilosc_punktow, i, j: integer;
       x1, x2, wielkosc_kroku, krok: real;
       tablica: array[1..100, 1..2] of real;

function fx(x : real) : real;
var funkcja:real;
begin
   if x <= 0 then funkcja := 1/(1+(x*x))
   else
       if x > 0 then funkcja := (1/(1+(x*x)))+x
       else funkcja := 0;
Result := funkcja;
end;


begin

     Welcome('10.2');

REPEAT
      Write(PL('  Podaj iloúÊ punktÛw tablicowania (min. 2 - max. 100): ')); Readln(ilosc_punktow);
      if (ilosc_punktow < 2) or (ilosc_punktow > 100) then Writeln(PL('     B£•D: Podana liczba musi byÊ z przedzia≥u <2; 100>'));
      Writeln;
UNTIL (ilosc_punktow >= 2) and (ilosc_punktow <= 100);


REPEAT
      Writeln(PL('  Podaj przedzia≥, na ktÛrym majπ zostaÊ')); Writeln(PL('  policzone wartoúci funkcji - <x1; x2>: '));
      Write('   x1: '); Readln(x1);
      Write('   x2: '); Readln(x2);
      if x2 < x1 then Writeln(PL('     B£•D: x2 musi byÊ wiÍksze lub rÛwne x1'));
      Writeln;
UNTIL x2 >= x1;


wielkosc_kroku := (x2 - x1)/(ilosc_punktow - 1);

krok := x1;

for i := 1 to ilosc_punktow do
begin
     tablica[i][1] := krok;
     tablica[i][2] := fx(krok);
     krok := krok + wielkosc_kroku;
end;

ClrScr;

strona := 1;
Writeln(PL('  IloúÊ krokÛw: '),ilosc_punktow,PL('    Przedzia≥: <'),x1:5:2,'; ',x2:5:2,'>',PL('    WielkoúÊ kroku: '),wielkosc_kroku:7:3);
x:=0; REPEAT Write(chr(196)); x:= x+1; UNTIL x=80; Writeln('Strona: ',strona);

Writeln('         ',chr(218),'------',chr(194),'--------------------------',chr(194),'--------------------------',chr(191));
Writeln('         ',chr(179),' krok ',chr(179),PL('                WartoúÊ x '),chr(179),PL('             WartoúÊ f(x) '),chr(179));
Writeln('         ',chr(195),'------',chr(197),'--------------------------',chr(197),'--------------------------',chr(180));

for i := 1 to ilosc_punktow do
begin
          Writeln('         ',chr(179),' ',i:4,' ',chr(179),'                ',tablica[i][1]:9:4,' ',chr(179),'             ',tablica[i][2]:12:5,' ',chr(179));

          if (i = 16) or (i = 32) or (i = 48) or (i = 64) or (i = 80) or (i = 96) then
          begin
               Writeln('         ',chr(192),'------',chr(193),'--------------------------',chr(193),'--------------------------',chr(217));
               Writeln;
               Write(PL('Naciúnij klawisz Enter, aby kontynuowaÊ...'));
               strona:=strona+1;
               Readln;
               ClrScr;
               Writeln(PL('  IloúÊ krokÛw: '),ilosc_punktow,PL('    Przedzia≥: <'),x1:5:2,'; ',x2:5:2,'>',PL('    WielkoúÊ kroku: '),wielkosc_kroku:7:3);
               x:=0; REPEAT Write(chr(196)); x:=x+1; UNTIL x=80; Writeln('Strona: ',strona);
               Writeln('         ',chr(218),'------',chr(194),'--------------------------',chr(194),'--------------------------',chr(191));
               Writeln('         ',chr(179),' krok ',chr(179),PL('                WartoúÊ x '),chr(179),PL('             WartoúÊ f(x) '),chr(179));
               Writeln('         ',chr(195),'------',chr(197),'--------------------------',chr(197),'--------------------------',chr(180));
          end;
end;

Writeln('         ',chr(192),'------',chr(193),'--------------------------',chr(193),'--------------------------',chr(217));
Writeln; Writeln('Koniec.');

Readln;
end.
