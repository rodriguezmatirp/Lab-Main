library(lpSolve)

cost.mat<-matrix(c(10, 14, 16, 13,
                   12, 13, 15, 12, 
                   9, 12, 12, 11,
                   14, 16, 18, 16),nrow = 4 )

lpassign <- lp.assign(cost.mat, direction = "min")
lpassign$solution 