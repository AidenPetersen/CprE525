import matplotlib.pyplot as plt

filename = "chebyshev.txt"
with open(filename) as file:
lines = [line.rstrip() for line in file]

xvals = []
yvals = []

for line in lines:
s = line.split(" ")
xvals.append(float(s[0]))
yvals.append(float(s[1]))


plt.plot(xvals, yvals)
plt.savefig("chebyshev.png")
