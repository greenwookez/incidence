rm test_results.txt
echo "Точки, которые лежат вне ГО:" >> test_results.txt
./checkIncidence.out 0 65 0 >> test_results.txt
./checkIncidence.out -51 0 130 >> test_results.txt
./checkIncidence.out 52 0 130 >> test_results.txt
./checkIncidence.out -60 -90 130 >> test_results.txt
echo "\nТочки, которые лежат внутри ГО:" >> test_results.txt
./checkIncidence.out 21 -5 100 >> test_results.txt
./checkIncidence.out 20 -40 10 >> test_results.txt
./checkIncidence.out 0 -88 119 >> test_results.txt
echo "\nТочки, которые лежат на ребрах ГО:" >> test_results.txt
./checkIncidence.out 0 0 0 >> test_results.txt
./checkIncidence.out 1 0 0 >> test_results.txt
./checkIncidence.out 0 -88.33 10 >> test_results.txt
./checkIncidence.out 51 0 60 >> test_results.txt
./checkIncidence.out -51 0 45 >> test_results.txt
echo "\nТочки, которые являются вершинами ГО:" >> test_results.txt
./checkIncidence.out 0 -88.33 120 >> test_results.txt
./checkIncidence.out 51 0 120 >> test_results.txt
./checkIncidence.out -51 0 120 >> test_results.txt
./checkIncidence.out 0 -88.33 0 >> test_results.txt
./checkIncidence.out 51 0 0 >> test_results.txt
./checkIncidence.out -51 0 0 >> test_results.txt
echo "\nТочки, которые лежат на гранях ГО:" >> test_results.txt
./checkIncidence.out -30 0 12 >> test_results.txt
./checkIncidence.out 20 -40 0 >> test_results.txt
./checkIncidence.out 21 0 100 >> test_results.txt
./checkIncidence.out -10 -10 120 >> test_results.txt
