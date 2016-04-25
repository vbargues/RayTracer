i=1
count=1
sp="/-\|"
while [ $count != 10 ] 
do
		sleep 0.1
	    printf "\033[97m\rCompiling\033[1;92m $1 \033[0m${sp:i++%${#sp}:1}"
		count=`expr $count + 1`
	done
echo "\b👌 \a"
