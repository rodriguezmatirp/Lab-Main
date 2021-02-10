def findUnfilledPos(sudoku):
    for x in range(9):
        for y in range(9):
            if sudoku[x][y] == 0:
                return x,y
    return -1,-1



if __name__ == '__main__':
    sdm_string = list(input('Enter the input in SDM format : '))
    sudoku = []
    for x in range(9):
        sudoku.append(sdm_string[int(9*x):int(9*x + 9)])
    print(sudoku)
