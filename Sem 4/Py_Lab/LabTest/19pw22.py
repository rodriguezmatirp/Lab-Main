'''
Author : R Tarun Pritam - 19PW22
Objective : To find the percentage of internet/non_internet Users in given years/regions.
            To find the mean and standard deviation for the input data set.
Given : Years, Number of Internet Users, World Population, Region.
Input Format : YEAR INTERNET_USERS WORLD_POPULATION REGION
'''

def region_wise(dataset):
    regions = {}
    for x in dataset:
        if x[3] not in regions:
            regions[x[3]] = [[x[1], x[2]]]
        else:
            regions[x[3]].append([x[1], x[2]])
    for x in regions.keys():
        internet_users =0
        total_population = 0
        for region in regions[x]:
            internet_users += int(region[0])
            total_population += int(region[1])
        percentage_internet_users = float(internet_users/total_population)*100
        regions[x] = [percentage_internet_users , 100 - percentage_internet_users]
    return regions


def year_wise(dataset):
    years = []
    years_dict = {}
    for i in range(len(dataset)):
        if dataset[i][0] not in years:
            years.append(dataset[i][0])
    total_population = 0
    for year in years:
        sum_of_internet_users = 0
        for i in range(len(dataset)):
            if year == dataset[i][0]:
                sum_of_internet_users += int(dataset[i][1])
                total_population = int(dataset[i][2])
        year_percentage = (sum_of_internet_users/total_population)*100
        years_dict[year] = [year_percentage,100 - year_percentage]
    return years_dict


def mean(dataset):
    internet_users = 0
    for x in dataset:
        internet_users += int(x[1])
    return (internet_users/len(dataset))

def standard_deviation(data):
    mean_data = mean(data)
    phaseA = 0
    for x in data:
        phaseA += (float(x[1]) - mean_data) ** 2
    return (phaseA/len(data) ** 0.5)

if __name__ == '__main__':
    dataset = []
    input_count = int(input("Enter the number of inputs: "))
    count = 0
    print('Data in [YEAR INTERNET_USERS WORLD_POPULATION REGION] format')
    while count < input_count:
        input_data = input().split()
        dataset.append(input_data)
        count += 1
    print(f'Region wise : {region_wise(dataset)}')
    print(f'Year wise : {year_wise(dataset)}')
    print(f'Mean : {mean(dataset)}')
    print(f'Standard deviation : {standard_deviation(dataset)}')
