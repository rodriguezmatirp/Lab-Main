'''
Sudoku Solver

Input  - SDM format
Output - String
'''

#Finds 0 and returns the position
def findUnfilledPos(sudoku):
    for x in range(9):
        for y in range(9):
            if sudoku[x][y] == 0:
                return x,y
    return -1,-1

#Returns a list with possible Values that a position can take
def possibleValues(sudoku,x,y):
    negletedValues = set()
    for i in range(9):
        if sudoku[x][i] != 0:
            negletedValues.add(sudoku[x][i])
        if sudoku[i][y] != 0:
            negletedValues.add(sudoku[i][y])
    x1 = 3*(x//3)
    y1 = 3*(y//3)
    for i in range(3):
        for j in range(3):
            if sudoku[i+x1][j+y1] != 0:
                negletedValues.add(sudoku[i+x1][j+y1])
    possibleList = list(set(range(1,10)).difference(negletedValues))
    return possibleList

#Recursive function that substitutes the possible values one by one and returns boolean value
def solveSudoku(sudoku):
    x,y = findUnfilledPos(sudoku)
    if x == -1 and y == -1:
        return True
    
    possibleList = possibleValues(sudoku,x,y)
    for i in possibleList:
        sudoku[x][y] = i
        if solveSudoku(sudoku):
            return True
        sudoku[x][y] = 0
    return False        

#Prints the passed board in sudoku format
def printSudoku(type,board):
    print(type)
    for x in range(9):
        for y in range(9):
            print(board[x][y], end=' ')
            if y == 2 or y == 5:
                print(end=' ')
        print()
        if x == 2 or x == 5:
            print()
    print()

if __name__ == '__main__':
    sdm_string = input('Enter the input in SDM format : ')
    sudoku = []
    
    #Converts string list to int list 
    for x in range(9):
        sudoku.append(list(map(int,sdm_string[9*x:9*x + 9])))
    printSudoku("Input",sudoku)
    
    if solveSudoku(sudoku):
        printSudoku("Solution",sudoku)
    else:
        print('Unsolvable')
