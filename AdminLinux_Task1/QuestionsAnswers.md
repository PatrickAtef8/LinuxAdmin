# Task 1 Questions and Answers

## 1. **List three linux distribution.**
- Ubuntu
- Fedora
- Red Hat

## 2. **From the slides what is the man command used for?**
- It's used to display the **manual pages** (documentation) for various commands and programs. it provide detailed information about commands,their options, syntax and usage examples (used for external commands only)

## 3. **What is the difference between rm and rmdir using man command?**
- **rm** used to remove files or directories.
- **rmdir** used to remove empty directories, it doesn't work if the directory contains files or other directories.

## 4. **Created the hierarchy**
**a.** After removing dir11 with **rmdir** in one-step, message says that directory is not empty so you cant remove the directory, overcome it by go to the dir11 and use **rm file** to delete the created file (content of the directory) then use rmdir to remove it.

**b.** trying to remove OldFiles using rmdir –p command. error because this command is not used to remove files but directories 

**c.** - **Absolute path** --> **C:\Users\Patrick\docs\mycv**
       --- **Relative path** --> **docs\mycv**

## 7. **Four Ways to home directory**
1. cd ~
2. cd
3. cd $HOME 
4. cd /c/Users/user_name

## 8. **Commands starts with w**
- Commands can used to know them like man -k w or compgen -c | grep ^w
Ex. watch-wait-who-while

## 9. **What command type are used for?**
- Display information about command type

## 10. **Show 2 types of command file in /usr/bin that start with letter c**
- cat, cp

## 12. **apropos command**
- used to search for keywords related to available commands and their description in the manual pages.


