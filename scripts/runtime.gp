reset
set ylabel 'time(sec)'
set style fill solid
set title 'performance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

#plot [:][:0.150]'output.txt' using 2:xtic(1) with histogram title 'original', \
#'' using ($0-0.06):($2+0.001):2 with labels title ' ', \
#'' using 3:xtic(1) with histogram title 'optimized'  , \
#'' using 4:xtic(1) with histogram title 'hash'  , \
#'' using ($0+0.3):($3+0.0015):3 with labels title ' ', \
#'' using ($0+0.4):($4+0.0015):4 with labels title ' '

plot [:][:0.150]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using ($0-0.3):($2+0.001):2 with labels title ' ', \
'' using 3:xtic(1) with histogram title 'size:1'  , \
'' using 4:xtic(1) with histogram title 'size:2^5'  , \
'' using 5:xtic(1) with histogram title 'size:2^1^0'  , \
'' using 6:xtic(1) with histogram title 'size:2^1^5'  , \
'' using 7:xtic(1) with histogram title 'size:2^2^0'  , \
'' using ($0-0.06):($3+0.0015):3 with labels title ' ', \
'' using ($0+0.1):($4+0.0015):4 with labels title ' ', \
'' using ($0+0.1):($5+0.0015):5 with labels title ' ', \
'' using ($0+0.3):($6+0.0015):6 with labels title ' ', \
'' using ($0+0.3):($7+0.0015):7 with labels title ' '
