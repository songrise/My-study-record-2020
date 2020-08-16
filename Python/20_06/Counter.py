from collections import Counter

fruit = ["Apple", "Pear", "Apple", "Grape", "Orange", "Grape"]
count = Counter(fruit)
print(count)
print(count.most_common(2))
