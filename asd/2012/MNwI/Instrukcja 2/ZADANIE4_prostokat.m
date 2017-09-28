function wynik=ZADANIE4_prostokat(F, a, b, n)
h = (b - a)/n;
suma = 0;

for i = 1:n
    suma = suma + F(a + (i - 0.5)*h);  %feval(F, a+(i-0.5)*h)feval(F, a+(i-0.5)*h)
end

wynik = suma*h;
