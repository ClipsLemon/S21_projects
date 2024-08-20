#!/bin/bash

declare -a test_files=(
    "test_files/test_file1"
    "test_files/test_file2"
    "test_files/test_file3"
    "test_files/test_file4"
)

# я не использовал флаг -s и несуществующие флаги для теста по той причине,
# что оригинальный греп все равно будет выкидывать сообщение
# об ошибке в консоль, а результат моего грепа будет писаться в файл
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

DIFF_res=""
total=0
success=0
fail=0

# 1 флаг
echo "############################" >grep_test.log
echo "########## 1 FLAG ##########" >>grep_test.log
echo "############################" >>grep_test.log

for ((i = 0; i <= ${#test_files[@]} - 1; i++)); do
    for ((f_f = 0; f_f <= ${#flags[@]} - 1; f_f++)); do
        for ((templ = 0; templ <= ${#templates[@]} - 1; templ++)); do
            let "total++"
            $(./s21_grep ${flags[$f_f]} ${templates[$templ]} ${test_files[$i]} >outputs/s21_grep_out_f${i}_t${templ}_${f_f})
            $(grep ${flags[$f_f]} ${templates[$templ]} ${test_files[$i]} >outputs/grep_out_f${i}_t${templ}_${f_f})
            DIFF_res="$(diff -s outputs/s21_grep_out_f${i}_t${templ}_${f_f} outputs/grep_out_f${i}_t${templ}_${f_f})"
            if [ "$DIFF_res" == "Files outputs/s21_grep_out_f${i}_t${templ}_${f_f} and outputs/grep_out_f${i}_t${templ}_${f_f} are identical" ]; then
                echo -e "${total}. SUCCESS || ${test_files[$i]} || ${flags[$f_f]} || ${templates[$templ]}" >>grep_test.log
                let "success++"
            else
                echo -e "${total}. FAIL || ${test_files[$i]} || ${flags[$f_f]} || ${templates[$templ]}" >>grep_test.log
                let "fail++"
            fi
        done
    done
done

echo "############################" >>grep_test.log
echo "########## 2 FLAG ##########" >>grep_test.log
echo "############################" >>grep_test.log

for ((i = 0; i <= ${#test_files[@]} - 1; i++)); do
    for ((f_f = 0; f_f <= ${#flags[@]} - 1; f_f++)); do
        for ((f_s = 0; f_s <= ${#flags[@]} - 1; f_s++)); do
            for ((templ = 0; templ <= ${#templates[@]} - 1; templ++)); do
                if [[ $f_f != $f_s && $f_f != 0 ]]; then
                    let "total++"
                    $(./s21_grep ${flags[$f_f]} ${flags[$f_s]} ${templates[$templ]} ${test_files[$i]} >outputs/s21_grep_out_f${i}_t${templ}_${f_f}_${f_s})
                    $(grep ${flags[$f_f]} ${flags[$f_s]} ${templates[$templ]} ${test_files[$i]} >outputs/grep_out_f${i}_t${templ}_${f_f}_${f_s})
                    DIFF_res="$(diff -s outputs/s21_grep_out_f${i}_t${templ}_${f_f}_${f_s} outputs/grep_out_f${i}_t${templ}_${f_f}_${f_s})"
                    if [ "$DIFF_res" == "Files outputs/s21_grep_out_f${i}_t${templ}_${f_f}_${f_s} and outputs/grep_out_f${i}_t${templ}_${f_f}_${f_s} are identical" ]; then
                        echo -e "${total}. SUCCESS || ${test_files[$i]} || ${flags[$f_f]} ${flags[$f_s]} || ${templates[$templ]}" >>grep_test.log
                        let "success++"
                    else
                        echo -e "${total}. FAIL || ${test_files[$i]} || ${flags[$f_f]} ${flags[$f_s]} || ${templates[$templ]}" >>grep_test.log
                        let "fail++"
                    fi
                fi
            done
        done
    done
done

echo "############################" >>grep_test.log
echo "####### SPECIAL TEST #######" >>grep_test.log
echo "############################" >>grep_test.log

for ((s_templ = 0; s_templ < ${#spec_templates[@]}; s_templ++)); do
    let "total++"
    $(./s21_grep ${spec_templates[$s_templ]} ${test_files[2]} >outputs/s21_grep_out_f${2}_st${s_templ})
    $(grep ${spec_templates[$s_templ]} ${test_files[2]} >outputs/grep_out_f${2}_st${s_templ})
    DIFF_res="$(diff -s outputs/s21_grep_out_f${2}_st${s_templ} outputs/grep_out_f${2}_st${s_templ})"
    if [ "$DIFF_res" == "Files outputs/s21_grep_out_f${2}_st${s_templ} and outputs/grep_out_f${2}_st${s_templ} are identical" ]; then
        echo -e "${total}. SUCCESS || ${test_files[$2]} || ${spec_templates[$s_templ]}" >>grep_test.log
        let "success++"
    else
        echo -e "${total}. FAIL || ${test_files[$2]} || ${spec_templates[$s_templ]}" >>grep_test.log
        let "fail++"
    fi
done

echo "############################" >>grep_test.log
echo "       2 FILES 1 FLAG" >>grep_test.log
echo "############################" >>grep_test.log

for ((i = 0; i <= ${#test_files[@]} - 1; i++)); do
    for ((j = 0; j <= ${#test_files[@]} - 1; j++)); do
        if [ $j != $i ]; then
            # если первый файл не равен второму
            for ((f_f = 0; f_f <= ${#flags[@]} - 1; f_f++)); do
                for ((templ = 0; templ <= ${#templates[@]} - 1; templ++)); do
                    let "total++"
                    $(./s21_grep ${flags[$f_f]} ${templates[$templ]} ${test_files[$i]} ${test_files[$j]} >outputs/s21_grep_out_f${i}_${j}_t${templ}_${f_f})
                    $(grep ${flags[$f_f]} ${templates[$templ]} ${test_files[$i]} ${test_files[$j]} >outputs/grep_out_f${i}_${j}_t${templ}_${f_f})
                    DIFF_res="$(diff -s outputs/s21_grep_out_f${i}_${j}_t${templ}_${f_f} outputs/grep_out_f${i}_${j}_t${templ}_${f_f})"
                    if [ "$DIFF_res" == "Files outputs/s21_grep_out_f${i}_${j}_t${templ}_${f_f} and outputs/grep_out_f${i}_${j}_t${templ}_${f_f} are identical" ]; then
                        echo -e "${total}. SUCCESS || ${test_files[$i]} ${test_files[$j]} || ${flags[$f_f]} || ${templates[$templ]}" >>grep_test.log
                        let "success++"
                    else
                        echo -e "${total}. FAIL || ${test_files[$i]} ${test_files[$j]} || ${flags[$f_f]} || ${templates[$templ]}" >>grep_test.log
                        let "fail++"
                    fi
                done
            done
        fi
    done
done
echo "TOTAL: ${total}"
echo "SUCCESS: ${success}"
echo "FAIL: ${fail}"
