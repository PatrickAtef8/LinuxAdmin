#!/bin/bash
# 1. Create a directory called "myDirectory" in your home folder.
cd ~
mkdir myDirectory
# 2. Inside "myDirectory," create another directory named "secondDirectory."
cd myDirectory
mkdir secondDirectory
# 3. Within "secondDirectory," create a file named "myNotePaper."
cd secondDirectory
touch myNotePaper
# 4. Copy "myNotePaper" from "secondDirectory" to "myDirectory."
cp myNotePaper ~/myDirectory
# 5. Rename the copied file in "myDirectory" to "myOldNotePaper."
mv ~/myDirectory/myNotePaper ~/myDirectory/myOldNotePaper