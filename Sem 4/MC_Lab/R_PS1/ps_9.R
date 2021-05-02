library(lpSolve)
f.obj <- c(0.07,0.11,0.19,0.15)
f.con <- matrix(c(1,1, 1, 1,
                  1, 0, 0, 0,
                  0, 1, 0, 0,
                  0, 0, 1, 0,
                  0, 0, 0, 1,
                  0.55, 0.55, -0.45, -0.45,
                  -0.85, 0.15, 0.15, 0.15), nrow=7, byrow=TRUE)
f.dir <- c("<=", "<=","<=", "<=", "<=", "<=", "<=")

f.rhs <- c(5000000,1000000,2500000, 1500000, 1800000,0,0)

lp("max", f.obj, f.con, f.dir, f.rhs)

lp1 <- lp("max", f.obj, f.con, f.dir, f.rhs)
lp1$solution