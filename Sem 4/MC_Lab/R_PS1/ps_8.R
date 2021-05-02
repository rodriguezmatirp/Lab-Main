library(lpSolve)
f.obj <- c(5,4,3,2,1)
f.con <- matrix(c(1, 1, 1, 1, 1,
                  1, 0, 0, 0, 0,
                  1, 1, 0, 0, 0,
                  1, -1/3, -1/3, 0, 0,
                  1, 1, -1/3, -1/3, 0,
                  1, 1, 1, -1/3, -1/3), nrow=6, byrow=TRUE)
f.dir <- c("=", "<=","<=", ">=", ">=", ">=")

f.rhs <- c(150, 60, 6, 5, 60, 100)

lp("min", f.obj, f.con, f.dir, f.rhs)

lp1 <- lp("min", f.obj, f.con, f.dir, f.rhs)
lp1$solution