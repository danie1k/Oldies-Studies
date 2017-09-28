program zad_11_2;
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


   var y, strona, lp, i, k, l: integer;
       x: array[1..40] of real;
       suma: real;

procedure stronicowanie;
begin
     if (lp mod 16 = 0) and (lp <> l-1)then
     begin
          Writeln('             ',chr(192),'----',chr(193),'--------',chr(193),'------------------------------',chr(217));
          Writeln;
          Write(PL('Naciúnij klawisz Enter, aby kontynuowaÊ...'));
          Readln;
          ClrScr;

          strona:=strona+1;
          Writeln('Poodpunkt b)        ',PL('Przedzia≥: <'),k:0,'; ',l:0,'>        ',PL('Suma wynosi: '),suma:0:0); y:=0; REPEAT Write(chr(196)); y:=y+1; UNTIL y=80; Writeln('Strona: ',strona);

          Writeln('             ',chr(218),'----',chr(194),'--------',chr(194),'------------------------------',chr(191));
          Writeln('             ',chr(179),' lp ',chr(179),' liczba ',chr(179),PL('                      WartoúÊ '),chr(179));
          Writeln('             ',chr(195),'----',chr(197),'--------',chr(197),'------------------------------',chr(180));
      end;
end;

begin

     Welcome('11.2');

REPEAT
      Writeln(PL('Podaj przedzia≥ <k; l>:'));
      Write('  k: '); Readln(k);
      Write('  l: '); Readln(l);
      if  (k > l) or (l > 40) or (k < 0) or (l < 0)  then
      begin
           Writeln(PL('    B£•D: Liczby muszπ spe≥niaÊ zaleønoúÊ: k <= l <= 40'));
           Writeln
      end;
UNTIL (k <= l) and (l <= 40) and (k > 0) and (l > 0);


x[1] := 2;
x[2] := 5;

for i := 3 to l do
begin
      x[i] := (2*x[i-2] + x[i-1]);
end;

if k < 3 then
begin
     for i := k to 2 do
     begin
          suma := suma + x[i];
     end;
end;

for i := 3 to l do
begin
     suma := suma + x[i];
end;

ClrScr;


Writeln('Poodpunkt a)'); y:=0; REPEAT Write(chr(196)); y:=y+1; UNTIL y=80; Writeln;
Writeln(PL('  Suma wszystkich elementÛw z przedzia≥u <'),k:0,'; ',l:0,'> wynosi: ',suma:0:0);

GotoXY(1,25);
Write(PL('Naciúnij klawisz Enter, aby kontynuowaÊ...'));

Readln;
ClrScr;

strona := 1;
Writeln('Poodpunkt b)        ',PL('Przedzia≥: <'),k:0,'; ',l:0,'>        ',PL('Suma wynosi: '),suma:0:0); y:=0; REPEAT Write(chr(196)); y:=y+1; UNTIL y=80; Writeln('Strona: ',strona);

Writeln('             ',chr(218),'----',chr(194),'--------',chr(194),'------------------------------',chr(191));
Writeln('             ',chr(179),' lp ',chr(179),' liczba ',chr(179),PL('                      WartoúÊ '),chr(179));
Writeln('             ',chr(195),'----',chr(197),'--------',chr(197),'------------------------------',chr(180));

lp := 0;
for i := k to l do
begin
     lp := lp + 1;
     Writeln('             ',chr(179),' ',lp:2,' ',chr(179),' ',i:6,' ',chr(179),' ',x[i]:28:0,' ',chr(179));
     stronicowanie;
end;

Writeln('             ',chr(192),'----',chr(193),'--------',chr(193),'------------------------------',chr(217));
GotoXY(1,25); Write('Koniec.');

Readln;
end.
