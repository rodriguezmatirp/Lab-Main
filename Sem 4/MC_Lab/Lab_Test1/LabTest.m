% 1 A i
r =2;
h =10;
output = sarea(r,h)
fprintf('surface area - %f\n ',output)

% 1 A ii
[r,h] = heirad('2*h -20*r ==0',100)
fprintf('radius - %f\n height - %f\n',r(2),h(2))

% 1 B
x = linspace(-4, 4);
y = (((x .^ 2)+1)./(5 .* x - 3));

p = plot(x, y, ':or', ...
    'LineWidth', 3,...
    'MarkerEdgeColor', 'y',...
    'MarkerFaceColor', 'g',...
    'MarkerSize', 14);

% 2 A
distribution = input('Enter the distribution - ', 's');

if strcmp(lower(distribution),'binomial')
    n = input('Enter n -  ');
    p = input('Enter p - ');
    fprintf('Mean: %f\n', n * p;
    fprintf('Variance: %f\n', (n * p)) * (1 - p);

elseif strcmp(lower(distribution),'geometric')
    p = input('Enter p -  ');
    fprintf('Mean: %f\n', p^-1);
    fprintf('Variance: %f\n',  (1 - p)/ (p^2));

elseif strcmp(lower(distribution),'poisson')
    lambda = input('Enter lambda - ');
    fprintf('Mean: %f\n', lambda);
    fprintf('Variance: %f\n', lambda);
else
    fprintf('Illegal distribution input.\n')
    
end

% 2 B
for i = 1:1000
    if mod(i,2) == 0
        if mod(i,5) == 0 && mod(i,7) == 0
            if mod(i,3) ~= 0   
                fprintf('%d\n', i)
            end
        end
    end
end