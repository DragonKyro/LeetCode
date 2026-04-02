class FizzBuzz:
    def __init__(self, n: int):
        import threading
        self.n = n
        self.current = 1
        self.lock = threading.Lock()
        self.condition = threading.Condition(self.lock)

    def fizz(self, printFizz: 'Callable[[], None]') -> None:
        import threading
        while True:
            with self.condition:
                while self.current <= self.n and not (self.current % 3 == 0 and self.current % 5 != 0):
                    self.condition.wait()
                if self.current > self.n:
                    return
                printFizz()
                self.current += 1
                self.condition.notify_all()

    def buzz(self, printBuzz: 'Callable[[], None]') -> None:
        import threading
        while True:
            with self.condition:
                while self.current <= self.n and not (self.current % 5 == 0 and self.current % 3 != 0):
                    self.condition.wait()
                if self.current > self.n:
                    return
                printBuzz()
                self.current += 1
                self.condition.notify_all()

    def fizzbuzz(self, printFizzBuzz: 'Callable[[], None]') -> None:
        import threading
        while True:
            with self.condition:
                while self.current <= self.n and not (self.current % 15 == 0):
                    self.condition.wait()
                if self.current > self.n:
                    return
                printFizzBuzz()
                self.current += 1
                self.condition.notify_all()

    def number(self, printNumber: 'Callable[[int], None]') -> None:
        import threading
        while True:
            with self.condition:
                while self.current <= self.n and (self.current % 3 == 0 or self.current % 5 == 0):
                    self.condition.wait()
                if self.current > self.n:
                    return
                printNumber(self.current)
                self.current += 1
                self.condition.notify_all()
