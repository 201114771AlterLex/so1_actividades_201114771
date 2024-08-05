#!/bin/bash 

##Variable with the user name of system
GITHUB_USER=$(git config user.name || echo "201114771AlterLex")
##Get json from api with information of user git
response=$(curl -s https://api.github.com/users/$GITHUB_USER)

###Parse the json 
##User name and quit the double quoation of begin and end 
r1=$(jq --argjson j "$response" -n '$j.login')
r1=${r1:1:-1}
##Id user
r2=$(jq --argjson k "$response" -n '$k.id')
##The date to create the account  in git and quit the double quoation of begin and end
r3=$(jq --argjson l "$response" -n '$l.created_at')
r3=${r3:1:-1}

##Today to create the folder, where log file save
TODAY=$(date +"%d-%m-%Y")

##directory path
dir=/tmp/$TODAY
##file path
file=$dir/saludos.log

##if exist directory, check if the file exist and only append message in file otherwise 
## create the file and write message in file, otherwise create directory and create the file
## and write message in file
if [[ -d  $dir ]] then
    if [[ -e $file ]] then 
        echo Hola $r1. User ID: $r2. Cuenta fue creada el: $r3. >> $file
    else
        touch $file
        echo Hola $r1. User ID: $r2. Cuenta fue creada el: $r3. >> $file
    fi
else
    mkdir $dir
    touch $file
    echo Hola $r1. User ID: $r2. Cuenta fue creada el: $r3. >> $file
fi