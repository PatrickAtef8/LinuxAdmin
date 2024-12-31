#!/bin/bash

# Variables
USERNAME="yourname"
GROUPNAME="FamilyName"
LOGFILE="log.txt"
ERRORFILE="error.txt"

# Function to display user info
display_user_info() {
    echo "User information:" >> "$LOGFILE"
    id "$USERNAME" >> "$LOGFILE" 2>> "$ERRORFILE"
    echo "User '$USERNAME' UID: $(id "$USERNAME")" >> "$LOGFILE"
    echo "User '$USERNAME' UID: $(id -u "$USERNAME")" >> "$LOGFILE"
    echo "User '$USERNAME' GID: $(id -g "$USERNAME")" >> "$LOGFILE"
}

# Function to display group info
display_group_info() {
    echo "Group information:" >> "$LOGFILE"
    getent group "$GROUPNAME">> "$LOGFILE" 2>> "$ERRORFILE"
    echo "Group '$GROUPNAME' GID: $(getent group "$GROUPNAME" | cut -d: -f3)" >> "$LOGFILE"
    echo "Group '$GROUPNAME' Members: $(getent group "$GROUPNAME" | cut -d: -f4)" >> "$LOGFILE"
}

# Check if group exists; if not, create it
if getent group "$GROUPNAME" >> "$LOGFILE" 2>> "$ERRORFILE"; then
    echo "Group '$GROUPNAME' already exists." >> "$LOGFILE"
else
    echo "Group '$GROUPNAME' does not exist. Creating group..." >> "$LOGFILE"
    groupadd "$GROUPNAME" >> "$LOGFILE" 2>> "$ERRORFILE"
    
    if [ $? -eq 0 ]; then
        echo "Group '$GROUPNAME' created successfully." >> "$LOGFILE"
    else
        echo "Failed to create group '$GROUPNAME'." >> "$ERRORFILE"
        exit 1
    fi
fi

# Check if user exists; if not, create it
if id "$USERNAME" >> "$LOGFILE" 2>> "$ERRORFILE"; then
    echo "User '$USERNAME' already exists." >> "$LOGFILE"
else
    echo "User '$USERNAME' does not exist. Creating user..." >> "$LOGFILE"
    adduser --disabled-password "$USERNAME" >> "$LOGFILE" 2>> "$ERRORFILE"
    
    if [ $? -eq 0 ]; then
        echo "User '$USERNAME' created successfully." >> "$LOGFILE"
        # Add user to the FamilyName group
        usermod -aG "$GROUPNAME" "$USERNAME" >> "$LOGFILE" 2>> "$ERRORFILE"
        echo "User '$USERNAME' added to group '$GROUPNAME'." >> "$LOGFILE"
    else
        echo "Failed to create user '$USERNAME'." >> "$ERRORFILE"
        exit 1
    fi
fi

# Display user and group information
display_user_info
display_group_info

