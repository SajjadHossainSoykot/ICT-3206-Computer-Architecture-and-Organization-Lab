# Lab 01 — Register Transfer Operations (4-bit)
# Run: python 01_register_transfer.py

class Register4:
    def __init__(self, value=0):
        self.value = value & 0b1111  # keep 4 bits

    def load(self, value):
        self.value = value & 0b1111

    def inc(self):
        self.value = (self.value + 1) & 0b1111

    def and_with(self, other):
        return Register4(self.value & other.value)

    def shift_left(self):
        self.value = ((self.value << 1) & 0b1111)

    def bits(self):
        return format(self.value, "04b")

class ControlUnit:
    def __init__(self):
        self.A = Register4()
        self.B = Register4()
        self.C = Register4()

    def transfer_A_to_B(self):
        self.B.load(self.A.value)

    def increment_A(self):
        self.A.inc()

    def and_A_B_to_C(self):
        self.C = self.A.and_with(self.B)

    def shift_A_left(self):
        self.A.shift_left()

    def state(self):
        return dict(A=self.A.bits(), B=self.B.bits(), C=self.C.bits())

def demo():
    cu = ControlUnit()
    cu.A.load(0b1010)
    print("Initial:", cu.state())
    cu.transfer_A_to_B()
    print("After transfer A→B:", cu.state())
    cu.increment_A()
    print("After INC A:", cu.state())
    cu.and_A_B_to_C()
    print("After AND A&B → C:", cu.state())
    cu.shift_A_left()
    print("After SHIFT LEFT A:", cu.state())

if __name__ == "__main__":
    demo()
    
# Output:
# Initial: {'A': '1010', 'B': '0000', 'C': '0000'}
# After transfer A→B: {'A': '1010', 'B': '1010', 'C': '0000'}
# After INC A: {'A': '1011', 'B': '1010', 'C': '0000'}
# After AND A&B → C: {'A': '1011', 'B': '1010', 'C': '1010'}
# After SHIFT LEFT A: {'A': '0110', 'B': '1010', 'C': '1010'}