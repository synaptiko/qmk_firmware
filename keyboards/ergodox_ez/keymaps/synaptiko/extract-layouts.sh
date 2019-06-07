#!/usr/bin/env bash
grep -E "^( {2}/\*| {3}\*)" keymap.c | sed -r 's/^.{5}//'
