#!/bin/bash

DATE=`date`

git add .
git commit -m "$DATE"
git push origin master
