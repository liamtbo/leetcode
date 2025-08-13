"""
list
    Operation 	        Examples 	        Average case 	Amortised Worst case
    Append 	            l.append(item) 	    O(1) 	        O(1)(resize)
    Clear 	            l.clear() 	        O(1) 	        O(1)
    Containment         item in/not in l    O(N) 	        O(N)
    Copy 	            l.copy() 	        O(N) 	        O(N)
    Delete 	            del l[i] 	        O(N) 	        O(N)
    Extend 	            l.extend(iterable) 	O(N) 	        O(N)
    Equality 	        l1==l2, l1!=l2 	    O(N) 	        O(N)
    Index 	            l[i] 	            O(1) 	        O(1)
    Iteration 	        for item in l: 	    O(N) 	        O(N)
    Length 	            len(l) 	            O(1) 	        O(1)
    Multiply 	        k*l 	            O(k*N) 	        O(k*N)
    Min, Max 	        min(l), max(l) 	    O(N) 	        O(N)
    Pop from end 	    l.pop(-1) 	        O(1) 	        O(1)
    Pop intermediate 	l.pop(item) 	    O(N) 	        O(N)
    Pop from beginning  l.pop(0)            O(N)            O(N)
    Remove 	            l.remove(…) 	    O(N) 	        O(N)
    Reverse 	        l.reverse() 	    O(N) 	        O(N)
    Slice 	            l[x:y] 	            O(y-x) 	        O(y-x)
    Sort 	            l.sort() 	        O(N log N) 	    O(N log N)
    Store by index 	    l[i]=item 	        O(1) 	        O(1)
"""
"""
deque
    syntax:
        from collections import deque
        new_deque = deque(old_list)

    Operation               Time Complexity
    append(x)               O(1)
    appendleft(x)           O(1)
    pop()	                O(1)
    popleft()	            O(1)
    extend(iterable)        O(k)
    extendleft(iterable)	O(k)
    remove(value)	        O(n)
    rotate(n)	            O(k)
    clear()		            O(n)
    count(value)	        O(n)
    index(value)	        O(n)
    reverse()	            O(n)
"""
"""
deque vs list
    deque when you need fast popping from the front
    lists when you need fast random access but don't pop from front often
"""

# Basic Functions
print("Hello, World!")  # Outputs to the console
length = len([1, 2, 3])  # Returns the length of an object
t = type(42)  # Returns the type of an object
name = input("Enter your name: ")  # Gets input from the user
nums = range(1, 5)  # Generates a sequence of numbers
total = sum([1, 2, 3])  # Sums elements of an iterable
maximum = max([10, 20, 30])  # Returns the max value
minimum = min([10, 20, 30])  # Returns the min value
absolute = abs(-7)  # Returns the absolute value
rounded = round(3.14159, 2)  # Rounds a number
sorted_list = sorted([3, 1, 2])  # Returns a sorted list

# Type Conversion
i = int("42")  # Converts to an integer
f = float("3.14")  # Converts to a float
s = str(100)  # Converts to a string
lst = list((1, 2, 3))  # Converts to a list
tpl = tuple([1, 2, 3])  # Converts to a tuple
st = set([1, 2, 3, 1])  # Converts to a set (removes duplicates)
d = dict([(1, 'one'), (2, 'two')])  # Converts to a dictionary
b = bool(0)  # Converts to a boolean

# Data Structures Methods
l = [1, 2, 3]
l.append(4)  # Adds an item to the end
l.extend([5, 6])  # Extends list with another list
x = l.pop()  # Removes and returns last element
l.remove(2)  # Removes first matching element
l.insert(1, 99)  # Inserts at index 1
count = l.count(1)  # Counts occurrences of 1
idx = l.index(99)  # Finds index of 99
l.sort()  # Sorts in place
l.reverse()  # Reverses in place
l_copy = l.copy()  # Returns a shallow copy
l.clear()  # Clears all elements

d = {'a': 1, 'b': 2}
keys = d.keys()  # Gets dictionary keys
values = d.values()  # Gets dictionary values
items = d.items()  # Gets key-value pairs
val = d.get('a')  # Gets value of key 'a'

# String Methods
rev = "".join(reversed("hello"))  # Reverses a string
upper = "hello".upper()  # Converts to uppercase
lower = "HELLO".lower()  # Converts to lowercase
trimmed = "  hello  ".strip()  # Trims whitespace
words = "a,b,c".split(",")  # Splits into a list
joined = "-".join(["a", "b", "c"])  # Joins list into a string
replaced = "hello world".replace("world", "Python")  # Replaces text
idx = "hello".find("e")  # Finds index of 'e'
is_start = "hello".startswith("he")  # Checks start of string
is_end = "hello".endswith("lo")  # Checks end of string
formatted = "My name is {}".format("Liam")  # Formats strings

# Functional Programming Tools
squared = list(map(lambda x: x ** 2, [1, 2, 3]))  # Applies function to each item
evens = list(filter(lambda x: x % 2 == 0, [1, 2, 3, 4]))  # Filters based on condition
from functools import reduce
product = reduce(lambda x, y: x * y, [1, 2, 3, 4])  # Reduces iterable to a single value
add = lambda x, y: x + y  # Defines a small anonymous function

# Error Handling
try:
    1 / 0  # Attempt to divide by zero
except ZeroDivisionError:
    print("Cannot divide by zero!")  # Handles exception
finally:
    print("This runs no matter what.")  # Runs always

# raise ValueError("An error occurred")  # Raises an exception manually
assert 2 + 2 == 4  # Tests a condition

# File Handling
with open("file.txt", "w") as f:
    f.write("Hello, File!")  # Writes to file

with open("file.txt", "r") as f:
    content = f.read()  # Reads entire file

with open("file.txt", "r") as f:
    first_line = f.readline()  # Reads one line

with open("file.txt", "r") as f:
    all_lines = f.readlines()  # Reads all lines as a list

# Miscellaneous
for i, val in enumerate(["a", "b", "c"]):  # Enumerates with index
    print(i, val)

zipped = list(zip([1, 2], ["a", "b"]))  # Combines iterables

all_true = all([True, True, False])  # Checks if all are True
any_true = any([False, False, True])  # Checks if any are True

is_instance = isinstance(42, int)  # Checks object type
is_callable = callable(print)  # Checks if object is callable

attributes = dir(str)  # Lists attributes of an object
help(str)  # Displays help for str functions

unique_id = id(42)  # Gets unique ID of an object
hashed = hash("hello")  # Gets hash value

eval_result = eval("3 + 4")  # Evaluates a string as code
exec("x = 5; print(x)")  # Executes string as code

"""
importing functions from parents folders
    .
    ├── db.py
    └── tests/
        └── test_something.py
"""
import sys
import os
parent_dir = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.append(parent_dir)
import file
