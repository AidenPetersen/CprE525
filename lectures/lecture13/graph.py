import matplotlib.pyplot as mat

filename = "output.txt"
with open(filename) as f:
   xs = []
   ys = []
   for line in f:
       vals = line.split(" ")
       xs.append(float(vals[0]))
       ys.append(float(vals[1]))
   mat.plot(xs, ys)
   mat.savefig("sin.png")
