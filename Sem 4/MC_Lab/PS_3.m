% 1
X = [1 2 3 4 5 6 7 8 9 10]
Y = [2 5 6 7 8 10 13 15 18 19]
plot(x,y)

% 2
p = plot(X, Y, ':or',...
    'LineWidth', 2,...
    'MarkerEdgeColor', 'g',...
    'MarkerFaceColor', 'y',...
    'MarkerSize', 12);

% 3
X = -2:0.01:4
fplot('(3.5^-0.5*x)*cos(6*x)',[-2,4])

%4
fplot(@(x)x^2,[1,10])
fplot(@(x)x^3,[1,10])
fplot(@(x)log(x),[1,10])
fplot(@(x)x^-1,[1,10])

%5
fplot(@(x)sin(x),[0,2*pi])
fplot(@(x)cos(x),[0,2*pi])
fplot(@(x)tan(x),[0,2*pi])

%6
fplot(@(x)(x+5)^2/(4+3*x^2),[-3,5])

%7
x = linspace(-2,4);
y = 3.*((x).^3)-26.*x+10;
fx1 = diff(y);
fx2 = diff(fx1);
dom_1 = x(1:end-1);
dom_2 = x(1:end-2);
plot(x,y,dom_1,fx1,dom_2,fx2)

%8
x = linspace(-2,4);
y = 3.*((x).^3)-26.*x+10;
fx1 = diff(y);
fx2 = diff(fx1);
dom_1 = x(1:end-1);
dom_2 = x(1:end-2);
plot(x,y)
hold on
plot(dom_1,fx1)
hold on
plot(dom_2,fx2)

%9
x1 = linspace(-2,4);
y = 3.*((x1).^3)-26.*x1+10;
fx1 = diff(y);
fx2 = diff(fx1);
x2 = x1(1:end-1);
x3 = x1(1:end-2);
x = [x1 x2 x3]
z = [y fx1 fx2]
line(x,z)

%10
x = -1:0.01:1;
y = 95000./((x).^2);

plot(x, y)
xlabel('Distance (cm)');
ylabel('Intensity (lux)');
title('Light Intensity as a Function of Distance')
axis([8 24 0 1200])
text(600, 18, 'Comparision between theory and exeriment')
legend('first_function')

%11
x = 1:0.01:10;

subplot(2, 2, 1);
plot(x, x.^2)
subplot(2, 2, 2);
plot(x, x.^3)
subplot(2, 2, 3);
plot(x, log10(x))
subplot(2, 2, 4);
plot(x, 1./x)

%12

y = @(x)(x+1)*(x-2)*(2*x-0.25) - exp(x)
subplot(2,1,1);
fplot(y,[0 3])

subplot(2,1,2);
fplot(y,[-3 6])