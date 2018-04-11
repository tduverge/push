if [ $# -ne 2 ]
then
	echo "usage : ./script.sh nb_of_values nb_of_tests"
else
	let "nb = 0"
	let "j = 0"
	let "arg_1 = $1"
	let "arg_2 = $2"
	let "sum_ok = 0"
	let "sum_ko = 0"
	let "min = -1"
	let "max = -1"
	if [ $arg_2 -le 0 ] || [ $arg_1 -le 0 ]
	then
		echo "error : nb_of_values and nb_of_tests have to be numbers scrictly positive"
	else
		for ((a=$arg_2; a>0; a--))
		do
			ARG="`ruby -e "puts (1..$arg_1).to_a.shuffle.join(' ')"`"
			let "res = $(./push_swap $ARG | wc -l)"
			let "nb = $nb + $res"
			ok=$(./push_swap $ARG | ./checker $ARG)
			if [ $ok = "OK" ]
			then
				let "sum_ok= $sum_ok + 1"
			else
				let "sum_ko= $sum_ko + 1"
			fi
			if [ $min = -1 ] || [ $res -lt $min ]
			then
				let "min = $res"
			fi
			if [ $max = -1 ] || [ $res -gt $max ]
			then
				let "max = $res"
			fi
		done
		let "nb = $nb / $arg_2"
		if [ $sum_ko -eq 0 ]
		then
			echo "              \033[42m\033[30mCONGRATULATION !!!\033[0m"
		fi
		echo "\033[1;34mYou have \033[32m$sum_ok\033[34m success for \033[36m$2\033[34m test(s) and \033[31m$sum_ko\033[34m fail(s)"
		echo "Your maximum is \033[31m$max\033[34m"
		echo "Your average is \033[36m$nb\033[34m"
		echo "Your minimum is \033[32m$min\033[0m"
	fi
fi
