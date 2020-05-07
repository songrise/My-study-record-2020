This assignment asked us to implement a console-based food ordering system.

Base:

1. As mentioned in the description file, our target user is the staff of the 7-23-cafe, so the system should be easy to use. That is to say, it should have a clear UI design although it just is a console program.

2. The system should be able to handle wrong user inputs, and prompt user to input again. This means the program should be robust enough to detect exceptions and recover from exceptions.

3. The system should have built-in data. That means, the data used to record food name, food price, food code.. etc. For this assignment, the simplest way is to hardcode them into source code. And a structure array is probably the most direct way to implement the task to organize those data. (See source code file for more details.)

4. At check out phase, system should show the ordered food. It means the system should be able to "record" the food that user food. The simplest way should be C array.

5. The system should detect if sets can be formed. So it means we should develop some kind of algorithm to solve this. As for this case, the data set should be rather small, so a brute-force algorithm should be OK.

6. The system should check if the total price is higher than $100.00 If so, get a 95% discount.

Extras:

1. As mentioned previously, the system should be easy to use. So the problem is how to design the user interface. To solve this problem, I designed two simple UI functions (see source code). Now my program have a good UI. 
