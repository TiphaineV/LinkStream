#!/bin/bash

# Take raw link stream on input, clean it
inputFile=$1

# Sort nodes so that b e u v implies u < v
cat $inputFile | awk -F ' ' '{
    if($3 > $4){
        print($1,$2,$4,$3);
    } else {
        print($1,$2,$3,$4);
    }
}' > out2
echo "Done ensuring u,v means u < v." 1>&2
# Sort by u,v, then b,e
sort out2 -T 2G -k3n,3n -k4n,4n -k1n,1n -k2n,2n > out3
echo "Done sorting file by u,v,b,e priority." 1>&2
# Remove overlapping links (for now, just one u,v)
cat out3 |python utils/rm_overlap.py > out4
echo "Done removing overlaps." 1>&2

uniq out4 > $inputFile-clean

echo "Done removing duplicates." 1>&2
rm out2 out3
echo "Done cleaning." 1>&2
