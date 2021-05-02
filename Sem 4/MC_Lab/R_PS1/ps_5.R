library(lpSolve)
c1 <- (5 + 0.03*40*3) * 8
c2 <- (4 + 0.05*30*3) * 8
f.obj <- c(c1,c2)
f.con <- matrix(c(40*8, 30*8,
                  1, 0,
                  0, 1), nrow=3, byrow=TRUE)
f.dir <- c(">=", "<=", "<=")

f.rhs <- c(2000,9,11)

lp("min", f.obj, f.con, f.dir, f.rhs)

lp1 <- lp("min", f.obj, f.con, f.dir, f.rhs)
lp1$solution