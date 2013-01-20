set terminal png truecolor size 800,600
set output "graph_results.png"
set logscale y
set autoscale
set xlabel 'tries'
set ylabel 'error'

plot "graph_poly1_t1.dat" using 0:1 title "poly1" with lines
      
