library(lpSolve)
f.obj <- c(2,3)
f.con <- matrix(c(2, 2,
                  3, 6), nrow=2, byrow=TRUE)

f.dir <- c("<=", "<=")

f.rhs <- c(8,18)

lp("max", f.obj, f.con, f.dir, f.rhs)

lp1 <- lp("max", f.obj, f.con, f.dir, f.rhs)
lp1$solution
z <- lp1$objval

# Q1

dcons <- lp("max", f.obj, f.con, f.dir, f.rhs, compute.sens=TRUE)$duals
cat("Dual prices : ",dcons[1], dcons[2])

dfrom <- lp("max", f.obj, f.con, f.dir, f.rhs, compute.sens=TRUE)$duals.from
dto <- lp("max", f.obj, f.con, f.dir, f.rhs, compute.sens=TRUE)$duals.to
cat("Feasibility region for M1 : ", dfrom[1], " to ", dto[1])
cat("Feasibility region for M2 : ", dfrom[2], " to ", dto[2])

# Q2
if ((f.rhs[1]+4)>=dfrom[1]&&(f.rhs[1]+4)<=dto[1]){
  if(4*dcons[1]>4*0.3){
    print("Purchase is recommended")
  }else{
    print("Purchase is not recommended")
  }
}else{
  print("purchase is not recommended")
}

# Q3
max_expense_M2 =dcons[2]
cat("Maximum expense can be ", max_expense_M2, " for M2")

# Q4
if((f.rhs[2]+5)>=dfrom[2]&&(f.rhs[2]+5)<=dto[2]){
  increase = dcons[2]*5
  cat("Optimum revenue after increasing 5 units of M2 : ", increase+z)
}else{
  print("Increase is not possible")
}