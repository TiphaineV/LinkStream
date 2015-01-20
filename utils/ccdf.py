# Don't forget to sort -n before !
import sys


total = int(sys.argv[1])
i = 0
old_val = None

for line in sys.stdin:
    val = float(line)
    if val != old_val:
        print(str(val) + " " + str(total - i))
    if val < old_val:
        sys.stderr.write("Seems like your data is unsorted. Did you run sort -n ?\n")
        break
    
    old_val = val
    i += 1
