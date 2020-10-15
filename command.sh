#!/bin/bash
git init
git add main.c
git add pgm.h
git add pgm.c
git add command.sh
git commit -m "old version PGM-version-1.0"
git remote add origin https://github.com/slow92/PGM-version-1.0.git
git push origin master -f