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
      Write(PL('Podaj d≥ugoúÊ boku a: ')); Readln(a);
      if a <= 0 then
      begin
         Writeln(PL('  B£•D: Poda≥eú niew≥aúciwπ d≥ugoúÊ boku a.'));
         Writeln;
      end;
   UNTIL a > 0;

   REPEAT
      Write(PL('Podaj d≥ugoúÊ boku b: ')); Readln(b);
      if b <= 0 then
      begin
         Writeln(PL('  B£•D: Poda≥eú niew≥aúciwπ d≥ugoúÊ boku b.'));
         Writeln;
      end;
   UNTIL b > 0;

   c := sqrt(a*a+b*b);
   alpha := arcsin((a/c));
   beta := arcsin((b/c));

   Writeln;
   Writeln('---------------------------------------------------');
   Writeln(PL(' D≥ugoúÊ boku c wynosi: '), c:6:2);
   Writeln(PL(' Kπt '), chr(224) ,' wynosi:     ', alpha*(180/pi):3:1 , chr(248) ,' (',  alpha:4:2 ,' rad)');
   Writeln(PL(' Kπt '), chr(225) ,' wynosi:     ', beta*(180/pi):3:1 , chr(248) ,' (',  beta:4:2 ,' rad)');
   Writeln('---------------------------------------------------');

   Readln;
end.
