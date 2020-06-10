class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for op in tokens:
            if (op == "+" or op == "-" or op == "*" or op == "/"): 
                op1 = stack.pop()
                op2 = stack.pop()
                if op == "/":
                    stack.append(str(int(int(op2) / float(op1))))
                else:
                    stack.append(str(eval(op2+op+op1)))

            else: 
                stack.append(op)

        return int(stack[-1])
