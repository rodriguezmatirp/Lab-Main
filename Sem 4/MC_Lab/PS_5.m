% ws5_1

syms x
% 1_a
diff(( ((x^2)-5) .* ((x.^3) - (2*x) + 3) ))
% 1_b
diff(sin(x) * cos(x))
% 1_c
diff(abs(x))
%1_d
diff(x* abs(x))
% 1_e
diff(((x.^0.5) + 2.*x) .* (4*(x.^2) - 1))
% 1_f
diff(((x.^2) + 1)./(5.*x-3))

% ws5_2

syms x y
z = cos(2.*x) - (x.^2) * exp(5 .* y) + 3*(y.^2);
% 2_a
diff(z, x)
% 2_b
diff(z, y)
% 2_c
diff(diff(z, x), x)
% 2_d
diff(diff(z, y), y)
% 2_e
diff(diff(z, x), y)
%2_f
diff(diff(diff(diff(z, y), y), y), y)
%2_g
diff(diff(diff(z, x), y), x)

% ws5_3

syms x
% 1_a
subs(diff(( ((x.^2)-5) .* ((x.^3) - (2.*x) + 3) )), x, 2)
% 1_b
eval(subs(diff(sin(x) * cos(x)), x, 2))
% 1_c
subs(diff(abs(x)), x, 2)
%1_d
subs(diff(x* abs(x)), x, 2)
% 1_e
eval(subs(diff(((x.^0.5) + 2.*x) .* (4*(x.^2) - 1)), x, 2))
% 1_f
subs(diff(((x.^2) + 1)./(5.*x-3)), x, 2)

% ws5_4

syms x y
z = cos(2.*x) - (x.^2) * exp(5 .* y) + 3*(y.^2);
% 2_a
eval(subs(diff(z, x), [x y], [2 3]))
% 2_b
eval(subs(diff(z, y), [x y], [2 3] ))
% 2_c
eval(subs(diff(diff(z, x), x), [x y], [2 3]))
% 2_d
eval(subs(diff(diff(z, y), y), [x y], [2 3]))
% 2_e
eval(subs(diff(diff(z, x), y), [x y], [2 3]))
%2_f
eval(subs(diff(diff(diff(diff(z, y), y), y), y), [x y], [2 3]))
%2_g
eval(subs(diff(diff(diff(z, x), y), x), [x y], [2 3]))

% ws5_5

syms x y z

% 5_a
int(sin(2*x)* cos(x))
% 5_b
int(1/((x^2) + (5*x) + 6))
% 5_c
int((9-(4*(x^2)))^0.5)
% 5_d
int(log(tan(x)), [0 pi/2])
% 5_e
eval(int(1/(1+(cot(x)^0.5)), [pi/6 pi/3]))
% 5_f
int(sin(x)* (cos(x)^4), [-1 1])
% 5_g
int(int(12 * (x^2) * (y^3), y, [-1 0]), x, [1 2])
% 5_h
int(int((x * exp(x*y)), x, [1 2] ), y, [1 3])
% 5_i
int(int(int((8 * x * y *z), x ,[0 1]), y, [0 2]), z, [0 3])
% 5_j
int(int(int((x+y), z ,[0 4-(x^2)]), x, [0 2]), y, [0 1])

%ws5_6

syms y(x)

% 6_a
dsolve(diff(y, x) == exp(3*x) + sin(x))

% 6_b
dsolve(diff(y, x, 2) == 2+x)

% 6_c
dsolve(diff(y, x, 10) == 0)

% 6_d
dsolve(diff(y, x, 3) == x^2)

% 6_e
dsolve(diff(y, x) + (cos(x)*y) == sin(x) * cos(x))


% ws5_7

syms y(x)

Dx = diff(y, x);
Dx_2 = diff(y, x, 2);

% 7_a
dsolve(diff(y, x) == 9.8 - (0.196 * y), y(0) == 48)

% 7_b
eval(dsolve(x*diff(y, x) + (2 * y) == ((x^2) - x + 1), y(1) == 0.5))

% 7_c
dsolve(x*diff(y, x) - (2 * y) == ((x^5) * sin(2*x) - (x^3) + (4 * (x^4))), y(pi) == (3/2)*(pi^4))

% 7_d
dsolve(2*diff(y, x) -  y == 4 * sin(3*x), y(0) == 1)

% 7_e
dsolve((diff(y, x, 2) - 2 * diff(y, x) - 3 * y == 0), y(0) == 0, Dx(0) == 1)

% 7_f
dsolve((diff(y, x, 2) + ((4i + 1 ) * diff(y, x)) + y == 0), y(0) == 0, Dx(0) == 0)

% 7_g
dsolve((diff(y, x, 2) + (10 * y) == 0), y(0) == pi, Dx(0) == 2)

% 7_h
dsolve(diff(y, x, 2) == 4 - sin(x) + y - (2*diff(y, x)), y(0) == 1, Dx(0) == 2)

% 7_i
dsolve(diff(y, x, 3) == y - (x * diff(y, x)) + 4 * diff(y, x, 2), y(2) == 1, Dx(2) == 2, Dx_2(2) == 3)