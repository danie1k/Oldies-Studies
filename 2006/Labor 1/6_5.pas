program Zad_6_5;
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


   var a, b, c, alpha, beta : real;

function arcsin(x : real) : real;
begin
   if x < 0 then
      arcsin := -arcsin(-x)
   else
      if x = 1 then
         arcsin := pi / 2
      else
         arcsin := arctan(x / sqrt(1 - x * x))
end;

begin

   Welcome('6.5');

   REPEAT
      Write(PL('Podaj d�ugo�� boku a: ')); Readln(a);
      if a <= 0 then
      begin
         Writeln(PL('  B��D: Poda�e� niew�a�ciw� d�ugo�� boku a.'));
         Writeln;
      end;
   UNTIL a > 0;

   REPEAT
      Write(PL('Podaj d�ugo�� boku b: ')); Readln(b);
      if b <= 0 then
      begin
         Writeln(PL('  B��D: Poda�e� niew�a�ciw� d�ugo�� boku b.'));
         Writeln;
      end;
   UNTIL b > 0;

   c := sqrt(a*a+b*b);
   alpha := arcsin((a/c));
   beta := arcsin((b/c));

   Writeln;
   Writeln('---------------------------------------------------');
   Writeln(PL(' D�ugo�� boku c wynosi: '), c:6:2);
   Writeln(PL(' K�t '), chr(224) ,' wynosi:     ', alpha*(180/pi):3:1 , chr(248) ,' (',  alpha:4:2 ,' rad)');
   Writeln(PL(' K�t '), chr(225) ,' wynosi:     ', beta*(180/pi):3:1 , chr(248) ,' (',  beta:4:2 ,' rad)');
   Writeln('---------------------------------------------------');

   Readln;
end.
