set terminal png truecolor size 800,600
set output "graph_results.png"
set logscale y
set xrange [1:1000000]
set yrange [1e-19:1]
set xlabel 'tries'
set ylabel 'error'

plot "graph_poly1_t1.dat" using 1:0 title "poly1" with lines, "graph_poly2_t1.dat" using 1:0 title "poly2" with lines, "graph_poly3_t1.dat" using 1:0 title "poly3" with lines, "graph_poly4_t1.dat" using 1:0 title "poly4" with lines
      
