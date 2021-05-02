library(lpSolve)

cost.mat<-matrix(c(17, 25, 31,
                   10, 25, 16,
                   12, 14, 11),nrow = 3 )

lpassign <- lp.assign(cost.mat, direction = "min")
lpassign$solution
