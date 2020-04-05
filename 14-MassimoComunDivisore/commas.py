f = open("2T_part1.txt", "r")
g = open("primesWithCommas.txt", "w");

maxNumPrimes = 10*100000 # 1000000 de primos
nLinea = 0
g.write("{")
for x in f:
    if(nLinea < 99999):
        g.write(x.replace("\t", ", ")+", ")
        nLinea += 1
    else:
        g.write(x.replace("\t", ", "))
        break
g.write("}")
f.close()
g.close()