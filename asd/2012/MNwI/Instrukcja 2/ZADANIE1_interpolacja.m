% Interpolacja i aproksymacja

% ZADANIE 1
% Dla dowolnie wybranych danych Ÿród³owych (np. danych statystycznych.
% œrednich miesiêcznych wartoœci indeksów gie³dowych itp.) o co najmniej 20
% wartoœciach (dyskretnych) mierzonych co sta³y okres czasu. dokonaj interpolacji
% za pomoc¹ wbudowanej funkcji Matlaba interp1 (zwracaj¹cej wspó³czynniki
% wielomianu interpolacyjnego). metodami „nearest”. „linear” oraz „spline”.
% Otrzymane krzywe przedstaw na wspólnym wykresie wraz z zaznaczonymi
% danymi Ÿród³owymi.

function ZADANIE1_interpolacja()

% Indeks WIG20 za m-c maj 2012
x = 1:21;
y = [2096.35, 2072.09, 2090.74, 2055.69, 2037.18, 2035.80, 2038.14, 2099.75, 2096.35, 2060.99, 2057.12, 2119.73, 2111.15, 2137.12, 2178.77, 2187.54, 2168.49, 2168.35, 2217.40, 2210.08, 2225.96];

plot(x, y, 'r.')
title('Indeks WIG20 / maj 2012');
axis([1 21 min(y) max(y)])
xlabel('Dzieñ miesi¹ca');
ylabel('Wartoœæ na zamkniêcie sesji');
hold on; grid on;

xx=1:0.2:21;

int1 = interp1(x, y, xx, 'nearest');
plot(xx,int1,'k-');

int2 = interp1(x, y, xx, 'linear');
plot(xx,int2,'g-');

int3 = interp1(x, y, xx ,'spline');
plot(xx, int3, 'm-');

legend('Wartoœci', 'nearest', 'linear', 'spline');
