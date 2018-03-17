nb=0
j=0
k=$1
for ((a=$k; a>0; a--))
do
	ARG="`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`"
	nb=$(expr $nb + $(./push_swap $ARG | wc -l))
done
	nb=$(expr $nb / $k)
echo "$nb"
