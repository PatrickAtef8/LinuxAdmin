#!/bin/bash

# Check if .bashrc exists
if [ -f ~/.bashrc ]; then
    # Append environment variables to .bashrc
    echo "export HELLO=\"\$HOSTNAME\"" >> ~/.bashrc
    echo "LOCAL=\"\$(whoami)\"" >> ~/.bashrc

    # Source .bashrc to apply changes immediately
    source ~/.bashrc

    # Open a new terminal
    gnome-terminal

fi
