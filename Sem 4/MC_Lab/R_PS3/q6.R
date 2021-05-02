library(lpSolve)

cost.mat<-matrix(c(80, 55, 45, 45,
                   58, 35, 70, 50, 
                   70, 50, 80, 65,
                   90, 70, 40, 80),nrow = 4 )

lpassign <- lp.assign(cost.mat, direction = "min")
lpassign$solution 