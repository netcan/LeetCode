#########################################################################
# File Name: solution.sh
# Author: Netcan
# Blog: http://www.netcan666.com
# Mail: 1469709759@qq.com
# Created Time: 2017-01-09 Mon 12:49:49 CST
#########################################################################
#!/bin/bash

if(($(wc -l < file.txt) < 10))
then
	:;
else
	head -n 10 file.txt | tail -n 1
fi

