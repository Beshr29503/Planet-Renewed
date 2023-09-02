# Embracing Freedom: Linux
---
## pwd
It prints the path of the working directory, starting from the root.
### Arguments:
1) -L:

It resolves symbolic links and prints the path of the target directory.

2) -p:

It displays the actual path without resolving symbolic links.

---
## mkdir
It allows User to create directories ( also referred as folders )
#### Arguments:
1) –help:
   
It displays help-related information and exits.

2) –version:

It displays the version number, some information regarding the license and exits. 

3) -v or –verbose:

It displays a message for every directory created.

4) -p:

A flag which enables the command to create parent directories as necessary. If the directories exist, no error is specified.

5) -m:

This option is used to set the file modes, i.e. permissions, etc. for the created directories. The syntax of the mode is the same as the chmod command. 

---
## cd
It is used to move efficiently from the current working directory to different directories in our System.
### Arguments:
1) /:

It change the directory to the root directory. The root directory is the first directory in your filesystem hierarchy. 

2) ~:

It change the directory to the home directory from any location in Linux System.

3) ..:

It move to the parent directory of current directory.

---
## ls
It lists directory contents of files and directories.
### Arguments:
1) -l:

It displays detailed information about files and directories.
2) -a:

It represent all files Include hidden files and directories in the listing.

3) -t:

It sort files and directories by their last modification time, displaying the most recently modified ones first.

4) -r:

It reverse the default order of listing.

5) -S:

It sort files and directories by their sizes, listing the largest ones first.

---
## touch
It is used to create a file without any content.

### Arguments:

1) -a:

This command is used to change access time only. To change or update the last access or modification times of a file touch -a command is used.

2) -c :

This command is used to check whether a file is created or not. If not created then don’t create it.

3) -c-d : 

This is used to update access and modification time.

---
## rm
It remove objects such as files, directories, symbolic links.

### Arguments:

1) -i:

It makes the command ask the user for confirmation before removing each file, you have to press y for confirm deletion, any other key leaves the file un-deleted.

2)  -f:
   
This option overrides this minor protection and removes the file forcefully.

3) -version:

This option is used to display the version of rm which is currently running on your system.

---
## cat
It reads data from the file and gives its content as output. It helps us to create, view, and concatenate files.

### Arguments:

1) -n file_name:

To view contents of a file preceding with line numbers. 

2) \> newfile_name :

To create a file and add content.

3) filename-whose-contents-is-to-be-copied > destination-filename:

Copy the contents of one file to another file. 

4) file_name1 >> file_name2:

Append the contents of one file to the end of another file. 

5) *.txt:

Display the content of all text files in the folder. 

---
## chmod
It is used to change the access mode of a file.

---
## clear
It clears the terminal screen.

---
### htop
It allows the user to interactively monitor the system’s vital resources or server’s processes in real time.

---
### sudo
It allows a user with proper permissions to execute a command as another user, such as the superuser. This is the equivalent of the “run as administrator” option in Windows.
