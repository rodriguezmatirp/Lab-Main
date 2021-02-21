% QN 1

function [ output_args ] = eval( input_args )
    output_args = ((input_args.^4) .* ((3.*input_args) + 5).^0.5)./((input_args.^2 + 1).^2);
end
eval(6)
eval([1 3 5 7 9 11])

% QN 2

function [ output_args ] = average( input_args )
output_args = sum(input_args)/numel(input_args);
end
function [ output_args ] = standard_deviation( input_args )
    avg = average(input_args);
    output_args = 0;
    for i = 1:numel(input_args)
       output_args = output_args + ((input_args(i)-avg)^2);
    end
    output_args = output_args/(numel(input_args));
    output_args = output_args^0.5;
end
average([80 75 91 60 79 89 65 80 95 50 81])
standard_deviation([80 75 91 60 79 89 65 80 95 50 81])

% QN 3
function [ output_args ] = ws4_3_function( input_args )
    output_args = (-0.2.*(input_args.^4)) + ((exp(-0.5.*input_args)) .* (input_args.^3)) + (7 .* (input_args.^2));
end


ws4_3_function([-2.5])
ws4_3_function([3])

x = linspace(-3, 4);
plot(x, ws4_3_function(x))

% QN 4
x = input('Co-efficients of the polynomial: ', 's');
numbers = sscanf(x, '%f');
roots(numbers)

% QN 5
num = input('Enter the number: ');

if bitand(num, 1) == 0
    display('Number - even')
else 
    display('Number - odd')
end

% QN 6
num_1 = input('Enter the number 1: ');
num_2 = input('Enter the number 2: ');
choice = input('Enter the choice: ');

switch(choice)
    case 1
       fprintf('Addition: %d\n', num_1+num_2);
    case 2
       fprintf('Subtraction: %d\n', num_1-num_2);
    case 3
       fprintf('Multiplication: %d\n', num_1*num_2);
    case 4
       fprintf('Division: %d\n', num_1/num_2);
    otherwise
        fprintf('The choice made is invalid')
end

% QN 7
num = input('Enter the number: ');

if num == 0
    display('Number - 0')
elseif num > 0  
    display('Number - positive')
else
    display('Number - negative')
end

% QN 8
temp = input('Enter the temparature: ');

if temp < 32
    display('ICE')
elseif temp < 212  
    display('WATER')
else
    display('STEAM')
end

% QN 9
num = input('Please enter the number: ');
if isprime(num) == 1
    display('The given number is Prime')
else 
    display('The given number is not Prime')
end

% QN 10
for i = 1:20
    fprintf('13 x %d = %d\n', i, i*13)
end

% QN 11
 for i = 1:4
    for j = 1:i
        fprintf('*')
    end
    fprintf('\n')
end

% QN 12
star = 1;
space = 2;
for i = 1:3
    for j = 1:space
        fprintf(' ')
    end
    for j = 1:star
        fprintf('*')
    end
    fprintf('\n')
    space = space -1;
    star = star + 2;
end

star = 3;
space = 1;

for i = 1:2
    for j = 1:space
        fprintf(' ')
    end
    for j = 1:star
        fprintf('*')
    end
    fprintf('\n')
    space = space + 1;
    star = star - 2;
end

% QN 13
function [ output_args ] = getFac( num )
    if num == 1
        output_args = 1;
    else
        output_args = num*getFac(num-1);
    end
end

num = input('Please enter the number: ');
fprintf('The factorial of the number is %d\n', getFac(num))

% QN 14
function [  ] = func( num )
    printFib([0 1], num)
end
function [  ] = printFib( sequence, num )
    if numel(sequence) ~= num
        printFib([sequence sequence(end)+sequence(end-1)], num)
    else
        sequence
    end
end

num = input('Please enter the number: ');
func(num)   

% QN 15
sum = 0;
for i = 2:20
    sum = sum + (i*i);
end
fprintf('The sum of squares from 2 to 20 is %d\n', sum)

% QN 16
sum = 0;
for i = 1:2:501
    sum = sum + (i);
end
fprintf('The sum of odd integers from 1 to 501 is %d\n', sum)

% QN 17
years = 0:30;
account_balance = [1000];
for i = 1:30
    account_balance(end+1) = account_balance(end)+ (account_balance(end)*(2/25));
end
plot(years, account_balance)

% QN 18 
years = 0:30;
account_balance = [5000];
count = 0;
while account_balance(end) < 1000000
    account_balance(end+1) = account_balance(end)+ (account_balance(end)*(9/100));
    count = count+1;
end
fprintf('Number of years it takes to reach retirement is: %d\n', count)

% QN 19
 function [ mps ] = mphToMps( mph )
    mps = mph*0.44704;
end

fprintf('55 miles per hr is %f meters per seconds \n', mphToMps(55));

% QN 20
function [ area ] = triangle( a, b, c )
semi = (a+b+c)/2;
area = ((semi)*(semi-a)*(semi-b)*(semi-c))^0.5;
end
fprintf('Area of triangle with sides 3, 8 and 10 is %f \n', triangle(3, 8, 10));
fprintf('Area of triangle with sides 7, 7 and 5 is %f \n', triangle(7, 7, 5));

%21
function [g] = fgrade(R)
    g = zeros(size(R,1),1);
    for r = size(1,R)
        assignment_marks = R(r,1:6);
        minimum = min(assignment_marks);
        assignment_marks(find(assignment_marks == minimum)) = [];
        assignment_avg = average(assignment_marks);
        midterm_marks = R(r,7:9);
        midterm_avg = average(midterm_marks);
        finalexam_marks = R(r,end);
        if midterm_avg > finalexam_marks
            g(r,1) = 0.85*midterm_avg + 0.15 *assignment_avg;
        else
            g(r,1) = 0.15*R(r, 7) + 0.15*R(r, 8) + 0.15*R(r, 9) + 0.15*midterm_avg + 0.15*assignment_avg;
        end
    end
end

R = input('Enter students mark in each row\n');
g = fgrade(R);
fprintf('Grades - \n');
g

% QN 22
i = 1;
sum = 0;
sign = 1;
while i <= 9999 
    sum = sum + sign * (i*i);
    sign = sign * -1;
    i = i + 2; 
end 

fprintf('The sum is: %d\n',sum)

% QN 23
x = input('Please enter the number: ');
for i = 0:2:x
    fprintf('square root of %d is %f\n',i, i^0.5);
end

% QN 24
for i = 1:1000;
    if isprime(i)
        fprintf('%d\n', i)
    end
end

% QN 25
sum = 0;
for i = 1:50;
    if ~isprime(i)
        sum = sum + i;
    end
end
fprintf('The sum is %d\n', sum)

%26
flag = 1
while flag
    if round(3 + 7*rand()) == 5
        flag = 0
    else
        disp(round(3+7*rand()))
    end
end

%27
i = 0;
x = [];
while i<10
    x(i+1) = 3 + 7*rand();
    i = i +1;
end
disp(x)
