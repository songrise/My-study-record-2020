#!/bin/bash
# run blog server
pkill -f jekyll

sudo nginx
source /home/ubuntu/.rvm/scripts/rvm
cd ./test/github/jekyll-theme-next
jekyll serve -H 0.0.0.0 -P 8080 --detach