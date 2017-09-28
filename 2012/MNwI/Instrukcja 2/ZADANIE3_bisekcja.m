function ZADANIE3_bisekcja(f, a, b, eps)
ya = f(a);
yb = f(b);

if ya*yb > 0
    disp('Blad danych wejsciowych')
    return
else
    while (b-a) > eps
        x = (a+b)/2;
        y = f(x);
        if y == 0
            disp(['szukanym pierwiastkiem jest x=',num2str(x)]);
        else
            if ya*y>0
                a=x;
                ya=y;
            else
                b=x; 
                yb=y;
            end
        end
    end
end
disp(['Szukanym pierwiastkiem jest x = ',num2str(x)]);
disp(['w przedziale  <',num2str(a),',',num2str(b),'>']);
                