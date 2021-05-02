% ws6_1
syms t

laplace((3*(t^2)) - (4*t)+ 5)
laplace((cos(t)^2) + (2* exp(-3*t)) - 7)
laplace(exp(3*t) * cosh(2*t))
laplace(sinh(t) * cos(3*t))
laplace(((t + 1)^2) * exp(3 * t))


% ws6_2
syms s

ilaplace((-s-10)/((s^2) -s-2))
ilaplace((s-2)/(s^2)-16)
ilaplace(3/((s^2) + (6*s) + 18))
ilaplace(((s^2) + (6*s) - 18)/((s^5)-(3*(s^4))))
ilaplace(4/((s^2) - (2*s) - 3))

% ws6_3

syms t
subplot(5, 2, 1)
fplot(t*cos(2*t))
subplot(5, 2, 2)
fplot(laplace(t*cos(2*t)))

subplot(5, 2, 3)
fplot((t*sin(3*t)) - 2)
subplot(5, 2, 4)
fplot(laplace((t*sin(3*t)) - 2))

subplot(5, 2, 5)
fplot(sin(2*t) - (2 * t * cos(2*t)))
subplot(5, 2, 6)
fplot(laplace(sin(2*t) - (2 * t * cos(2*t))))

subplot(5, 2, 7)
fplot(sin(3*t) + (3 * t * cos(3*t)))
subplot(5, 2, 8)
fplot(laplace(sin(3*t) + (3 * t * cos(3*t))))

subplot(5, 2, 9)
fplot(t * exp(-2 * t) * cos(3 * t))
subplot(5, 2, 10)
fplot(laplace(t * exp(-2 * t) * cos(3 * t)))

% ws6_4
syms t
subplot(6, 2, 1)
fplot((s^2)/((s-1)^2))
subplot(6, 2, 2)
fplot(ilaplace((s^2)/((s-1)^2)))

subplot(6, 2, 3)
fplot(s/(((s^2)-9)^2))
subplot(6, 2, 4)
fplot(ilaplace(s/(((s^2)-9)^2)))

subplot(6, 2, 5)
fplot((2*s)/(((s^2)-s-2)^2))
subplot(6, 2, 6)
fplot(ilaplace((2*s)/(((s^2)-s-2)^2)))


subplot(6, 2, 7)
fplot(s/(((s^2)+9)^2))
subplot(6, 2, 8)
fplot(ilaplace(s/(((s^2)+9)^2)))

subplot(6, 2, 9)
fplot((s^2)/(((s^2)+16)^2))
subplot(6, 2, 10)
fplot(ilaplace((s^2)/(((s^2)+16)^2)))

subplot(6, 2, 11)
fplot((4)/(((s^2)+25)^2))
subplot(6, 2, 12)
fplot(ilaplace((4)/(((s^2)+25)^2)))

% ws6_5

syms x
subplot(6, 2, 1);
fplot((3 * heaviside(x))+(heaviside(x-2) * (-3+5)))
subplot(6, 2, 2);
fplot(laplace((3 * heaviside(x))+(heaviside(x-2) * (-3+5))))

subplot(6, 2, 3);
fplot((2 * heaviside(x))+(heaviside(x-2) * (-2-1)) + (heaviside(x-3) * (1)))
subplot(6, 2, 4);
fplot(laplace((2 * heaviside(x))+(heaviside(x-2) * (-2-1)) + (heaviside(x-3) * (1))))

subplot(6, 2, 5)
fplot((15*x * heaviside(x))+(heaviside(x-3) * (-15*x)))
subplot(6, 2, 6)
fplot(laplace((15*x * heaviside(x))+(heaviside(x-3) * (-15*x))))

subplot(6, 2, 7)
fplot((heaviside(x-(2*pi)) * (sin(x))), [0 10*pi])
subplot(6, 2, 8)
fplot(laplace((heaviside(x-(2*pi)) * (sin(x))), [0 10*pi]))

subplot(6, 2, 9)
fplot(((x^2) * heaviside(x))+(heaviside(x-3) * (-1 * (x^2))))
subplot(6, 2, 10)
fplot(laplace(((x^2) * heaviside(x))+(heaviside(x-3) * (-1 * (x^2)))))

subplot(6, 2, 11)
fplot((2 + ((x-3) * heaviside(x-4))+(heaviside(x-6) * (-1 * (x-1)))), [0 10])
subplot(6, 2, 12)
fplot(laplace(2 + ((x-3) * heaviside(x-4))+(heaviside(x-6) * (-1 * (x-1)))), [0 10])

% ws6_6
t = linspace(-5, 5);

subplot(5, 1, 1)
plot(t, conv(1, 1))

subplot(5, 1, 2)
plot(t, conv(1, sin(2*t)))

subplot(5, 1, 3)
convolution = conv(exp(t), exp(-t));
plot(t, convolution(1:100))

subplot(5, 1, 4)
convolution = conv(exp(t), t);
plot(t, convolution(1:100))

subplot(5, 1, 5)
convolution = conv(cos(2*t), sin(3 * t));
plot(t, convolution(1:100))