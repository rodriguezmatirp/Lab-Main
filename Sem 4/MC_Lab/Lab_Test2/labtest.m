% A
syms t;

fx = 1*heaviside(t) - 1*heaviside(t-2) + (t-2)*heaviside(t-2);
subplot(2,1,1);
fplot(fx,[0 5]);

laplace_fx = laplace(fx);
subplot(2,1,2);
fplot(laplace_fx);

% B1) ans = 9
syms x y z;
int(int(int(2*x,z,[0 6-2*x-3*y]),y,[0 (-(2/3)*x + 2)]),x,[0 3]);

% B2) ans = 49/5
syms x y z;
int(int(int(1,x,[0 (8-y-z)]),z,[0.75*y 1.5*y^0.5]),y,[0 4]);