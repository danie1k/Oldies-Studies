program Zad_7_1;
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


   var x, y : Real;

begin

   Welcome('7.1');

   REPEAT
      Write(PL('Podaj warto�� x: ')); Readln(x);
      if x = 0 then
         begin
            Writeln(PL('  B��D: x musi by� r�ny od zera.'));
            Writeln;
         end;
   UNTIL x <> 0;

   Writeln;
   Writeln('---------------------------------------------------');
   if (x >= -1) and (x < 0) then
      Writeln(PL(' Dla x z przedzia�u  <-1; 0)  f(x) = 0'))
   else if (x >= 2) and (x <= 5) then
      Writeln(PL(' Dla x z przedzia�u  <2; 5>  f(x) = 0'))
   else
   begin
      y := sqrt(x*(x+1)*(x-2)*(x-5));
      Writeln(PL(' Warto�� funkcji dla x = '), x:6:3);
      Writeln(' wynosi f(x) = ', y:8:3);
   end;
   Writeln('---------------------------------------------------');

   Readln;
end.
