#!/bin/bash

a="somefile"
trap 'rm $a' EXIT
exit 1
