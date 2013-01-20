set terminal png truecolor size 800,600
set output "graph_results.png"
set autoscale
set logscale xy
set title "Błędy obliczania schematem Hornera"

plot "graph_poly1_t1.txt" using 1:2 title "p1" with lines, "graph_poly2_t1.txt" using 1:2 title "p2" with lines, "graph_poly3_t1.txt" using 1:2 title "p3" with lines, "graph_poly4_t1.txt" using 1:2 title "p4" with lines
      
