#!/usr/bin/env python

import json
import sys
import os

if len(sys.argv) != 2:
    sys.stderr.write("usage %s <filename>" % sys.argv[0])

val=None
with open(sys.argv[1]) as src:
    val=json.loads(src.read())
    val["credentials"]["user"] = "newpassword"

with open(sys.argv[1], "w") as dest:
    dest.write(json.dumps(val,indent=4))

