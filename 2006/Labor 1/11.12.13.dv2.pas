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


   var strona, x, y, lp: integer;
       i, a, b, liczba: longint;
       liczbapierwsza: boolean;
       liczby: array[2..200,1..2] of real;

procedure stronicowanie;
begin
     if (lp mod 16 = 0) and (lp <> b)then
     begin
          Writeln('       ',chr(192),'-----',chr(193),'--------',chr(193),'-----------------',chr(193),'---------------------------',chr(217));
          Writeln;
          Write(PL('Naciúnij klawisz Enter, aby kontynuowaÊ...'));
          Readln;
          ClrScr;

          strona:=strona+1;
          Writeln('   ',PL('Przedzia≥: <'),a:0,'; ',b:0,'>'); y:=0; REPEAT Write(chr(196)); y:=y+1; UNTIL y=80; Writeln('Strona: ',strona);

          Writeln('       ',chr(218),'-----',chr(194),'--------',chr(194),'-----------------',chr(194),'---------------------------',chr(191));
          Writeln('       ',chr(179),'  lp ',chr(179),' Liczba ',chr(179),' Liczba pierwsza ',chr(179),' Liczba podzielna przez 23 ',chr(179));
          Writeln('       ',chr(195),'-----',chr(197),'--------',chr(197),'-----------------',chr(197),'---------------------------',chr(180));
      end;
end;

procedure pierwsza;
begin
     liczbapierwsza := true;
     for x:=2 to i-1 do
     begin
          if (i mod x) = 0 then {reszta z dzielenia ca≥kowitego}
             liczbapierwsza := false;
     end;
end;



begin

     Welcome('123d');

REPEAT
      Writeln(PL(' Podaj dowolnπ przedzia≥ liczb naturanlych <a; b> wiÍkszych od 1: '));
      Write('  a: '); Readln(a);
      Write('  b: '); Readln(b);
      if  (a > b) or (b > 200) or (a < 1) or (b < 1) then
      begin
           Writeln(PL('    B£•D: Liczby muszπ spe≥niaÊ zaleønoúÊ: a <= b <= 200'));
           Writeln
      end;
UNTIL (a <= b) and (b <= 200) and (a > 1) and (b > 1);

for i := a to b do
begin
     pierwsza;
     if liczbapierwsza then
          liczby[i,1] := 1
     else
          liczby[i,1] := 0;

     if (i mod 23) = 0 then
          liczby[i,2] := 1
     else
          liczby[i,2] := 0;
end;

ClrScr;

strona := 1;
Writeln('   ',PL('Przedzia≥: <'),a:0,'; ',b:0,'>'); y:=0; REPEAT Write(chr(196)); y:=y+1; UNTIL y=80; Writeln('Strona: ',strona);

Writeln('       ',chr(218),'-----',chr(194),'--------',chr(194),'-----------------',chr(194),'---------------------------',chr(191));
Writeln('       ',chr(179),'  lp ',chr(179),' Liczba ',chr(179),' Liczba pierwsza ',chr(179),' Liczba podzielna przez 23 ',chr(179));
Writeln('       ',chr(195),'-----',chr(197),'--------',chr(197),'-----------------',chr(197),'---------------------------',chr(180));

lp := 0;
for i := a to b do
begin
     lp := lp + 1;

     Write('       ',chr(179),' ',lp:3,' ',chr(179),' ',i:6,' ',chr(179),' ');

     if liczby[i,1] = 1 then
     begin
          textcolor(2);
          Write('            TAK');
          textcolor(7);
     end
     else
     begin
          textcolor(8);
          Write('              .');
          textcolor(7);
     end;

     Write(' ',chr(179),' ');

     if liczby[i,2] = 1 then
     begin
          textcolor(14);
          Write('                      TAK');
          textcolor(7);
     end
     else
     begin
          textcolor(8);
          Write('                        .');
          textcolor(7);
     end;

     Writeln(' ',chr(179));
     stronicowanie;
end;

Writeln('       ',chr(192),'-----',chr(193),'--------',chr(193),'-----------------',chr(193),'---------------------------',chr(217));
GotoXY(1,25); Write('Koniec.');

Readln;
end.
