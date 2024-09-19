time = [0,10,10,20,30,40,40,40,50]

time_len = len(time)
number = [0]
count = [0]
for i, num_i in enumerate(range(time_len)):
    remainder = time[num_i] % 60
    if i == 0:
        number[0] = remainder
        count[0] += 1
        continue
    if remainder == number[-1]:
        count[-1] += 1
    else:
        number.append(remainder)
        count.append(1)
    
print(number)
print(count)