program Zad_dod_8_1;
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
         '�' : c := #165;
         '�' : c := #134;
         '�' : c := #169;
         '�' : c := #136;
         '�' : c := #228;
         '�' : c := #162;
         '�' : c := #152;
         '�' : c := #190;
         '�' : c := #171;
         '�' : c := #164;
         '�' : c := #143;
         '�' : c := #168;
         '�' : c := #157;
         '�' : c := #227;
         '�' : c := #224;
         '�' : c := #151;
         '�' : c := #189;
         '�' : c := #141;
      else
         c := s[i];
   end;
   s[i] := c;
end;
Result := s;
end;


      {g��wna cz�� programu}


   var pierwiastek: real;
       liczba: integer;

begin

   Welcome('8d1');

   Writeln(PL('   Program oblicza warto�� pierwiastka kwadratowego podanej liczby.')); Writeln;

REPEAT
      Write(PL('Podaj liczb�: '));
      readln(liczba);
      if (liczba < 0) then Writeln(PL('   Liczba musi by� wi�ksza lub r�wna zero!'))
UNTIL liczba >= 0;

pierwiastek := 1;

REPEAT
      pierwiastek := 1/2 * (pierwiastek + (liczba/pierwiastek))
UNTIL abs( (sqr(pierwiastek) - liczba)/liczba ) < 0.001;

Writeln;
Writeln('---------------------------------------------------');
Writeln(PL(' Pierwiastek wynosi w przybli�eniu: '), pierwiastek:5:10);
Writeln(' Pierwiastek z funkcji sqrt wynosi: ', sqrt(liczba):5:10);
Writeln('---------------------------------------------------');
Readln;
end.
