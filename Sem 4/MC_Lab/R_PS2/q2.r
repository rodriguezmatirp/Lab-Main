library(lpSolve)
f.obj <- c(8,5)
f.con <- matrix(c(2, 1,
                  1, 0,
                  0, 1), nrow=3, byrow=TRUE)

f.dir <- c("<=", "<=", "<=")

f.rhs <- c(400,150,200)

lp("max", f.obj, f.con, f.dir, f.rhs)

lp1 <- lp("max", f.obj, f.con, f.dir, f.rhs)
sol<-lp1$solution
z <- lp1$objval

# Q1
dcons <- lp("max", f.obj, f.con, f.dir, f.rhs, compute.sens=TRUE)$duals
dfrom <- lp("max", f.obj, f.con, f.dir, f.rhs, compute.sens=TRUE)$duals.from
dto <- lp("max", f.obj, f.con, f.dir, f.rhs, compute.sens=TRUE)$duals.to

cat("Type 1 : ", sol[1], "\nType 2 : ", sol[2])

#Q2
cat("Dual price of production capacity : ", dcons[1])
cat("Range : ", dfrom[1], " to ", dto[1])

#Q3
if ((f.rhs[2]-120)>=dfrom[2]&&(f.rhs-120)<=dto[2]){
  increase = dcons[2]*(f.rhs[2]-120)
  cat("Effect in optimum revenue : ",increase)
}else{
  print("Is not possible")
}

#Q4
cat("Dual price of type 2 hat : ",dcons[3])
max_increase = dto[3]-f.rhs[3]
cat("Maximum Increase : ",max_increase)