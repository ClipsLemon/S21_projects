#!/bin/bash

declare -a test_files=(
    "test_files/nofile.txt"
    "test_files/test_file1"
    "test_files/test_file2"
    "test_files/test_file3"
    "test_files/test_file4"
)

declare -a flags=(
    "-e"
    "-i"
    "-v"
    "-c"
    "-l"
    "-n"
    "-h"
)

declare -a templates=(
    "[a-z]"
    "[A-Z]"
    "T"
    "t"
    "k"
)

declare -a spec_templates=(
    "^foobar"
    "foobar$"
    "^foobar$"
    "foob.r"
    # метасимволы
    "foob\dr"     # \d - цифра
    "foob[\w\s]"r # \w - буквы, цифры, _; \s - пробел. \n\t\r\f
)
COUNTER=0
SUCCESS=0
FAIL=0
run_test() {
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose -q --log-file=s21_grep.log ./$command >/dev/null
    leaks=$(grep -ic "LEAK SUMMARY:" "s21_grep.log" || true)
    leak_err=$(grep -ic "ERROR SUMMARY: [^0]" "s21_grep.log" || true)
    if [ "$leaks" -eq "0" ] && [ "$leak_err" -eq "0" ]; then
        let "SUCCESS++"
        echo -n "${COUNTER}. SUCCESS"
        echo -n "${COUNTER}. SUCCESS" >>grep_leaks.log
    else
        let "FAIL++"
        echo -n "${COUNTER}. FAIL"
        echo -n "${COUNTER}. FAIL" >>grep_leaks.log
    fi
}

echo "LEAKS TEST" >grep_leaks.log
for ((i = 0; i < ${#test_files[@]}; i++)); do
    for ((f_f = 0; f_f < ${#flags[@]}; f_f++)); do
        for ((t = 0; t < ${#templates[@]}; t++)); do
            let "COUNTER++"
            command="s21_grep ${flags[$f_f]} ${templates[$t]} ${test_files[$i]}"
            run_test $command
            echo " - ${test_files[$i]} ${flags[$f_f]} ${templates[$t]}"
            echo " - ${test_files[$i]} ${flags[$f_f]} ${templates[$t]}" >>grep_leaks.log
        done
    done
done

for ((i = 0; i < ${#test_files[@]}; i++)); do
    for ((f_f = 0; f_f < ${#flags[@]}; f_f++)); do
        for ((f_s = 0; f_s < ${#flags[@]}; f_s++)); do
            for ((t = 0; t < ${#templates[@]}; t++)); do
                if [[ $f_f != $f_s && $f_f != 0 ]]; then
                    let "COUNTER++"
                    command="s21_grep ${flags[$f_f]} ${flags[$f_s]} ${templates[$t]} ${test_files[$i]}"
                    echo " - ${test_files[$i]} ${flags[$f_f]} ${flags[$f_s]} ${templates[$t]}"
                    echo " - ${test_files[$i]} ${flags[$f_f]} ${flags[$f_s]} ${templates[$t]}" >>grep_leaks.log
                    run_test $command
                fi
            done
        done
    done
done

echo "TOTAL: ${COUNTER}"
echo "SUCCESS: ${SUCCESS}"
echo "FAIL: ${FAIL}"
rm -f s21_grep.log
