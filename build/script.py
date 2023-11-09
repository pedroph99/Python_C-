import random
import torch
import numpy as np
from torch import nn
import sys

print(sys.path)
class neural_generator_reta(nn.Module):
    def __init__(self):
        super().__init__()
        self.layers = nn.Sequential(
        nn.Linear(1,1)
        )
    def foward(self, x):
        return self.layers(x)
    

def simple_func():
    print("ok hello world")

class dataset(torch.utils.data.Dataset):
    def __init__(self, f, interval, nsamples):
        self.data = []
        for x in range(nsamples):
            y = random.randint(interval[0],interval[1])
            if[y, f(y)] not in self.data:
                self.data.append([y, f(y)])

        

        self.data.sort()
    def teste(self):
        print("Objeto chamado com sucesso")

def func(b):
    
    teste = int(b)
    print(3*teste+3)
    return 3*teste+3
def teste_dataset(dataset):
    print(dataset.data)
    
loss_func = nn.MSELoss()



new_neural = neural_generator_reta()
func = lambda b: 3*b +3
new_dataset = dataset(func, [1,200], 100)
print(new_dataset.data)



