% 1 a = 21.663 
((14.8)^2 + (6.5)^2)/(3.8^2) + 55/(sqrt(2)+14)

% 1 b = 27.461 ? ln?
(-3.5)^3 + e^6/log(524) + 206^(1/3)

% 2 a = 7.6412
(16.5^2)*(8.4-sqrt(70))/((4.3)^2 - 17.3)

% 2 b = 6.8450
((5.2)^3 - (6.4)^2 + 3 )/((1.6)^8 - 2) + (13.3 / 5)^1.5

% 3 a  = 50.204
15 * ((sqrt(10) + 3.7^2)/(log10(1365) + 1.9))

% 3 b = 11.0501
(2.5^3 * (16 - 216/22))/(1.7^4 + 14) + 2050^(1/4)

% 4 a = 7.9842
((2.3^2) * 1.7)/sqrt(((1-(0.8^2))^2) + (2 - sqrt(0.87))^2)

% 4 b = 80.089
2.34 + 0.5*2.7((5.9)^2 - (2.4)^2) + 9.8*log(51)

% 5 a = 2.1867
sin(7*pi/9)/(cos(5*pi/7)^2) + tan(5*pi/12)/7

% 5 b = 2.1238
tand(64)/(cosd(14)**2) - 3*sind(80)/(0.9)^(1/3) + cosd(55)/sind(11)

x=2.34
% 6 a = 73.226
2*(x)^4 - 6*(x)^3 + 14.8*(x)^2 + 9.1

% 6 b = 26.034
e^(2*x)/(sqrt(14 + x^2 - x))

t = 6.8
% 7 a = 5.5917
log(abs(t^2-t^3))

% 7 b = -4.2122
75/(2*t)*cos(0.8*t-3)

x = 8.3
y = 2.4
% 8 a = 62.690
x^2 + y^2 - x^2/y^2

% 8 b = 2.1741
sqrt(x*y) - sqrt(x+y)+((x-y)/(x-2*y))^2 - sqrt(x/y)

a=13
b=4.2
c=4*b/a
d=a*b*c/(a+b+c)
% 9 a = 43.529
a*b/(c+d) + d*a/(c*b) - (a-(b^2))*(c+d)

% 9 b = 7.8410
sqrt(a^2 + b^2)/(d-c) + log(abs(b-a + c-d))

% 10 = 0.4634
function [integral] = stat(x,a)
    integral = x/2-sin(2*a*x)/(4*a)
end
stat(3*pi/5,0.5)-stat(pi/9,0.5)

% 11 a = 42.149
a = 9
b = 3
p = 2*pi*sqrt((a^2 + b^2)/2)

% 11 b  
syms a,b
[sola,solb]= solve((2*pi)*sqrt((a^2 + b^2)/2) == 20 , 2*a == b,a,b)
b = (2-sqrt(10))/pi
a = (4-sqrt(10))/pi

% 12 a
syms x
assume(x = pi/9)
logical(sin(4*x) == 4*sin(x)*cos(x) - 8*(sin(x)^3)*cos(x))

% 12 b
syms x
assume(x == x/9)
logical(cos(2*x) == (1 - tan(x)^2)/(1 + tan(x)^2))

% 13 a = (+/-)2244^(1/2)
syms a b c
a = 16
c = 50
b = solve([c^2 == a^2 + b^2],b)

% 13 b = 18.6629
alpha = acosd(b/c)

% 14 = 2.6042
// syms A B C D d x y z
// function d = dist(a,b,c,d,x,y,z)
//     d = abs(a*x + b*y + c*z + d)/ sqrt(a^2 + b^2 + c^2)
// end
// dist(2,23,13,-24,8,3,-10)
x = 8;
y = 3;
z = -10;
A = 2;
B = 23;
C = 13;
D = -24;

(abs(A*x+B*y+C*z+D))/(sqrt((A^2)+(B^2)+(C^2)))