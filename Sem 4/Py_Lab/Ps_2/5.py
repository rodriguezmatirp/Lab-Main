#Normalized against the sum 
def normalized_num(num_list):
    return [x/sum(num_list) for x in num_list]

print(normalized_num([0.7,1.4,0.7]))