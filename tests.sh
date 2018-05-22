#!/bin/sh

e = "-e"

echo "env"
echo $e "env" | ./mysh > tutu
echo $e "env" | tcsh > tutu2
diff tutu tutu2
rm tutu tutu2
echo "---------------------------------------------------------"
echo "setenv"
echo $e "setenv a a\nenv" | ./mysh > tata
echo $e "setenv a a\nenv" | tcsh > tata2
diff tata tata2
rm tata tata2
echo "---------------------------------------------------------"
echo "1. ls Got :"
echo $e "ls" | ./mysh
echo "\n ls Expected :"
echo $e "ls" | tcsh
echo "---------------------------------------------------------"
echo "2. ls -l Got :"
echo $e "ls -l" | ./mysh
echo "\n ls -l Expected :"
echo $e "ls -l" | tcsh
echo "---------------------------------------------------------"
echo "3. pwd cd .. pwd Got :"
echo $e "pwd\ncd ..\npwd" | ./mysh
echo "\n pwd cd .. pwd Expected :"
echo $e "pwd\ncd ..\npwd" | tcsh
echo "---------------------------------------------------------"
echo "4. pwd cd ../PSU_minishell2_2017 pwd Got :"
echo $e "pwd\ncd ../PSU_minishell2_2017\npwd" | ./mysh
echo "\n pwd cd ../PSU_minishell2_2017 pwd Expected :"
echo $e "pwd\ncd ../PSU_minishell2_2017\npwd" | tcsh
echo "---------------------------------------------------------"
echo "5. cd ../error Got :"
echo $e "cd ../error" | ./mysh
echo "\n cd../error Expected :"
echo $e "cd ../error" | tcsh
echo "---------------------------------------------------------"
echo "6. setenv a[test Got :"
echo $e "setenv a[test" | ./mysh
echo "\n setenv a[test Expected :"
echo $e "setenv a[test" | tcsh
echo "---------------------------------------------------------"
echo "7. testerror Got :"
echo $e "testerror" | ./mysh
echo "\n testerror Expected :"
echo $e "testerror" | tcsh
echo "---------------------------------------------------------"
echo "8. \tls  \t-a\t Got :"
echo $e "\tls  \t-a\t" | ./mysh
echo "\n \tls  \t-a\t Expected :"
echo $e "\tls  \t-a\t" | tcsh
echo "---------------------------------------------------------"
