class Cashier:

    def __init__(self, n: int, discount: int, products: List[int], prices: List[int]
        ):
        self.price = {p : prices[i] for i, p in enumerate(products)}
        self.discount = discount
        self.n = n
        self.counter = 0

    def getBill(self, product: List[int], amount: List[int]) -> float:
        total = 0.0
        self.counter += 1
        
        for i in range(0, len(product)):
            total += self.price[product[i]] * amount[i]
        if self.counter == self.n:
            total = total - ((self.discount * total) / 100)
            self.counter = 0
        
        return total


# Your Cashier object will be instantiated and called as such:
# obj = Cashier(n, discount, products, prices)
# param_1 = obj.getBill(product,amount)
