#!/bin/bash

total=`ls stats/values|wc -l|awk '{print($1)}'`
i=1

for statfile in `ls stats/values`
do
    # Compute dist
    cat 'stats/values/'$statfile |sort -n |uniq -c |awk '{print($2,$1)}' > stats/dists/$statfile-dist

    # Compute ccdf
    cat stats/dists/$statfile-dist |sort -nk1,1 -r |awk '{t+=$2;print($1,t);}' > stats/dists/$statfile-ccdf
    # Make plots (gnuplot ?)
echo "
set terminal postscript;

# Dists
set output 'stats/plots/$statfile-dist.eps';
set multiplot layout 2,2;

plot 'stats/dists/$statfile-dist' notitle;

set logscale x;
plot 'stats/dists/$statfile-dist' notitle;

unset logscale x;
set logscale y;
plot 'stats/dists/$statfile-dist' notitle;

set logscale x;
plot 'stats/dists/$statfile-dist' notitle;

unset multiplot;
unset logscale x;
unset logscale y;

# CCDF
set output 'stats/plots/$statfile-ccdf.eps';
set multiplot layout 2,2;

plot 'stats/dists/$statfile-ccdf' notitle;

set logscale x;
plot 'stats/dists/$statfile-ccdf' notitle;

unset logscale x;
set logscale y;
plot 'stats/dists/$statfile-ccdf' notitle;

set logscale x;
plot 'stats/dists/$statfile-ccdf' notitle;

unset multiplot;
" > out.gp

    gnuplot out.gp
    rm out.gp

    echo "Done with file $statfile. ($i/$total)" 1>&2
    ((i++))
done
