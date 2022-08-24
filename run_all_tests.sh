sh run_call_graph_test.sh $@
sh run_cpu_test.sh $@
python run_xv6_test.py --test $@
if [ -f 'out/final_report.txt' ]; then rm 'out/final_report.txt'; fi
ls out/*_metadata.txt |
while read file_name;
do
    cat "$file_name" >> out/final_report.txt
done