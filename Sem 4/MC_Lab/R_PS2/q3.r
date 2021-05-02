library(lpSolve)
f.obj <- c(20,50,35)
f.con <- matrix(c(1, -1, -1,
                  1, 0, 0,
                  2, 4, 3), nrow=3, byrow=TRUE)

f.dir <- c(">=", "<=", "<=")

f.rhs <- c(0,75,240)

lp("max", f.obj, f.con, f.dir, f.rhs)

lp1 <- lp("max", f.obj, f.con, f.dir, f.rhs)
sol<-lp1$solution
z <- lp1$objval

# Q1
cat("Optimal mix : ",sol[1], sol[2], sol[3])

# Q2
dcons <- lp("max", f.obj, f.con, f.dir, f.rhs, compute.sens=TRUE)$duals
dfrom <- lp("max", f.obj, f.con, f.dir, f.rhs, compute.sens=TRUE)$duals.from
dto <- lp("max", f.obj, f.con, f.dir, f.rhs, compute.sens=TRUE)$duals.to

cat("Dual price of raw material resource : ", dcons[3])
cat("Range : ", dfrom[3], " to ", dto[3])

if ((f.rhs[3] + 120)>=dfrom[3]&&(f.rhs[3]+ 120)<=dto[3]){
  change = 120*dcons[3]
  cat("Change in total revenue : ", change)
  f.rhs1 <- c(f.rhs[1], f.rhs[2], f.rhs[3]+120)
  sol <- lp("max", f.obj, f.con, f.dir, f.rhs1)$solution
  cat("\nOptimal solution : ", sol[1], sol[2], sol[3])
}else{
  print("Not possible")  
}

# Q3
if((f.rhs[2]+10)>=dfrom[2]&&(f.rhs[2]+10)<=dto[2]){
  change = 10*dcons[2]
  cat("Change when demand of product A increased by 10 : ", change)
}else{
  print("+10 in product A Not possible")
}

if((f.rhs[2]-10)>=dfrom[2]&&(f.rhs[2]-10)<=dto[2]){
  change = -10*dcons[2]
  cat("Change when demand of product A increased by 10 : ", change)
}else{
  print("-10 in product A Not possible")
}




