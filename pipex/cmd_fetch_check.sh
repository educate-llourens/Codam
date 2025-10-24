
echo "get_cmd_path returns the correct directory path:"

cc ./testing/cmd_fetch_check.c ./utils/get_cmd_path.c -L. -l:./printf/libftprintf.a -o a.out
output1=$(./a.out)

if [ "$output1" = "/usr/bin/wc" ]; then
	echo "✅"
else
	echo "❌"
fi