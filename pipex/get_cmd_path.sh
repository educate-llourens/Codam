#!/bin/bash

echo "ft_get_env is able to get the string of directories:"

cc ./testing/get_env.c
./a.out > output1.txt
output1=$(cat output1.txt)

cc ./testing/get_env_check.c ./utils/get_cmd_path.c -L./printf -lftprintf -o a.out
./a.out > output2.txt
output2=$(cat output2.txt)

if [ "$output1" = "$output2" ]; then
    echo "✅"
else
    echo "❌"
fi
