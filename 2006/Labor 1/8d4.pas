program Zad_dod_8_4;
   uses Crt;


      {funkcje pomocnicze}


function Welcome(s : string) : string;
var w : integer;
begin
   ClrScr;
   Writeln;
   w := 0; Write(' ',chr(201)); repeat Write(chr(205)); w:=w+1; until w=26; Writeln(chr(187));
   Writeln(' ',chr(186),'                          ',chr(186));
   Writeln(' ',chr(186),'  Realizacja zadania ', s ,'  ',chr(186));
   Writeln(' ',chr(186),'                          ',chr(186));
   w := 0; Write(' ',chr(200)); repeat Write(chr(205)); w:=w+1; until w=6;
   Write(' Daniel Kuruc ');
   w := 0; repeat Write(chr(205)); w:=w+1; until w=6; Writeln(chr(188));
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
         '¹' : c := #165;
         'æ' : c := #134;
         'ê' : c := #169;
         '³' : c := #136;
         'ñ' : c := #228;
         'ó' : c := #162;
         'œ' : c := #152;
         '¿' : c := #190;
         'Ÿ' : c := #171;
         '¥' : c := #164;
         'Æ' : c := #143;
         'Ê' : c := #168;
         '£' : c := #157;
         'Ñ' : c := #227;
         'Ó' : c := #224;
         'Œ' : c := #151;
         '¯' : c := #189;
         '' : c := #141;
      else
         c := s[i];
   end;
   s[i] := c;
end;
Result := s;
end;


      {g³ówna czêœæ programu}


   var liczba, i, dodatnie, modul: integer;
   srednia: real;

begin

     Welcome('8d4');

     i := 1;
     dodatnie := 0;
     modul := 0;

     Writeln(PL('   Program podaje œredni¹ dodatnich liczb ci¹gu'));
     Writeln(PL('   i wyœwiela ile z nich ma modu³ mniejszy od 100.'));
     Writeln(PL('   (Wpisanie zera koñczy dzia³anie programu)')); Writeln;

REPEAT
    Write('Podaj ', i ,PL(' wyraz ci¹gu: '));
    Readln(liczba);

    if liczba > 0 then
    begin
       srednia := srednia + liczba;
       dodatnie := dodatnie + 1;
    end;

    if (abs(liczba) < 100) and (liczba <> 0) then modul := modul +1;

    i := i + 1;
UNTIL liczba = 0;

if dodatnie <> 0 then srednia := srednia/dodatnie;

Writeln;
Writeln('------------------------------------------------------------------------');
Writeln(PL(' Ci¹g zawiera '), modul ,PL(' liczb, których wartoœæ bezwzglêdna jest mniejsza od 100'));
Writeln(PL(' Œrednia wszystkich dodatnich liczb wynosi: '), srednia:6:6);
Writeln('------------------------------------------------------------------------');
Readln;
end.
