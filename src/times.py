import sys

old_b = -1
ends = dict()
active = set()
nodes = dict()

for line in sys.stdin:
    contents = line.split(" ")
    b = int(contents[0])
    e = int(contents[1])
    u = int(contents[2])
    v = int(contents[3])

    if(old_b != -1 and b != old_b):
        nb_links = len(active)
        nb_nodes = 0
        nb_links_2 = nb_links
        nb_nodes_2 = nb_nodes
        if old_b in ends:
            active = active.difference(ends[old_b])
            nb_links_2 = len(active)
        for n in nodes:
            if nodes[n] >= old_b:
                nb_nodes += 1
            if nodes[n] == old_b:
                nb_nodes_2 -= 1
        nb_nodes_2 += nb_nodes

        print(str(old_b) + " " + str(nb_links) + " " + str(nb_nodes))
        print(str(old_b) + " " + str(nb_links_2) + " " + str(nb_nodes_2))

    old_b = b

    if not u in nodes:
        nodes[u] = 0
    if not v in nodes:
        nodes[v] = 0
    nodes[u] = max(nodes[u], e)
    nodes[v] = max(nodes[v], e)

    if not e in ends:
        ends[e] = set()
    ends[e].add((u,v))

    active.add((u,v))

# Last time
nb_links = len(active)
nb_nodes = 0
nb_links_2 = nb_links
nb_nodes_2 = nb_nodes

if old_b in ends.keys():
    active = active.difference(ends[old_b])
    nb_links_2 = len(active)
for n in nodes:
    if nodes[n] >= old_b:
        nb_nodes += 1
    if nodes[n] == old_b:
        nb_nodes_2 -= 1
nb_nodes_2 += nb_nodes

print(str(old_b) + " " + str(nb_links) + " " + str(nb_nodes))
print(str(old_b) + " " + str(nb_links_2) + " " + str(nb_nodes_2))
