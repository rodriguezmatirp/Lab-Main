library(lpSolve)

costs <- matrix(c(464,513,654,867,
                  352,416,690,791,
                  995,682,388,685),nrow=3, byrow = TRUE)
row.signs <- rep("<=",3)
row.rhs <- c(75,125,100)
col.signs <- rep(">=",4)
col.rhs <- c(80,65,70,85)

lptrans <- lp.transport(costs, "min", row.signs, row.rhs, col.signs, col.rhs)
lptrans$solution