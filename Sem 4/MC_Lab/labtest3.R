#Q2
library(lpSolve)
f.obj <- c(0.05,0.03,0.02)
f.con <- matrix(c(1, 1, 1,
                  1, 0, 0,
                  0, 1, 0,
                  0, 0, 1), nrow=4, byrow=TRUE)

f.dir <- c("=","<=", "<=", "<=")

f.rhs <- c(100, 40, 32, 36)

lp1 <- lp("min", f.obj, f.con, f.dir, f.rhs)

sol <- lp1$solution

z <- lp1$objval

#Q3
dcons <- lp("min", f.obj, f.con, f.dir, f.rhs, compute.sens=TRUE)$duals

cat("Number of scripts Evaluator 1 evaluate : ", sol[1], "\n")
cat("Number of scripts Evaluator 2 evaluate : ", sol[2], "\n")
cat("Number of scripts Evaluator 3 evaluate : ", sol[3], "\n")

cat("Minimized correction error : ", z)
cat("Dual price for constraint 1 : ", dcons[1], "\n")
cat("Dual price for constraint 2 : ", dcons[2], "\n")
cat("Dual price for constraint 3 : ", dcons[3], "\n")
cat("Dual price for constraint 4 : ", dcons[4], "\n")
