import re
import json

f = open('materias.txt','r')
emptyline = re.compile('[\s]*\n')
materias = []
parcial = ""
for line in f:
	if not emptyline.match(line):
		parcial = parcial + line
	else:
		materias.append(parcial)
		parcial = ""

with open('separado.txt', 'w') as outfile:
    json.dump(materias, outfile)
f.close