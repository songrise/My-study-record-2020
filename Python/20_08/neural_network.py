import numpy


class NeuralNetwork:
    def __init__(self, inputNodes, hiddenNodes, outputNodes, learningRate):
        self.inodes = inputNodes
        self.hnodes = hiddenNodes
        self.onodes = outputNodes
        self.lr = learningRate
        # link weight matrices
        self.wih = (random.normal(0.0, pow(self.inodes)) - 0.5)
        self.who = (random.normal(0.0, pow(self.onodes)) - 0.5)

    def train(self):
        pass

    def query(self):
        pass
