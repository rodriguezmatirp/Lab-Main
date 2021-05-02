class Budget():
    transactions = dict()

    def __init__(self, name, balance=0):
        self.name = name
        self.balance = balance
        self.update_transactions(balance)
        print("Added new Category", name)

    def update_transactions(self, balance):
        if self.name not in self.transactions:
            self.transactions[self.name] = 0
        else:
            self.transactions[self.name] += balance
        print("Updated Expense")

    def show_transactions(self):
        total_budget = sum(self.transactions.values())
        print(self.transactions)
        for category in self.transactions:
            print("Category :", category, self.transactions[category], str(round((self.transactions[category] / total_budget * 100), 2)) + '%')
        print("Total Expenses classified with categories", total_budget, "(100%)")

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            print(f'New balance for ',self.name, 'is', self.balance)
            return True

        print("Check the amount Entered")
        return False

    def withdraw(self, amount):
        if amount > 0:
            if self.balance < amount:
                print('Insufficient balance', self.name)
                return False

            self.balance += -amount
            self.update_transactions(-amount)
            print('Your New balance of category',self.name, 'is', self.balance)
            return True

        print("Check the amount Entered")
        return False

    def get_balance(self):
        print('Balance of category', self.name, 'is', self.balance)
        return self.balance

    def transfer(self, amount, category):
        if self.name == category.name:
            print('Cannot Transfer funds between same category')
            return False

        else:
            if self.balance < amount:
                print('Insufficient balance for transfer from ', self.name, "\nCheck the amount entered!")
                return False

            self.withdraw(amount)
            category.deposit(amount)
            print("Transferred from ", self.name, 'to', category.name)
            print("Amount :", amount)
            return True

    #This returns a string which provides the status
    def __str__(self):
        category_status = f"Category : {self.name}  Balance : {self.transactions[self.name]}"
        return category_status

if __name__ == "__main__":
    clothing = Budget("clothing", 4000)
    food = Budget("food")
    entertainment = Budget("entertainment", 2000)

    food.deposit(5000)
    clothing.withdraw(500)
    entertainment.transfer(1000, food)
    food.show_transactions()
    print(str(food))