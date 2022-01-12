./tetgen 15 > z
./a.out z > our_result
./fillit z > their_result
diff our_result their_result> dif
cat dif
