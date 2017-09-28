program zad_11_3v2;
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


   var y, lp, a, b, i: integer;
       strona, p, np : integer;
       liczba: array[1..200,1..2] of real;


procedure stronicowanie;
begin
     if (lp mod 16 = 0) and (lp <> b-1)then
     begin
          Writeln('                  ',chr(192),'------',chr(193),'------------',chr(193),'--------------------',chr(217));
          Writeln;
          Write(PL('Naciúnij klawisz Enter, aby kontynuowaÊ...'));
          Readln;
          ClrScr;

          strona:=strona+1;
          Writeln(PL(' Przedzia≥: <'),a:0,'; ',b:0,'>  ',PL('IloúÊ elementÛw: '),(b-a+1),' (',p:0,' parzystych i ',np:0,' nieparzystych)'); y:=0; REPEAT Write(chr(196)); y:=y+1; UNTIL y=80; Writeln('Strona: ',strona);

          Writeln('                  ',chr(218),'------',chr(194),'------------',chr(194),'--------------------',chr(191));
          Writeln('                  ',chr(179),'   lp ',chr(179),'     liczba ',chr(179),PL('            WartoúÊ '),chr(179));
          Writeln('                  ',chr(195),'------',chr(197),'------------',chr(197),'--------------------',chr(180));
      end;
end;

{funkcja obliczajπca wartoúÊ wyraøenia}
function Wn(n: integer): real;
begin

     if odd(n) then
        begin
          Wn := (n-5)*n;
          np := np + 1;
        end
     else
        begin
          Wn := n div 2 + sqr(n);
          p := p + 1;
        end;

Result := Wn;
end;


begin

     Welcome('11.3');

REPEAT
      Writeln(PL(' Podaj przedzia≥ liczb naturalnych <a; b>:'));
      Write('  a: '); Readln(a);
      Write('  b: '); Readln(b);
      if (a > 200) or (b > 200) then
         begin
           Writeln(PL('    B£•D: Liczby nie mogπ byÊ wiÍksze niø 200!'));
           Writeln
         end
      else
         if  (a <= 0) or (b <= 0) or (a > b) then
         begin
              Writeln(PL('    B£•D: Liczby muszπ byÊ wiÍksze od zera oraz b >= a!'));
              Writeln
         end;

UNTIL (a > 0) and (b > 0) and (a <= b) and (a <= 200) and (b <= 200);

for i := a to b do
begin
     liczba[i,1] := i;
     liczba[i,2] := Wn(i);
end;

ClrScr;

strona := 1;
Writeln(PL(' Przedzia≥: <'),a:0,'; ',b:0,'>  ',PL('IloúÊ elementÛw: '),(b-a+1),' (',p:0,' parzystych i ',np:0,' nieparzystych)'); y:=0; REPEAT Write(chr(196)); y:=y+1; UNTIL y=80; Writeln('Strona: ',strona);

Writeln('                  ',chr(218),'------',chr(194),'------------',chr(194),'--------------------',chr(191));
Writeln('                  ',chr(179),'   lp ',chr(179),'     liczba ',chr(179),PL('            WartoúÊ '),chr(179));
Writeln('                  ',chr(195),'------',chr(197),'------------',chr(197),'--------------------',chr(180));

lp := 0;
for i := a to b do
begin
     lp := lp + 1;
     Writeln('                  ',chr(179),'  ',lp:3,' ',chr(179),'     ',liczba[i,1]:6:0,' ',chr(179),'         ',liczba[i,2]:10:0,' ',chr(179));
     stronicowanie;
end;

Writeln('                  ',chr(192),'------',chr(193),'------------',chr(193),'--------------------',chr(217));
GotoXY(1,25); Write('Koniec.');

Readln;
end.
