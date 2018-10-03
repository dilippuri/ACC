import numpy as np

def make2dList(rows, cols):
    a=[]
    for row in xrange(rows): a += [[0]*cols]
    return a

def make2dList2elements(rows, cols):
    a=[]
    for row in xrange(rows): a += [[[0]*rows]*cols]
    return a

def initializeOptimal(s, oc, i):
	x = np.array(s)
	y = np.array(i)
	z = np.array(oc)
	z[:,0] = x[:,0] + y[:,0]
	oc = z.tolist()
	return oc

def finalOptimal(oc, i):
	x = np.array(i)
	y = np.array(oc)
	z = x[:,1] + y[:,len(s[0])-1]
	z = z.tolist()
	return z.index(min(z)), min(z)

def findOptimalCost(s, oc, t):
	for j in range(1,len(s[0])):
		for i in xrange(len(s)):
			temp = [None]*len(s)			
			for k in xrange(len(s)):
				temp[k] = oc[k][j-1] + t[k][j-1][i]
			oc[i][j] = min(temp) + s[i][j]
			pt[i][j] = temp.index(min(temp)) #+ 1
			
	return oc, pt

def finalPath(pt, line):
	path = []
	for x in range(len(pt[0])-1, 0, -1):
		temp = pt[line][x]
		path.append(temp + 1)
		line = temp
	return path
#"""	

if __name__ == '__main__':
	s = [[4,3,2],[2,6,5],[1,3,3]]
	i = [[1,3],[2,2],[3,1]]
	t = [[[0,2,2],[0,3,1]],[[3,0,2],[1,0,2]],[[6,1,0],[2,1,0]]]

	scols = len(s[0])#raw_input("No of stations: ")
	sraws = len(s)#raw_input("No of lines: ")

#	s = make2dList(sraws,scols)
#	i = make2dList(sraws,2)
#	t = make2dList2elements(sraws,scols-1)
	oc = make2dList(sraws,scols)
	pt = make2dList(sraws,scols)


	oc = initializeOptimal(s, oc, i)
	oc, pt = findOptimalCost(s, oc, t)
	print oc
	print pt

	line, cost = finalOptimal(oc, i)
	path = finalPath(pt, line)
	path = path[::-1]
	path.append(line+1)
	print "Final Optimal Cost: ", cost
	print "Final Optimal Path: ", path
	print "Assembly Line: ", line+1

"""#
	s = [[7, 9, 3, 4, 8, 4], [8, 5, 6, 4, 5, 7]]
	i = [[2, 3], [4, 2]]
	t = [[[0, 2],[0, 3],[0, 1,],[0, 3],[0, 4]], [[2, 0], [1, 0], [2,0], [2, 0], [1, 0]]]

	s = [[4,3,2],[2,6,5],[1,3,3]]
	i = [[1,3],[2,2],[3,1]]
	t = [[[0,2,2],[0,3,1]],[[3,0,2],[1,0,2]],[[6,1,0],[2,1,0]]]
#"""
