class Budget:
    Expenses = {}
    def __init__(self, category, amount=0):
        self.category = category
        self.amount = amount
        self.transactions = {"Deposits":[], "Withdraws":[], "Transfer-Outgoing":[], "Transfer-Incoming":[], "Balance":[]}

    def deposit(self, amount, description= ""):
        self.amount += amount
        self.transactions["Deposits"].append([amount,description])
        return self.update_balance()
        
    def withdraw(self,amount, description= ""):
        if self.check_funds(amount):
            self.amount -=amount
            self.transactions["Withdraws"].append([amount,description])
            self.update_balance()
            self.update_expenses(amount)
            return True
        else:
          return False

    def get_balance(self):
        return self.amount
    
    def transfer(self,amount,Budget):
        if self.check_funds(amount)==True:
            self.amount-=amount
            self.transactions["Transfer-Outgoing"].append([amount, Budget.category])
            self.update_balance()
            Budget.amount += amount
            Budget.transactions["Transfer-Incoming"].append([amount, self.category])
            Budget.update_balance()
            return True
        return False
    
    def check_funds(self, amount):
        if self.amount < amount:
            return False
        return True

    def update_balance(self):
        self.transactions["Balance"] = self.amount
        return self.amount

    def update_expenses(self, amount):
        if not self.Expenses[self.category]:
            self.Expenses[self.category] = amount
        else:
            self.Expenses[self.category] += amount

    def __str__(self):
        transactions_result = "Status : "
        for x in self.transactions:
            if x != "Balance":
                transactions_result += x + ' : \n'
                if not self.transactions[x]:
                    transactions_result += "None\n"
                for y in self.transactions[x]:
                    transactions_result += f"Amount : {y[0]} Description : {y[1]}\n"
            else:
                transactions_result += f'Balance : {self.transactions[x]}'
        return transactions_result

if __name__ == '__main__':
    food = Budget("food")
    food.deposit(100)
    food.withdraw(20)
    print(food.get_balance())
    print(food.transactions)
    clothing = Budget("clothing")
    clothing.deposit(100)
    clothing.transfer(20, food)
    clothing.transfer(40,food)
    print(clothing.transactions)
    print(food.transactions)
    print(str(clothing))