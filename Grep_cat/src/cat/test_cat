#!/bin/bash

declare -a test_files=(
    "test_files2/ASCII"
    "test_files2/test_file1"
    "test_files2/test_file2"
    "test_files2/test_file3"
)

declare -a flags=(
    "-b"
    "--number-nonblank"
    "-n"
    "--number"
    "-e"
    "-E"
    "-v"
    "-s"
    "--squeeze-blank"
    "-t"
    "-T"
)

DIFF_res=""
total=0
success=0
fail=0

# раздельное тестирование флагов
echo "------------1 FLAG------------" >cat_test.log
for ((i = 0; i <= ${#test_files[@]} - 1; i++)); do
    echo "__________________________" >>cat_test.log
    # последовательный перебор всех флагов
    for ((f = 0; f <= ${#flags[@]} - 1; f++)); do
        let "total++"
        # s21_cat
        $(./s21_cat ${test_files[$i]} ${flags[$f]} >outputs/s21_cat_out_${i}_${f})
        # cat
        $(cat ${test_files[$i]} ${flags[$f]} >outputs/cat_out_${i}_${f})
        DIFF_res="$(diff -s outputs/cat_out_${i}_${f} outputs/s21_cat_out_${i}_${f})"
        if [ "$DIFF_res" == "Files outputs/cat_out_${i}_${f} and outputs/s21_cat_out_${i}_${f} are identical" ]; then
            echo -e "${test_files[$i]}||${flags[$f]}||SUCCESS" >>cat_test.log
            let "success++"
        else
            echo -e "${test_files[$i]}||${flags[$f]}||NOT SUCCESS" >>cat_test.log
            echo $DIFF_res
            lef "fail++"
        fi
    done
done

echo "------------2 FLAGS------------" >>cat_test.log
for ((i = 0; i <= ${#test_files[@]} - 1; i++)); do
    echo "__________________________" >>cat_test.log
    # последовательный перебор всех флагов
    for ((f_first = 0; f_first <= ${#flags[@]} - 1; f_first++)); do
        for ((f_second = 0; f_second <= ${#flags[@]} - 1; f_second++)); do
            if [ $f_first != $f_second ]; then
                let "total++"
                # s21_cat
                $(./s21_cat ${test_files[$i]} ${flags[$f_first]} ${flags[$f_second]} >outputs/s21_cat_out_${i}_${f_first}_${f_second})
                # cat
                $(cat ${test_files[$i]} ${flags[$f_first]} ${flags[$f_second]} >outputs/cat_out_${i}_${f_first}_${f_second})
                DIFF_res="$(diff -s outputs/cat_out_${i}_${f_first}_${f_second} outputs/s21_cat_out_${i}_${f_first}_${f_second})"
                if [ "$DIFF_res" == "Files outputs/cat_out_${i}_${f_first}_${f_second} and outputs/s21_cat_out_${i}_${f_first}_${f_second} are identical" ]; then
                    echo -e "${test_files[$i]}||${flags[$f_first]}  ${flags[$f_second]}||SUCCESS" >>cat_test.log
                    let "success++"
                else
                    echo -e "${test_files[$i]}||${flags[$f_first]}  ${flags[$f_second]}||NOT SUCCESS" >>cat_test.log
                    let "fail++"
                    echo $DIFF_res
                fi
            fi
        done
    done
done

echo "TOTAL: ${total}"
echo "SUCCESS: ${success}"
echo "FAIL: ${fail}"
