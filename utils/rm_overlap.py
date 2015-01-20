import sys

links = {}
new = False

for line in sys.stdin:
    contents = line.split(" ")
    b = int(contents[0])
    e = int(contents[1])
    u = int(contents[2])
    v = int(contents[3])

    if (u,v) not in links:
        links[(u,v)] = []

    if len(links[(u,v)]) > 0:
        for (i,j) in links[(u,v)]:
            if b >= i and b < j:
                #C'est un overlap/une inclusion, on fait une modif
                time = links[(u,v)].index((i,j))
                links[(u,v)][time] = (min(b,i), max(j,e))
                break
            else:
                new = True #links[(u,v)].append((b,e))

        if new:
            # Nouveau lien
            new = False
            links[(u,v)].append((b,e))
    else:
        links[(u,v)].append((b,e))

for (u,v) in links:
    for (b,e) in links[(u,v)]:
        sys.stdout.write(str(b) + " " + str(e) + " " + str(u) + " " + str(v) + "\n")
