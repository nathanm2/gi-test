#!/usr/bin/env python3
import gi
gi.require_version("My", "0.1")
from gi.repository import My

print("{}".format(My.get_constant()))
