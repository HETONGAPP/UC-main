#!/bin/bash

# getting current directory
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# target directory
parent_dir="$script_dir/../.git/hooks"

# delete old directory
rm -rf "$parent_dir"

# symbolic link
ln -s "$script_dir/../hooks" "$parent_dir"
