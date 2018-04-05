ARG="`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`"
min=$(./push_swap $ARG | wc -l)
j=0
k=$1
for ((a=$k; a>0; a--))
do
	ARG="`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`"
	nb=$(./push_swap $ARG | wc -l)
	if [ $nb -gt $min ]
	then
		ARG_MIN=$ARG
		min=$nb
	fi
done
echo "$min"
echo "\n"
echo "$ARG_MIN"
