library(lpSolve)

costs <- matrix(c(5, 2,
                  7, 3,
                  6, 5), nrow = 2)

row.signs <- rep("<=", 2)
row.rhs <- c(60, 40)
col.signs <- rep(">=", 3)
col.rhs <- c(50, 30, 20)

lptrans <- lp.transport(costs, "min", row.signs, row.rhs, col.signs, col.rhs)

lptrans$solution