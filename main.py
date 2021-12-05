import csv
import matplotlib.pyplot as plt

def plotBlockedPoints(blocked):
	x = list()
	y = list()
	for pair in blocked:
		x.append(int(pair[0]))
		y.append(int(pair[1]))
	plt.scatter(x, y, s=1, alpha=0.1, color='aliceblue')

def plotPathPoints(path):
	x = list()
	y = list()
	for pair in path:
		x.append(int(pair[0]))
		y.append(int(pair[1]))
	endpoints_x = [x[0], x[-1]]
	endpoints_y = [y[0], y[-1]]
	plt.scatter(endpoints_x, endpoints_y, color='red', s=20)
	plt.plot(x, y, color='green', alpha=1)

blocked = list()
path = list()
with open('output.csv', newline='') as csvfile :
	reader = csv.reader(csvfile, delimiter=',')
	i = 0
	row = next(reader)
	reached_end_block = False
	while (row[0] != "PATH"):
		row = next(reader)
		blocked.append(row)
	row = next(reader)
	while (True) :
		path.append(row)
		try:
			row = next(reader)
		except StopIteration:
			break

blocked = blocked[0:-1]
#for a in blocked :
#	print(a)
for b in path:
	print(b)
plotBlockedPoints(blocked)	
plotPathPoints(path)
plt.show()