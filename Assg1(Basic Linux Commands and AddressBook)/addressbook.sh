#!/usr/bin/env bash
echo "Enter the file name "
read fname 

ans=1
while [ $ans -eq 1 ]
do
while [[ $ch -lt 7 ]]
do
echo -e "\nMENU\n1.Insert\n2.View\n3.Delete\n4.Modify\n5.Search\n6.Exit\n"
echo -e "Enter the choice : "
read ch

case $ch in
1) 

a=1
while [ $a -eq 1 ]
do

echo -e "Enter the data"
pati="^[0-9]"

echo -e "\nEnter the ID:"
read id
 while [[ ! $id =~ $pati ]]
        do
        echo "please enter valid id"
          read id
        done  
patn="^[A-Za-z]"
echo -e "\nEnter the Name:"
read name
 while [[ ! $name =~ $patn ]]
        do
        echo "please enter valid name"
          read name
        done    
patc="^[A-Za-z]"
echo -e "\nEnter the City:"
read city
 while [[ ! $city =~ $patc ]]
        do
        echo "please enter valid cityname"
          read city
        done 
echo -e "\nEnter the Phone number:"
read add
pat="^[0-9]{10}$"
        while [[ ! $add =~ $pat ]]
        do
        echo "please enter phone number as XXXXXXXXXX:"
          read add
        done    

        echo "enter email:"
        read em
        patem="^[a-z0-9._%-+]+@[a-z]+\.[a-z]{2,4}$"
        while [[ ! $em =~ $patem ]]
        do
                echo "please enter valid email address"
                read em
        done
echo -e ""
echo -e "id\tname\tcity\t phone no\t    email"
echo -e "$id\t$name\t$city\t$add\t$em">>$fname

echo -e "do u want to continue?(1/0)"
read a
done
;;

2)
echo -e "id\tname\tcity\t phone no\t    email"
cat $fname
;;
3)
echo -e "Enter the Record to Delete :"
     read name 
    if grep $name $fname
        then 
	grep -v $name $fname>>temp
	rm $fname 
	mv temp $fname
	echo -e "content after delete \n"
	echo -e "id\tname\tcity\t phone no\t    email"
	cat $fname
else
 echo "Record is NOT resent"

fi
;;


4)
echo -e "Enter the Record to Modify :"
read name
 if grep $name $fname
 then
	grep -v $name $fname>>temp
	rm $fname
	mv temp $fname
pati="^[0-9]"

echo -e "\nEnter the ID:"
read id
 while [[ ! $id =~ $pati ]]
        do
        echo "please enter valid id"
          read id
        done  
patn="^[A-Za-z]"
echo -e "\nEnter the Name:"
read name
 while [[ ! $name =~ $patn ]]
        do
        echo "please enter valid name"
          read name
        done    
patc="^[A-Za-z]"
echo -e "\nEnter the City:"
read city
 while [[ ! $city =~ $patc ]]
        do
        echo "please enter valid cityname"
          read city
        done 
echo -e "\nEnter the Phone number:"
read add
pat="^[0-9]{10}$"
        while [[ ! $add =~ $pat ]]
        do
        echo "please enter phone number as XXXXXXXXXX:"
          read add
        done    

        echo "enter email:"
        read em
        patem="^[a-z0-9._%-+]+@[a-z]+\.[a-z]{2,4}$"
        while [[ ! $em =~ $patem ]]
        do
                echo "please enter valid email address"
                read em
        done
echo -e "id\tname\tcity\t phone no\t    email"
echo -e "$id\t$name\t$city\t$add\t$em">>$fname
else 
 echo "Record is NOT resent"

fi



;;

5) echo -e "Enter the Record to search :"
read id
echo -e "id\tname\tcity\t phone no\t    email"
  grep $id $fname

;;
	
6) echo "THANK YOU"
exit 0
;;

esac
done

echo -e "do u want to continue?(1/0)"
read ans
done

# comp69@comp69:~$ chmod +x c.sh
# comp69@comp69:~$ ./c.sh
# Enter the file name
# stdinfo

# MENU
# 1.Insert
# 2.View
# 3.Delete
# 4.Modify
# 5.Search
# 6.Exit

# Enter the choice :
# 1
# Enter the data

# Enter the ID:
# 1

# Enter the Name:
# 34
# please enter valid name
# comp69

# Enter the City:
# 26
# please enter valid cityname
# pune

# Enter the Phone number:
# 93
# please enter phone number as XXXXXXXXXX:
# 5464789702
# enter email:
# comp69@gmail.com

# id      name    city     phone no           email
# do u want to continue?(1/0)
# 0

# MENU
# 1.Insert
# 2.View
# 3.Delete
# 4.Modify
# 5.Search
# 6.Exit

# Enter the choice :
# 2
# id      name    city     phone no           email
# 1       comp69   pune    5464789702      comp69@gmail.com

# MENU
# 1.Insert
# 2.View
# 3.Delete
# 4.Modify
# 5.Search
# 6.Exit

# Enter the choice :
# 5
# Enter the Record to search :
# comp69
# id      name    city     phone no           email
# 1       comp69   pune    5464789702      comp69@gmail.com

# MENU
# 1.Insert
# 2.View
# 3.Delete
# 4.Modify
# 5.Search
# 6.Exit

# Enter the choice :
# 4
# Enter the Record to Modify :
# 1
# 1       comp69   pune    5464789702      comp69@gmail.com

# Enter the ID:
# 2

# Enter the Name:
# comp69

# Enter the City:
# pune

# Enter the Phone number:
# 5464789702
# enter email:
# omk@gmail.com
# id      name    city     phone no           email

# MENU
# 1.Insert
# 2.View
# 3.Delete
# 4.Modify
# 5.Search
# 6.Exit


# Enter the choice :
# 3
# Enter the Record to Delete :
# 2
# 2       comp69   pune    5464789702      omk@gmail.com
# content after delete

# id      name    city     phone no           email

# MENU
# 1.Insert
# 2.View
# 3.Delete
# 4.Modify
# 5.Search
# 6.Exit

# Enter the choice :
# 6
# THANK YOU
# comp69@comp69:~$