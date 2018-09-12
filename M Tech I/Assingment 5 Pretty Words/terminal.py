import os
rows, columns = os.popen('stty size', 'r').read().split()
