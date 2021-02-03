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
function Y = F(X):
Y =  3.5^(-0.5*X)*cos(6*X)
end

plot(X,Y)