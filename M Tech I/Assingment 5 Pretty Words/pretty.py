import os
rows, columns = os.popen('stty size', 'r').read().split()
#words = raw_input().split(' ')
c = 0;flag = 0;l=[[]];j=0;i=0
L = int(columns)

with open('file.txt', 'r') as myfile:
	data=myfile.read().replace('\n', ' ')
words = data.split()
while i<len(words):
	if flag==0 and L-(len(words[i])+c)>=0:
		l[j].append(words[i])
#		print i, len(i)
		c = c + len(words[i])
		flag=1
		i=i+1
	elif flag==1 and L-(len(words[i])+c+1)>=0:
		l[j].append(words[i])
#		print i, len(i)
		c = c + len(words[i]) + 1
		i=i+1
	else:
		if L-len(words[i]) < 0:
			print "-"*L
			print words[i] + " can not fit in line length"
			break
#		str1 = ' '.join(l[j])
#		print str1
		flag = 0
		c = 0
		j=j+1
		l.append([])

print "*"*L
for q in l:
	str1 = ' '.join(q)
	print str1
print "*"*L
